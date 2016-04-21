/*
 * PCB.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: rigo
 */

#include "PCB.h"
#include "Info.h"
#include "IO.h"

/*
 *
 */
PCB::PCB() {
	m_pid = 999;
}
void PCB::set_pid(int id) {
	m_pid = id;
}
int PCB::get_pid() {
	return m_pid;
}
PCB::~PCB() {
	// TODO Auto-generated destructor stub
}

