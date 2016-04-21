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
	std::list<PCB> new_state;
	virtual ~StateManager();
};

#endif /* STATE_STATEMANAGER_H_ */
