/*
 * IO.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: rigo
 */

#include "IO.h"

IO::IO() {
	// TODO Auto-generated constructor stub

}
void IO::setIoRequired(int required) {
	io_required = required;
}
int IO::getIoRequired() {
	return io_required;
}
void IO::setIoCompleted(int completed) {
	io_completed = completed;
}
int IO::getIoCompleted() {
	return io_completed;
}
void IO::setIoPending(int pending) {
	io_pending = pending;
}
int IO::getIoPending() {
	return io_pending;
}
IO::~IO() {
	// TODO Auto-generated destructor stub
}

