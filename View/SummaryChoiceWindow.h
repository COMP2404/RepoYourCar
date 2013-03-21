#ifndef SUM_CHOICE_WINDOW
#define SUM_CHOICE_WINDOW
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
#include "AdminWindow.h"
//
//#include <String.h>

using namespace std;
class Control;
class AdminPage;
class AdminWindow;
class SummaryChoiceWindow{
	public:
		friend class AdminPage;
		friend class AdminWindow;

		//AdminPage adminPage;
		

	private:
		GtkWidget *summary_choice_window,*summary_choice_frame, *btnOneCourse, *btnAllCourses;
		
		void draw();
		void close();
		
		
		
};
#endif