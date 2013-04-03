#include "Application.h"
//#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Application::Application(int appNum, string cor, string stat, string type){
	//CONSTRUCTOR!===========
        applicationNumber = appNum;
        course 		  = cor;
        applicationStatus = stat;
        stuType = type;
	
}

//==============================GETTERS==========================================
//Student* Application::getApplicant(){ return applicant; }
int      Application::getApplicationNumber(){ return applicationNumber; }
string   Application::getCourse(){ return course; }
string   Application::getStatus(){ return applicationStatus; }

//int      Application::getStuCGPA(){ return stuCGPA; }
//int      Application::getStuMGPA(){ return stuMGPA; }
string   Application::getStuName(){ return stuFirst; }
string   Application::getStuFirst(){ return stuFirst; }
string   Application::getStuLast(){ return stuLast; }
string   Application::getStuEmail(){ return stuEmail; }
//string   Application::getStuMajor(){ return stuMajor; }
//int      Application::getStuYrStanding(){ return stuYearStanding; }
string   Application::getStuID(){ return stuID; }
string   Application::getType(){  return stuType; }
//string 	 Application::getStuArea(){ return stuArea;}
//string   Application::getStuSuper(){ return stuSuper;}
//string   Application::getStuProgram(){return stuProgram;}
//===============================================================================

//==============================OPERATORS========================================
Application& Application::operator-(){
	applicationStatus = "closed";
}

Application& Application::operator+(){
	applicationStatus = "assigned";
}

bool Application::operator==(Application& app){
	return (course == app.getCourse() && applicationNumber == app.getApplicationNumber());
}

ostream& operator<<(ostream& out, Application& app){
	out << app.stuFirst << " " << app.stuLast << " " << app.stuEmail << " Applying for course " << app.course << "Status: " << app.getStatus();

	return out;
}
//===============================================================================


//Destructor:
Application::~Application(){

}

//bool printModifiedApp(ofstream& out){}
/*
bool Application::printApp(){
	
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
*/
/*
void Application::setRelatedCourses(CourseQueue *queue){
	relatedCourses = queue;
	
}



*/
void Application::setRelatedTAPositions(Queue<Course> *queue){
	relatedTAPositions = queue;

}

void Application::setRelatedWorkEXP(Queue<Job> *queue){
	relatedWorkEXP = queue;

}
