#ifndef _ITEM_H_
#define _ITEM_H_

#include "opencv.h"
#include <fstream>

using namespace cv;
using namespace std;

class view_feature{
	public:
	view_feature();
	view_feature(ifstream &is);

	void set(vector<KeyPoint> kp,Mat desc,Point pt,int d);
	void clear();
	void save(ofstream &os);

	bool empty();

	void match_draw(Mat &frame,Mat &desc,vector<KeyPoint> &kp);
	bool match_coord(Mat &desc,vector<KeyPoint> &kp,Point &pt,int &d);
	private:
	Point _pt;
	vector<KeyPoint> _kp;
	Mat _desc;
	int _d;
};

class item{
	public:
	item();
	item(string name);
	item(string name, ifstream &is);
	item(vector<view_feature> &f);
	
	bool item_match(Mat &desc,vector<KeyPoint> &kp,Point &pos,int &d);

	int push_view(view_feature &view);
	int save();

	string _name;	

	private:	
	vector<view_feature> views;
};

#endif
