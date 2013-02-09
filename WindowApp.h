#ifndef WINDOWAPP_H
#define WINDOWAPP_H
#include <iostream>
#include <gtk/gtk.h>
//#include <String.h>
using namespace std;
class WindowApp{
	public:
		GtkWidget *label, *window, *frame, *apply, *login, *appFrame, *fName, *lblfName, *lName, *lbllName, *major, *lblMajor, *gpa, *lblGpa, *cgpa, *lblCgpa, *stuNum,*lblstuNum, *email, *lblEmail, *year, *lblYear, *submit, *cancel, *combo, *ei_relatedCourse1, *ei_relatedCourse2, *ei_term1, *ei_term2, *ei_year1, *ei_year2, *ei_finalGrade, *ei_supervisor, *ei_relevantWork, *ei_responsabilities, *ei_duration, *ei_startDate, *ei_endDate, *ei_continue, *ei_repeat;
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
