#include "Job.h"
#include <string>
#include <iostream>

Job::Job(string name, string *jobs, string timeSpent, string start, string end, int k){
	jobTitle = name;
//	tasks
	duration = timeSpent;
	startDate = start;
	endDate = end;

	r = -1;
	
}
//GETTERS===================================================

string Job::getJobTitle() {return jobTitle;}
string Job::getDuration() { return duration; }
string Job::getStartDate() {return startDate;}
string Job::getEndDate() {return endDate;}

int Job::getNumTasks() {return r;}
//==========================================================

//DESTRUCTOR:
Job::~Job(){
}
