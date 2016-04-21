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

void test() {
	cout << "Starting OS"<<endl;
};

int main() {

	PCB proc1;
	StateManager sm;
	sm.m_new_state.push_front(proc1);

	cout << "The new state list contains: " << sm.m_new_state.size() << " elements" << endl;
	for (list<PCB>::iterator it = sm.m_new_state.begin();
		 it != sm.m_new_state.end(); it++) {
		cout << "Start time: " << (*it).info.get_time() << endl;
	}
//	cout << "The 1 element has a start time of " << sm.m_new_state.get_allocator(
//	cout << "First element in list contains: " << sm.m_new_state.
//	test();
//	int id;
//	PCB pcb, pcb2;
//
//	id = pcb.get_pid();
//
//	cout << "Process1 PID: " << id<<endl;
//
//	pcb2.set_pid(123);
//	id = pcb2.get_pid();
//
//	cout << "Process2 PID: " << id<<endl;
//
//	cout << "Process1 start time: " << pcb.info.get_time()<<endl;
	return 0;
}
