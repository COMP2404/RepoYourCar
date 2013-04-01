#include "GradApp.h"
#include <string>
#include <fstream>
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

//bool compare(GradApp* app){

//}

//bool compare(UndergradApp* app){

//}

Application* GradApp::getCopy(){
	return (new GradApp(*this));//return a copy of this class
}

/*
GradApp::GradApp(GradApp& ga){
	////////////////COPY CTOR//////////////////
	applicationNumber = ga.getApplicationNumber();
    course 	= ga.getCourse();
    applicationStatus = ga.getStatus();
	
 	stuFirst = ga.getStuFirst();
	stuLast = ga.getStuLast();
	stuEmail = ga.getStuEmail();
	stuID = ga.getStuID();
	stuProgram = ga.getStuProgram();
	stuArea = ga.getStuArea();
	stuSuper = ga.getStuSuper();
}
*/
//==============================GETTERS==========================================
	int GradApp::getApplicationNumber(){ return applicationNumber; }
	string   GradApp::getStuFirst(){ return stuFirst; }
	string   GradApp::getStuLast(){ return stuLast; }
	string   GradApp::getCourse(){ return course; }
	string   GradApp::getStatus(){ return applicationStatus; }
	string   GradApp::getStuEmail(){ return stuEmail; }
	string   GradApp::getStuID(){ return stuID; }
	string   GradApp::getStuType(){  return stuType; }
	
	string 	 GradApp::getStuArea(){ return stuArea;}
	string   GradApp::getStuSuper(){ return stuSuper;}
	string   GradApp::getStuProgram(){return stuProgram;}

	string 	 GradApp::getSummaryString(){
		string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, summary;
		s1 = getStuFirst();
		//cout << s1 << endl;
		s2 = getStuLast();
		s6 = getStuEmail();
		s7 = getStuID();
		s9 = getStuArea();
		s10 = getStuProgram();
		s11 = getStuSuper();
		summary = "Course: " + course +  " Grad: " + s1 + " " + s2 +  "  | Email: " + s6 + "  |  ID: " + s7 + "  | Area: " + s9 + "  |  Program:  "  + s10 + " |  Supervisor:  " + s11;
		return summary;
	}

	bool GradApp::saveSummary(){
	
	//debugging stuff..
	int i;
	int aSize;

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

	Queue<Course> otherTemp(*relatedTAPositions);
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

	Queue<Job> tempJQueue(*relatedWorkEXP);
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


bool GradApp::printApp(bool append){
	//Application::printApp();
	
	int k = relatedTAPositions->size();
	cout << "SIZE OF RELATED TA POSITIONS: "<< k << endl;
	int l = relatedWorkEXP->size();
	cout << "SIZE OF RELATED WORK EXP: " << l << endl;	
	//there.

	ofstream outFile("Applications.txt", ios::out|ios::app);
	//Course tempCourse;

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

	Queue<Course> otherTemp(*relatedTAPositions);
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

	Queue<Job> tempJQueue(*relatedWorkEXP);
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

bool GradApp::printModifiedApp(ofstream& outFile){
	//Application::printApp();
	
	int k = relatedTAPositions->size();
	cout << "SIZE OF RELATED TA POSITIONS: "<< k << endl;
	int l = relatedWorkEXP->size();
	cout << "SIZE OF RELATED WORK EXP: " << l << endl;	
	//there.

	//ofstream outFile("Applications.txt", ios::out|ios::app);
	//Course tempCourse;

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

	Queue<Course> otherTemp(*relatedTAPositions);
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

	Queue<Job> tempJQueue(*relatedWorkEXP);
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
