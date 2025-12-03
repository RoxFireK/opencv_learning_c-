#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
using namespace cv;

void getContours(Mat imgDil,Mat img){

    vector<vector<Point>> contours;//二维数组
    vector<Vec4i> hierarchy;//内置数组，数组元素包含四个point,表示层次结构

    findContours(imgDil,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);//SIMPLE更节省内存
    //drawContours(img,contours,-1,Scalar(255,0,255),2);

    //遍历访问
    for (int i = 0;i<contours.size();i++){
        double area = contourArea(contours[i]);//定义面积
        cout<<area<<endl;
        vector<vector<Point>> conPoly(contours.size());//定义多边形点集数组（二维）
        vector<Rect> boundRect(contours.size());//定义数组储存矩阵（一维）(内置长宽函数)
        string objectType;

        if(area>1000){
            float peri = arcLength(contours[i],true);//生成周长
            approxPolyDP(contours[i],conPoly[i],0.02*peri,true);//根据周长将复杂曲线分布转化为更简单的多边形
            
            cout<<conPoly[i].size()<<endl;;
            boundRect[i] = boundingRect(conPoly[i]);//获取简化多边形的最小外接矩形
            
            int objCor = (int)conPoly[i].size();

            if(objCor == 3) {objectType="Tri";}
            if(objCor == 4) {
                float aspRatio = (float)boundRect[i].width/(float)boundRect[i].height;
                if (aspRatio>0.95&&aspRatio<1.05){
                    objectType = "Square";
                }
                else{
                    objectType = "Rect";
                }            }
            if(objCor > 4) {objectType="Circle";}
            
            rectangle(img,boundRect[i].tl(),boundRect[i].br(),Scalar(0,255,0),5);//注意此处要控制矩形边缘厚度
            putText(img,objectType,{boundRect[i].x,boundRect[i].y - 5},FONT_HERSHEY_PLAIN,2,Scalar(0,69,255),2);           
            drawContours(img,conPoly,i,Scalar(255,0,255),1);//设置阈值，面积大于1000能够输出,注意此处输出的是contour的第i个

        }
    }
}

int main() {

    string path = "C:/Users/Admin/Desktop/opencv/shapes.jpg";
    Mat img =imread(path);//mat:matrix矩阵，用以储存图像，是一种数据类型
    Mat imgGray,imgblur,imgCanny,imgDil;

    //Preprocessing
    cvtColor(img,imgGray,COLOR_BGR2GRAY);//颜色提取
    GaussianBlur(imgGray,imgblur,Size(3,3),5,0);//高斯模糊：自变量，因变量，模糊程度，模糊位置(x,y)
    Canny(imgblur,imgCanny,50,150);

    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));//生成一个用于膨胀的核,参数只能为奇数
    dilate(imgCanny,imgDil,kernel);//对形状线条进行加粗

    getContours(imgDil,img);//调用函数生成矩形

    imshow("Image",img);//给img命名
    /*imshow("Image G",imgGray);
    imshow("Image B",imgblur);
    imshow("Image C",imgCanny);
    imshow("Image D",imgDil);*/

    waitKey(0);//让图像展示时间延长至无限期（0）

return 0;
}