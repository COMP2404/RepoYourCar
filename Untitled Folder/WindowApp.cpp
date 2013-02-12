#include "WindowApp.h"

/*WindowApp::WindowApp(){
	setfName("");
	setlName("");
	setMajor("");
	setGpa("");
	setEmail("");
	setYear("");
}

WindowApp::~WindowApp(){
	
}*/




void WindowApp::setfName(string s){
	strfName = s;
}
void WindowApp::setlName(string s){
	strlName = s;
}
void WindowApp::setMajor(string s){
	strMajor  = s;
}
void WindowApp::setGpa(string s){
	strGpa  = s;
}
void WindowApp::setCgpa(string s){
	strCgpa  = s;
}
void WindowApp::setEmail(string s){
	strEmail = s;
}
void WindowApp::setYear(string s){
	strYear = s;
}
void WindowApp::setStuNum(string s){
	strStuNum = s;
}

string WindowApp::getfName(){
	return strfName;
}
string WindowApp::getlName(){
	return strlName;
}
string WindowApp::getMajor(){
	return strMajor;
}
string WindowApp::getGpa(){
	return strGpa;
}
string WindowApp::getEmail(){
	return strEmail;
}
string WindowApp::getYear(){
	return strYear;
}
string WindowApp::getCgpa(){
	return strCgpa;
}
string WindowApp::getStuNum(){
	return strStuNum;
}

