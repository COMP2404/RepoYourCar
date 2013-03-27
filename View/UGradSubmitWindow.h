#ifndef UNDERGRAD_SUBMIT_WINDOW
#define UNDERGRAD_SUBMIT_WINDOW
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
class WindowApp;
#include "WindowApp.h"


//
//#include <String.h>

using namespace std;


class UGradSubmitWindow{
	public:
		friend class UnderGradAppPage;
		friend class WindowApp;
	private:
		void draw(UGradSubmitWindow*);
		void submit();
		static void close(GtkWidget*,WindowApp*);
		GtkWidget *submitWindow, *submitFrame, *submitRepeat,*submitFinish;
		
		
};
#endif