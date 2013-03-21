#ifndef ERROR_WINDOW
#define ERROR_WINDOW
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
#include "WindowApp.h"
//
//#include <String.h>

using namespace std;
class Control;
class WindowApp;
class ErrorWindow{
	public:
		friend class WindowApp;
		

	private:
		GtkWidget *error_window, *error_frame, *error_dismiss, *error_message;
		
		void draw(string s);
		void close();
		
		
		
};
#endif