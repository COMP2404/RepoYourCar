#ifndef UGRAD_ERROR_CHECK
#define UGRAD_ERROR_CHECK
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "UGradAppData.h"
#include <gtk/gtk.h>


using namespace std;


class UGradErrorCheck{
	public:
		UGradErrorCheck();
		friend class UnderGradAppPage;
	private:
		GtkWidget *error_window, *error_frame, *error_dismiss,*error_message;
		bool check(UGradAppData*);
		void popWindow(string);
		static void closePopWindow(GtkWidget*, GtkWidget*);
		
		
		
};
#endif