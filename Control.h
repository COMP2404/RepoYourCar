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
#include "main.h"
#include <cstdlib>
#include <string.h>
#include <fstream>
using namespace std;

class Control{
	public:
		int createWindow(int, char**);
		static bool errorCheck(string*, string*, string*, string*, string*, string*, string*, string*, string*);
		static bool submit(string*, string*, string*, int, int, string*, int, string*, string*,WindowApp*);
		static void cancel();
		void loadApplications();
		
		static void adminPage(GtkWidget*, WindowApp*);
		
	private:
		
		AppQueue applicationList;//TO BE AppQueue
		static bool printApp(Application*);	
		bool errorCheck2();
		
	protected:
		static int makeApplication(GtkWidget*, WindowApp*);	
		static int getInfo(GtkWidget*,WindowApp*);
		static void workExperience(GtkWidget *, WindowApp *);
		static void relatedCourses1(GtkWidget *, WindowApp *);
		static void relatedCourses2(GtkWidget *, WindowApp *);
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
