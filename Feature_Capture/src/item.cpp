#include "item.h"
#include "surf.h"

view_feature::view_feature(){
	_d = 100;
	return;
}

view_feature::view_feature(ifstream &is){
	int temp;
	_d = 100;
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
	is.read((char *)&_pt,sizeof(Point));
	is.read((char *)&_d,sizeof(int));
	return;
}

void view_feature::set(vector<KeyPoint> kp,Mat desc,Point pt,int d){
	_kp = kp;
	_desc=desc;
	_pt = pt;
	_d = d;
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
	os.write((const char *)&_pt,sizeof(Point));
	os.write((const char *)&_d,sizeof(int));
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

bool view_feature::match_coord(Mat &desc,vector<KeyPoint> &kp,Point &pt,int &d){
	feature_algo ft;
	int d_temp=_d;
	Point pt_temp = _pt;
	if(ft.match_coord(_desc,desc,kp,_kp,_pt,_d)){
		d=_d;
		_d = d_temp;
		pt=_pt;
		_pt=pt_temp;
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
	
bool item::item_match(Mat &desc,vector<KeyPoint> &kp,Point &pos,int &d){
	for(int i=0;i<views.size();i++){
		if(views[i].match_coord(desc,kp,pos,d)){
			cout<<"Location: "<<pos<<" Radius: "<<d<<endl;
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
