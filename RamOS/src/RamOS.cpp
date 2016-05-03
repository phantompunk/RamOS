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
int main() {
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
	for(int i=0;i<5;i++) {
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

	//INIT READER
	InputReader reader;
	reader.parseInput("");

	Scheduler sch;

	//USE THIS FOR READER
	for (list<PCB>::iterator it = reader.nullList.begin();
			it != reader.nullList.end(); it++) {
		sch.sm.null_state.push_back((*it));
	}

	int end = sch.sm.null_state.size();
	bool is_processing = true;
	// WORKING FOR LOOP
	while(is_processing) {
		sch.admit();
		sch.allocate();
		sch.dispatch();
		if(!sch.get_exit_state().empty() && sch.get_exit_state().size()==end) {
			cout<<"Finished"<<endl;
			is_processing = false;
		}
		sch.increase_clock();
	}
	return 0;
}
