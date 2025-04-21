#include "quickopencv.h"

quickopenCV::quickopenCV()
{


}

void quickopenCV::colorSpace_Demo(cv::Mat& image)
{
    cv::Mat gray;
    //ɫ�ʿռ�ת��
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    imshow("Gray", gray);
    imwrite("G:/LocalWorkSpace/gray.png", gray);


    //Mat hsv;
    //cvtColor(image, hsv, COLOR_BGR2HSV);
    //imshow("HSV", hsv);

    //Mat ycrcb;
    //cvtColor(image, ycrcb, COLOR_BGR2YCrCb);
    //imshow("YCrCb", ycrcb);

    //Mat lab;
    //cvtColor(image, lab, COLOR_BGR2Lab);
    //imshow("Lab", lab);

    //Mat luv;
    //cvtColor(image, luv, COLOR_BGR2Luv);
    //imshow("Luv", luv);

    //Mat hls;
    //cvtColor(image, hls, COLOR_BGR2HLS);
    //imshow("HLS", hls);

    //Mat xyz;
    //cvtColor(image, xyz, COLOR_BGR2XYZ);
    //imshow("XYZ", xyz);

    //Mat yuv;
    //cvtColor(image, yuv, COLOR_BGR2YUV);
    //imshow("YUV", yuv);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void quickopenCV::mat_create_demo(cv::Mat& image)
{
    cv::Mat c, cc;

    c=image.clone();//clone,�µ�Ԫ�أ����Ƕ��ϵ�ʵ��������

    image.copyTo(cc);//samillar with clone.���Ʋ����µ�Ԫ�أ����Ƕ��ϵ�ʵ��������

    cv::Mat ccc=image;//reference,���õȼ���C����$������,����Mat����

    //Mat m1(480, 640, CV_8UC3, Scalar(0, 0, 255));
    //imshow("m1", m1);

    //Mat m2(Size(640, 480), CV_8UC3, Scalar(0, 255, 0));
    //imshow("m2", m2);

    //Mat m3 = Mat::zeros(Size(8, 8), CV_8UC3);
    //imshow("m3", m3);

    cv::Mat m4 = cv::Mat::ones(cv::Size(4, 4), CV_8UC3);
    m4=cv::Scalar(1, 255, 0);//mat������ÿһ��Ԫ�ض���(1, 255, 0)
    imshow("m4", m4);

    cv::Mat m5 = cv::Mat::eye(cv::Size(4, 4), CV_8UC3);
    imshow("m5", m5);
    std::cout<<m5<<std::endl;

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void quickopenCV::pixel_access_demo(cv::Mat& image)
{
    int width = image.cols;
    int height = image.rows;

    int channels = image.channels();

    //2d matrix access
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (channels == 1)
            {
                int pixel = image.at<uchar>(row, col);
            }
            if (channels == 3)
            {
                cv::Vec3b pixel = image.at<cv::Vec3b>(row, col);
                image.at<cv::Vec3b>(row, col)[0] = 255 - pixel[0];
                image.at<cv::Vec3b>(row, col)[1] = 255 - pixel[1];
                image.at<cv::Vec3b>(row, col)[2] = 255 - pixel[2];
                /*uchar b = pixel[0];
                uchar g = pixel[1];
                uchar r = pixel[2];
                std::cout << "BGR: " << b << " " << g << " " << r << std::endl;*/

            }
            //uchar* pixel = image.ptr<uchar>(row, col);
            //uchar* pixel = image.ptr<uchar>(row, col, 0);

        }
    }

    //3d matrix access
    //Mat volume(10, 10, 10, CV_32F);  // 3D ������
    //Vec<int, 3> idx = { 5, 5, 5 };  // ���� (5,5,5) λ��
    //// Is this equal to Vec3b? Refer to the documentation
    //const float* dataPtr = volume.ptr<float>(idx);
    //std::cout << "Value at (5,5,5): " << dataPtr[0] << std::endl;
    imshow("Recersed Image", image);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

void quickopenCV::operator_demo(cv::Mat& image)
{
    cv::Mat dst;
    imshow("origin", image);
    //ɫ�ʿռ�ת��
    cvtColor(image, dst, cv::COLOR_BGR2HLS);

    // �Ӽ�������
    //dst= dst+ Scalar(0, 20, 10);//�Ӽ�����������ֱ�Ӷ�Mat���в���
    //add(dst, Scalar(0, 20, 10), dst);//�Ӽ�����������ֱ�Ӷ�Mat���в���
    //subtract(dst, Scalar(0, 20, 10), dst);//�Ӽ�����������ֱ�Ӷ�Mat���в���
    //divide(dst, Scalar(0, 20, 10), dst);//�Ӽ�����������ֱ�Ӷ�Mat���в���
    int width = dst.cols;
    int height = dst.rows;
    cv::Mat medium(dst.size(), dst.type(), cv::Scalar(0, 20, 0));
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            cv::Vec3b pixel1 = dst.at<cv::Vec3b>(row, col);
            cv::Vec3b pixel2 = medium.at<cv::Vec3b>(row, col);
            dst.at<cv::Vec3b>(row, col)[0] = cv::saturate_cast<uchar>(pixel1[0] + pixel2[0]);
            dst.at<cv::Vec3b>(row, col)[1] = cv::saturate_cast<uchar>(pixel1[1] + pixel2[1]);
            dst.at<cv::Vec3b>(row, col)[2] = cv::saturate_cast<uchar>(pixel1[2] + pixel2[2]);
        }
    }

    //�˷�����
    //Mat medium(dst.size(), dst.type(), Scalar(1, 2, 1));,Scalar������������
    //multiply(dst, medium, dst);//�˷�����

    cvtColor(dst, image, cv::COLOR_HLS2BGR);
    imshow("HLS changed", image);



    cv::waitKey(0);
    cv::destroyAllWindows();
}

static int brightness = 50;
const int Max_Brightness = 100;
static cv::Mat medium;

static void on_trackbar(int pos, void* userdata) {
    cv::Mat* medium_Inner;
    medium_Inner = (cv::Mat*)userdata;
    double multiply_variable = (double)pos / Max_Brightness;

    cv::Mat medium1 = (*medium_Inner).clone();
    (*medium_Inner).convertTo(medium1, -1, 2 * multiply_variable, 0);
    imshow("Brightness adjust", medium1);
}

void quickopenCV::tracking_bar_demo(cv::Mat& image)
{
    medium = image.clone();


    namedWindow("Brightness adjust", cv::WINDOW_FREERATIO);


    char Brightness[50];
    snprintf(Brightness, sizeof(Brightness), "Max Brightness is %d", Max_Brightness);
    cv::createTrackbar(Brightness, "Brightness adjust", &brightness, Max_Brightness, on_trackbar,(void*)&medium);

    on_trackbar(brightness, (void*)&medium);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return;
}

void quickopenCV::key_demo(cv::Mat& image)
{
    cv::Mat dest;

    imshow("origin", image);

    while (1)
    {
        char c =cv::waitKey(10000);
        std::cout << c << std::endl;
    }
}

//009
void quickopenCV::color_style_demo(cv::Mat& image)
{

}

void quickopenCV::channel_demo(cv::Mat& image)
{
    //cv::split,cv::merge,cv::extractChannel,cv::insertChannel and some forms of cv::cvtColor are partial cases of cv::mixChannels.

    std::vector<cv::Mat> channels;
    split(image, channels);//split the image into x channels
    imshow("B", channels[0]);
    imshow("G", channels[1]);
    imshow("R", channels[2]);
    cv::waitKey(0);

    merge(channels, image);//merge the channels into one image
    imshow("Merged", image);

    mixChannels(channels, channels, { 0, 0, 1, 1, 2, 2 });

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void quickopenCV::inrange_demo(cv::Mat& image)
{
    cv::Mat dst;

    imshow("origin", image);
    cvtColor(image, dst, cv::COLOR_BGR2HSV);

    cv::Mat mask;

    inRange(dst, cv::Scalar(35, 43, 46), cv::Scalar(77, 255, 255), mask);

    imshow("Mask", mask);

    cv::Mat redback(image.size(), image.type(),cv::Scalar(40,40,200));

    //bitwise_not(mask, mask);
    image.copyTo(redback, mask);//mask��Ϊ0�ĵط�������,��ɫ0

    imshow("Redback", redback);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void quickopenCV::pixel_statistic_demo(cv::Mat& image)
{
    double min, max;
    cv::Point min_loc, max_loc;

    std::vector<cv::Mat> singleChanel;
    split(image, singleChanel);

    minMaxLoc(singleChanel[0], &min, &max, &min_loc, &max_loc);

    std::cout << "Min: " << min << " Max: " << max << std::endl;

    cv::Mat mean, stddev;
    meanStdDev(image, mean, stddev);//Calculates a mean and standard deviation of array elements.
    std::cout << "Mean: " << mean << " Stddev: " << stddev << std::endl;
}

void quickopenCV::draw_demo(cv::Mat& image)
{
    //draw a rectangle
    cv::Rect rect(100, 100, 200, 200);

    cv::Mat bg(image.size(), image.type(), cv::Scalar(0, 0, 0));//black background
    rectangle(bg, rect, cv::Scalar(0, 255, 0), 2, cv::LINE_AA,0);

    line(bg, cv::Point(100, 100), cv::Point(300, 200), cv::Scalar(0, 0, 255), 2, cv::LINE_AA, 0);

    circle(bg, cv::Point(50, 50), 50, cv::Scalar(0, 0, 255), 2, cv::LINE_AA, 0);

    cv::RotatedRect rRect(cv::Point2f(200, 200), cv::Size2f(100, 50), 30);

    ellipse(bg, cv::Point(100, 100), cv::Size(100, 50), 0, 0, 360, cv::Scalar(0, 255, 0), 2, cv::LINE_AA, 0);

    addWeighted(image, 1, bg, 0.5, 0, image);


    imshow("origin", image);


}

void quickopenCV::random_drawings(cv::Mat& image)
{
    cv::Mat canvas(image.size(), image.type(), cv::Scalar(0, 0, 0));

    cv::RNG rng(12345);
    unsigned char input;

    while (1)
    {
        input = cv::waitKey(500);
        if (input == 27)
        {
            break;
        }
        int x1 = rng.uniform(0, canvas.cols);
        int y1 = rng.uniform(0, canvas.rows);
        line(canvas, cv::Point(x1, y1), cv::Point(rng.uniform(0, canvas.cols), rng.uniform(0, canvas.rows)), cv::Scalar(0, 0, 255));
        imshow("Random", canvas);
    }

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void quickopenCV::polyline_drawing_demo()
{
    int weight = 200;
    int height = 200;
    cv::Mat canvas(cv::Size(weight, height), CV_8SC3, cv::Scalar(0, 0, 0));

    cv::Point p1(0, 0);
    cv::Point p2(25, 25);
    cv::Point p3(75, 100);
    cv::Point p4(125, 150);
    cv::Point p5(150, 190);

    std::vector<cv::Point> pts;
    pts.push_back(p1);
    pts.push_back(p2);
    pts.push_back(p3);
    pts.push_back(p4);
    pts.push_back(p5);

    //polylines(canvas, pts, true, Scalar(0, 0, 255));
    //fillPoly(canvas, pts, Scalar(0, 0, 255));

    std::vector<std::vector<cv::Point>> contours;

    contours.push_back(pts);

    drawContours(canvas, contours, 0, cv::Scalar(0, 0, 255), -1, 8);

    imshow("sample",canvas);
}


cv::Mat bgForMouse;
cv::Point sp(-1, -1);
cv::Point ep(-1, -1);
static void mouse_drawing(int event, int x, int y, int flags, void* userdata)
{
    if ((event & (cv::EVENT_LBUTTONDOWN | cv::EVENT_MOUSEMOVE)) == (cv::EVENT_LBUTTONDOWN | cv::EVENT_MOUSEMOVE))
    {
        sp.x = x;
        sp.y = y;
        std::cout << "start point:" << sp << std::endl;
    }
    if ((event & (cv::EVENT_LBUTTONUP | cv::EVENT_MOUSEMOVE)) == (cv::EVENT_LBUTTONUP | cv::EVENT_MOUSEMOVE))
    {
        ep.x = x;
        ep.y = y;
        std::cout << "end point:" << ep << std::endl;

        int dx = ep.x - sp.x;
        int dy = ep.y - sp.y;
        if ((dx > 0) && (dy > 0))
        {
            cv::Mat canvas(cv::Size(bgForMouse.cols, bgForMouse.rows), CV_8UC3, cv::Scalar(0, 0, 0));

            cv::Point p2(sp.x, ep.y);
            cv::Point p3(ep.x, sp.y);

            std::vector<cv::Point> pts;
            pts.push_back(sp);
            pts.push_back(p2);
            pts.push_back(ep);
            pts.push_back(p3);

            cv::Rect Box(sp.x, sp.y, dx, dy);
            //addWeighted(canvas, 1, bgForMouse, 1, 0, canvas);
            imshow("ROI area", bgForMouse(Box));

            polylines(canvas, pts, true, cv::Scalar(0, 0, 255));
            addWeighted(canvas, 1, bgForMouse, 1, 0, canvas);
            imshow("mouse_aciton", canvas);


        }
    }
}

void quickopenCV::mouse_drawing_demo(cv::Mat& image)
{
    bgForMouse = image.clone();
    namedWindow("mouse_aciton", cv::WINDOW_FREERATIO);
    imshow("mouse_aciton", bgForMouse);
    cv::setMouseCallback("mouse_aciton", mouse_drawing, NULL);
}

void quickopenCV::norm_demo(cv::Mat& image)
{
    cv::Mat dst;
    image.convertTo(image, CV_32F);
    normalize(image, dst, 1, 0, cv::NORM_MINMAX);
    imshow("output", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void quickopenCV::resize_demo(cv::Mat& image)
{
    cv::Mat zoomin, zoomout;

    int height = image.rows;
    int width = image.cols;

    resize(image, zoomin, cv::Size(height / 2, width / 2), 0, 0, cv::INTER_LINEAR);

    resize(image, zoomout, cv::Size(width, height*2), 0, 0, cv::INTER_LINEAR);
    //namedWindow("output", WINDOW_FREERATIO);

    //imshow("output",zoomin);
    imshow("output", zoomout);

    cv::waitKey(0);
    cv::destroyAllWindows();
}


void quickopenCV::flip_demo(cv::Mat& image)
{
    cv::Mat dst;

    flip(image, dst, -1);//-1,0,1������ͬ��ת��ʽ

    imshow("output", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();


}


void quickopenCV::rotate_demo(cv::Mat& image)
{
    cv::Mat dst,M;

    int width = image.cols;
    int height = image.rows;

    M = getRotationMatrix2D(cv::Point2f(width / 2, height / 2), 45,1);

    //these part of equation may not correct, chech them with cautious
    double cos = abs(M.at<double>(0, 0));
    double sin = abs(M.at<double>(0, 1));

    int nw = cos * width + sin * height;
    int nh= sin * width + cos * height;


    M.at<double>(0, 2) = M.at<double>(0.2) + (nw / 2 - width / 2);
    M.at<double>(1, 2) = M.at<double>(1.2) + (nh / 2 - height / 2);

    warpAffine(image, dst, M, cv::Size(nw,nh), cv::INTER_LINEAR);
    //warpAffine(image, dst, M, image.size(), INTER_LINEAR);

    imshow("output", dst);

    cv::waitKey(0);

    cv::destroyAllWindows();

}


void quickopenCV::video_demo()
{
    //VideoCapture capture("G:/VisualAlgorthym/2.mp4");
    cv::VideoCapture capture(0);
    int frame_width = capture.get(cv::CAP_PROP_FRAME_WIDTH);
    int frame_height = capture.get(cv::CAP_PROP_FRAME_HEIGHT);
    int frame_count = capture.get(cv::CAP_PROP_FRAME_COUNT);

    double fps = capture.get(cv::CAP_PROP_FPS);

    std::cout << "frame_width:" << frame_width << std::endl;
    std::cout << "frame_height:" << frame_height << std::endl;
    std::cout << "frame_count:" << frame_count << std::endl;
    std::cout << "fps:" << fps << std::endl;

    cv::VideoWriter writer("G:/VisualAlgorthym/3.mp4", capture.get(cv::CAP_PROP_FOURCC),fps,cv::Size(frame_width,frame_height),1);

    cv::Mat frame;
    while (1)
    {
        capture.read(frame);

        //flip(frame, frame, 1);
        if (frame.empty())
        {
            break;
        }
        imshow("frame", frame);
        writer.write(frame);
        int c = cv::waitKey(10);
        if (c == 27)
        {
            break;
        }
    }
    writer.release();
    capture.release();
}

void quickopenCV::show_Histogram_demo(cv::Mat& image)
{
    std::vector <cv::Mat> bgr_plane;
    split(image, bgr_plane);

    const int channels[1] = { 0 };
    const int bins[1] = { 256 };
    float hranges[2] = { 0,255 };
    const float* ranges[1] = { hranges };

    cv::Mat b_hist;
    cv::Mat g_hist;
    cv::Mat r_hist;

    /*
    Mat():mask
    Optional mask. If the matrix is not empty, it must be an 8-bit array of the same size as images[i] .
    The non-zero mask elements mark the array elements counted in the histogram.

    b_hist:Output histogram, which is a dense or sparse dims -dimensional array.

    1:behind of b_hist: Histogram dimensionality that must be positive and not greater than CV_MAX_DIMS (equal to 32 in the current OpenCV version).

    bins:histSize	Array of histogram sizes in each dimension.

    ranges:	Array of the dims arrays of the histogram bin boundaries in each dimension.
    */
    calcHist(&bgr_plane[0], 1, 0, cv::Mat(), b_hist, 1, bins, ranges);
    calcHist(&bgr_plane[1], 1, 0, cv::Mat(), g_hist, 1, bins, ranges);
    calcHist(&bgr_plane[2], 1, 0, cv::Mat(), r_hist, 1, bins, ranges);



    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double)hist_w / bins[0]);//length of each hist step:bin_w

    cv::Mat histImage = cv::Mat::zeros(hist_h, hist_w, CV_8UC3);

    /*
    0:norm value to normalize to or the lower range boundary in case of the range normalization.

    histImage.rows:upper range boundary in case of the range normalization

    -1:when negative, the output array has the same type as src
    */
    normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1);
    normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1);
    normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1);

    for (int i = 1; i < bins[0]; i++)
    {
        line(histImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))), cv::Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))), cv::Scalar(255, 0, 0));
        line(histImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))), cv::Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))), cv::Scalar(0, 255, 0));
        line(histImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))), cv::Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))), cv::Scalar(0, 0, 255));
    }



    imshow("b_hist", histImage);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void quickopenCV::Histogram_2d_demo(cv::Mat& image)
{
    cv::Mat hsv, hs_hist;
    cvtColor(image, hsv, cv::COLOR_BGR2HSV);

    int hbins = 30, sbins = 32;
    int hist_bins[] = { hbins ,sbins };

    float h_range[] = { 0,180 };
    float s_range[] = { 0,256 };

    const float* hs_ranges[] = { h_range ,s_range };

    int hs_channels[] = { 0,1 };

    /*
    * &hsv:input images
    *
    * 1:number of images
    *
    * hs_channels:List of the dims channels used to compute the histogram. The first array channels are numerated from 0 to images[0].channels()-1 ,
    the second array channels are counted from images[0].channels() to images[0].channels() + images[1].channels()-1, and so on.
    *
    Mat():mask
    Optional mask. If the matrix is not empty, it must be an 8-bit array of the same size as images[i] .
    The non-zero mask elements mark the array elements counted in the histogram.

    hs_hist:Output histogram, which is a dense or sparse dims -dimensional array.

    2: Histogram dimensionality that must be positive and not greater than CV_MAX_DIMS (equal to 32 in the current OpenCV version).

    hist_bins:Array of histogram sizes in each dimension.���������Ϸֵ�bins���������������ϸ��ֶ�����

    ranges:	Array of the dimensions arrays of the histogram bin boundaries in each dimension.
    */
    //we will get 2 chanenls :H&S here
    //hue's boundary is 0~180 and been divided into 30 steps with 5steplengths
    calcHist(&hsv, 1, hs_channels, cv::Mat(), hs_hist, 2, hist_bins, hs_ranges);

    double maxVal = 0;
    //find max value in hs_hist
    minMaxLoc(hs_hist, 0, &maxVal);

    int scale = 10;

    //S��saturation������ as row,H(hue)ɫ�� as col
    //every bin's width is 10
    cv::Mat hist2d_image = cv::Mat::zeros(sbins * scale, hbins * scale, CV_8UC3);

    for (int h = 0; h < hbins; h++)
    {
        for (int s = 0; s < sbins; s++)
        {
            float binVal = hs_hist.at<float>(h, s);
            int intensity = cvRound(binVal * 255 / maxVal);//normalize

            rectangle(hist2d_image, cv::Point(h * scale, s * scale),
                      cv::Point((h + 1) * scale - 1, (s + 1) * scale - 1),
                      cv::Scalar::all(intensity),
                      -1
                      );
        }
    }
    imshow("H-S Histogram", hist2d_image);

    cv::waitKey(0);

}

void quickopenCV::histogram_eq_demo(cv::Mat& image)
{
    cv::Mat gray;
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);


    cv::Mat dst;
    equalizeHist(gray, dst);//only support single channel
    imshow("output", dst);


    cv::waitKey(0);
}

void quickopenCV::blur_demo(cv::Mat& image)
{
    cv::Mat dst;

    blur(image, dst, cv::Size(3,3));

    imshow("output", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void quickopenCV::gaussian_blur_demo(cv::Mat& image)
{
    cv::Mat dst;

    GaussianBlur(image, dst, cv::Size(3, 3),15);

    imshow("output", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}


void quickopenCV::bilateral_blur_demo(cv::Mat& image)
{
    cv::Mat dst;

    bilateralFilter(image, dst,0,100,10);

    imshow("output", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}




void quickopenCV::camera_preparation()
{
    //cv::VideoCapture capture("/home/cx/Desktop/LocalWorkSpace/embedded-courses/untitled/1.mp4");
    capture=new cv::VideoCapture;
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    // open selected camera using selected API
    capture->open(deviceID, apiID);

    if (!capture->isOpened()) {
        std::cout << "ERROR! Unable to open camera\n";
        return ;
    }
    //capture.release();
}


char quickopenCV::picture_capture(std::string path)
{
    //cv::VideoCapture capture("/home/cx/Desktop/LocalWorkSpace/embedded-courses/untitled/1.mp4");
    char returnValue=0;
    cv::Mat frame;
    capture->read(frame);
    //frame = cv::imread("/home/cx/Desktop/LocalWorkSpace/embedded-courses/untitled/1.png");
    if (!frame.empty())
    {
        //cv::imwrite("/home/cx/Desktop/LocalWorkSpace/embedded-courses/untitled/RealtimeVideo.png",frame);

        std::string pb_file_path = "/home/cx/Desktop/LocalWorkSpace/embedded-courses/untitled/opencv_face_detector_uint8.pb";
        std::string pbtxt_file_path = "/home/cx/Desktop/LocalWorkSpace/embedded-courses/untitled/opencv_face_detector.pbtxt";


        cv::dnn::Net net = cv::dnn::readNetFromTensorflow(pb_file_path, pbtxt_file_path);

        cv::Mat blob = cv::dnn::blobFromImage(frame, 1.0, cv::Size(300, 300), cv::Scalar(104, 177, 123));
        net.setInput(blob);
        cv::Mat probs = net.forward();
        //1x1xNx7

        cv::Mat detectMat(probs.size[2], probs.size[3], CV_32F, probs.ptr<float>());
        for (int row = 0; row < detectMat.rows; row++)
        {
            float conf = detectMat.at<float>(row, 2);
            if (conf > 0.5)
            {
                float x1 = detectMat.at<float>(row, 3)*frame.cols;
                float y1 = detectMat.at<float>(row, 4) * frame.rows;
                float x2 = detectMat.at<float>(row, 5) * frame.cols;
                float y2 = detectMat.at<float>(row, 6) * frame.rows;

                cv::Rect box(x1, y1, x2 - x1, y2 - y1);
                cv::rectangle(frame, box, cv::Scalar(0, 0, 255), 2, 8);
                returnValue=(conf*100);
            }
        }

        cv::imwrite(path,frame);


    }
    //capture->release();
    if(returnValue>100)returnValue=100;
    return returnValue;
}

