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
#include "ProcessGenerator.h"
#include "InputReader.h"
#include <string>
#include <sstream>
#include <fstream>
#include <ncurses.h>
//#include <chrono>
//#include "State/StateManager.h"
//#include "Process/PCB.h"
//#include "FileReader.h"
//#include "Info.h"
using namespace std;

static void iterate_state(list<PCB> state) {
	for (list<PCB>::iterator it = state.begin();
			it != state.end(); it++) {
		if ((*it).get_pid() == 0)
			cout << "Process RAM: " << (*it).get_memory()<<endl;
		else
			cout << "Process ID: " << (*it).get_pid() << endl;
	}
};
void init_pcb() {
	PCB pcb,pcb2,pcb3,pcb4,pcb5;

	pcb.set_id();
	pcb2.set_id();
	pcb3.set_id();

	pcb.set_cpu_arrival(0);
	pcb2.set_cpu_arrival(3);
	pcb3.set_cpu_arrival(6);
	pcb4.set_cpu_arrival(8);
	pcb5.set_cpu_arrival(12);

	pcb.set_cpu_required(5);
	pcb2.set_cpu_required(6);
	pcb3.set_cpu_required(4);
	pcb4.set_cpu_required(3);
	pcb5.set_cpu_required(15);

	pcb.set_io_required(2);
	pcb2.set_io_required(0);
	pcb3.set_io_required(3);
	pcb4.set_io_required(5);
	pcb5.set_io_required(3);

	pcb.set_io_arrival(1);
	pcb.set_io_arrival(3);
	pcb3.set_io_arrival(1);
	pcb3.set_io_arrival(3);
	pcb3.set_io_arrival(2);
	pcb4.set_io_arrival(4);
	pcb4.set_io_arrival(2);
	pcb4.set_io_arrival(5);
	pcb4.set_io_arrival(4);
	pcb4.set_io_arrival(3);
	pcb5.set_io_arrival(2);
	pcb5.set_io_arrival(4);
	pcb5.set_io_arrival(5);

	pcb.set_io_wait(5);
	pcb.set_io_wait(1);
	pcb3.set_io_wait(2);
	pcb3.set_io_wait(4);
	pcb3.set_io_wait(2);
	pcb4.set_io_wait(2);
	pcb4.set_io_wait(3);
	pcb4.set_io_wait(4);
	pcb4.set_io_wait(2);
	pcb4.set_io_wait(2);
	pcb5.set_io_wait(4);
	pcb5.set_io_wait(3);
	pcb5.set_io_wait(1);

	pcb.set_memory(4);
	pcb2.set_memory(6);
	pcb3.set_memory(8);
	pcb4.set_memory(12);
	pcb5.set_memory(6);

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
//
//	initscr();
//	raw();
//	printw("Hello");
//	getch();
//	endwin();

	//
//	srand(time(0));
	// START OF File Generator
	ProcessGenerator pgen;
	srand(time(0));
	ofstream fs;
	fs.open("GeneratedFile.txt");
	int cpu_r;
	int cpu_a = 0;
	int mem;
	int io_r;
	int ar;
	int wt;
	ostringstream x;
	string temp;
	//	cout<<(rand()%16 + 1)<<endl;
	for(int i=0;i<5;i++) {
		//		srand(time(0);
		pgen.ioArrivalTime_list.clear();
		pgen.waitTime_list.clear();
		temp = "";
		x.str("");
		x.clear();
		cpu_r = pgen.random_runtime();
		cpu_a = pgen.processArrivalTime(cpu_a);
		mem = pgen.random_processMemory();
		io_r = pgen.random_io();
		pgen.io_at(cpu_r, io_r);
		pgen.io_wt(io_r);
		//		cout<<"CPU_R:"<<cpu_r<<endl;
		//		cout<<"CPU_A:"<<cpu_a<<endl;
		//		cout<<"MEM:"<<mem<<endl;
		//		cout<<"IO:"<<io_r<<endl;
		while(!pgen.ioArrivalTime_list.empty()) {
			ar = pgen.ioArrivalTime_list.front();
			wt = pgen.waitTime_list.front();
			pgen.ioArrivalTime_list.pop_front();
			pgen.waitTime_list.pop_front();
			x << " "<< ar << " "<< wt;

			temp = x.str();
		}
		//		cout << temp<<endl;
		fs << cpu_r << " " << cpu_a << " " << mem;
		fs << " " << io_r << " " << temp <<endl;
	}
	//END OF GEN
	//


	//	pgen.io_at(100,5);
	//	for (list<int>::iterator it = pgen.ioArrivalTime_list.begin();
	//		 it != pgen.ioArrivalTime_list.end(); it++) {
	//		cout << (*it)<<endl;
	//	}
	//	pgen.io_at(100,5);
	//	for (list<int>::iterator it = pgen.IO_list.begin();
	//		 it !=pgen.IO_list.end();it++){
	//		cout<<(*it)<<endl;
	//	}

	//INIT READER
	InputReader reader;
	reader.parseInput("");

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
	//	while (!reader.nullList.empty()) {
	//		sch.sm.null_state.merge(reader.nullList);
	//	}

	//USE THIS FOR READER
	for (list<PCB>::iterator it = reader.nullList.begin();
			it != reader.nullList.end(); it++) {
		sch.sm.null_state.push_back((*it));
	}

//	//TEST DATA FOR SCH
//	PCB pcb,pcb2,pcb3,pcb4,pcb5;
//
//	pcb.set_id();
//	pcb2.set_id();
//	pcb3.set_id();
//
//	pcb.set_cpu_arrival(0);
//	pcb2.set_cpu_arrival(3);
//	pcb3.set_cpu_arrival(6);
//	pcb4.set_cpu_arrival(8);
//	pcb5.set_cpu_arrival(12);
//
//	pcb.set_cpu_required(5);
//	pcb2.set_cpu_required(6);
//	pcb3.set_cpu_required(4);
//	pcb4.set_cpu_required(3);
//	pcb5.set_cpu_required(15);
//
//	pcb.set_io_required(2);
//	pcb2.set_io_required(0);
//	pcb3.set_io_required(3);
//	pcb4.set_io_required(5);
//	pcb5.set_io_required(3);
//
//	pcb.set_io_arrival(1);
//	pcb.set_io_arrival(3);
//	pcb3.set_io_arrival(1);
//	pcb3.set_io_arrival(3);
//	pcb3.set_io_arrival(2);
//	pcb4.set_io_arrival(4);
//	pcb4.set_io_arrival(2);
//	pcb4.set_io_arrival(5);
//	pcb4.set_io_arrival(4);
//	pcb4.set_io_arrival(3);
//	pcb5.set_io_arrival(2);
//	pcb5.set_io_arrival(4);
//	pcb5.set_io_arrival(5);
//
//	pcb.set_io_wait(5);
//	pcb.set_io_wait(1);
//	pcb3.set_io_wait(2);
//	pcb3.set_io_wait(4);
//	pcb3.set_io_wait(2);
//	pcb4.set_io_wait(2);
//	pcb4.set_io_wait(3);
//	pcb4.set_io_wait(4);
//	pcb4.set_io_wait(2);
//	pcb4.set_io_wait(2);
//	pcb5.set_io_wait(4);
//	pcb5.set_io_wait(3);
//	pcb5.set_io_wait(1);
//
//	pcb.set_memory(4);
//	pcb2.set_memory(6);
//	pcb3.set_memory(8);
//	pcb4.set_memory(12);
//	pcb5.set_memory(6);


//	sch.sm.null_state.push_back(pcb);
//	sch.sm.null_state.push_back(pcb2);
//	sch.sm.null_state.push_back(pcb3);
//	sch.sm.null_state.push_back(pcb4);
//	sch.sm.null_state.push_back(pcb5);//*/
	// END OF TEST DATA
//	iterate_state(sch.sm.null_state);

	int end = sch.sm.null_state.size();
	//	cout<<"End: "<<end<<endl;
	bool is_processing = true;
	//	cout << "True is " << true<<endl;
	//	cout << "Init Run State: "<< sch.sm.run_state.get_state().compare("Run")<<endl;
	//	cout << "Init Run ID: "<< sch.sm.run_state.get_pid()<<endl;
	// WORKING FOR LOOP
	while(is_processing) {
		sch.admit();
		sch.allocate();
		sch.dispatch();
//		printw(sch.sm.get_run_state().is_running());
		if(!sch.get_exit_state().empty() && sch.get_exit_state().size()==end) {
			cout<<"Finished"<<endl;
			is_processing = false;
		}
		sch.increase_clock();
//		cout<<"Exit:"<<sch.get_exit_state().size()<<"\tEnd:"<<end<<endl;
		//		iterate_state(sch.get_new_state());
	}

	//	cout << "PCB: " << pcb.get_pid()<<endl;
	//	cout << "PCB2: " << pcb2.get_pid()<<endl;
	//	cout << "PCB: " << pcb.get_cpu_arrival()<<endl;

	//	cout<<"PCB "<<pcb.get_cpu_pending()<<endl;
	//	sch.sm.run_state = pcb;
	//	sch.sm.run_state.consume_cpu();
	//	cout<<"PCB 1 "<<sch.sm.get_run_state().get_cpu_pending()<<endl;
	//	cout<<"IO PCB1"<<endl;
	//	cout<<pcb.get_wait()<<endl;
	//	pcb.consume_io();
	//	cout<<pcb.get_wait()<<endl;


	//	sch.sm.blocked_state.push_back(pcb);
	//	sch.sm.blocked_state.push_back(pcb2);
	//	sch.sm.blocked_state.push_back(pcb3);
	//	sch.sm.new_state.pop_front();

	//	iterate_state(sch.get_blocked_state());
	//	for (list<PCB>::iterator it = sch.sm.blocked_state.begin();
	//		 it != sch.sm.blocked_state.end(); it++) {
	//		if ((*it).get_wait() == 0)
	//			it = sch.sm.blocked_state.erase(it);
	//
	//	}
	//	sch.sm.new_state.front().io.m_io_wait.remove_if(wait_complete);
	//	sch.sm.new_state.remove(is_done);
	//	cout<<"Remove if IO wait is 0"<<endl;
	//	iterate_state(sch.get_blocked_state());



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


	//	 State
	//	ProcessGenerator pgen;

	//	for (int i=0;i<10;i++){
	//	pgen.ioArrivalTime_list.clear();
	//
	//	pgen.io_at(100,5);
	//	for (list<int>::iterator it = pgen.ioArrivalTime_list.begin();
	//		 it !=pgen.ioArrivalTime_list.end();it++){
	//		cout<<(*it)<<endl;
	//	}
	//	}

	// NCURSES END
//	printw("Hello");
//	getch();
//	endwin();
	return 0;
}
