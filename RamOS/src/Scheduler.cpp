/*
 * Scheduler.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: rigo
 */

#include "Scheduler.h"
//#include "State/StateManager.h"
#include <time.h>
#include <iostream>

int Scheduler::ram[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int Scheduler::clock_cycle = 0;
int Scheduler::run_clock = 0;
int Scheduler::TIMESLICE = 100;

Scheduler::Scheduler() {
//	time_t start = time(0);
//	m_start_time = start;
}
void Scheduler::admit() {
	PCB temp = sm.new_state.front();
	// Check how much memory is available
	if (temp.get_memory() <= get_ram()) {
	// Allocate memory if available and move to ready
		set_ram(temp.get_pid(),temp.get_memory());
		sm.new_to_ready();
	}
}
void Scheduler::dispatch() {
	// If the run state is free, move to run
	if (sm.get_run_state().get_pid() == 0) {
//		std::cout << "Run is Empty"<<std::endl;
		sm.ready_to_run();
//		// If cpu time pending equals 0 and ios pending is 0 move to exit
		if (sm.get_run_state().get_cpu_pending() == 0 &&
			sm.get_run_state().get_io_pending() == 0) {
			terminate();
			std::cout << "End" << std::endl;
		}
		else if (run_clock > TIMESLICE){
			std::cout << "Back to ready" <<std::endl;
			sm.run_to_ready();
			run_clock = 0;
		}
//		// Check for IO then IO ArrTm
//		// If ArrTm is equal to the clock cycle move to ready
		else if (sm.get_run_state().get_arrival() == clock_cycle) {
			std::cout << "Has " <<sm.get_run_state().get_io_pending()<<" IOs"<<std::endl;
		}
////		std::cout << "Run PID: "<<sm.run_state.get_pid()<<std::endl;
	}
	else {
		std::cout << "Run PID: "<<sm.run_state.get_pid()<<std::endl;
		// decrease the io operation count for every blocked element
		// increase
		run_clock++;
	}
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
Scheduler::~Scheduler() {
	// TODO Auto-generated destructor stub
}

