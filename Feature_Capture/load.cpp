#include"opencv.h"
#include"surf.h"
#include"item.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;
using namespace cv;

#define CAP_WIDTH 640
#define CAP_HEIGHT 480

Mat display;

Point select_start;
Point select_end;

Mat frame,gray_frame;

int main(int argc, char **argv){
    string name,file_name;
    VideoWriter writer;
    ifstream is;
    feature_algo ft;
    char c = 0;

    cout << "Input item name" <<endl;
    cin>>name;
    file_name = name;
	file_name.append(".features");
    is.open(file_name);
    item cur_item(name,is);

    cout << "Opening camera..." << endl;
    VideoCapture capture(0); // open the first camera
    cout << "Setting camera..." << endl;
    capture.set(CAP_PROP_FRAME_WIDTH,CAP_WIDTH);
    capture.set(CAP_PROP_FRAME_HEIGHT,CAP_HEIGHT);
    if (!capture.isOpened())
    {
        cerr << "ERROR: Can't initialize camera capture" << endl;
        return 1;
    }
    namedWindow("Video");
    capture>>frame;
    while(c!='q'){
        Point pt;
        vector<KeyPoint> glo_kp;
        Mat glo_desc;
        capture>>frame;
        frame.copyTo(display);
        cvtColor(frame,frame,COLOR_BGR2GRAY);
        ft.detect_key_point(frame,glo_kp,glo_desc,Rect(Point(0,0),Point(CAP_WIDTH-1,CAP_HEIGHT-1)));
        if(cur_item.item_match(glo_desc,glo_kp,pt)){
            cout<<pt<<endl;
            circle(display,pt,10,Scalar(0,255,0),2);
        }
        imshow("Video",display);
        c=waitKey(20);
    }
    return 0;
}
