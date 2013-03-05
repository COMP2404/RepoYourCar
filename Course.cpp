#include "Course.h"

#include <string>

#include <iostream>



Course::Course(string name, int y, string when, string person, string grade){

	title =	name;

	term =	when;

	supervisor = person;

	final = grade;

	year = y;

    	

	

}

//GETTERS===================================================



string Course::getSupervisor() {return supervisor;}

string Course::getTitle() { return title; }

int Course::getYear() {return year;}

string Course::getTerm() {return term;}

string Course::getFinal() {return final;}





//==========================================================



//DESTRUCTOR:

Course::~Course(){

}

