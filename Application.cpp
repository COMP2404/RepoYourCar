#include "Application.h"
//#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Application::Application(GradStudent *g, UndergradStudent *u, int appNum, string cor, string stat){
	//CONSTRUCTOR!===========
        applicationNumber = appNum;
        course 		  = cor;
        applicationStatus = stat;
//	
        GradStudent *gs;
        UndergradStudent *ugs;
        gs = g;
        ugs = u;
     if(gs != NULL){
     	cout << "grad app" << endl;
     	stuFirst = gs->getFirst();
		stuYearStanding = 5;//flag for graduate
		stuLast = gs->getLast();
		stuEmail = gs->getEmail();
		stuID = gs->getStudentNumber();
		stuProgram = gs->getProgram();
		stuArea = gs->getArea();
		stuSuper = gs->getSupervisor();
     }
     else if(ugs != NULL){
     	cout << "ugrad app" << endl;
     	stuFirst = u->getFirst();
     	
		stuLast = u->getLast();
		stuEmail = u->getEmail();
		stuMajor = u->getMajor();
		stuYearStanding = u->getYearStanding();
		stuID = u->getStudentNumber();
		stuCGPA = u->getCGPA();
		stuMGPA = u->getMajorGPA();
     }
      
	
	
	
	
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
string 	 Application::getStuArea(){ return stuArea;}
string   Application::getStuSuper(){ return stuSuper;}
string   Application::getStuProgram(){return stuProgram;}
//===============================================================================

//Destructor:
Application::~Application(){

}


bool Application::printApp(bool gradApp){
	int i;

	//debugging stuff..
	if(!gradApp){
		cout << "SIZES OF LINKED LISTS:" << endl;
		int j = relatedCourses->size();
		cout << "SIZE OF RELATED COURSES: " << j << endl;
	}
	
	
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

	if(gradApp){
		outFile << "Graduate" << endl;
		outFile << applicationNumber << endl;
		outFile << course << endl;
		outFile << applicationStatus << endl;
		outFile << stuProgram << endl;
		outFile << stuArea << endl;
		
		outFile << stuFirst << endl;
		outFile << stuLast << endl;
		outFile << stuEmail << endl;
		outFile << stuSuper << endl;
		outFile << stuID << endl;
	}
	else{
		outFile << "underGrad" << endl;
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
	}

	//Save the Application data:	
	

	int aSize;
	if(!gradApp){
		//Save the related courses for undergraduates:
		cout << "SAVING RELATED COURSES: " << endl;
		CourseQueue tempQ(*relatedCourses);
		aSize = tempQ.size();
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
		tempJQueue.popFront();
	}
	outFile << "ENDAPP" << endl;	

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


