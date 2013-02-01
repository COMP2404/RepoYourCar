#ifndef CONTROL
#define CONTROL
#include <iostream>
#include <gtk/gtk.h>
#include "WindowApp.h"
#include "Student.h"
#include "Application.h"
#include "main.h"
#include <cstdlib>
#include <string.h>
#include <fstream>
class Control{
	public:
		int createWindow(int, char**);
		
	private:
		bool errorCheck(string*, string*, string*, string*, string*, string*, string*, string*);
		bool submit(string*, string*, string*, int, int, string*, int, string*);
		bool printApp(Application*);	
		int application(GtkWidget*, WindowApp*);	
};
#endif
