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
//#include "CourseQueue.h"
//#include "JobQueue.h"
#include "Queue.h"

class GradApp : public Application{
public:
	//Constructors
	GradApp(GradStudent *, int, string, string);
	~GradApp();
	//GradApp(GradApp&);//COPY CONSTRUCTOR
	///////////
	//GETTERS//
	//////////
	
	//From base Application
	int      getApplicationNumber();
	string   getAppStatus();
	string   getStuFirst();
	string   getStuLast();
	string   getCourse();
	string   getStatus();
	string   getStuEmail();
	string   getStuID();
	string   getStuType();
	bool 	 printApp(bool,bool,bool);
	bool     printApp(bool);
	bool     saveSummary();
	bool 	 printModifiedApp(ofstream&);
	Application*  getCopy();
	string 	 getSummaryString();
	//bool     compare(GradApp*);
	//bool     compare(UndergradApp*);

	Application& operator-();//unary '-' changes status of application to "closed"
    Application& operator+();//unary '+' changes status to "assigned"
    bool operator==(Application&);

	//New for gradApp's
	string   getStuProgram();
	string   getStuArea();
	string   getStuSuper();

	string 	 getStuName(); //?
	bool     rTA;
	bool	 rWorkExp;

private:
	string stuProgram;
	string stuArea;
	string stuSuper;
};
#endif
