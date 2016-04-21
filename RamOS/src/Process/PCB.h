/*
 * PCB.h
 *
 *  Created on: Apr 19, 2016
 *      Author: rigo
 */

#ifndef PCB_H_
#define PCB_H_

#include "Info.h"
#include "IO.h"


class PCB {
private:
	int m_pid;	// Unique process id
	// Pointer points to another pcb
	// State: new, ready, run, blocked, exit
	// PC indicated the address of the next instruction
	// Memory stuff
	// Context Data
	// IO status info
	// Accounting info: CPU,real time used,etc
public:
	PCB();
	Info info;
	IO io;
	void set_pid(int id);
	int get_pid();
	virtual ~PCB();

	const Info& getInfo() const {
		return info;
	}

	void setInfo(const Info& info) {
		this->info = info;
	}

	const IO& getIo() const {
		return io;
	}

	void setIo(const IO& io) {
		this->io = io;
	}
};

#endif /* PCB_H_ */
