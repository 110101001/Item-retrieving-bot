#include "item.h"
#include "surf.h"
#include <fstream>

view_feature::view_feature(){
	return;
}

void view_feature::set(vector<KeyPoint> kp,Mat desc){
	_kp = kp;
	_desc=desc;
}
void view_feature::clear(){
	_kp.clear();
}

void view_feature::save(ofstream &os){
	int temp = _kp.size();
	os.write((const char *)&temp,sizeof(int));
	for(int i=0;i<_kp.size();i++){
		KeyPoint t = _kp[i];
		os.write((const char *)&t,sizeof(KeyPoint));
	}
	temp = _desc.type();
	os.write((const char *)(&temp),sizeof(int));
	os.write((const char *)(&_desc.rows), sizeof(int));
	os.write((const char *)(&_desc.cols), sizeof(int));
	os.write((const char *)(_desc.data), _desc.elemSize() * _desc.total());
	return;
}

bool view_feature::empty(){
	return _kp.empty();
}

void view_feature::match_draw(Mat &frame,Mat &desc,vector<KeyPoint> &kp){
	vector<KeyPoint> kp_out;
	match_getKp(_desc,desc,kp_out,kp);
	drawKeypoints(frame,kp_out,frame);
}

item::item(){
	return;
}

item::item(string name){
	_name = name;
	return;
}

item::item(vector<view_feature> &f){
	views = f;
	return;
}
	
//int item::item_match(Mat &desc,Point &pos);

int item::push_view(view_feature &view){
	views.push_back(view);
	return 0;
}

int item::save(){
	int temp;
	ofstream save;
	string file_name(_name);

	temp = views.size();

	file_name.append(".features");
  	save.open(file_name,ios::binary);
	save.write((const char *)&temp,sizeof(int));
	for(int i=0;i<views.size();i++){
		views[i].save(save);	
	}
	save.close();	
}
