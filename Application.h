#ifndef APPLICATION_H
#define APPLICATION_H

#include "Student.h"
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
	
//Student* getApplicant(void);
	int      getApplicationNumber(void);
	string   getCourse(void);
	string   getStatus();

	int      getStuCGPA();
	int      getStuMGPA();
	string   getStuFirst();
	string   getStuLast();
	string   getStuEmail();
	string   getStuMajor();
	int      getStuYrStanding();
	string   getStuID();
	void 	 setRelatedCourses(CourseQueue*);
	void	 setRelatedTAPositions(CourseQueue*);
	void	 setRelatedWorkEXP(JobQueue*);

	bool printApp();
	Application(Student*, int, string="unknown", string="pending");
	~Application();
	CourseQueue	*relatedCourses;
	CourseQueue	*relatedTAPositions;
	JobQueue	*relatedWorkEXP;
	//------------------------------

private:
	//VARIABLES---------------------
//Student *applicant;
	int     applicationNumber;
	string  course;
	
	
	string  applicationStatus;
	//Student members:
	int    stuCGPA;
	int    stuMGPA;
	string stuFirst;
	string stuLast;
	string stuEmail;
	string stuMajor;
	int    stuYearStanding;
	string stuID;
	//------------------------------
};


#endif
