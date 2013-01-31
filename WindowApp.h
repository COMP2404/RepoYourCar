#ifndef WINDOWAPP_H
#define WINDOWAPP_H
#include <iostream>
#include <gtk/gtk.h>
//#include <String.h>
using namespace std;
class WindowApp{
	public:
		GtkWidget *label, *window, *frame, *apply, *login, *appFrame, *fName, *lblfName, *lName, *lbllName, *major, *lblMajor, *gpa, *lblGpa, *email, *lblEmail, *year, *lblYear, *submit, *cancel;
		/*WindowApp();
		~WindowApp();*/
		void setfName(string);
		void setlName(string);
		void setMajor(string);
		void setGpa(string);
		void setEmail(string);
		void setYear(string);

		string getfName();
		string getlName();
		string getMajor();
		string getGpa();
		string getEmail();
		string getYear();
	private:
		string strfName, strlName, strMajor, strGpa, strEmail, strYear;
		
		

		
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
