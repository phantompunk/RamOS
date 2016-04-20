/*
 * PCB.h
 *
 *  Created on: Apr 19, 2016
 *      Author: rigo
 */

#ifndef PCB_H_
#define PCB_H_

#include "Info.h"


class PCB {
private:
	int m_pid;	// Unique process id
	// Pointer points to another pcb
	// State: new, ready, run, blocked, exit
	// PC indicated the address of the next instruction
	// Memory stuff
	// Accounting info: CPU,real time used,etc
public:
	PCB();
	Info info;
	void set_pid(int id);
	int get_pid();
	virtual ~PCB();

	const Info& getInfo() const {
		return info;
	}

	void setInfo(const Info& info) {
		this->info = info;
	}
};

#endif /* PCB_H_ */
