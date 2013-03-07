#include "GradApp.h"
#include <string>
#include <iostream>
using namespace std;

GradApp::GradApp(GradStudent *gs, int appNum, string cor, string stat):Application(0,"",""){
	applicationNumber = appNum;
    course 		  = cor;
    applicationStatus = stat;
	
 	stuFirst = gs->getFirst();
	stuLast = gs->getLast();
	stuEmail = gs->getEmail();
	stuID = gs->getStudentNumber();
	stuProgram = gs->getProgram();
	stuArea = gs->getArea();
	stuSuper = gs->getSupervisor();

	cout << "created grad app" << endl;

}
GradApp::~GradApp(){

}

//==============================GETTERS==========================================
//string 	 Application::getStuArea(){ return stuArea;}
//string   Application::getStuSuper(){ return stuSuper;}
//string   Application::getStuProgram(){return stuProgram;}


bool GradApp::printApp(){
	Application::printApp();
	
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
    cout << "printing app" << l << endl;
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

	int aSize;

	//Save the related TA positions:
	outFile << "RELATEDTAPOSITIONS" << endl; // header	

	CourseQueue otherTemp(*relatedTAPositions);
	aSize = otherTemp.size();
	int i;
	for(i=0; i < aSize; i++){
		cout << "inside course queue" << endl;
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