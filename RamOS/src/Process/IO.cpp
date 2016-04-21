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

int IO::getCompleted() const {
	return m_completed;
}

void IO::setCompleted(int completed) {
	m_completed = completed;
}

int IO::getPending() const {
	return m_pending;
}

void IO::setPending(int pending) {
	m_pending = pending;
}

int IO::getRequired() const {
	return m_required;
}

void IO::setRequired(int required) {
	m_required = required;
}

IO::~IO() {
	// TODO Auto-generated destructor stub
}

