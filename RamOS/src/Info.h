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
	int m_burst_time;
public:
	Info();
	void start_timer();
	int get_time();
	virtual ~Info();
};

#endif /* INFO_H_ */
