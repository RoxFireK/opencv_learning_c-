#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<string>
/*Basic Functions*/
using namespace std;
using namespace cv;

 int main() {

    //blank image
    Mat img(512,512,CV_8UC3,Scalar(255,255,255));//创建一个画布，宽，高，


    circle(img,Point(256,256),155,Scalar(0,69,255),FILLED);//在哪个图像生成，原点位置，大小，颜色,厚度

    rectangle(img,Point(130,226),Point(382,286),Scalar(255,255,255),FILLED);//生成矩形，在哪个图像生成，左上点，右下点，颜色，粗细

    line(img,Point(130,296),Point(382,296),Scalar(255,255,255),2);//生成线段，起点，终点，其他同上

    putText(img,"Parking Limited!",Point(155,262),FONT_HERSHEY_DUPLEX,0.75,Scalar(0,69,255),2);//在哪个图像生成，内容，生成起始点，字体，字体大小，颜色，线条粗细


    imshow("image",img);
    waitKey(0);//让图像展示时间延长至无限期（0）

return 0;
}