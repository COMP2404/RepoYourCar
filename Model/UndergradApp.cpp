#include "UndergradApp.h"
#include <string>
#include <iostream>
using namespace std;

UndergradApp::UndergradApp(UndergradStudent *ugs, int appNum, string cor, string stat): Application(0,"","","undergrad"){
	applicationNumber = appNum;
    course 		  = cor;
    applicationStatus = stat;
	
 	stuFirst = ugs->getFirst();
	stuLast = ugs->getLast();
	stuEmail = ugs->getEmail();
	stuID = ugs->getStudentNumber();
	stuCGPA = ugs->getCGPA();
	stuMGPA = ugs->getMajorGPA();
	stuMajor = ugs->getMajor();
	stuYearStanding = ugs->getYearStanding();

}

//==============================GETTERS==========================================

int      UndergradApp::getStuCGPA(){ return stuCGPA; }
int      UndergradApp::getStuMGPA(){ return stuMGPA; }
string   UndergradApp::getStuMajor(){ return stuMajor; }
int      UndergradApp::getStuYrStanding(){ return stuYearStanding; }
string   UndergradApp::getStuName(){ return stuFirst; }


bool UndergradApp::saveSummary(){
	
	int i;
	int rlCS = relatedCourses->size();
	
	
	
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

	outFile << "UnderGraduate Application:" << endl;
	outFile << "Application Number: " << applicationNumber << endl;
	outFile << "Course: " << course << endl;
	outFile << "Application Status: " << applicationStatus << endl;
	outFile << "Student CGPA: " << stuCGPA << endl;
	outFile << "Student GPA: " << stuMGPA << endl;
	outFile << "First Name: " << stuFirst << endl;
	outFile << "Last Name: " << stuLast << endl;
	outFile << "Email: " << stuEmail << endl;
	outFile << "Major: " << stuMajor << endl;
	outFile << "Current year Standing: " << stuYearStanding << endl;
	outFile << "Student ID: " << stuID << endl;
	

	//Save the Application data:	
	

	int aSize;

	CourseQueue tempQ(*relatedCourses);
	//Save the related courses for undergraduates:

	outFile << "Related Courses: " << endl <<endl;
	cout << "SIZE OF tempQ: " << aSize << endl; 
	int cSize = relatedCourses->size();
	for(i=0; i < cSize; i++){
		outFile << "Related Course " << i << ":" << endl;
		outFile << "Title: " << tempQ.front()->getTitle() << endl;
		outFile << "Final Grad: " << tempQ.front()->getFinal() << endl;
		outFile << "Year: " << tempQ.front()->getYear() << endl;
		outFile << "Term: " << tempQ.front()->getTerm() << endl;
		tempQ.popFront();
	}
	
	

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


bool UndergradApp::printApp(){
	Application::printApp();

	cout << "SIZES OF LINKED LISTS:" << endl;
	int j = relatedCourses->size();
	cout << "SIZE OF RELATED COURSES: " << j << endl;
	int k = relatedTAPositions->size();
	cout << "SIZE OF RELATED TA POSITIONS: "<< k << endl;
	int l = relatedWorkEXP->size();
	cout << "SIZE OF RELATED WORK EXP: " << l << endl;
	ofstream outFile("Applications.txt", ios::out|ios::app);

    if (!outFile) {
            //ios::out<<"Could not open file"<<endl;
            return false;
    }
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

	int aSize;
	int i;
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

void UndergradApp::setRelatedCourses(CourseQueue *queue){
	relatedCourses = queue;
	
}