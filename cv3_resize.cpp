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
    Mat imgResize,imgCrop;
    cout<<img.size()<<endl;//宽度788*高度665
    resize(img,imgResize,Size(),0.5,0.5);

    Rect roi(100,120,600,250);
    imgCrop = img(roi);

    imshow("image",img);
    imshow("image resize",imgResize);
    imshow("image crop",imgCrop);
    waitKey(0);//让图像展示时间延长至无限期（0）

return 0;
}