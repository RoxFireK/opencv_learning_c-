#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<string>

using namespace std;
using namespace cv;
////图像
// int main() {

//     string path = "C:/Users/Admin/Desktop/opencv/soyo.png";
//     Mat img =imread(path);//mat:matrix矩阵，用以储存图像，是一种数据类型
//     imshow("Image",img);//给img命名
//     waitKey(0);//让图像展示时间延长至无限期（0）

// return 0;
// }
//视频
// int main() {
//     string path = "C:/Users/Admin/Desktop/opencv/call.mp4";
//     VideoCapture cap(path);
//     Mat img;

//     while(1){

//         cap .read(img);

//         imshow("image",img);
//         waitKey(20);//让图像展示时间延长至无限期（0）
//     }
// return 0;
// }
////摄像头
int main() {

    VideoCapture cap(0);//此处为摄像头的id
    Mat img;

    while(1){

        cap .read(img);

        imshow("image",img);
        waitKey(1);//让图像展示时间延长至无限期（0）
    }
return 0;
}