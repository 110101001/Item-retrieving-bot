#include "opencv.h"
#include <stdlib.h>
#include <vector>
#include "surf.h"
#define MIN_HESSIAN 400

using namespace cv;
using namespace std;

int detect_key_point(Mat &img,vector<KeyPoint> &kp,Mat &desc,Rect target){
	Ptr<SiftFeatureDetector> detector = SiftFeatureDetector::create(); 
	Mat mask=Mat_<bool>::zeros(img.size());
	Mat region=mask(target);
	region.setTo(true);
	detector->detectAndCompute(img,mask,kp,desc);
	return sizeof(kp);
}

void detect_base_desc(Mat &img,vector<KeyPoint> &kp, Mat &desc){
	Ptr<SiftFeatureDetector> detector = SiftFeatureDetector::create(); 
	Mat mask=Mat_<bool>::ones(img.size());
	detector->detectAndCompute(img,mask,kp,desc);
}

Point match_key_point(Mat &src,Mat &pattern){
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
	vector< std::vector<DMatch> > knn_matches;
	vector<DMatch> good_matches;
    	matcher->knnMatch(src, pattern, knn_matches, 2);
	const float ratio_thresh = 0.7f;
	for (size_t i = 0; i < knn_matches.size(); i++)
	{
		if (knn_matches[i][0].distance < ratio_thresh * knn_matches[i][1].distance)
		{
		good_matches.push_back(knn_matches[i][0]);
		}
	}
	return Point(0,0);
}

void display_match(Mat &src, Mat &out, Mat){

}