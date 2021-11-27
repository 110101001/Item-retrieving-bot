#include"opencv.h"
#include"surf.h"
#include"item.h"

#include<iostream>
#include<string>

using namespace std;
using namespace cv;

#define CAP_WIDTH 640
#define CAP_HEIGHT 480

Mat display;

Point select_start;
Point select_end;

int pressed = 0;

Mat frame,gray_frame;

view_feature cur_view;

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
        vector<KeyPoint> cur_view_kp;
        Mat cur_view_desc;
        pressed = 0;
        select_end=Point(x,y);
        detect_key_point(frame,cur_view_kp,cur_view_desc,Rect(select_start,select_end));
        cur_view.set_view(cur_view_kp,cur_view_desc);
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
    capture.set(CAP_PROP_FRAME_WIDTH,CAP_WIDTH);
    capture.set(CAP_PROP_FRAME_HEIGHT,CAP_HEIGHT);
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
        vector<KeyPoint> glo_kp;
        Mat glo_desc;
        capture>>frame;
        frame.copyTo(display);
        cvtColor(frame,frame,COLOR_BGR2GRAY);
        detect_key_point(frame,glo_kp,glo_desc,Rect(Point(0,0),Point(CAP_WIDTH-1,CAP_HEIGHT-1)));

        if(pressed) rectangle(display,select_start,select_end,Scalar(0,255,0),2);

        if(!cur_view.empty()){
            cur_view.match_draw(display,glo_desc,glo_kp);
        }
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
