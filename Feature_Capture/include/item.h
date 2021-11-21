#ifndef _ITEM_H_
#define _ITEM_H_

#include "opencv.h"

using namespace cv;
using namespace std;

typedef struct view_feature{
	vector<KeyPoint> kp;
	Mat desc;
	view_feature();
}view_feature;

class item{
	public:
	item();
	item(vector<view_feature> &f);
	
	int item_match(Mat &desc,Point &pos);

	private:	

};

#endif