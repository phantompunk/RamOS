/*
 * InputReader.h
 *
 *  Created on: Apr 30, 2016
 *      Author: kjkap
 */
#include <iostream>
#include <fstream>
#include <string>
using std::string;

#ifndef INPUTREADER_H_
#define INPUTREADER_H_

class InputReader {
public:
	InputReader();
	bool isValidFileName(string fileName);
	bool hasNextInput(string input, char regex);
	string getInput(string fileName);
	string setnextInput(string input, char regex);
	int getnextInput(string input, char regex);
	void parseInput(string fileName);
//added
	virtual ~InputReader();
};

#endif /* INPUTREADER_H_ */
