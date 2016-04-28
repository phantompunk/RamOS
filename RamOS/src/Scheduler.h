/*
 * Scheduler.h
 *
 *  Created on: Apr 21, 2016
 *      Author: rigo
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

//#include <time.h>
#include <list>
//#include <array>

#include "State/StateManager.h"
#include "Dispatcher.h"

class Scheduler {
	static int clock_cycle;
	static int TIMESLICE;
	static int run_clock;
public:
	// Timeslice are ineffect
	// process runtime
	// start stop clock()
	clock_t start,stop;
	static int ram[];
	Scheduler();
	Dispatcher dispatcher;
	StateManager sm;
	void admit();		// Move element to ready if there is enough memory
	void dispatch();	// Move first element from ready to run
	void terminate();	// Move element from run to exit
	void timeout();		// Move element from run to back of ready queue
	void block();		// Move element from run to blocked
	void release();		// Move element from block to back of ready
	void set_ram(int id, int mem);		// Allocate process memory
	void display_ram();
	StateManager get_state_manager();
	std::list<PCB> get_new_state();		// Return new state list
	std::list<PCB> get_ready_state();	// Return ready state list
	std::list<PCB> get_blocked_state();	// Return blocked state list
	std::list<PCB> get_exit_state();	// Return exit state list
	PCB get_run_state();				// Return run state pcb
	double get_runtime();
	int get_ram();			// Return current amount of free ram
	virtual ~Scheduler();

	const StateManager& getSm() const {
		return sm;
	}

	void setSm(const StateManager& sm) {
		this->sm = sm;
	}
};

#endif /* SCHEDULER_H_ */
