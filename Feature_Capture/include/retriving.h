#ifndef _RETRIVING
#define _RETRIVING
#include "opencv.h"
#include "robot_control.h"
#include "item.h"
#include "surf.h"

#define TOLERATE_RANGE 60
#define MOVE_TIME 80
#define FAR_MOVE_TIME 150
#define TURN_TIME 45
#define RUSH_TIME 800
#define SEARCH_TURN_TIME 80
#define CLOSE_DIAMETER 130
#define HOME_DIAMETER 200
#define FAR_DIAMETER 100
#define CLOSE_COUNT 3
#define MOVE_MAX_FAIL 3

enum robot_state{
	STATE_RESET,STATE_SEARCH,STATE_MOVE
};

enum error{
	ERR_NULL, ERR_FAIL,ERR_SUCC
};

class state_machine{
	public:
	state_machine();

	void set_target(item *_target);

	void run(Mat &desc,vector<KeyPoint> &kp);
	int search_run(Mat &desc,vector<KeyPoint> &kp);
	int move_run(Mat &desc,vector<KeyPoint> &kp);
	int reset_run();

	private:
	feature_algo ft;
	int state;
	item *target;
};

#endif
