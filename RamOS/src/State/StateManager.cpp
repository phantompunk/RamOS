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
std::list<PCB> StateManager::get_null_state() {
	return null_state;
}
std::list<PCB> StateManager::get_new_state() {
	return new_state;
}
std::list<PCB> StateManager::get_ready_state() {
	return ready_state;
}
std::list<PCB> StateManager::get_runn_state() {

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
	run_state.clear_id();
	run_state.set_cpu_required(0);
	run_state.set_cpu_completed(0);
	run_state.set_cpu_pending(0);
	run_state.io.m_io_arrival.clear();
	run_state.io.m_io_wait.clear();
	run_state.set_memory(0);
	run_state.set_to_null();
	run_state.m_running = false;
}
void StateManager::null_to_new() {
	PCB temp = null_state.front();
	temp.set_to_new();
	temp.set_id();
	new_state.push_back(temp);
	null_state.pop_front();
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
	clear_run();
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
	clear_run();
}
void StateManager::blocked_to_ready(PCB pcb){
	PCB temp = pcb;
	temp.set_to_ready();
	ready_state.push_back(temp);
}
bool StateManager::is_running() {
	return run_state.m_running;
}
StateManager::~StateManager() {
	// TODO Auto-generated destructor stub
}
