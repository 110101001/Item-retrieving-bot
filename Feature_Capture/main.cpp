#include"opencv.h"
#include"surf.h"
#include"item.h"

#include<iostream>
#include<string>

using namespace std;
using namespace cv;

Mat display;

Point select_start;
Point select_end;

int pressed = 0;

Mat frame,gray_frame;
vector<view_feature> current;

int current_count = 0;

void Mouse_handler(int event,int x,int y,int flags,void *ustc){
    if(event==EVENT_LBUTTONDOWN){
        pressed=1;
        select_start=Point(x,y);
        select_end=Point(x,y);
    }
    else if(event==EVENT_MOUSEMOVE && (EVENT_FLAG_LBUTTON)){
        select_end=Point(x,y);
    }
    else if((event==EVENT_LBUTTONUP)&&(pressed==1)){
        pressed=0;
        select_end=Point(x,y);
        current.push_back(view_feature());
        detect_key_point(frame,current[current_count].kp,current[current_count].desc,Rect(select_start,select_end));
        select_end=Point(0,0);
        select_start=Point(0,0);
    }
}

int main(int argc, char **argv){
    int mode=0;
    VideoWriter writer;
  
    cout << "Opening camera..." << endl;
    VideoCapture capture(0); // open the first camera
    cout << "Setting camera..." << endl;
    capture.set(CAP_PROP_FRAME_WIDTH,640);
    capture.set(CAP_PROP_FRAME_HEIGHT,480);
    Mat mask,masked_frame;
    char c=0;
    if (!capture.isOpened())
    {
        cerr << "ERROR: Can't initialize camera capture" << endl;
        return 1;
    }
    namedWindow("Video");
    setMouseCallback("Video",Mouse_handler,0);
    capture>>frame;
    while(c!='q'){
        capture>>frame;
        frame.copyTo(display);
        cvtColor(frame,gray_frame,COLOR_BGR2GRAY);

        if(pressed) rectangle(display,select_start,select_end,Scalar(0,255,0),2);
        switch(c){
            case 's':
                break;
            case 'c':
                break;
        }
        
        imshow("Video",display);
        c=waitKey(20);
    }
    return 0;
}
