#ifndef CONTROL
#define CONTROL
#include <iostream>
#include <gtk/gtk.h>
#include "WindowApp.h"
#include "Student.h"
#include "Application.h"
#include "Queue.h"
#include "Student.h"
#include "main.h"
#include <cstdlib>
#include <string.h>
#include <fstream>

class Control{
	public:
		int createWindow(int, char**);
		static bool errorCheck(string*, string*, string*, string*, string*, string*, string*, string*, string*);
		static bool submit(string*, string*, string*, int, int, string*, int, string*, string*);
		static void cancel();
		void loadApplications();
		
	private:
		
		Queue applicationList;
		static bool printApp(Application*);	
		
	protected:
		static int makeApplication(GtkWidget*, WindowApp*);	
		static int getInfo(GtkWidget*,WindowApp*);
		static void workExperience(GtkWidget *, WindowApp *);
		static void relatedCourses1(GtkWidget *, WindowApp *);
		static void relatedCourses2(GtkWidget *, WindowApp *);
		
		
};
#endif
