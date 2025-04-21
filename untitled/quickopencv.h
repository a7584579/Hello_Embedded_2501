#ifndef QUICKOPENCV_H
#define QUICKOPENCV_H

//#pragma once

#include <cstring>
#include "opencv2/opencv.hpp"

class quickopenCV
{
public:
    explicit quickopenCV();
    ~quickopenCV()
    {

    }

    void colorSpace_Demo(cv::Mat& image);
    void mat_create_demo(cv::Mat& image);
    void pixel_access_demo(cv::Mat& image);
    void operator_demo(cv::Mat& image);

    void tracking_bar_demo(cv::Mat& image);
    void key_demo(cv::Mat& image);

    void color_style_demo(cv::Mat& image);

    void channel_demo(cv::Mat& image);

    void inrange_demo(cv::Mat& image);

    void pixel_statistic_demo(cv::Mat& image);

    void draw_demo(cv::Mat& image);

    void random_drawings(cv::Mat& image);

    void polyline_drawing_demo();

    void mouse_drawing_demo(cv::Mat& image);

    void norm_demo(cv::Mat& image);

    void resize_demo(cv::Mat& image);

    void flip_demo(cv::Mat& image);

    void rotate_demo(cv::Mat& image);

    void video_demo();

    void show_Histogram_demo(cv::Mat& image);//gistogram

    void Histogram_2d_demo(cv::Mat& image);//gistogram

    void histogram_eq_demo(cv::Mat& image);

    void blur_demo(cv::Mat& image);

    void gaussian_blur_demo(cv::Mat& image);

    void bilateral_blur_demo(cv::Mat& image);

    void camera_preparation();
    void picture_capture(std::string);
private :
    cv::VideoCapture *capture;
};




#endif // QUICKOPENCV_H
