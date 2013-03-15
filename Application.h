#ifndef APPLICATION_H
#define APPLICATION_H

#include "Student.h"
#include "GradStudent.h"
#include "UndergradStudent.h"
#include <string>
#include <iostream>
#include <fstream>

//#include "AppQueue.h"
#define APP_MAX_BUF 1000

#define INCLUDED
using namespace std;
#include "CourseQueue.h"
#include "JobQueue.h"

class Application{
public:
	//VARIABLES---------------------	
	//------------------------------
	//FUNCTIONS---------------------
	

	
	int      getApplicationNumber(void);
	string   getCourse(void);
	string   getStatus();

	string   getStuFirst();
	string   getStuLast();
	string   getStuEmail();
	string 	 getType();
	
	string   getStuID();
	
	void	 setRelatedTAPositions(CourseQueue*);
	void	 setRelatedWorkEXP(JobQueue*);

	virtual bool printApp();
	Application(int, string="unknown", string="pending", string="grad");
	~Application();
	CourseQueue	*relatedCourses;
	CourseQueue	*relatedTAPositions;
	JobQueue	*relatedWorkEXP;
	//------------------------------

	Application& operator-();//unary '-' changes status of application to "closed"
    Application& operator+();//unary '+' changes status to "assigned"

protected:
	//VARIABLES---------------------

	int     applicationNumber;
	string  course;
	
	
	string  applicationStatus;
	
	string stuFirst;
	string stuLast;
	string stuEmail;
	
	string stuID;
	string stuType;
	
	//------------------------------
};


#endif
