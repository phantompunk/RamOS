/*
 * PCB.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: rigo
 */

#include "PCB.h"
#include "Info.h"
#include "IO.h"
#include <string>

// Initialized static variables
int PCB::m_id = 0;

// No arg constructor instantiates member data
PCB::PCB() {
	m_pid = m_id++;
}
void PCB::set_to_ready() {
	m_state = "Ready";
}
int PCB::get_pid() {
	return m_pid;
}
std::string PCB::get_state() {
	return m_state;
}
PCB::~PCB() {
	// TODO Auto-generated destructor stub
}
