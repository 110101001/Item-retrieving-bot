#ifndef __SURF_H_
#define __SURF_H_

#include "opencv.h"

using namespace cv;
using namespace std;

int detect_key_point(Mat &img,vector<KeyPoint> &kp,Mat &desc,Rect target);

Point match_key_point(Mat &src,Mat &pattern);
void match_getKp(Mat &src,Mat &pattern,vector<KeyPoint> &kp_out,vector<KeyPoint> &kp);

#endif