/*
 * ProcessGenerator.cpp
 *
 *  Created on: Apr 22, 2016
 *      Author: josephconteh
 */

#include "ProcessGenerator.h"
#include <fstream>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<thread>
#include<chrono>
#include<ncurses.h>

int ProcessGenerator::number_IO = 0;
int ProcessGenerator::cpu_runtime = 0;

ProcessGenerator::ProcessGenerator() {
	create_file();
	close_file();

}
void ProcessGenerator::set_cpu_time(){
	cpu_time = 5;
}
void ProcessGenerator::create_file(){
	std::ofstream fs("GeneratedFile.txt");
	for(int i = 0; i < 60; i++){
	fs<< "this works "<< random_io();
	fs<< " " << random_runtime();
	fs<< " " << random_processMemory() << "\n";
	}
}
//void ProcessGenerator::write_file(){
//	std::ofstream fs;

//}
 void ProcessGenerator::close_file(){
	 std::ofstream fs;
	 fs.close();
 }
 int ProcessGenerator::random_io(){ //Method for random number of IO request per process
	std::srand((unsigned)time(0));
	 return rand()%6;
 }
 int ProcessGenerator::random_runtime(){ //Method for random runtime generator
	 std::srand((unsigned)time(0));
	 return (rand()%(950-10)+10);
 }
 int ProcessGenerator::random_processMemory(){ //Method for process allocation before moving to ready array
	 std::srand((unsigned)time(0));
	 return (rand()%16 + 1);
 }

 int ProcessGenerator::get_IO(){
	 return number_IO;
 }

 void ProcessGenerator::set_IO(int IO ){
	 number_IO = IO;
 }


 std::list<int> ProcessGenerator::io_at(int cpu, int IO){
	 int IO_L = cpu/IO;
	 for(int i=0; i<IO; i++){
		 std::srand((unsigned)time(0));
		 IO_list.push_back(rand()%IO_L);

	 }
		return IO_list;


 }
 int ProcessGenerator::io_wt(){
	 std::srand((unsigned)time(0));
	 return (rand()%50 + 25);
	  }



ProcessGenerator::~ProcessGenerator() {
	// TODO Auto-generated destructor stub
}

