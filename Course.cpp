#include "Course.h"
#include <string>
#include <iostream>

Course::Course(string name, int y, int when, string person){
	title =	name;
	year =	y;
	term =	when;
	supervisor = person;
	
}
//GETTERS===================================================

string Course::getSupervisor() {return supervisor;}
string Course::getTitle() { return title; }
int Course::getYear() {return year;}
int Course::getTerm() {return term;}


//==========================================================

//DESTRUCTOR:
Course::~Course(){
}
