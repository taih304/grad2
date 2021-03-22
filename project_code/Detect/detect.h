#ifndef DETECT_H
#define DETECT_H

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <QTime>
#include <QThread>
#include <QPixmap>
#include <QDebug>


#define ID_CAMERA 1

class detect: public QThread
{
    Q_OBJECT
public:
    detect(QObject *parent = nullptr);
    QPixmap pixmap() const
    {
        return mPixmap;
    }
    std::vector<std::vector<double>> buffer;
    double ticks, precTick, dT = 0;
    bool found = false;
    int notFoundCount = 0;
signals:
    void newPixmapCaptured();
protected:
    void run() override;
private:
    cv::Point center;
    double theta;
    QTime m_time;
    QPixmap mPixmap;
    cv::Mat mFrame ;
    cv::UMat U_mFrame,U_mFrame_resize, blob;
    cv::VideoCapture mVideoCap;
    QImage cvMatToQImage(const cv::Mat &inMat);
    QPixmap cvMatToQPixmap(const cv::Mat &inMat);
};

#endif // DETECT_H

