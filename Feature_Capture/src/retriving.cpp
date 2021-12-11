#include "retriving.h"
#include <math.h>

item home;

state_machine::state_machine() : state(STATE_RESET), target(NULL)
{
}

void state_machine::run(Mat &desc,vector<KeyPoint> &kp)
{
	int ret;
	switch (state)
	{
		case STATE_RESET:
			ret = reset_run();
			switch (ret)
			{
				case ERR_SUCC:
					state = STATE_SEARCH;
					break;
				default:
					break;
			}
			break;
		case STATE_SEARCH:
			ret = search_run(desc, kp);
			cout<<"Searching"<<endl;
			switch (ret)
			{
				case ERR_SUCC:
					cout<<"Found"<<endl;
					state = STATE_MOVE;
					break;
				case ERR_FAIL:
					cout<<"Search Failed"<<endl;
					set_target(NULL);
					state = STATE_RESET;
					break;
				default:
					break;
			}
			break;
		case STATE_MOVE:
			ret = move_run(desc, kp);
			cout<<"Moving"<<endl;
			switch (ret)
			{
				case ERR_SUCC:
					cout<<"Arrived"<<endl;
					if (target != &home) {
						set_target(&home);
						state = STATE_SEARCH;
					} else {
						set_target(NULL);
						state = STATE_RESET;
					} break;
				case ERR_FAIL:
					cout<<"Lost capture"<<endl;
					state = STATE_SEARCH;
					break;
				default:
					break;
			}
	}
}
void state_machine::set_target(item *_target){
	target = _target;
}

//search the item in current capture
//Trun clock-wise if didn't find
//Return ERR_SUCC if target is in find, and stop all motor.
//Return ERR_FAIL if exceed time limit.
//Return ERR_NULL otherwise.

int state_machine::search_run(Mat &desc,vector<KeyPoint> &kp){
	Point pt;
	int d;
	bool ret = target->item_match(desc,kp,pt,d);
	static int times = 0;
	if(ret == false){
		turnRight(TURN_MIN_SPEED);
		times++;
		if(times>100){
			times = 0;
			return ERR_FAIL;
		}
		return ERR_NULL;
	}else{
		times = 0;
		robotStop();
		return ERR_SUCC;
	}
}

//Turn to target if not facing the target
//Move to target if facing the target
//Return ERR_SUCC if target is close enough
//Return ERR_FAIL if lose track of target
//Return ERR_NULL otherwise.
int state_machine::move_run(Mat &desc,vector<KeyPoint> &kp){
	int dis;
	Point pt;
	bool ret = target->item_match(desc,kp,pt,dis);
	static int close_count = 0;
	if(ret == false){
		return ERR_FAIL;
	}
	if(dis > CLOSE_DIAMETER){
		robotStop();
		if(close_count >= CLOSE_COUNT){
			close_count = 0;
			return ERR_SUCC;
		}
		close_count++;
	}
	close_count=0;
	int diff = CAP_WIDTH - 2 * pt.x;
	if(abs(diff) < TOLERATE_RANGE){
		cout<<"Move forward"<<endl;
		moveForward(FORWARD_SPEED);
	}
	else{
		cout<<"Turn"<<endl;
		if(diff > 0){
			turnLeft(TURN_MIN_SPEED);
		}
		else{
			turnRight(TURN_MIN_SPEED);
		}
	}
	return ERR_NULL;
}

//Return ERR_SUCC if target is not NULL
//Return ERR_NULL otherwise.
int state_machine::reset_run()
{
	return target != NULL ? ERR_SUCC: ERR_NULL;
}
