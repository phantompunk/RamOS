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
#include <list>


InputReader::InputReader() {
	// TODO Auto-generated constructor stub
	std::cout<<"Reader Created"<<std::endl;

}

InputReader::~InputReader() {
	// TODO Auto-generated destructor stub
}


void InputReader::parseInput(string fileName){
	/*This method handles the main logic of reading the inputs from the generated file, then using those inputs to create a list of PCB objects*/
	std::cout<<"Parsing"<<std::endl;
	string cleanInput;		//variable to hold a clean copy of the input line in case an original is needed
	string workingInput;	//variable to hold a copy of the input line that the program can manipulate while parsing the string
	string temp;
	char regex  = ' ';		//this will be the regex used to differentiate between input values
	std::ifstream myfile;
	myfile.open("GeneratedFile.txt");

	while(!myfile.eof()) {
	 getline(myfile,workingInput);							//reads in the next line of the file which is expected to be a string of integer values seperated by " "
	 std::cout<<"contains: "<<workingInput<<std::endl;
	 cleanInput = workingInput;								 //saves a copy of the original string before any string manipulation

	int CPURequired,CPUArrivalTime, Process_Mem, IO_Requests;  //variables we expect to be inputed and that will be passed along to PCB
	std::list<int> IO_AT;
	std::list<int> IO_WAIT;

	CPURequired = getnextInput(workingInput, regex);		//calls getNextInput to return the first integer in the input string
	std::cout<<"CPUR: "<<CPURequired<<std::endl;
	workingInput = setnextInput(workingInput,regex);		//passes the input string to setnextInput which returns a substring containing the remaining values that need to be input

	CPUArrivalTime = getnextInput(workingInput, regex);		//calls getNextInput to return the first integer in the input string
	std::cout<<"CPUA: "<<CPUArrivalTime<<std::endl;
	workingInput = setnextInput(workingInput,regex);		//passes the input string to setnextInput which returns a substring containing the remaining values that need to be input

	Process_Mem = getnextInput(workingInput, regex);		//same
	workingInput = setnextInput(workingInput,regex);

	IO_Requests = getnextInput(workingInput, regex);		//same
	workingInput = setnextInput(workingInput,regex);

	for(int i=0; i<IO_Requests; i++){						//We expect a value for the IO_AT list and the IO_WAIT list for each number in IO_Requests so this loops should read the rest of the inputs
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
	/*This method gets the next input from the file string by taking
	a substring starting from the beginning of the string to the first
	instance of the regex and passes that input along*/

	string value;
	value = input.substr(0,input.find_first_of(regex));

	int number;
	std::istringstream (value) >> number;
	return number;
}

bool InputReader::isValidFileName(string fileName){
	/*This checks to make sure that the filename being passed to the reader
	is a valid filename (ends in .txt) and returns a boolean indicating
	whether it is or not */


	std::cout<<"checking file name"<<std::endl;
	int end = fileName.length();
	std::cout<<"file length: "<<std::endl;
	if(fileName.substr(end-4,end)==".txt"){
		return true;
	} else return false;
}

bool InputReader::hasNextInput(string input, char regex){
	/*This method returns a boolean value indicating whether or not the input string
	 has more value to be read*/

	if(input.empty()){
		return false;
	}
	if(input.size()<=1){
		return true;
	}else return false;

}



string InputReader::setnextInput(string input, char regex){
	/*This method returns the input string prepared for for the next value to be read, removing the previous
	value that was input and setting the next value as the first character of the string by taking a substring of
	itself starting with the first character after the first instance of the regex*/

	string nextInput;
	nextInput = input.substr(input.find_first_of(regex)+1,input.length());
	return nextInput;
}


