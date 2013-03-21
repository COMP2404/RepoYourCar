#ifndef GRAD_SUBMIT_WINDOW
#define GRAD_SUBMIT_WINDOW
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>



//
//#include <String.h>

using namespace std;


class GradSubmitWindow{
	public:
		friend class GradAppPage;
		
	private:
		void draw(GradSubmitWindow*);
		void submit();
		static void close(GtkWidget*,GradSubmitWindow*);
		GtkWidget *submitWindow, *submitFrame, *submitRepeat, *submitFinish;
		
		
};
#endif