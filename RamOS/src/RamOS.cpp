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

bool wait_complete(const int& value) {
	return (value==15);
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
	PCB pcb,pcb2,pcb3;

	pcb.set_id();
	pcb2.set_id();
	pcb3.set_id();

	pcb.set_cpu_arrival(2);
	pcb2.set_cpu_arrival(40);
	pcb2.set_cpu_arrival(85);

	pcb.set_cpu_required(200);
	pcb2.set_cpu_required(150);
	pcb3.set_cpu_required(255);

	pcb.set_io_required(2);
	pcb2.set_io_required(0);
	pcb3.set_io_required(3);

	pcb.set_io_arrival(15);
	pcb.set_io_arrival(25);
	pcb3.set_io_arrival(5);
	pcb3.set_io_arrival(25);
	pcb3.set_io_arrival(15);

	pcb.set_io_wait(0);
	pcb.set_io_wait(48);
	pcb2.set_io_wait(10);
	pcb3.set_io_wait(28);
	pcb3.set_io_wait(34);
	pcb3.set_io_wait(40);

	pcb.set_memory(4);
	pcb2.set_memory(6);
	pcb3.set_memory(8);

	cout << "PCB: " << pcb.get_pid()<<endl;
	cout << "PCB2: " << pcb2.get_pid()<<endl;
	cout << "PCB: " << pcb.get_cpu_arrival()<<endl;

	cout<<"PCB "<<pcb.get_cpu_pending()<<endl;
	sch.sm.run_state = pcb;
	sch.sm.run_state.consume_cpu();
	cout<<"PCB 1 "<<sch.sm.get_run_state().get_cpu_pending()<<endl;

	sch.sm.new_state.push_back(pcb);
	sch.sm.new_state.push_back(pcb2);
	sch.sm.new_state.push_back(pcb3);
	sch.sm.new_state.pop_front();

	iterate_state(sch.get_new_state());
	sch.sm.new_state.front().io.m_io_wait.remove_if(wait_complete);
	cout<<"Remove if IO wait is 0"<<endl;
	iterate_state(sch.get_new_state());







//
//	list<PCB> null;
//	sch.sm.null_state.push_back(pcb);
//	sch.sm.null_state.push_back(pcb2);
//	iterate_state(null);
//	while(sch.get_clock() < 1500) {
//		cout<<"Clock cylce: "<<sch.get_clock()<<endl;
//		cout<<"Ram: "<<sch.get_ram()<<endl;
//		cout<<"State: "<<sch.get_ready_state().empty()<<endl;
//		sch.admit();
//		sch.allocate();
//
////		sch.dispatch();
//		sch.increase_clock();
//	}
//	sch.sm.new_state.push_back(pcb);
//	sch.sm.new_state.push_back(pcb2);
//	iterate_state(sch.get_new_state());

//	while(!sch.get_new_state().empty()) {
//		sch.admit();
//		sch.increase_clock();
//	}


//	sch.admit();
//	sch.admit();
//	iterate_state(sch.get_ready_state());
//	cout << "Ram: " << sch.get_ram()<<endl;
//	sch.display_ram();
//	sch.dispatch();
//	sch.dispatch();
//	cout << "RUN PID: " << sch.get_run_state().get_pid()<<endl;
//	cout<<" RunTime: " << sch.get_runtime()<<endl;

}
