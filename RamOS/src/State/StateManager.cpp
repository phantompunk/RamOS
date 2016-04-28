/*
 * StateManager.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: rigo
 */

#include "StateManager.h"

StateManager::StateManager() {
	// TODO Auto-generated constructor stub

}
std::list<PCB> StateManager::get_new_state() {
	return new_state;
}
std::list<PCB> StateManager::get_ready_state() {
	return ready_state;
}
std::list<PCB> StateManager::get_blocked_state() {
	return blocked_state;
}
std::list<PCB> StateManager::get_exit_state() {
	return exit_state;
}
PCB StateManager::get_run_state() {
	return run_state;
}
//PCB StateManager::get_running() {
////	return running;
//}
void StateManager::clear_run() {
	run_state.set_id(0);
	run_state.set_cpu_required(0);
	run_state.set_memory(0);
}
void StateManager::new_to_ready() {
	PCB temp = new_state.front();
	temp.set_to_ready();
	new_state.pop_front();
	ready_state.push_back(temp);
}
void StateManager::ready_to_run() {
	// Allocate memory + some more stuff
	PCB temp = ready_state.front();
	temp.set_to_run();
	ready_state.pop_front();
	run_state = temp;
}
//void StateManager::ready_to_running() {
//	PCB temp = ready_state.front();
//	temp.set_to_run();
//	ready_state.pop_front();
////	running.
//}
void StateManager::run_to_blocked() {
	PCB temp = run_state;
	temp.set_to_blocked();
	blocked_state.push_back(temp);
//	temp.~PCB();
}
void StateManager::run_to_exit() {
	PCB temp = run_state;
	temp.set_to_exit();
	exit_state.push_front(temp);
	clear_run();
}
void StateManager::run_to_ready() {
	PCB temp = run_state;
	temp.set_to_ready();
	ready_state.push_back(temp);
}
void StateManager::blocked_to_ready(){
	PCB temp = blocked_state.front();
	temp.set_to_ready();
	ready_state.push_back(temp);
}
StateManager::~StateManager() {
	// TODO Auto-generated destructor stub
}
