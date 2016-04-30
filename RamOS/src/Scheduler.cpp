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
	PCB temp = sm.null_state.front();
	if (temp.get_cpu_arrival() == clock_cycle) {
		std::cout << "Process Arrived"<<std::endl;
		sm.null_to_new();
	}
}
void Scheduler::allocate() {
	if (!sm.get_new_state().empty()){
		PCB temp = sm.new_state.front();
		std::cout<<"Arrive time"<<std::endl;
		if (temp.get_memory() <= get_ram()) {
			std::cout<<"Allocate Mem"<<std::endl;
			set_ram(temp.get_pid(), temp.get_memory());
			sm.new_to_ready();
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
	PCB temp; // TODO - ids are created when added to new state
		// While not empty
	if (!sm.get_ready_state().empty()) {
			// A process is running
		if (sm.get_run_state().get_pid() != 0) {
			temp = sm.get_run_state();
			std::cout<<"PID: "<<sm.get_run_state().get_pid()<<" is running"<<std::endl;
			// Check cpu pending
			// Check for IO arrival
			// Increase runtime
			if (temp.get_cpu_pending() == 0) {
				terminate();
			}
			else if (temp.get_arrival() == run_clock) {
				block();
			}
			else if (run_clock <= TIMESLICE){
				timeout();
			}
			else {
				consume();
				// Increase run clock
				// decrease io wait if applicable
			}

		}
		else {
			sm.ready_to_run();
			// Check cpu pending
			// Check for IO arrival
			// Increase runtime
		}
	}
	else if (sm.get_run_state().get_pid() != 0) {
		if (sm.get_run_state().get_pid() != 0) {
			temp = sm.get_run_state();
			std::cout<<"PID: "<<sm.get_run_state().get_pid()<<" is running"<<std::endl;
			// Check cpu pending
			// Check for IO arrival
			// Increase runtime
			if (temp.get_cpu_pending() == 0) {
				terminate();
			}
			else if (temp.get_arrival() == run_clock) {
				block();
			}
			else if (run_clock <= TIMESLICE){
				timeout();
			}
			else {
				// Increase run clock
				// decrease io wait if applicable
			}

		}
		else {
			sm.ready_to_run();
			// Check cpu pending
			// Check for IO arrival
			// Increase runtime
		}
	}
	else {
		std::cout<<"Ready is empty"<<std::endl;
		// Ready is empty. There might still be a process in run or blocked
		// Continue increamenting
	}








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
	sm.run_to_exit();
	stop = clock();
}
void Scheduler::timeout() {
	// move pcb to either blocked or the end of ready depending on whether its using an IO
	sm.run_to_ready();
	stop = clock();
}
void Scheduler::block() {
	sm.run_to_ready();
}
void Scheduler::release() {
	sm.blocked_to_ready();
}
void Scheduler::consume() {
	if (sm.get_run_state().get_pid() != 0) {
		sm.run_state.consume_cpu();
	}
	if (sm.get_blocked_state().front().get_pid() != 0) {
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
	run_clock++;
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

