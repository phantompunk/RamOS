/*
 * Info.h
 *
 *  Created on: Apr 20, 2016
 *      Author: rigo
 */

#ifndef INFO_H_
#define INFO_H_

class Info {
private:

public:
	int m_cpu_required;		// Amount of clock cycles required
	int m_cpu_completed;	// Amount of clock cycles completed
	int m_cpu_pending;		// Amount of clock cycles left to go
	int m_cpu_arrival;		// Clock cycle when process arrives
	Info();
	virtual ~Info();
};

#endif /* INFO_H_ */
