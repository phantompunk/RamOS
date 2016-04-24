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
void StateManager::new_to_ready() {
	PCB temp = new_state.front();
	temp.set_to_ready();
	new_state.pop_front();
	ready_state.push_back(temp);
//	temp.~PCB();
}
void StateManager::ready_to_run() {
	// Allocate memory + some more stuff

}
void StateManager::run_to_blocked() {
	PCB temp = run_state;
	blocked_state.push_back(temp);
//	temp.~PCB();
}
void StateManager::run_to_exit() {
	PCB temp = run_state;
	exit_state.push_front(temp);
//	temp.~PCB();
}
void StateManager::run_to_ready() {

}
void StateManager::blocked_to_ready(){

}
StateManager::~StateManager() {
	// TODO Auto-generated destructor stub
}
