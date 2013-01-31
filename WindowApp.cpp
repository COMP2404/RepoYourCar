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
void WindowApp::setEmail(string s){
	strEmail = s;
}
void WindowApp::setYear(string s){
	strYear = s;
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

/*GtkWidget* WindowApp::getLabel(){

}
GtkWidget* WindowApp::getWindow(){

}
GtkWidget* WindowApp::getFrame(){

}
GtkWidget* WindowApp::getApply(){

}
GtkWidget* WindowApp::getLogin(){

}

void WindowApp::setLabel(){

}
void WindowApp::setWindow(){

}
void WindowApp::setFrame(){

}
void WindowApp::setApply(){

}
void WindowApp::setLogin(){

}*/
