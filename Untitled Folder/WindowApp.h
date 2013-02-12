#ifndef WINDOWAPP_H
#define WINDOWAPP_H
#include <iostream>
#include <gtk/gtk.h>
//#include <String.h>
using namespace std;
class WindowApp{
	public:
		GtkWidget *label, *window, *frame, *apply, *login, *appFrame, *fName, *lblfName, *lName, *lbllName, *major, *lblMajor, *gpa, *lblGpa, *cgpa, *lblCgpa, *stuNum,*lblstuNum, *email, *lblEmail, *year, *lblYear, *submit, *cancel, *combo;
		/*WindowApp();
		~WindowApp();*/
		void setfName(string);
		void setlName(string);
		void setMajor(string);
		void setGpa(string);
		void setEmail(string);
		void setYear(string);
		void setCgpa(string);
		void setStuNum(string);

		string getfName();
		string getlName();
		string getMajor();
		string getGpa();
		string getEmail();
		string getYear();
		string getStuNum();
		string getCgpa();
	private:
		string strfName, strlName, strMajor, strGpa, strCgpa, strEmail, strYear, strStuNum;
		
				
};

#endif
