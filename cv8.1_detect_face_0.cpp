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

    VideoCapture cap(0);//此处为摄像头的id
    Mat img;

    while(1){

        cap .read(img);

        CascadeClassifier faceCascade;

        faceCascade.load("C:/Users/Admin/Desktop/opencv/resources/Resources/haarcascade_frontalface_default.xml");

        vector<Rect> faces;
        faceCascade.detectMultiScale(img,faces,1.1,10);//尺度因子，最小邻居数

        for(int i = 0;i<faces.size();i++){
            rectangle(img,faces[i].tl(),faces[i].br(),Scalar(0,255,0),5);
        }

        imshow("image",img);
        waitKey(1);//形成动态图像
    }
return 0;
}


    
