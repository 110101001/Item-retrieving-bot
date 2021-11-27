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
Mat frame,gray_frame;

int main(int argc, char **argv){
    string name;
    VideoWriter writer;

    cout << "Input item name" <<endl;
    cin>>name;
    item cur_item(name);

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

    return 0;
}
