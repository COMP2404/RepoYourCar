#ifndef WINDOWAPP_H
#define WINDOWAPP_H
#include <iostream>
#include <gtk/gtk.h>
using namespace std;
class WindowApp{
	public:
		GtkWidget *label, *window, *frame, *apply, *login, *appFrame, *fName, *lblfName, *lName, *lbllName, *major, *lblMajor, *gpa, *lblGpa, *email, *lblEmail, *year, *lblYear, *submit, *cancel;
		
	private:
		GtkWidget* getLabel();
		GtkWidget* getWindow();
		GtkWidget* getFrame();
		GtkWidget* getApply();
		GtkWidget* getLogin();

		void setLabel();
		void setWindow();
		void setFrame();
		void setApply();
		void setLogin();		
};

#endif
