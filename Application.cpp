#include "Application.h"
//#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Application::Application(Student *s, int appNum, string cor, string stat){
	//CONSTRUCTOR!===========
        applicationNumber = appNum;
        course 		  = cor;
        applicationStatus = stat;
	stuCGPA = s->getCGPA();
	stuMGPA = s->getMajorGPA();
	stuFirst = s->getFirst();
	stuLast = s->getLast();
	stuEmail = s->getEmail();
	stuMajor = s->getMajor();
	stuYearStanding = s->getYearStanding();
	stuID = s->getStudentNumber();
}
//==============================GETTERS==========================================
//Student* Application::getApplicant(){ return applicant; }
int      Application::getApplicationNumber(){ return applicationNumber; }
string   Application::getCourse(){ return course; }
string   Application::getStatus(){ return applicationStatus; }

int      Application::getStuCGPA(){ return stuCGPA; }
int      Application::getStuMGPA(){ return stuMGPA; }
string   Application::getStuFirst(){ return stuFirst; }
string   Application::getStuLast(){ return stuLast; }
string   Application::getStuEmail(){ return stuEmail; }
string   Application::getStuMajor(){ return stuMajor; }
int      Application::getStuYrStanding(){ return stuYearStanding; }
string   Application::getStuID(){ return stuID; }
//===============================================================================

//Destructor:
Application::~Application(){

}


bool Application::printApp(){
	int i;
	//Course tempCourse;
        ofstream outFile("Applications.txt", ios::out|ios::app);

        if (!outFile) {
                //ios::out<<"Could not open file"<<endl;
                return false;
        }
	//Save the Application data:
	outFile << applicationNumber << endl;
	outFile << course << endl;
	outFile << applicationStatus << endl;
	outFile << stuCGPA << endl;
	outFile << stuMGPA << endl;
	outFile << stuFirst << endl;
	outFile << stuLast << endl;
	outFile << stuEmail << endl;
	outFile << stuMajor << endl;
	outFile << stuYearStanding << endl;
	outFile << stuID << endl;

	//Save the related courses:
	
	CourseQueue tempQ(*relatedCourses);
	for(i=0; i < tempQ.size(); i++){
		outFile << tempQ.front()->getData()->getTitle() << endl;
		outFile << tempQ.front()->getData()->getSupervisor() << endl;
		outFile << tempQ.front()->getData()->getYear() << endl;
		outFile << tempQ.front()->getData()->getTerm() << endl;
		tempQ.popFront();
	}

	//Save the related TA positions:
	outFile << "RELATED TA POSITIONS" << endl; // header	

	CourseQueue otherTemp(*relatedTAPositions);
	for(i=0; i < otherTemp.size(); i++){
		outFile << otherTemp.front()->getData()->getTitle() << endl;
		outFile << otherTemp.front()->getData()->getSupervisor() << endl;
		outFile << otherTemp.front()->getData()->getYear() << endl;
		outFile << otherTemp.front()->getData()->getTerm() << endl;
		otherTemp.popFront();
	}

	//Save related work EXP
	outFile << "WORK EXP" << endl; //header

	JobQueue tempJQueue(*relatedWorkEXP);
	for(i=0; i < tempJQueue.size(); i++){
		outFile << tempJQueue.front()->getData()->getJobTitle() << endl;
		outFile << tempJQueue.front()->getData()->getDuration() << endl;
		outFile << tempJQueue.front()->getData()->getStartDate() << endl;
		outFile << tempJQueue.front()->getData()->getEndDate() << endl;
		otherTemp.popFront(); // currently not writing the tasks
	}	

}

void Application::setRelatedCourses(CourseQueue *queue){
	relatedCourses = queue;
	
}

void Application::setRelatedTAPositions(CourseQueue *queue){
	relatedTAPositions = queue;

}

void Application::setRelatedWorkEXP(JobQueue *queue){
	relatedWorkEXP = queue;

}


