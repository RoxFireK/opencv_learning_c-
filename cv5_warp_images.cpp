#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace cv;
//将图像扭曲成正面(从任意四边形区域变换为矩形区域)透视，如此简单（）
float w = 200,h = 280;//定义长宽
Mat matrix,imgWarp;//定义矩阵，矫正图片
int main() {

    string path = "C:/Users/Admin/Desktop/opencv/pkx.jpg";
    Mat img =imread(path);//mat:matrix矩阵，用以储存图像，是一种数据类型

    //注意src和dst必须按照相同的端点顺序排列
    Point2f src[4] = {{417,105},{639,336},{53,494},{293,634}};//原图像（斜）的端点位置
    Point2f dst[4] = {{0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};//想要生成图像（正）的端点位置（w，h需提前定义）

    matrix = getPerspectiveTransform(src,dst);//通过两组对应的四个点求解出8个参数
    warpPerspective(img,imgWarp,matrix,Point(w,h));//应用透视变换到整个图像

    for(int i = 0;i<4;i++){
        circle(img,src[i],10,Scalar(0,0,255),FILLED);
    }//生成圆点判断原图片端点选择是否正确


    imshow("Image",img);//给img命名
    imshow("Image Warp",imgWarp);
    waitKey(0);//让图像展示时间延长至无限期（0）放在最后防止圆圈出现在截图里

return 0;
}