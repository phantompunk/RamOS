/*
 * StateManager.h
 *
 *  Created on: Apr 21, 2016
 *      Author: rigo
 */

#ifndef STATE_STATEMANAGER_H_
#define STATE_STATEMANAGER_H_

#include <list>
//#include <array>
#include "../Process/PCB.h"

class StateManager {
private:
//	std::list<PCB> new_state;
//	size_t run_state_size(1);
	const static int run_size = 1;
public:
	StateManager();
	std::list<PCB> null_state;		// List of all incoming PCBs
	std::list<PCB> new_state;		// List of objects in new state
	std::list<PCB> ready_state;		// List of objects in ready state
	std::list<PCB> blocked_state;	// List of objects in blocked state
	std::list<PCB> exit_state;		// List of objects in exit state
	PCB run_state;					// Object in run state
//	PCB running[run_size];

	std::list<PCB> get_null_state();	// Return null state list
	std::list<PCB> get_new_state(); 	// Return new state list
	std::list<PCB> get_ready_state();	// Return ready state list
	std::list<PCB> get_blocked_state();	// Return blocked state list
	std::list<PCB> get_exit_state();	// Return exit state list
	PCB get_run_state();				// Return run state
//	PCB get_running();
	void clear_run();		// Set PCB in run state to an empty object
	void null_to_new();		// Move first pcb from null to back of new
	void new_to_ready();	// Move first pcb from new to back of ready
	void ready_to_run();	// Move first pcb from ready to run state
//	void ready_to_running();
	void run_to_exit();		// Move pcb from run to back of exit state
	void run_to_ready();	// Move pcb from run to back of ready
	void run_to_blocked();	// Move pcb from run to back of blocked
	void blocked_to_ready();// Move first pcb from blocked to back of ready
	virtual ~StateManager();

	const std::list<PCB>& getBlockedState() const {
		return blocked_state;
	}

	const std::list<PCB>& getExitState() const {
		return exit_state;
	}

	const std::list<PCB>& getNewState() const {
		return new_state;
	}

	const std::list<PCB>& getReadyState() const {
		return ready_state;
	}

	const PCB& getRunState() const {
		return run_state;
	}
};

#endif /* STATE_STATEMANAGER_H_ */
