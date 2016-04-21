/*
 * StateManager.h
 *
 *  Created on: Apr 20, 2016
 *      Author: rigo
 */

#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_

#include <list>
#include "../Process/PCB.h"

class StateManager {
//private:
//	std::list<PCB> m_new_state;
//	std::list<PCB> m_ready_state;
//	std::list<PCB> m_running_state;
//	std::list<PCB> m_blocked_state;
//	std::list<PCB> m_exit_state;
public:
	StateManager();
	std::list<PCB> m_new_state;
//	std::list<PCB> m_ready_state;
//	std::list<PCB> m_running_state;
//	std::list<PCB> m_blocked_state;
//	std::list<PCB> m_exit_state;
	virtual ~StateManager();

	const std::list<PCB>& getNewState() const {
		return m_new_state;
	}

	void setNewState(const std::list<PCB>& newState) {
		m_new_state = newState;
	}
};

#endif /* STATEMANAGER_H_ */
