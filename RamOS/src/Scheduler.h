/*
 * Scheduler.h
 *
 *  Created on: Apr 21, 2016
 *      Author: rigo
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

//#include <time.h>
#include "State/StateManager.h"

class Scheduler {
public:
	// Timeslice
	// process runtime
	Scheduler();
	StateManager sm;

	virtual ~Scheduler();

	const StateManager& getSm() const {
		return sm;
	}

	void setSm(const StateManager& sm) {
		this->sm = sm;
	}
};

#endif /* SCHEDULER_H_ */
