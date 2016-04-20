//============================================================================
// Name        : RamOS.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include "PCB.h"
using namespace std;

int main() {

	int id;
	PCB pcb, pcb2;

	id = pcb.get_pid();

	cout << "Process PID: " << id<<endl;

	pcb2.set_pid(123);
	id = pcb2.get_pid();

	cout << "Process2 PID: " << id<<endl;
	return 0;
}
