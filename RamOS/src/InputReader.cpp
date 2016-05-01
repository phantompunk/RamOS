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
#include <regex>
#include <list>
using namespace std;
//added
InputReader::InputReader() {
	// TODO Auto-generated constructor stub

}

InputReader::~InputReader() {
	// TODO Auto-generated destructor stub
}


void InputReader::parseInput(string fileName){
	string cleanInput,workingInput;
	char regex  = ' ';
	 workingInput = getInput(fileName);
	 cleanInput = workingInput;								//gets string containing input file inputs to perform operations on
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 //clean input to incase an unaltered input was needed to be referenced and working to actually perform operations on

	int CPURequired,CPUArrivalTime, Process_Mem, IO_Requests;  //variables we expect to be inputed and that will be passed along to PCB
	list<int> IO_AT;
	list<int> IO_WAIT;

	CPURequired = getnextInput(workingInput, regex);
	workingInput = setnextInput(workingInput,regex);
	CPUArrivalTime = getnextInput(workingInput, regex);
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



}

int InputReader::getnextInput(string input, char regex){
	string value;
	value = input.substr(0,input.find_first_of(regex));

	int number;
	istringstream (value) >> number;
	return number;
}

bool InputReader::isValidFileName(string fileName){
	//Checks to see if the input file is a text file
	int end = fileName.length();
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

string InputReader::getInput(string fileName){
	ifstream myfile;
	string input;

	if(isValidFileName(fileName)){				//checks to make sure that the correct file type is used since iosstream doesn't like variables used here
		myfile.open("GeneratedInput.txt");

	} else cout<<"Invalid file name used"<<endl; //throws error if invalid filetype used for input file

	if(myfile.is_open()){
		getline(myfile,input);
	}

	return input;
}

string InputReader::setnextInput(string input, char regex){
	string nextInput;

	nextInput = input.substr(input.find_first_of(regex)+1,input.length());

	return nextInput;
}


