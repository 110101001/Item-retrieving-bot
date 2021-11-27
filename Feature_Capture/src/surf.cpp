#include "opencv.h"
#include <stdlib.h>
#include <vector>
#include "surf.h"
#include "item.h"
#define MIN_HESSIAN 400

using namespace cv;
using namespace std;
using namespace cv::xfeatures2d;

int detect_key_point(Mat &img,vector<KeyPoint> &kp,Mat &desc,Rect target){
	Ptr<SURF> detector = SURF::create(MIN_HESSIAN); 
	Mat mask=Mat_<bool>::zeros(img.size());
	Mat region=mask(target);
	region.setTo(true);
	detector->detectAndCompute(img,mask,kp,desc);
	return sizeof(kp);
}

void detect_base_desc(Mat &img,vector<KeyPoint> &kp, Mat &desc){
	Ptr<SURF> detector = SURF::create(MIN_HESSIAN); 
	Mat mask=Mat_<bool>::ones(img.size());
	detector->detectAndCompute(img,mask,kp,desc);
}

Point match_coord(Mat &src,Mat &pattern,vector<KeyPoint> &kp){
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

void match_getKp(Mat &src,Mat &pattern,vector<KeyPoint> &kp_out,vector<KeyPoint> &kp){
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
	vector< std::vector<DMatch> > knn_matches;
	vector<KeyPoint> good_matches;
    	matcher->knnMatch(src, pattern, knn_matches, 2);
	const float ratio_thresh = 0.7f;
	for (size_t i = 0; i < knn_matches.size(); i++)
	{
		if (knn_matches[i][0].distance < ratio_thresh * knn_matches[i][1].distance)
		{
			kp_out.push_back(kp[knn_matches[i][0].trainIdx]);
		}
	}
}

