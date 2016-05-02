/*
 * PCB.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: rigo
 */

#include "PCB.h"
#include "Info.h"
#include "IO.h"
#include <iostream>
#include <list>
//#include <string>

// Initialized static variables
int PCB::m_id = 0;

// No arg constructor instantiates member data
// TODO - initialize to 0 everything
PCB::PCB() {
//	m_pid = m_id++;	// Set when move to new
	clear_id();
	set_cpu_required(0);
	set_memory(0);
	set_io_required(0);
	set_io_required(0);
	set_to_null();
	m_running = false;
}
PCB::PCB(int cpu, int mem, int io_r, std::list<int> arrival,std::list<int> wait) {
	m_pid = m_id++;
	set_cpu_required(cpu);
	set_memory(mem);
	set_io_required(io_r);
	io.m_io_arrival.merge(arrival);
	io.m_io_wait.merge(wait);
}
void PCB::set_id() {
	m_pid = ++m_id;
}
void PCB::clear_id() {
	m_pid = 0;
}
void PCB::toggle_run() {
	m_running = !m_running;
}
void PCB::set_memory(int mem) {
	m_memory = mem;
}
void PCB::consume_cpu() {
	info.m_cpu_pending--;
	info.m_cpu_completed++;
}
void PCB::consume_io() {
	io.m_io_wait.front()--;
}
void PCB::set_to_null() {
	m_state = "Null";
}
void PCB::set_to_new() {
	m_state = "New";
}
void PCB::set_to_ready() {
	m_state = "Ready";
}
void PCB::set_to_run() {
	m_state = "Run";
	toggle_run();
}
void PCB::set_to_blocked() {
	m_state = "Blocked";
	toggle_run();
}
void PCB::set_to_exit() {
	m_state = "Exit";
	toggle_run();
}
void PCB::set_cpu_arrival(int time) {
	info.m_cpu_arrival = time;
}
void PCB::set_cpu_required(int cpu) {
	info.m_cpu_required = cpu;
	info.m_cpu_pending = cpu;
}
void PCB::set_cpu_completed(int cpu) {
	info.m_cpu_completed = cpu;
}
void PCB::set_cpu_pending(int cpu){
	io.m_io_pending = cpu;
}
void PCB::set_io_required(int required) {
	io.m_io_required = required;
	io.m_io_pending = required;
}
void PCB::set_io_completed(int completed) {
	io.m_io_completed = completed;
}
void PCB::set_io_pending(int pending) {
	io.m_io_pending = pending;
}
void PCB::set_io_arrival(int arrive) {
	io.set_arrival(arrive);
}
void PCB::set_io_wait(int wait) {
	io.set_wait(wait);
}
int PCB::get_pid() {
	return m_pid;
}
int PCB::get_memory() {
	return m_memory;
}
std::string PCB::get_state() {
	return m_state;
}
int PCB::get_cpu_arrival() {
	return info.m_cpu_arrival;
}
int PCB::get_cpu_required() {
	return info.m_cpu_required;
}
int PCB::get_cpu_completed() {
	return info.m_cpu_completed;
}
int PCB::get_cpu_pending() {
	return info.m_cpu_pending;
}
int PCB::get_io_required() {
	return this->io.m_io_required;
}
int PCB::get_io_completed() {
	return this->io.m_io_completed;
}
int PCB::get_io_pending() {
	return this->io.m_io_pending;
}
int PCB::get_arrival() {
	return io.get_arrival_list().front();
}
int PCB::get_wait() {
	return io.get_wait_list().front();
}
bool PCB::is_running() {
	return m_running;
}
PCB::~PCB() {
	// TODO Auto-generated destructor stub
}
