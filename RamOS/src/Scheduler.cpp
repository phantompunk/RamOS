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
#include <string>
#include <iostream>
#include <sstream>
//#include <>

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
			std::cout << "#####Null to New#####"<<std::endl;
			sm.null_to_new();
			display();
		}
	}
}
void Scheduler::allocate() {
	if (!sm.get_new_state().empty()){
		PCB temp = sm.new_state.front();
		if (temp.get_memory() <= get_ram()) {
			std::cout<<"#####New to Ready#####"<<std::endl;
			set_ram(temp.get_pid(), temp.get_memory());
			sm.new_to_ready();
			display();
			display_ram();
		}
	}
}
void Scheduler::dispatch() {
	PCB temp;
	if (!sm.get_blocked_state().empty()) {
		// Check if any pcbs wait time is 0
		for (std::list<PCB>::iterator it = sm.blocked_state.begin();
				it != sm.blocked_state.end(); it++) {
			if ((*it).get_wait() <= 0){
				std::cout<<"#####Blocked to Ready#####"<<std::endl;
				release((*it));
				sm.blocked_state.erase(it);
//				it = sm.blocked_state.erase(it);
				display();
			}
		}
	}
	if (!sm.get_ready_state().empty()) {
		if (!sm.get_run_state().is_running()) {
			std::cout<<"#####Ready to Run#####"<<std::endl;
			sm.ready_to_run();
			display();
		}
		else {
			// Check for 3 condtions
			if (sm.get_run_state().get_cpu_pending() <= 0 &&
					sm.get_run_state().is_running()){
				std::cout<<"#####Terminated to Exit#####"<<std::endl;
				terminate();
				display();
			}
			else if (sm.get_run_state().get_arrival() == get_runtime()) {
				std::cout<<"#####Run to Blocked#####"<<std::endl;
				block();
				display();
			}
			else if (get_runtime() == TIMESLICE) {
				std::cout<<"#####Timeout#####"<<std::endl;
				timeout();
				display();
			}

		}
		consume();
	}
	else if (sm.get_ready_state().empty()) {
		// Check for 3 condtions
		if (sm.get_run_state().get_cpu_required() == sm.get_run_state().get_cpu_completed()){
			std::cout<<"#####Terminated to Exit#####"<<std::endl;
			std::cout<<"PID:"<<sm.get_run_state().get_pid()<<"\tRam:"<<sm.get_run_state().get_memory()<<std::endl;
			terminate();
			display_ram();
			display();
		}
		else if (sm.get_run_state().get_arrival() == get_runtime()) {
			std::cout<<"#####Run to Blocked#####"<<std::endl;
			block();
			display();
		}
		else if (get_runtime() == TIMESLICE) {
			std::cout<<"#####Timeout#####"<<std::endl;
			timeout();
//			addstr(display());
			display();
		}
		else {
			admit();
		}
		consume();
	}
}
void Scheduler::terminate() {
	PCB temp = sm.run_state;
	clear_ram(temp.get_pid());
	sm.run_to_exit();
	run_clock = 0;
}
void Scheduler::timeout() {
	// move pcb to either blocked or the end of ready depending on whether its using an IO
	PCB temp = sm.run_state;
	sm.run_to_ready();
//	clear_ram(temp.get_pid());
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
		std::cout << " " << ram[i];
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
void Scheduler::display() {
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<"ClockCycle:"<<get_clock()<<"\tTotal PCBs:60"<<"\tPCBs Finished:"<<sm.get_exit_state().size()<<std::endl;
	std::cout<<"Free Ram:"<<get_ram()<<"\tRam:";display_ram();std::cout<<""<<std::endl;
//	std::cout<<"Free Ram:"<<get_ram()<<"\tRam={"<<std::endl
//	std::cout<<"************************************************"<<std::endl;
//	std::cout<<"ClockCycle::"<<get_clock()<<"\tNew Size:"<<sm.new_state.size()<<"\tExit Size:"<<sm.exit_state.size()<<std::endl;
	std::cout << "Run State:"<<sm.run_state.get_state()<<"\tRun Clock:"<<run_clock<<std::endl;
//	if (sm.run_state.get_pid() != 0){
		std::cout<<"\tPID:"<<sm.get_run_state().get_pid()<<"\tCycles Left:"<<sm.get_run_state().get_cpu_pending();
		std::cout<<"\tCycles Done:"<<sm.get_run_state().get_cpu_completed()<<"\tIOs Left:"<<sm.get_run_state().get_io_pending();
		std::cout<<"\tRam:"<<sm.get_run_state().get_memory()<<std::endl;
		//		std::cout<<std::endl;
//	}
	std::cout<<"Ready State Size:"<<sm.get_ready_state().size();
	std::cout<<"\tAvailable Ram:"<<get_ram()<<std::endl;
//	if (!sm.get_ready_state().empty()) {
		iterate(sm.ready_state);
//	}
	std::cout<<"Blocked State Size:"<<sm.get_blocked_state().size()<<std::endl;
//	if (!sm.get_blocked_state().empty()) {
		iterate(sm.blocked_state);
//	}
//	std::cout<<"************************************************"<<std::endl;
	std::cout<<std::endl;
}
void Scheduler::iterate(std::list<PCB> state) {
	for (std::list<PCB>::iterator it = state.begin();
			it != state.end(); it++) {
		if ((*it).get_pid() == 0){
			std::cout << "Process RAM: " << (*it).get_memory()<<std::endl;
		}
		else {
			std::cout<<"\tPID:"<<(*it).get_pid()<<"\tCycles Left:"<<(*it).get_cpu_pending();
			std::cout<<"\tCycles Done:"<<(*it).get_cpu_completed()<<"\tIOs Left:"<<(*it).get_io_pending();
			std::cout<<"\tRam:"<<(*it).get_memory()<<"\tIO Wait:"<<(*it).get_wait()<<std::endl;
		}
	}
}
std::string Scheduler::ram_string() {
	std::string ram = "";
	std::ostringstream x;
	for (int i = 0; i < 16; i++) {
		std::cout<<ram[i]<<std::endl;
		x << ram[i] << ",";
	}
	ram = x.str();
	std::cout<<ram;
	return ram;
}
Scheduler::~Scheduler() {
	// TODO Auto-generated destructor stub
}

