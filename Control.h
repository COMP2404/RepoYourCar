#ifndef CONTROL
#define CONTROL
#include <iostream>
#include <gtk/gtk.h>
#include "WindowApp.h"
#include "Student.h"
#include "Application.h"
//#include "Queue.h"
#include "AppQueue.h"
#include "Student.h"
#include "GradStudent.h"
#include "UndergradStudent.h"
#include "main.h"
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

class Control{
	public:
		friend class WindowApp;
		int createWindow(int, char**);
		static bool errorCheck(string*, string*, string*, string*, string*, string*, string*, string*, string*, string*, string*, string*,  WindowApp*);
		static bool submit(string*, string*, string*, int, int, string*, int, string*, string*,WindowApp*);
		static void cancel();
		void loadApplications(WindowApp*);
		
		
		//static void adminPage(GtkWidget*, WindowApp*);
		
	private:
		
		AppQueue applicationList;//TO BE AppQueue
		static bool printApp(Application*);	
		bool errorCheck2();
		
	protected:
		static void killSubmitWindow(GtkWidget*, WindowApp*);
		//static void viewSummary(GtkWidget*, WindowApp*);
	////	static void updateCombo(GtkWidget*, WindowApp*);
		//static void mainMenu(GtkWidget*, WindowApp*);
		//static void popWindow(string, WindowApp*);
		//static void closePopWindow(GtkWidget*, WindowApp*);
		//static void closeAdminPage(GtkWidget*, WindowApp*);
		//static void studentPage(GtkWidget*, WindowApp*);
		//static void closeStudentPage(GtkWidget*, WindowApp*);
		//static void prepareNewStudentApp(GtkWidget*, WindowApp*);
		//static void adminPage(GtkWidget*, WindowApp*);
		//static int makeApplication(GtkWidget*, WindowApp*);	
		static int getInfo(GtkWidget*,WindowApp*);

		//static void workExperience(GtkWidget *, WindowApp *);
		//static void relatedCourses1(GtkWidget *, WindowApp *);
		//static void relatedCourses2(GtkWidget *, WindowApp *);

		static void quickCheck(GtkWidget*, WindowApp*);
		static void quickCheck2(GtkWidget*, WindowApp*);
		static void quickCheck3(GtkWidget*, WindowApp*);

		static void addAnother(GtkWidget*,WindowApp*);
		static void addAnother2(GtkWidget*,WindowApp*);
		static void addAnother3(GtkWidget*,WindowApp*);
		static void finishExtra(GtkWidget*,WindowApp*);

		static void moveOn(GtkWidget*,WindowApp*);
		static void moveOn2(GtkWidget*,WindowApp*);
		static void moveOn3(GtkWidget*,WindowApp*);
		static void submitToMain(GtkWidget*,WindowApp*);
		static void submitToRepeat(GtkWidget*,WindowApp*);
		
};
#endif
