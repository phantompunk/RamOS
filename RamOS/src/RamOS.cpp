//============================================================================
// Name        : RamOS.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include "State/StateManager.h"
//#include "Process/PCB.h"
//#include "FileReader.h"
//#include "Info.h"
using namespace std;

void test_pcb() {
	cout << "Starting PCB Test"<<endl;

	int id;
	PCB pcb,pcb2;
	cout << "Process 1 pid: " << pcb.get_pid()<<endl;
	cout << "Process 1 time: " << pcb.info.get_time()<<endl;

	cout << "Process 2 pid: " << pcb2.get_pid()<<endl;
	cout << "Process 2 time: " << pcb2.info.get_time()<<endl;
};
void test_state_manager() {
	cout << "Staring StateManager Test"<<endl;
	PCB pcb,pcb1,pcb2;
	StateManager sm;

	sm.new_state.push_front(pcb);
	sm.new_state.push_back(pcb2);
	sm.new_state.push_front(pcb1);

	cout << "The new state list contains: " << sm.new_state.size() << " elements" << endl;
	for (list<PCB>::iterator it = sm.new_state.begin();
		 it != sm.new_state.end(); it++) {
		cout << "Start time: " << (*it).info.get_time() << endl;
	}
}

int main() {

	test_pcb();

	test_state_manager();

	return 0;
}
