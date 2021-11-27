#ifndef _ITEM_H_
#define _ITEM_H_

#include "opencv.h"

using namespace cv;
using namespace std;

class view_feature{
	public:
	view_feature();

	void set_view(vector<KeyPoint> kp,Mat desc);
	void clear_view();

	bool empty();

	void match_draw(Mat &frame,Mat &desc,vector<KeyPoint> &kp);
	private:
	vector<KeyPoint> _kp;
	Mat _desc;
};

class item{
	public:
	item();
	item(vector<view_feature> &f);
	
	int item_match(Mat &desc,Point &pos);

	private:	

};

#endif