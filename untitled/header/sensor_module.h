#ifndef SENSOR_MODULE_H
#define SENSOR_MODULE_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Sensor_Module : public QObject
{
    Q_OBJECT
public:
    explicit Sensor_Module(QObject *parent = nullptr);

    uint8_t HeartbeatValueHandle();
    uint8_t SP2O_ValueHandle();
    uint8_t SelfCheckHandle();

public slots:
    void Sensor_Module_Start_Slot();
signals:
    void Module_Ready();
private:
    MAX30102 sensor;
    QTimer sensorTimer;

    static const int BUFFER_SIZE = 100;
    std::array<uint32_t, BUFFER_SIZE> redBuffer{};
    std::array<uint32_t, BUFFER_SIZE> irBuffer{};
    int bufferIndex{0};
    int lastHeartRate{0};
    int lastSpo2{0};
    static const int MA4_SIZE = 4;
    static const int HAMMING_SIZE = 5;
    static const std::array<uint16_t, HAMMING_SIZE> auw_hamm;

    std::array<int32_t, BUFFER_SIZE> an_x{};
    std::array<int32_t, BUFFER_SIZE - MA4_SIZE> an_dx{};

    void updateSensorData();
    void processSensorData(std::array<uint32_t, BUFFER_SIZE>& redBuffer, std::array<uint32_t, BUFFER_SIZE>& irBuffer, int* heartRate, int* spo2);
    void maxim_find_peaks(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_size, int32_t n_min_height, int32_t n_min_distance, int32_t n_max_num);
    void maxim_peaks_above_min_height(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_size, int32_t n_min_height);
    void maxim_remove_close_peaks(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_min_distance);
    void maxim_sort_ascend(int32_t *pn_x, int32_t n_size);
    void maxim_sort_indices_descend(int32_t *pn_x, int32_t *pn_indx, int32_t n_size);

};

#endif // SENSOR_MODULE_H
