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
	std::list<int> m_io_arrival;	// List of arrival times
	std::list<int> m_io_wait;		// List of wait times
	IO();
	void set_arrival(int arrive);
	void set_wait(int wait);
//	int get_arrival();				   // Return front arrival time if available
//	int get_
	std::list<int> get_arrival_list(); // Return list of arrival times
	std::list<int> get_wait_list();	   // Return list of wait times
	virtual ~IO();
};

#endif /* PROCESS_IO_H_ */
