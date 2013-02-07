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


bool Application::printApp(){
        ofstream outFile("Application.txt", ios::out);

        if (!outFile) {
                //ios::out<<"Could not open file"<<endl;
                return false;
        }

        outFile << "\t\tAPPLICANTION FORM:\n" << endl;
        outFile << "Applying for TA for class: " << course << " Application id: " << applicationNumber << endl;
        outFile << "======================APPLICANT INFORMATION======================="<<endl;
        outFile << "Applicant name: " << applicant->getFirst() << " " << applicant->getLast() << endl;
        outFile << "Applicant email: " << applicant->getEmail() << endl;
        outFile << "Applicant student number: " << applicant->getStudentNumber() << endl;
	outFile << "Application status: "<< Application::applicationStatus << endl;
	outFile << "Applicant Major GPA: " << applicant->getMajorGPA() <<endl;
        return true;
}
