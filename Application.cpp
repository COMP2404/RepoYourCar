#include "Application.h"
//#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Application::Application(Student *s, int appNum, string cor, string stat){
	//CONSTRUCTOR!===========
	applicant	  = s;
        applicationNumber = appNum;
        course 		  = cor;
        applicationStatus = stat;
}
//==============================GETTERS==========================================
Student* Application::getApplicant(){ return applicant; }
int      Application::getApplicationNumber(){ return applicationNumber; }
string   Application::getCourse(){ return course; }
//===============================================================================

//Destructor:
Application::~Application(){

}

