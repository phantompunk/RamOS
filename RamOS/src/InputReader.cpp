/*
 * InputReader.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: kjkap
 */

#include "InputReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Scheduler.h"
//#include <regex>
#include <list>
//using namespace std;
//added
InputReader::InputReader() {
	// TODO Auto-generated constructor stub
	std::cout<<"Reader Created"<<std::endl;

}

InputReader::~InputReader() {
	// TODO Auto-generated destructor stub
}


void InputReader::parseInput(string fileName){
	std::cout<<"Parsing"<<std::endl;
	string cleanInput;
	string workingInput;
	string temp;
	char regex  = ' ';
	std::ifstream myfile;
	myfile.open("GeneratedFile.txt");

	while(!myfile.eof()) {
//	 workingInput = getInput(myfile);
	 getline(myfile,workingInput);
	 std::cout<<"contains: "<<workingInput<<std::endl;
	 cleanInput = workingInput;								//gets string containing input file inputs to perform operations on
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 //clean input to incase an unaltered input was needed to be referenced and working to actually perform operations on

	int CPURequired,CPUArrivalTime, Process_Mem, IO_Requests;  //variables we expect to be inputed and that will be passed along to PCB
	std::list<int> IO_AT;
	std::list<int> IO_WAIT;

	CPURequired = getnextInput(workingInput, regex);
	std::cout<<"CPUR: "<<CPURequired<<std::endl;
	workingInput = setnextInput(workingInput,regex);
	CPUArrivalTime = getnextInput(workingInput, regex);
	std::cout<<"CPUA: "<<CPUArrivalTime<<std::endl;
	workingInput = setnextInput(workingInput,regex);
	Process_Mem = getnextInput(workingInput, regex);
	workingInput = setnextInput(workingInput,regex);
	IO_Requests = getnextInput(workingInput, regex);
	workingInput = setnextInput(workingInput,regex);
	for(int i=0; i<IO_Requests; i++){
		IO_AT.push_back(getnextInput(workingInput,regex));
		workingInput = setnextInput(workingInput,regex);

		IO_WAIT.push_back(getnextInput(workingInput,regex));
		workingInput = setnextInput(workingInput,regex);
	}
	/* use these inputs to pass along to a or create a PCB object here */

	PCB x = PCB(CPURequired,Process_Mem,IO_Requests,IO_AT,IO_WAIT);
	nullList.push_back(x);

	std::cout<<"MEM:"<<x.get_memory()<<std::endl;
	}
	std::cout<<"End of file"<<std::endl;
}

int InputReader::getnextInput(string input, char regex){
	string value;
	value = input.substr(0,input.find_first_of(regex));

	int number;
	std::istringstream (value) >> number;
	return number;
}

bool InputReader::isValidFileName(string fileName){
	//Checks to see if the input file is a text file
	std::cout<<"checking file name"<<std::endl;
	int end = fileName.length();
	std::cout<<"file length: "<<std::endl;
	if(fileName.substr(end-4,end)==".txt"){
		return true;
	} else return false;
}

bool InputReader::hasNextInput(string input, char regex){
	if(input.empty()){
		return false;
	}
	if(input.size()<=1){
		return true;
	}else return false;

}

//string InputReader::getInput(std::ifstream myfile){
//	std::cout<<"Getting input"<<std::endl;
////	std::ifstream myfile;
//	string input;
//
////	if(isValidFileName(fileName)){				//checks to make sure that the correct file type is used since iosstream doesn't like variables used here
////		myfile.open("GeneratedFile.txt");
////		std::cout<<"Valid File"<<std::endl;
////	} else std::cout<<"Invalid file name used"<<std::endl; //throws error if invalid filetype used for input file
//
//	myfile.open("GeneratedFile.txt");
//
//	if(myfile.is_open()){
//		getline(myfile,input);
//	}
//
//	return input;
//}

string InputReader::setnextInput(string input, char regex){
	string nextInput;

	nextInput = input.substr(input.find_first_of(regex)+1,input.length());

	return nextInput;
}


