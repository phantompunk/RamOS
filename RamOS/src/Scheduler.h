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
#include <string>
//#include <array>

#include "State/StateManager.h"

class Scheduler {
	static int clock_cycle;
	static int TIMESLICE;
	static int run_clock;
public:
	static int ram[];
	Scheduler();
	StateManager sm;
	void admit();		// Add PCB to new when it arrives
	void allocate();	// Move element to ready if there is enough memory
	void dispatch();	// Move first element from ready to run
	void terminate();	// Move element from run to exit
	void timeout();		// Move element from run to back of ready queue
	void block();		// Move element from run to blocked
	void release(PCB pcb);		// Move element from block to back of ready
	void consume();		// Modify values: cpu time,runtime,io wait time
	void set_ram(int id, int mem);		// Allocate process memory
	void clear_ram(int id);				// Deallocate process memory
	void increase_clock();				// Increment clock cycle
	void display_ram();					// Iterate through Ram array
	void display();						// Displays state info
	StateManager get_state_manager();	// Return instance
	std::list<PCB> get_null_state();	// Return container for all incoming PCBs
	std::list<PCB> get_new_state();		// Return new state list
	std::list<PCB> get_ready_state();	// Return ready state list
	std::list<PCB> get_blocked_state();	// Return blocked state list
	std::list<PCB> get_exit_state();	// Return exit state list
	PCB get_run_state();				// Return run state pcb
	int get_runtime();				// Return clock cycles spent in run state
	int get_ram();			// Return current amount of free ram
	int get_clock();		// Return current clock cycle
	std::string ram_string();
	void iterate(std::list<PCB> x);
	virtual ~Scheduler();

	const StateManager& getSm() const {
		return sm;
	}

	void setSm(const StateManager& sm) {
		this->sm = sm;
	}
};

#endif /* SCHEDULER_H_ */
