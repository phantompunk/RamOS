/*
 * Scheduler.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: rigo
 */

#include "Scheduler.h"
//#include "State/StateManager.h"
#include <time.h>
#include <list>
#include <iostream>

int Scheduler::ram[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int Scheduler::clock_cycle = 0;
int Scheduler::run_clock = 0;
int Scheduler::TIMESLICE = 100;

Scheduler::Scheduler() {
}
void Scheduler::admit() {
	if (!sm.get_null_state().empty()) {
		PCB temp = sm.null_state.front();
		if (temp.get_cpu_arrival() == clock_cycle) {
			std::cout << "Process Arrived Clock:"<<clock_cycle<<std::endl;
			sm.null_to_new();
		}
	}
}
void Scheduler::allocate() {
	if (!sm.get_new_state().empty()){
		PCB temp = sm.new_state.front();
		if (temp.get_memory() <= get_ram()) {
			std::cout<<"Allocated Mem - "<<"Used Ram: "<<get_ram()<<std::endl;
			set_ram(temp.get_pid(), temp.get_memory());
			sm.new_to_ready();
			display_ram();
		}
	}
////	std::cout<<"Arrive Time "<<temp.get_arrival()<<std::endl;
////	if (temp.info.m_cpu_arrival == run_clock) {
//		// Check how much memory is available
//		std::cout<<"Process Arrived"<<std::endl;
//		if (temp.get_memory() <= get_ram()) {
//		// Allocate memory if available and move to ready
//			set_ram(temp.get_pid(),temp.get_memory());
//			sm.new_to_ready();
//		}
//	}
}
void Scheduler::dispatch() {
	PCB temp;
	if (!sm.get_blocked_state().empty()) {
		// Check if any pcbs wait time is 0
		for (std::list<PCB>::iterator it = sm.blocked_state.begin();
			 it != sm.blocked_state.end(); it++) {
			if ((*it).get_wait() <= 0){
				std::cout<<"Blocked to Ready"<<std::endl;
				release((*it));
				it = sm.blocked_state.erase(it);
			}
		}
	}
	if (!sm.get_ready_state().empty()) {
		if (!sm.get_run_state().is_running()) {
			std::cout<<"Moved to run - clock: "<<get_clock()<<std::endl;
			sm.ready_to_run();
		}
		else {
			// Check for 3 condtions
			if (sm.get_run_state().get_cpu_pending() == 0 &&
				sm.get_run_state().is_running()){
				std::cout<<"Terminated - clock: "<<get_clock()<<std::endl;
				terminate();
			}
			else if (sm.get_run_state().get_arrival() == get_runtime()) {
				std::cout<<"Blocked - clock: "<<get_clock()<<std::endl;
				block();
			}
			else if (get_runtime() == TIMESLICE) {
				std::cout<<"Timeout - clock: "<<get_clock()<<std::endl;
				timeout();
			}

		}
		consume();
	}
	else if (sm.get_ready_state().empty()) {
		// Check for 3 condtions
		if (sm.get_run_state().get_cpu_pending() == 0 &&
			sm.get_run_state().is_running()){
			std::cout<<"Terminated - clock: "<<get_clock()<<std::endl;
			terminate();
		}
		else if (sm.get_run_state().get_arrival() == get_runtime()) {
			std::cout<<"Blocked - clock: "<<get_clock()<<std::endl;
			block();
		}
		else if (get_runtime() == TIMESLICE) {
			std::cout<<"Timeout - clock: "<<get_clock()<<std::endl;
			timeout();
		}
		consume();
	}



































		// While not empty
//	if (!sm.get_ready_state().empty()) {
//			// A process is running
//		if (sm.get_run_state().get_pid() != 0) {
//			temp = sm.get_run_state();
//			std::cout<<"PID: "<<sm.get_run_state().get_pid()<<" is running"<<std::endl;
//			// Check cpu pending
//			// Check for IO arrival
//			// Increase runtime
//			if (temp.get_cpu_pending() == 0) {
//				terminate();
//				consume();
//			}
//			else if (temp.get_arrival() == run_clock) {
//				block();
//				consume();
//			}
//			else if (run_clock <= TIMESLICE){
//				timeout();
//				consume();
//			}
//			else {
//				consume();
//				// Increase run clock
//				// decrease io wait if applicable
//			}
//
//		}
//		else {
//			sm.ready_to_run();
//			consume();
//			// Check cpu pending
//			// Check for IO arrival
//			// Increase runtime
//		}
//	}
//	else if (sm.get_run_state().get_pid() != 0) {
//		if (sm.get_run_state().get_pid() != 0) {
//			temp = sm.get_run_state();
//			std::cout<<"PID: "<<sm.get_run_state().get_pid()<<" is running"<<std::endl;
//			// Check cpu pending
//			// Check for IO arrival
//			// Increase runtime
//			if (temp.get_cpu_pending() == 0) {
//				terminate();
//			}
//			else if (temp.get_arrival() == run_clock) {
//				block();
//			}
//			else if (run_clock <= TIMESLICE){
//				timeout();
//			}
//			else {
//				// Increase run clock
//				// decrease io wait if applicable
//			}
//
//		}
//		else {
//			sm.ready_to_run();
//			// Check cpu pending
//			// Check for IO arrival
//			// Increase runtime
//		}
//	}
//	else {
//		std::cout<<"Ready is empty"<<std::endl;
//		// Ready is empty. There might still be a process in run or blocked
//		// Continue increamenting
//	}








	// If the run state is free, move to run
//	if (sm.get_run_state().get_pid() == 0) {
////		std::cout << "Run is Empty"<<std::endl;
//		sm.ready_to_run();
////		// If cpu time pending equals 0 and ios pending is 0 move to exit
//		if (sm.get_run_state().get_cpu_pending() == 0 &&
//			sm.get_run_state().get_io_pending() == 0) {
//			terminate();
//			std::cout << "End" << std::endl;
//		}
//		else if (run_clock > TIMESLICE){
//			std::cout << "Back to ready" <<std::endl;
//			sm.run_to_ready();
//			run_clock = 0;
//		}
////		// Check for IO then IO ArrTm
////		// If ArrTm is equal to the clock cycle move to ready
//		else if (sm.get_run_state().get_arrival() == run_clock) {
//			std::cout << "Has " <<sm.get_run_state().get_io_pending()<<" IOs"<<std::endl;
//		}
//////		std::cout << "Run PID: "<<sm.run_state.get_pid()<<std::endl;
//	}
//	else {
//		std::cout << "Run PID: "<<sm.run_state.get_pid()<<std::endl;
//		// decrease the io operation count for every blocked element
//		// increase
//		run_clock++;
//	}
//	PCB temp = sm.ready_state.front();
//	sm.ready_state
	// Check if an IO is requested -> send to blocked
//	if (temp.get_io_pending() > 0)
		// decrement on clock cycle
	// Check if CPU time = 0 -> send to exit
//	if (temp.get_cpu_pending = 0)
		// decrement on clock cycle
	// Check if timeslice is up -> send to ready
//	if (clock_cycle == TIMESLICE)
		// move to ready

//	start = clock();
//	sm.ready_to_run();
}
void Scheduler::terminate() {
	PCB temp = sm.run_state;
	clear_ram(temp.get_pid());
	sm.run_to_exit();
	run_clock = 0;
}
void Scheduler::timeout() {
	// move pcb to either blocked or the end of ready depending on whether its using an IO
	sm.run_to_ready();
	run_clock = 0;
}
void Scheduler::block() {
	sm.run_to_blocked();
	run_clock = 0;
}
void Scheduler::release(PCB pcb) {
	pcb.io.m_io_pending--;
	pcb.io.m_io_completed++;
	pcb.io.m_io_arrival.pop_front();
	pcb.io.m_io_wait.pop_front();
	sm.blocked_to_ready(pcb);
}
void Scheduler::consume() {
	if (sm.get_run_state().get_pid() != 0) {
		sm.run_state.consume_cpu();
		run_clock++;
	}
	if (!sm.get_blocked_state().empty()) {
		for (std::list<PCB>::iterator it = sm.blocked_state.begin();
			 it != sm.blocked_state.end(); it++) {
			(*it).consume_io();
		}
	}
//	if (sm.get_run_state().get_pid() != 0 &&
//		sm.get_blocked_state().front().get_pid() != 0) {
//		sm.run_state.consume_cpu();
//		for (std::list<PCB>::iterator it = sm.blocked_state.begin();
//			 it != sm.blocked_state.end(); it++) {
//			(*it).consume_io();
//		}
//	}
//	else if ((sm.get_run_state().get_pid() != 0 &&
//		sm.get_blocked_state().front().get_pid() != 0)) {
//
//
//	}
}
void Scheduler::increase_clock() {
	clock_cycle++;
}
void Scheduler::set_ram(int id,int mem) {
	for (int i = 0; i < 16; i++) {
		if (ram[i] == 0 && mem > 0) {
			ram[i] = id;
			mem--;
		}
	}
}
void Scheduler::clear_ram(int id) {
	for (int i = 0; i < 16; i++) {
		if (ram[i] == id)
			ram[i] = 0;
	}
}
void Scheduler::display_ram() {
	for (int i = 0; i < 16; i++) {
		std::cout << "Ram " << i+1 << ": " << ram[i] <<std::endl;
	}
}
StateManager Scheduler::get_state_manager() {
	return sm;
}
std::list<PCB> Scheduler::get_null_state() {
	return sm.null_state;
}
std::list<PCB> Scheduler::get_new_state() {
	return sm.new_state;
}
std::list<PCB> Scheduler::get_ready_state() {
	return sm.ready_state;
}
std::list<PCB> Scheduler::get_blocked_state() {
	return sm.blocked_state;
}
std::list<PCB> Scheduler::get_exit_state() {
	return sm.exit_state;
}
PCB Scheduler::get_run_state() {
	return sm.run_state;
}
double Scheduler::get_runtime() {
//	return (stop-start)/double(CLOCKS_PER_SEC)*1000;
	return run_clock;
}
int Scheduler::get_ram() {
	int free_mem = 0;
	for (int i = 0; i < 16; i++) {
		if (ram[i] == 0)
			free_mem++;
	}
	return free_mem;
}
int Scheduler::get_clock() {
	return clock_cycle;
}
Scheduler::~Scheduler() {
	// TODO Auto-generated destructor stub
}

