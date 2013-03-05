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

	//debugging stuff..
	cout << "SIZES OF LINKED LISTS:" << endl;
	int j = relatedCourses->size();
	cout << "SIZE OF RELATED COURSES: " << j << endl;
	int k = relatedTAPositions->size();
	cout << "SIZE OF RELATED TA POSITIONS: "<< k << endl;
	int l = relatedWorkEXP->size();
	cout << "SIZE OF RELATED WORK EXP: " << l << endl;	
	//there.


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
	cout << "SAVING RELATED COURSES: " << endl;
	CourseQueue tempQ(*relatedCourses);
	int aSize = tempQ.size();
	cout << "SIZE OF tempQ: " << aSize << endl; 
	for(i=0; i < aSize; i++){
		cout << "Inside for loop! i is: " << i <<  endl;
		cout << "And tempQ.size is: " << tempQ.size() << endl;
		outFile << tempQ.front()->getTitle() << endl;
		outFile << tempQ.front()->getFinal() << endl;
		outFile << tempQ.front()->getYear() << endl;
		outFile << tempQ.front()->getTerm() << endl;
		tempQ.popFront();
	}

	//Save the related TA positions:
	outFile << "RELATEDTAPOSITIONS" << endl; // header	

	CourseQueue otherTemp(*relatedTAPositions);
	aSize = otherTemp.size();
	for(i=0; i < aSize; i++){
		outFile << otherTemp.front()->getTitle() << endl;
		outFile << otherTemp.front()->getSupervisor() << endl;
		outFile << otherTemp.front()->getYear() << endl;
		outFile << otherTemp.front()->getTerm() << endl;
		otherTemp.popFront();
	}

	//Save related work EXP
	outFile << "WORKEXP" << endl; //header

	JobQueue tempJQueue(*relatedWorkEXP);
	aSize = tempJQueue.size();
	for(i=0; i < aSize; i++){
		outFile << tempJQueue.front()->getJobTitle() << endl;
		outFile << tempJQueue.front()->getTasks() << endl;
		outFile << tempJQueue.front()->getDuration() << endl;
		outFile << tempJQueue.front()->getStartDate() << endl;
		outFile << tempJQueue.front()->getEndDate() << endl;
		tempJQueue.popFront(); // currently not writing the tasks
	}
	outFile << "ENDFILE" << endl;	

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


