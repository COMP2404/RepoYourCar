#ifndef GRAD_APP_DATA
#define GRAD_APP_DATA
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;


class GradAppData{
	public:
		friend class GradAppPage;
		friend class GradErrorCheck;
		friend class WindowApp;
		GradAppData(string,string,string,string,string,string,string,string);
	private:
		string first,last,supervisor,email,stuNum,course,areas,program;
		
		
		
};
#endif