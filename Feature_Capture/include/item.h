#ifndef _ITEM_H_
#define _ITEM_H_

#include "opencv.h"

using namespace cv;
using namespace std;

class view_feature{
	public:
	view_feature();

	void set(vector<KeyPoint> kp,Mat desc);
	void clear();
	void save(ofstream &os);

	bool empty();

	void match_draw(Mat &frame,Mat &desc,vector<KeyPoint> &kp);
	private:
	vector<KeyPoint> _kp;
	Mat _desc;
};

class item{
	public:
	item();
	item(string name);
	item(vector<view_feature> &f);
	
	int item_match(Mat &desc,Point &pos);

	int push_view(view_feature &view);
	int save();

	string _name;	
	
	private:	
	vector<view_feature> views;
};

#endif