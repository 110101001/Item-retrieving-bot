#include "item.h"
#include "surf.h"

view_feature::view_feature(){
	return;
}

view_feature::view_feature(ifstream &is){
	int temp;
	is.read((char *)&temp,sizeof(int));
	for(int i=0;i<temp;i++){
		KeyPoint t;
		is.read((char *)&t,sizeof(KeyPoint));
		_kp.push_back(t);
	}
	int type, row, col;
	is.read((char *)(&type), sizeof(int));
	is.read((char *)(&row), sizeof(int));
	is.read((char *)(&col), sizeof(int));

	_desc.create(row,col,type);
	is.read((char *)(_desc.data), _desc.elemSize() * _desc.total());
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
    	feature_algo ft;
	ft.match_getKp(_desc,desc,kp_out,kp);
	drawKeypoints(frame,kp_out,frame);
}

bool view_feature::match_coord(Mat &desc,vector<KeyPoint> &kp,Point &pt){
	feature_algo ft;
	if(ft.match_coord(_desc,desc,kp,pt)){
		return true;
	}
	return false;
}

item::item(){
	return;
}

item::item(string name):_name(name){
	return;
}

item::item(string name, ifstream &is):_name(name){
	int temp;
	is.read((char *)&temp,sizeof(int));
	for(int i=0;i<temp;i++){
		views.push_back(view_feature(is));
	}
}
item::item(vector<view_feature> &f){
	views = f;
	return;
}
	
bool item::item_match(Mat &desc,vector<KeyPoint> &kp,Point &pos){
	for(int i=0;i<views.size();i++){
		if(views[i].match_coord(desc,kp,pos)){
			return true;
		}
	}
	return false;
}

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
