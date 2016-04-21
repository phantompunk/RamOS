/*
 * IO.h
 *
 *  Created on: Apr 21, 2016
 *      Author: rigo
 */

#ifndef PROCESS_IO_H_
#define PROCESS_IO_H_

class IO {
private:
	int m_completed;
	int m_pending;
	int m_required;
public:
	IO();
	virtual ~IO();
	int getCompleted() const;
	void setCompleted(int completed);
	int getPending() const;
	void setPending(int pending);
	int getRequired() const;
	void setRequired(int required);
};

#endif /* PROCESS_IO_H_ */
