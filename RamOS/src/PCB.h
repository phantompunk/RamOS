/*
 * PCB.h
 *
 *  Created on: Apr 19, 2016
 *      Author: rigo
 */

#ifndef PCB_H_
#define PCB_H_

class PCB {
private:
	int m_pid;
public:
	PCB();
	void set_pid(int id);
	int get_pid();
	virtual ~PCB();
};

#endif /* PCB_H_ */
