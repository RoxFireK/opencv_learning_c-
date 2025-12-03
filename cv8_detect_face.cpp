#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
using namespace cv;

int main() {

    string path = "C:/Users/Admin/Desktop/opencv/face.png";
    Mat img =imread(path);//mat:matrix矩阵，用以储存图像，是一种数据类型

    CascadeClassifier faceCascade;
    faceCascade.load("C:/Users/Admin/Desktop/opencv/resources/Resources/haarcascade_frontalface_default.xml");

    if(faceCascade.empty()){
        cout<<"not loaded"<<endl;
    }

    vector<Rect> faces;
    faceCascade.detectMultiScale(img,faces,1.1,10);//尺度因子，最小邻居数

    for(int i = 0;i<faces.size();i++){
        rectangle(img,faces[i].tl(),faces[i].br(),Scalar(0,255,0),5);
    }

    imshow("Image",img);//给img命名
    waitKey(0);//让图像展示时间延长至无限期（0）

return 0;
}