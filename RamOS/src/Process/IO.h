/*
 * IO.h
 *
 *  Created on: Apr 21, 2016
 *      Author: rigo
 */

#ifndef PROCESS_IO_H_
#define PROCESS_IO_H_
#include <list>

class IO {
public:
	int m_io_required;	// Amount of IO requests needed
	int m_io_completed;	// Amount of IO requests finished
	int m_io_pending;	// Amount of IO requests left to go
	std::list<int> m_io_arrival;
	std::list<int> m_io_wait;
	IO();
	void set_arrival(int arrive);
	void set_wait(int wait);
	std::list<int> get_arrival();
	std::list<int> get_wait();
	virtual ~IO();
};

#endif /* PROCESS_IO_H_ */
