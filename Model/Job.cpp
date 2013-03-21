#include "Job.h"
#include <string>
#include <iostream>

Job::Job(string name, string jobs, string timeSpent, string start, string end){
	jobTitle = name;
	tasks    = jobs;
	duration = timeSpent;
	startDate = start;
	endDate = end;
	
}
//GETTERS===================================================

string Job::getJobTitle() {return jobTitle;}
string Job::getDuration() { return duration; }
string Job::getTasks() { return tasks; }
string Job::getStartDate() {return startDate;}
string Job::getEndDate() {return endDate;}

int Job::getNumTasks() {return r;}

void 	Job::setJobTitle(string s){jobTitle = s;}
void	Job::setDuration(string s){duration = s;}
void	Job::setEndDate(string s){endDate = s;}
void  	Job::setTasks(string s){tasks = s;}
//==========================================================

//DESTRUCTOR:
Job::~Job(){
}
