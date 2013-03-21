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

void Course::setSupervisor(string s) {supervisor = s;}
void Course::setTitle(string s) { title = s; }
void Course::setYear(int i) {year = i;}
void Course::setTerm(string s) {term = s;}
void Course::setFinal(string s) {final = s;}


//==========================================================

//DESTRUCTOR:
Course::~Course(){
}
