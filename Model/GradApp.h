#ifndef GRADAPP_H
#define GRADAPP_H

#include "Application.h"
#include <string>
#include <iostream>
#include <fstream>

//#include "AppQueue.h"
#define APP_MAX_BUF 1000

#define INCLUDED
using namespace std;
#include "CourseQueue.h"
#include "JobQueue.h"

class GradApp : public Application{
public:
	//Application(GradStudent*, UndergradStudent*, int, string="unknown", string="pending");
	GradApp(GradStudent *, int, string, string);
	~GradApp();
	string   getStuProgram();
	string   getStuArea();
	string   getStuSuper();
	bool 	 printApp();
	string 	 getStuName();
	bool     saveSummary();
	string   getStuLast();

private:
	string stuProgram;
	string stuArea;
	string stuSuper;
};
#endif