#ifndef _RETRIVING
#define _RETRIVING
#include "opencv.h"
#include "robot_control.h"

#define TOLERATE_RANGE 50
#define FORWARD_SPEED 200
#define TURN_MIN_SPEED 50
#define CLOSE_DIAMETER 100

enum state{
	STATE_RESET,STATE_SEARCH,STATE_MOVE
};

enum error{
	ERR_NULL, ERR_FAIL,ERR_SUCC
};

class state_machine{
	public:
	state_machine();

	void set_target(item &_target);

	void run(Mat &desc,vector<KeyPoint> &kp);
	int search_run(Mat &desc,vector<KeyPoint> &kp);
	int move_run(Mat &desc,vector<KeyPoint> &kp);
	int reset_run();

	private:
	feature_algo ft;
	enum state;
	item *target;
};

#endif
