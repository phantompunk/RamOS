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
	int m_cpu_required;
	int m_cpu_completed;
	int m_cpu_pending;
	int m_cpu_arrival;
	Info();
	void start_timer();
	int get_time();
	virtual ~Info();
};

#endif /* INFO_H_ */
