#include "item.h"
#include "surf.h"

view_feature::view_feature(){
	return;
}

void view_feature::set_view(vector<KeyPoint> kp,Mat desc){
	_kp = kp;
	_desc=desc;
}
void view_feature::clear_view(){
	_kp.clear();
}

bool view_feature::empty(){
	return _kp.empty();
}

void view_feature::match_draw(Mat &frame,Mat &desc,vector<KeyPoint> &kp){
	vector<KeyPoint> kp_out;
	match_getKp(_desc,desc,kp_out,kp);
	drawKeypoints(frame,kp_out,frame);
}

