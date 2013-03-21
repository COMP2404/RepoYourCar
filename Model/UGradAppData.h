#ifndef UGRAD_APP_DATA
#define UGRAD_APP_DATA
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;


class UGradAppData{
	public:
		friend class UGradErrorCheck;
		friend class WindowApp;
		UGradAppData(string,string,string,string,string,string,string,string,string);
	private:
		string first,last,gmajor,GPA,CGPA,email,stuNum,course,year;
		
		
		
};
#endif
