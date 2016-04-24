//============================================================================
// Name        : RamOS.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include "Scheduler.h"
#include "time.h"
#include <ctime>
//#include <chrono>
//#include "State/StateManager.h"
//#include "Process/PCB.h"
//#include "FileReader.h"
//#include "Info.h"
using namespace std;

void iterate_state(list<PCB> state) {
	for (list<PCB>::iterator it = state.begin();
			 it != state.end(); it++) {
			cout << "Process ID: " << (*it).get_pid() << endl;
		}
}
void test_pcb() {
	cout << "Starting PCB Test"<<endl;

	int id;
	PCB pcb,pcb2,pcb3;
	cout << "Process 1 pid: " << pcb.get_pid()<<endl;
	cout << "Process 1 time: " << pcb.info.get_time()<<endl;

	cout << "Process 2 pid: " << pcb2.get_pid()<<endl;
	cout << "Process 2 time: " << pcb2.info.get_time()<<endl;

	cout << "Process 3 pid: " << pcb3.get_pid()<<endl;
};
void test_state_manager() {
	cout << "Staring StateManager Test"<<endl;
	PCB pcb,pcb1,pcb2;
	StateManager sm;

	sm.new_state.push_front(pcb);
	sm.new_state.push_back(pcb2);
	sm.new_state.push_front(pcb1);

	cout << "The new state list contains: " << sm.new_state.size() << " elements" << endl;
	iterate_state(sm.new_state);
};
void test_scheduler() {
	// simulate a queue of PCBs with some info them
	Scheduler sch;
	PCB pcb[5];

	for (int i=0; i < 5; i++)
		sch.sm.new_state.push_back(pcb[i]);

	cout << "Initial PCBs in new state: " << sch.sm.new_state.size()<<endl;
	iterate_state(sch.sm.new_state);

	// Move the first PCB from the new state and add it to the ready state
//	it = sm.new_state.begin();
//	sm.new_state.splice(it, sm.ready_state);
//	sm.ready_state.splice(sm.ready_state.begin(), sm.new_state, it);

	sch.sm.new_to_ready();
	sch.sm.new_to_ready();

	cout << "PCBs in new state" <<endl;
	iterate_state(sch.sm.new_state);

	cout << "PCBs in ready state" <<endl;
	iterate_state(sch.sm.ready_state);

	cout << "Process state is: " << sch.sm.ready_state.front().get_state()<<endl;

};

int main() {
	clock_t start,stop;
	start = clock();

	// OS startup
	// Run process generator
	// Read from input file
		// Create an array
	// Begin creating processes and loading them in new state
	// Allocate memory for the 1st process and move to ready state
	// Scheduler decides which process to run, moves process to run state
	// Move process to either blocked or exit state


	test_scheduler();
//	test_pcb();
//	test_state_manager();





	stop = clock();
	cout << "Runtime: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;

	return 0;
}
