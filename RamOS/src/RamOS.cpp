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
#include <fstream>
#include <iostream>
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
	pcb.set_io_required(4);
	cout << "Process 1 pid: " << pcb.get_pid()<<endl;
	cout << "Process 1 IO: " << pcb.get_io_required()<<endl;
//	cout << "Process 1 time: " << pcb.info.get_time()<<endl;

	cout << "Process 2 pid: " << pcb2.get_pid()<<endl;
//	cout << "Process 2 time: " << pcb2.info.get_time()<<endl;

	cout << "Process 3 pid: " << pcb3.get_pid()<<endl;
};
void test_state_manager() {
	cout << "Staring StateManager Test"<<endl;
	PCB pcb,pcb1,pcb2;
	StateManager sm;

//	sm.new_state.push_front(pcb);
//	sm.new_state.push_back(pcb2);
//	sm.new_state.push_front(pcb1);

//	cout << "The new state list contains: " << sm.new_state.size() << " elements" << endl;
//	iterate_state(sm.new_state);
};
void test_scheduler() {
	Scheduler sch;
	// Initialize a queue of
	PCB pcb[5];

	for (int i=0; i < 5; i++)
		sch.sm.new_state.push_back(pcb[i]);

	cout << "Initial PCBs in new state: " << sch.get_new_state().size()<<endl;
	iterate_state(sch.get_new_state());

	// Move the first PCB from the new state and add it to the ready state
//	it = sm.new_state.begin();
//	sm.new_state.splice(it, sm.ready_state);
//	sm.ready_state.splice(sm.ready_state.begin(), sm.new_state, it);

//	sch.sm.new_to_ready();
//	sch.dispatch();
//	sch.dispatch();
//	sch.sm.new_to_ready();

//	cout << "PCBs in new state" <<endl;
//	iterate_state(sch.get_new_state());
//
//	cout << "PCBs in ready state" <<endl;
//	iterate_state(sch.get_ready_state());
//
//	cout << "Process state is: " << sch.get_ready_state().front().get_state()<<endl;
//	sch.dispatch();
//	cout << "Run state: " << sch.get_run_state().get_state()<<endl;
//	sch.terminate();
//	cout << "Runtime: " << sch.get_runtime()<<endl;
//	iterate_state(sch.get_exit_state());


//	cout << sch.get_ram()<<endl;
	sch.admit();
	sch.admit();
	sch.admit();
	cout << "Ready State"<<endl;
	iterate_state(sch.get_ready_state());
	sch.dispatch();
	cout << "Run State"<<endl;
	cout << sch.get_run_state().get_pid()<<endl;
	sch.terminate();
	cout << sch.get_run_state().get_pid()<<endl;
};

int main() {
	// OS startup
	// Run process generator
	// Read from input file
		// Create an array
	// Begin creating processes and loading them in new state
	// Allocate memory for the 1st process and move to ready state
	// Scheduler decides which process to run, moves process to run state
	// Dispatcher decides when to move pcbs to exit, blocked, or ready
		// Move pcb to ready if there is enough memory for it
		// Move process to run
			// Execute process until a timeslice ends, IO occurs, or ends
				// Move process accordingly

	Scheduler sch;
	PCB pcb = PCB(1, 8, 1);
	PCB pcb2 = PCB(450, 2, 2);
	cout << "PCB: " << pcb.get_pid()<<endl;
	sch.sm.new_state.push_back(pcb);
	sch.admit();
	cout << "Ram: " << sch.get_ram()<<endl;
//	sch.display_ram();
	sch.dispatch();
	sch.dispatch();
	cout << "RUN PID: " << sch.get_run_state().get_pid()<<endl;
	cout<<" RunTime: " << sch.get_runtime()<<endl;
//	iterate_state(sch.get_exit_state());
}
