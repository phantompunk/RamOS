/*
 * StateManager.h
 *
 *  Created on: Apr 21, 2016
 *      Author: rigo
 */

#ifndef STATE_STATEMANAGER_H_
#define STATE_STATEMANAGER_H_

#include <list>
#include "../Process/PCB.h"

class StateManager {
public:
	StateManager();
	std::list<PCB> new_state;		//
	std::list<PCB> ready_state;
	std::list<PCB> blocked_state;
	std::list<PCB> exit_state;
	PCB run_state;
	void null_to_new();
	void new_to_ready();
	void ready_to_run();
	void run_to_exit();
	void run_to_ready();
	void run_to_blocked();
	void blocked_to_ready();
	virtual ~StateManager();
};

#endif /* STATE_STATEMANAGER_H_ */
