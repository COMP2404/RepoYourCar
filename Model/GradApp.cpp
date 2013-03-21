#include "GradApp.h"
#include <string>
#include <iostream>
using namespace std;

GradApp::GradApp(GradStudent *gs, int appNum, string cor, string stat):Application(0,"","","grad"){
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

	//cout << "created grad app" << endl;

}
GradApp::~GradApp(){

}

//==============================GETTERS==========================================
string 	 GradApp::getStuArea(){ return stuArea;}
string   GradApp::getStuSuper(){ return stuSuper;}
string   GradApp::getStuProgram(){return stuProgram;}
string 	 GradApp::getStuName(){ return stuFirst; }
//string   GradApp::getType() {return stuType;}

bool GradApp::saveSummary(){
	
	//debugging stuff..
	int i;
	int aSize;
	
	//int rlTAS = relatedTAPositions->size();
	//int rlWS = relatedWorkEXP->size();
	//there.


	//Course tempCourse;
	string fileName = applicationNumber + ".txt";

    ofstream outFile("fileName", ios::out|ios::app);

    if (!outFile) {
            cout<<"Could not open file"<<endl;
            return false;
    }


	outFile << "Graduate Application:" << endl;
	outFile << "Application Number: " << applicationNumber << endl;
	outFile << "Course: " << course << endl;
	outFile << "Application Status: " << applicationStatus << endl;
	outFile << "Student's Program: " << stuProgram << endl;
	outFile << stuArea << endl;
		
	outFile << "First Name: " << stuFirst << endl;
	outFile << "Last Name: " << stuLast << endl;
	outFile << "Email: " << stuEmail << endl;
	outFile << stuSuper << endl;
	outFile << "Student ID: " << stuID << endl;


	//Save the Application data:	
	

	//Save the related TA positions:
	outFile << "Related TA Positions:" << endl <<endl; // header	

	CourseQueue otherTemp(*relatedTAPositions);
	aSize = otherTemp.size();
	for(i=0; i < aSize; i++){
		outFile << "Related TA Position " << i << ":" <<endl;
		outFile << "Title: " << otherTemp.front()->getTitle() << endl;
		outFile << "Supervisor: " << otherTemp.front()->getSupervisor() << endl;
		outFile << "Year: " << otherTemp.front()->getYear() << endl;
		outFile << "Term: " << otherTemp.front()->getTerm() << endl;
		otherTemp.popFront();
	}

	//Save related work EXP
	outFile << "Related Work Experience" << endl <<endl; //header

	JobQueue tempJQueue(*relatedWorkEXP);
	aSize = tempJQueue.size();
	for(i=0; i < aSize; i++){
		outFile << "Related Job " << i << ":" <<endl;
		outFile << "Title: " << tempJQueue.front()->getJobTitle() << endl;
		outFile << "Tasks: " << tempJQueue.front()->getTasks() << endl;
		outFile << "Duration : " << tempJQueue.front()->getDuration() << endl;
		outFile << "Start Date: " << tempJQueue.front()->getStartDate() << endl;
		outFile << "End Date: " << tempJQueue.front()->getEndDate() << endl;
		tempJQueue.popFront();
	}
	

}


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