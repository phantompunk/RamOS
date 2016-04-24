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
//#include "Scheduler.h"

#include <string>

class PCB {
	static int m_id;		// Global id count
private:
	int m_pid;				// Unique process id
	int m_ppid; 			// Unique parent process id
	std::string m_state;	// State PCB is currently in
	// Pointer points to another pcb
	// State: new, ready, run, blocked, exit
	// PC indicated the address of the next instruction
	// Memory stuff
	// Context Data
	// IO status info: IO requested, IO completed, isBlocked
	// Accounting info: CPU,real time used,etc
public:
	PCB();
	Info info;
	IO io;
	void set_to_new();
	void set_to_ready();
	void set_to_run();
	void set_to_blocked();
	void set_to_exit();

	int get_pid();
	std::string get_state();
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
