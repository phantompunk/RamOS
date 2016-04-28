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
	int m_memory;			// Memory stuff
	std::string m_state;	// State PCB is currently in
public:
	PCB();
	PCB(int cpu,int mem,int io);
	Info info;
	IO io;

	void set_id(int id);		// Set process id - only used to clear run
	void set_cpu_arrival(); 	// Set when the process the arrives
	void set_cpu_required(int cpu);	// Set amount of cycles required
	void set_cpu_completed(int cpu);// Set amount of completed cpu cycles
	void set_cpu_pending(int cpu);	// Set amount of cycles remaining
	void set_io_required(int io);	// Set amount of IOs requested
	void set_io_completed(int io);	// Set amount of IOs finished
	void set_io_pending(int io);	// Set amount of IOs remaining
	void set_io_arrival(int arrive);// Push arrival time to end of list
	void set_io_wait(int wait);		// Push wait time to end of list
	void set_memory(int mem);		// Set required memory
	void set_to_null();		// Set state flag to null
	void set_to_new();		// Set state flag to new
	void set_to_ready();	// Set state flag to ready
	void set_to_run();		// Set state flag to run
	void set_to_blocked();	// Set state flag to blocked
	void set_to_exit();		// Set state flag to exit

	int get_pid();			// Return unique process id
	int get_memory();		// Return required memory
	std::string get_state();// Return current process state flag
	int get_cpu_arrival();	// Return clock cycle when process arrives
	int get_cpu_required();	// Return clock cycles needed to finish
	int get_cpu_completed();// Return clock cycles finished
	int get_cpu_pending();	// Return clock cycles remaining
	int get_io_required();	// Return IOs requested
	int get_io_completed();	// Return IOs finished
	int get_io_pending();	// Return IOs still remaining
	int get_arrival();		// Return first arrival time if not null
	int get_wait();			// Return first wait time if not null
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
