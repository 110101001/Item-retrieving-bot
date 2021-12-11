#include"opencv.h"
#include"surf.h"
#include"item.h"
#include"robot_control.h"
#include"retriving.h"

#include<iostream>
#include<fstream>
#include<string>
#include<csignal>
#include<unistd.h>

using namespace std;
using namespace cv;

Mat frame,gray_frame;

void int_handler(int signum){
	robotStop();
	exit(0);
}

int main(int argc, char **argv){
    string name,file_name;
    VideoWriter writer;
    ifstream is;
    feature_algo ft;
    state_machine fsm;
    int fail_count;
    char c = 0;

    signal(2,int_handler);
    cout << "Input item name" <<endl;
    cin>>name;
    file_name = name;
	file_name.append(".features");
    is.open(file_name);
    item cur_item(name,is);

    cout << "Initialize Motor..." <<endl;
    initRobot();
    cout << "Opening camera..." << endl;
    VideoCapture capture(0); // open the first camera
    cout << "Setting camera..." << endl;
    capture.set(CAP_PROP_FRAME_WIDTH,CAP_WIDTH);
    capture.set(CAP_PROP_FRAME_HEIGHT,CAP_HEIGHT);
    capture.set(CAP_PROP_BUFFERSIZE, 1);
    capture.set(CAP_PROP_FPS, 2);
    capture.set(CAP_PROP_POS_FRAMES , 1);
    if (!capture.isOpened())
    {
        cerr << "ERROR: Can't initialize camera capture" << endl;
        return 1;
    }
    capture>>frame;
    fsm.set_target(&cur_item);
    cout<<"Target set"<<endl;
    while(c!='q'){
        Point pt;
        vector<KeyPoint> glo_kp;
        Mat glo_desc;
        capture>>frame;
        cvtColor(frame,frame,COLOR_BGR2GRAY);
        ft.detect_key_point(frame,glo_kp,glo_desc,Rect(Point(0,0),Point(CAP_WIDTH-1,CAP_HEIGHT-1)));
	fsm.run(glo_desc,glo_kp);	
        c=waitKey(100);
    }
    robotStop();
    return 0;
}
