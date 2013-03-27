#ifndef GRAD_ERROR_CHECK
#define GRAD_ERROR_CHECK
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "GradAppData.h"
#include <gtk/gtk.h>


using namespace std;


class GradErrorCheck{
	public:

		GradErrorCheck();
		friend class GradAppPage;
		
		
	private:
		GtkWidget *error_window, *error_frame, *error_dismiss, *error_message;
		bool check(GradAppData*);
		void popWindow(string);
	protected:
		static void closePopWindow(GtkWidget*, GtkWidget*);
		
};
#endif