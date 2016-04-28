/*
 * IO.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: rigo
 */

#include "IO.h"

IO::IO() {
	// TODO Auto-generated constructor stub

}
void IO::set_arrival(int arrive) {
	m_io_arrival.push_back(arrive);
}
void IO::set_wait(int wait) {
	m_io_wait.push_back(wait);
}
std::list<int> IO::get_arrival() {
	return m_io_arrival;
}
std::list<int> IO::get_wait() {
	return m_io_wait;
}
IO::~IO() {
	// TODO Auto-generated destructor stub
}

