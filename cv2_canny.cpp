#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<string>
/*Basic Functions*/
using namespace std;
using namespace cv;

 int main() {

    string path = "C:/Users/Admin/Desktop/opencv/soyo.png";
    Mat img =imread(path);//mat:matrix矩阵，用以储存图像，是一种数据类型
    Mat imgGray,imgblur,imgCanny,imgDil,imgErode;//存储灰度图像
    cvtColor(img,imgGray,COLOR_BGR2GRAY);//颜色提取
    GaussianBlur(img,imgblur,Size(3,3),5,0);//高斯模糊：自变量，因变量，模糊程度，模糊位置(x,y)
    Canny(imgblur,imgCanny,50,150);//边缘检测：使用模糊处理后的图像，因变量，a，b，用以设置a-b之间的阈值，低阈值边缘更多，高阈值更少边缘

    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));//生成一个用于膨胀的核,参数只能为奇数
    dilate(imgCanny,imgDil,kernel);//使边缘检测线条变粗
    erode(imgDil,imgErode,kernel);//使边缘检测线条变细

    imshow("Image",img);//给img命名
/*     imshow("Image gray",imgGray);
    imshow("Image blur",imgblur); */
    imshow("image Canny",imgCanny);
    imshow("image Dilation",imgDil);
    imshow("image erode",imgErode);
    waitKey(0);//让图像展示时间延长至无限期（0）

return 0;
}