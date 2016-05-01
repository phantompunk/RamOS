/*
 * ProcessGenerator.h

 *
 *  Created on: Apr 22, 2016
 *      Author: josephconteh
 */

#include<cstdlib>
#include<time.h>
#include<fstream>
#include<iostream>
#include <iostream>
#include <ctime>
#include<list>

/*
int show(int random)
{
	cout << random << endl;
	return 0;
}
int genRandom()
{
int i = 1;
int random[26];
srand((unsigned)time(NULL));
for (int i = 1; i < 26; i++)
{
random[i] = 1+ rand() % 10;
show (random[i]);
}
return 0;
}
*/

#ifndef PROCESSGENERATOR_H_
#define PROCESSGENERATOR_H_

class ProcessGenerator {
public:
	std::string file_name;
	static int cpu_runtime;
	int get_cpu();
	void set_cpu();
	static int number_IO;
	int get_IO();
	void set_IO(int IO);
	int cpu_time;
	int processArrivalTime();
	void set_io_request(); // method to create io request
	void set_cpu_time(); //method to create random total of process time needed
	void create_file(); //writes file
	void write_file();
	void close_file();
	int random_io();
	int random_runtime();
	int random_processMemory();
	void io_at(int cpu_runtime, int number_IO);
	void io_wt(int number_10);

	std::list<int> ioArrivalTime_list; // list of Process IO request times
	std::list<int> waitTime_list; // list of wait times; given IO request


	ProcessGenerator();
	virtual ~ProcessGenerator();
};

#endif /* PROCESSGENERATOR_H_ */
