/*
 * IO.h
 *
 *  Created on: Apr 20, 2016
 *      Author: rigo
 */

#ifndef IO_H_
#define IO_H_

class IO {
private:
	int io_required;
	int io_completed;
	int io_pending;
public:
	IO();
	int getIoCompleted();
	void setIoCompleted(int ioCompleted);
	int getIoPending();
	void setIoPending(int ioPending);
	int getIoRequired();
	void setIoRequired(int ioRequired);
	virtual ~IO();

};

#endif /* IO_H_ */
