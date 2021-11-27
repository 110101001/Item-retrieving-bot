#ifndef __SURF_H_
#define __SURF_H_

#include "opencv.h"

using namespace cv;
using namespace std;
class feature_algo
{
	public:
	int detect_key_point(Mat &img, vector<KeyPoint> &kp, Mat &desc, Rect target);
	Point match_key_point(Mat &src, Mat &pattern);

	bool match_coord(Mat &src, Mat &pattern, vector<KeyPoint> &kp, Point &pt);
	void match_getKp(Mat &src, Mat &pattern, vector<KeyPoint> &kp_out, vector<KeyPoint> &kp);
};

#endif