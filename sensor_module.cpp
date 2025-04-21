#include "sensor_module.h"
#include <algorithm>
#include <QDebug>

const std::array<uint16_t, Sensor_Module::HAMMING_SIZE> Sensor_Module::auw_hamm = {41, 276, 512, 276, 41};
Sensor_Module::Sensor_Module(QObject *parent)

    : QObject(parent),
      sensor(),
      sensorTimer(this),
{
    bufferIndex = 0;
    lastHeartRate = 0;
    lastSpo2 = 0;


    int result = sensor.begin();
    if (result < 0) {
        qWarning() << "Sensor initialization failed! Error: " << result;
    } else {
        qDebug() << "Sensor initialized successfully. Revision ID: " << result;
        sensor.setup();
    }
    connect(&sensorTimer, &QTimer::timeout, this, &Sensor_Module::updateSensorData);
    sensorTimer.start(10);//10ms cycle，
    //Configuration of the timer start attribute
    //sensorTimer.singleShot() is triggered once here instead of in a loop
}

/*Periodically executing function
    drive by sensorTimer::timeout
*/
void Sensor_Module::updateSensorData()
{
    uint32_t red = sensor.getRed();
    uint32_t ir = sensor.getIR();

    qDebug() << "RED:" << red << "IR:" << ir;

    redBuffer[bufferIndex] = red;
    irBuffer[bufferIndex] = ir;
    bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;

    if (bufferIndex == 0) {
        int heartRate, spo2;
        processSensorData(redBuffer, irBuffer, &heartRate, &spo2);
        qDebug() << "heartRate:" << heartRate << "spo2:" << spo2;
        lastHeartRate = heartRate;
        lastSpo2 = spo2;
    }
}

void Sensor_Module::processSensorData(std::array<uint32_t, BUFFER_SIZE>& redBuffer, std::array<uint32_t, BUFFER_SIZE>& irBuffer, int* heartRate, int* spo2)
{
    uint32_t un_red_mean = 0;
    for (int k = 0; k < BUFFER_SIZE; k++) un_red_mean += redBuffer[k];
    un_red_mean /= BUFFER_SIZE;
    for (int k = 0; k < BUFFER_SIZE; k++) an_x[k] = redBuffer[k] - un_red_mean;
    for (int k = 0; k < BUFFER_SIZE - MA4_SIZE; k++) {
        an_x[k] = (an_x[k] + an_x[k + 1] + an_x[k + 2] + an_x[k + 3]) / 4;
    }

    for (int k = 0; k < BUFFER_SIZE - MA4_SIZE - 1; k++) {
        an_dx[k] = an_x[k + 1] - an_x[k];
    }

    for (int k = 0; k < BUFFER_SIZE - MA4_SIZE - 2; k++) {
        an_dx[k] = (an_dx[k] + an_dx[k + 1]) / 2;
    }

    for (int i = 0; i < BUFFER_SIZE - HAMMING_SIZE - MA4_SIZE - 2; i++) {
        int32_t s = 0;
        for (int k = i; k < i + HAMMING_SIZE; k++) {
            s -= an_dx[k] * auw_hamm[k - i];
        }
        an_dx[i] = s / 1146;
    }

    int32_t n_th1 = 0;
    for (int k = 0; k < BUFFER_SIZE - HAMMING_SIZE; k++) {
        n_th1 += (an_dx[k] > 0 ? an_dx[k] : -an_dx[k]);
    }
    n_th1 /= (BUFFER_SIZE - HAMMING_SIZE);

    int32_t an_dx_peak_locs[15];
    int32_t n_npks = 0;
    maxim_find_peaks(an_dx_peak_locs, &n_npks, an_dx.data(), BUFFER_SIZE - HAMMING_SIZE, n_th1, 8, 5);

    if (n_npks >= 2) {
        int32_t n_peak_interval_sum = 0;
        for (int k = 1; k < n_npks; k++) {
            n_peak_interval_sum += (an_dx_peak_locs[k] - an_dx_peak_locs[k - 1]);
        }
        n_peak_interval_sum /= (n_npks - 1);
        *heartRate = 6000 / n_peak_interval_sum;
    } else {
        *heartRate = 255; // The heart value is invalid.
    }

    uint32_t redMax = *std::max_element(redBuffer.begin(), redBuffer.end());
    uint32_t redMin = *std::min_element(redBuffer.begin(), redBuffer.end());
    uint32_t irMax = *std::max_element(irBuffer.begin(), irBuffer.end());
    uint32_t irMin = *std::min_element(irBuffer.begin(), irBuffer.end());

    uint32_t ACred = redMax - redMin;
    uint32_t DCred = (redMax + redMin) / 2;
    uint32_t ACired = irMax - irMin;
    uint32_t DCired = (irMax + irMin) / 2;

    double R = ((double)(ACred * DCired)) / (DCred * ACired);
    *spo2 = -45.060 * R * R + 30.354 * R + 94.845;

    if (*heartRate > 200) {
        *heartRate = 255;
    }
    if (*spo2 < 80 || *spo2 > 100) {
        *spo2 = 255;
    }
}

uint8_t Sensor_Module::HeartbeatValueHandle()
{
    return static_cast<uint8_t>(lastHeartRate);
}

uint8_t Sensor_Module::SPO2_ValueHandle()
{
    return static_cast<uint8_t>(lastSpo2);
}

uint8_t Sensor_Module::SelfCheckHandle()
{
    int check_result = sensor.begin();
    bool success = (check_result >= 0);
    return success ? 0x00 : 0xFF;
}

void Sensor_Module::maxim_find_peaks(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_size, int32_t n_min_height, int32_t n_min_distance, int32_t n_max_num)
{
    maxim_peaks_above_min_height(pn_locs, pn_npks, pn_x, n_size, n_min_height);
    maxim_remove_close_peaks(pn_locs, pn_npks, pn_x, n_min_distance);
    *pn_npks = std::min(*pn_npks, n_max_num);
}

void Sensor_Module::maxim_peaks_above_min_height(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_size, int32_t n_min_height)

{
    int32_t i = 1, n_width;
    *pn_npks = 0;

    while (i < n_size - 1) {
        if (pn_x[i] > n_min_height && pn_x[i] > pn_x[i - 1]) {
            n_width = 1;

            while (i + n_width < n_size && pn_x[i] == pn_x[i + n_width]) n_width++;
            if (pn_x[i] > pn_x[i + n_width] && (*pn_npks) < 15) {
                pn_locs[(*pn_npks)++] = i;
                i += n_width + 1;
            } else {
                i += n_width;
            }
        } else {
            i++;
        }
    }
}

void Sensor_Module::maxim_remove_close_peaks(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_min_distance)
{
    int32_t i, j;
    int32_t accepted = 0;

    maxim_sort_indices_descend(pn_x, pn_locs, *pn_npks);


    for (j = 0; j < *pn_npks; j++) {
        bool keep = true;
        for (i = 0; i < accepted; i++) {
            if (abs(pn_locs[j] - pn_locs[i]) < n_min_distance) {
                keep = false;
                break;
            }
        }
        if (keep) {
            pn_locs[accepted++] = pn_locs[j];
        }
    }
    *pn_npks = accepted;

    maxim_sort_ascend(pn_locs, *pn_npks);
}

void Sensor_Module::maxim_sort_ascend(int32_t *pn_x, int32_t n_size)

{
    for (int i = 1; i < n_size; i++) {
        int32_t n_temp = pn_x[i];
        int j;
        for (j = i; j > 0 && n_temp < pn_x[j - 1]; j--) {
            pn_x[j] = pn_x[j - 1];
        }
        pn_x[j] = n_temp;
    }
}


void Sensor_Module::maxim_sort_indices_descend(int32_t *pn_x, int32_t *pn_indx, int32_t n_size)
{
    for (int i = 1; i < n_size; i++) {
        int32_t n_temp = pn_indx[i];
        int j;
        for (j = i; j > 0 && pn_x[n_temp] > pn_x[pn_indx[j - 1]]; j--) {
            pn_indx[j] = pn_indx[j - 1];
        }
        pn_indx[j] = n_temp;
    }
}
