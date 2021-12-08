#include "retriving.h"
#include <math>

state_machine::state_machine() : state(STATE_RESET), target(NULL)
{
}

void state_machine::run(Mat &desc,vector<KeyPoint> &kp)
{
	switch (state)
	{
	case STATE_RESET:
		int ret = reset_run();
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
		int ret = search_run(desc, kp);
		switch (ret)
		{
		case ERR_SUCC:
			state = STATE_MOVE;
			break;
		case ERR_FAIL:
			set_target(NULL);
			state = STATE_RESET;
			break;
		default:
			break;
		}
		break;
	case STATE_MOVE:
		int ret = move_run(desc, kp);
		switch (ret)
		{
		case ERR_SUCC if (target != &home) {
			set_target(&home);
			state = STATE_SEARCH;
		} else {
			set_target(NULL);
			state = STATE_RESET;
		} break;
		    case ERR_FAIL:
			state = STATE_SEARCH;
			break;
		default:
			break;
		}
	}
}
void state_machine::set_target(item &_target){
	target = _target;
}

//search the item in current capture
//Trun clock-wise if didn't find
//Return ERR_SUCC if target is in find, and stop all motor.
//Return ERR_FAIL if exceed time limit.
//Return ERR_NULL otherwise.

int state_machine::search_run(Mat &desc,vector<KeyPoint> &kp){
	Point pt;
	bool ret = target->item_match(desc,kp,pt);
	static int times = 0;
	if(ret == false){
		turnRight(200);
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
	Point pt;
	bool ret = target->item_match(desc,kp,pt);
	if(ret == false){
		return ERR_FAIL;
	}
	int diff = CAP_WIDTH - 2 * pt.x;
	if(abs(diff) < TOLERATE_RANGE){
		moveForward(FORWARD_SPEED);
	}
	else{
		if(diff > 0){
			turnRight(TURN_MIN_SPEED + diff);
		}
		else{
			turnLeft(TURN_MIN_SPEED - diff);
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
