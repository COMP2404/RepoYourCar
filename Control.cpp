#include "Control.h"
#include "Queue.h"
//`pkg-config gtkmm-3.0 --cflags --libs`

using namespace std;

int Control::makeApplication(GtkWidget *widget, WindowApp *theApp)
{
	/////////////////////////////////////////////////
	//--Creates new frame and adds it onto the window---//
	/////////////////////////////////////////////////
	
	
	
	
	
 	
	
	char text[MAX_BUF];
	string courses[800];

	ifstream inFile("courses.txt", ios::in);

	if (!inFile) {
		cout<<"Could not open file"<<endl;
		return 0;
	}	
	while (!inFile.eof()) {
		inFile.getline(text, MAX_BUF);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->combo), text);
	}
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->combo, 200, 200);
	/////////////////////////////////////////////////
	//--Creates text Boxes and submit\cancel buttons---//
	/////////////////////////////////////////////////
	//theApp->combo = combo;
	theApp->fName = gtk_entry_new();
	theApp->lName = gtk_entry_new();
	theApp->major = gtk_entry_new();
	theApp->gpa = gtk_entry_new();
	theApp->email = gtk_entry_new();
	theApp->year = gtk_entry_new();
	theApp->cgpa = gtk_entry_new();
	theApp->stuNum = gtk_entry_new();
	
	
	/////////////////////////////////////////////////
	//--Puts text boxes onto the new frame---------//
	/////////////////////////////////////////////////
	gtk_window_resize(GTK_WINDOW(theApp->window), 400,600);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->fName, 150, 280);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lName, 150, 310);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->major, 150, 340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->gpa, 150, 370);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->cgpa, 150, 400);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->email, 150, 430);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->year, 150, 460);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->stuNum, 150, 490);

	/////////////////////////////////////////////////
	//--Puts labels onto the new frame---------//
	/////////////////////////////////////////////////
	theApp->lblfName = gtk_label_new("First Name :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblfName, 30, 280); 
	theApp->lbllName = gtk_label_new("Last Name :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lbllName, 30, 310);
	theApp->lblMajor = gtk_label_new("Major :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblMajor, 30, 340);
	theApp->lblGpa = gtk_label_new("GPA :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblGpa, 30, 370);
	theApp->lblCgpa = gtk_label_new("CGPA :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblCgpa, 30, 400);
	theApp->lblEmail = gtk_label_new("Email Address :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblEmail, 30, 430);
	theApp->lblYear = gtk_label_new("Year :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblYear, 30, 460);
	theApp->lblstuNum = gtk_label_new("Student Number :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblstuNum, 30, 490);

	/////////////////////////////////////////////////
	//--Puts buttons onto the new frame---------//
	/////////////////////////////////////////////////
	gtk_widget_set_size_request(theApp->submit, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->submit, 50, 530);
	gtk_widget_set_size_request(theApp->cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->cancel, 200, 530);

	/////////////////////////////////////////////////
	//--Show all widgets on new frame---------//
	/////////////////////////////////////////////////
	gtk_widget_show_all(theApp->appFrame);
	
	gtk_label_set_text(GTK_LABEL(theApp->label), "Please Enter Info Below");
	
  	return 0;
}

bool Control::errorCheck(string* course, string* first, string* last, string* mgpa, string* gpa, string* email, string* year, string* major, string* stunum){

	bool good = true;
	int mg;
	int cg;
	int yr;
	if(course->length() == 0)
		good = false;
	if(first->length() == 0)
                good = false;
	if(last->length() == 0)
                good = false;
	if(mgpa->length() == 0)
                good = false;
	if(gpa->length() == 0)
                good = false;
	if(email->length() == 0)
                good = false;	
	if(year->length() == 0)
                good = false;
	if(major->length() == 0)
                good = false;
	if(stunum->length() == 0)
		good = false;
	
	mg = atoi(mgpa->c_str());	
	cg = atoi(gpa->c_str());
	yr = atoi(year->c_str());	

	if(mg < 0 || mg > 12)
		good = false;
	if(cg < 0 || cg > 12)
		good = false;
	if(yr < 0 )
		good = false;

	//bool ok = false;
	//if(good) 
		//ok = submit(course, first, last, mg, cg, email, yr, major, stunum);
	return good;
}


int Control::getInfo(GtkWidget *widget, WindowApp *theApp){
	

	const gchar *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
	double c, g;
	int num;
	s1 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(theApp->combo));
	if(s1==NULL)
		s1="no course specified";
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->fName));
	
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->lName));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->gpa));
	s5 = gtk_entry_get_text(GTK_ENTRY(theApp->cgpa));        
        s6 = gtk_entry_get_text(GTK_ENTRY(theApp->email));
        s7 = gtk_entry_get_text(GTK_ENTRY(theApp->year));
	s8 = gtk_entry_get_text(GTK_ENTRY(theApp->major));
	s9 = gtk_entry_get_text(GTK_ENTRY(theApp->stuNum));
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	string5 = (s5);
	string6 = (s6);
	string7 = (s7);
	string8 = (s8);
	string9 = (s9);
	
        
	
    	if (Control::errorCheck(&string1,&string2,&string3,&string4,&string5,&string6,&string7, &string8, &string9))
	{
		//Create a new student
		c = atof(s4);
		g = atof(s5);
		num = atoi(s7);

//		Student joe(c,g,s1,s2,s6,s3,num,s8);
		//Student *newStu = new Student(c, g, s1, s2, s6, s3, num, s8);
		
	//Use it to make an application
		//Application *newApp = new Application(newStu, 1007, "CompSci", "Pending");
		Control::submit(&string1,&string2,&string3,c,g,&string6,num, &string8, &string9);
		//submit(string*, string*, string*, int, int, string*, int, string*);
	}
	
	return 0;
}


bool Control::submit(string* course, string* first, string* last, int mgpa, int gpa, string* email, int year, string* major, string* stunum){
	static int applicationNum = 1;

	Student* s = new Student(gpa, mgpa, *first, *last, *email, *major, year, *stunum);
	Application *a;
	a = new Application(s, applicationNum++, *course, "PENDING");
	//Control::printApp(a);
	if(!a->printApp())
		return false;
	return true;
}

void Control::cancel(){
	exit(1);
}

void Control::loadApplications(){
	char text[80];

	ifstream inFile("Applications.txt", ios::in);

	int     a, cgpa, mgpa, y;
	string  c, s, f, l, e, m, i;

  	if (!inFile) {
    	//cout<<"Could not open file"<<endl;
    	return;
  	}

	while (!inFile.eof()) {
		//read an entire application
		inFile.getline(text, MAX_BUF);
		a = atoi(text);
		inFile.getline(text, MAX_BUF);
		c = text;
		inFile.getline(text, MAX_BUF);
		s = text;
		inFile.getline(text, MAX_BUF);
		cgpa = atoi(text);
		inFile.getline(text, MAX_BUF);
		mgpa = atoi(text);
		inFile.getline(text, MAX_BUF);
		f = text;
		inFile.getline(text, MAX_BUF);
		l = text;
		inFile.getline(text, MAX_BUF);
		e = text;
		inFile.getline(text, MAX_BUF);
		m = text;
		inFile.getline(text, MAX_BUF);
		y = atoi(text);
		inFile.getline(text, MAX_BUF);
		i = text;

		//Now initialise an application
		Student *stu = new Student(cgpa, mgpa, f, l, e, m, y, i);
		Application *newApp = new Application(stu, a, c, s);
		
		applicationList.pushBack(applicationList.createNode(newApp));
				
  	}
 
}


void Control::relatedCourses1(GtkWidget *widget, WindowApp *theApp){


	//resize the window to accomodate the new widgets
	gtk_window_resize(GTK_WINDOW(theApp->window), 800,600);
	
	
	/////////////////////////////////////////////////////
	//-----------Put Labels on Entries---------------////
	/////////////////////////////////////////////////////
	
	theApp->ei_lblRelatedCourse = gtk_label_new("Related Course :");
	theApp->ei_lblTerm = gtk_label_new("Term :");
	theApp->ei_lblYear = gtk_label_new("Year :");
	theApp->ei_lblFinalGrade = gtk_label_new("Final Grade :");

	/////////////////////////////////////////////////////
	//-----------Attach Labels To Frame -------------////
	/////////////////////////////////////////////////////
	
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblRelatedCourse, 400, 280);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblTerm, 400, 310);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblYear, 400,340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblFinalGrade, 400, 370);


	/////////////////////////////////////////////////////
	//-----------Attach Entries To Frame -------------////
	/////////////////////////////////////////////////////
	
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_relatedCourse1, 550, 280);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_term1, 550, 310);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_year1, 550, 340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_finalGrade, 550, 370);



	/////////////////////////////////////////////////////
	//-----------Attach Buttons To Frame -------------////
	/////////////////////////////////////////////////////
	gtk_widget_set_size_request(theApp->ei_continue, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_continue, 450, 430);
	
	gtk_widget_set_size_request(theApp->ei_repeat, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_repeat, 550, 430);
	gtk_widget_show_all(theApp->appFrame);


	/////////////////////////////////////////////////////
	//-----------Make Buttons Not Clickable-------------////
	/////////////////////////////////////////////////////

	gtk_widget_set_sensitive(theApp->ei_continue, FALSE);
	gtk_widget_set_sensitive(theApp->ei_repeat, FALSE);
	

}
void Control::quickCheck(GtkWidget *widget, WindowApp *theApp){
	

	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
	
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relatedCourse1));
	
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_year1));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_term1));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_finalGrade));        
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""){
		gtk_widget_set_sensitive(theApp->ei_continue, TRUE);
		gtk_widget_set_sensitive(theApp->ei_repeat, TRUE);
	}
}

void Control::relatedCourses2(GtkWidget *widget, WindowApp *theApp){

	/////////////////////////////////////////////////////
	//-----------Remove Old Text Entries\Labels------////
	/////////////////////////////////////////////////////
	
	gtk_widget_destroy(theApp->ei_relatedCourse1);
	gtk_widget_destroy(theApp->ei_term1);
	gtk_widget_destroy(theApp->ei_year1);
	gtk_widget_destroy(theApp->ei_finalGrade);

	gtk_widget_destroy(theApp->ei_lblFinalGrade);
	gtk_widget_destroy(theApp->ei_continue);



	/////////////////////////////////////////////////////
	//-----------New Buttons, labels and entries------////
	/////////////////////////////////////////////////////
	theApp->ei_lblSupervisor = gtk_label_new("Supervisor :");	
	gtk_widget_set_size_request(theApp->ei_continue2, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_continue2, 450, 430);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_relatedCourse2, 550, 280);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_term2, 550, 310);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_year2, 550, 340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_supervisor, 550, 370);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblSupervisor, 400, 370);
	gtk_widget_show_all(theApp->appFrame);

}


void Control::workExperience(GtkWidget *widget, WindowApp *theApp){
	
	/////////////////////////////////////////////////////
	//-----------Remove Old Text Entries------////
	/////////////////////////////////////////////////////
	gtk_widget_destroy(theApp->ei_relatedCourse2);
	gtk_widget_destroy(theApp->ei_term2);
	gtk_widget_destroy(theApp->ei_year2);
	gtk_widget_destroy(theApp->ei_supervisor);	
	
	/////////////////////////////////////////////////////
	//-----------Remove Old Labels-------------------////
	/////////////////////////////////////////////////////
	gtk_widget_destroy(theApp->ei_lblRelatedCourse);
	gtk_widget_destroy(theApp->ei_lblSupervisor);
	gtk_widget_destroy(theApp->ei_lblTerm);
	gtk_widget_destroy(theApp->ei_lblYear);
	gtk_widget_destroy(theApp->ei_continue2);


	


	/////////////////////////////////////////////////////
	//-----------New Buttons, labels and entries------////
	/////////////////////////////////////////////////////

	theApp->ei_lblRelevantWork = gtk_label_new("Relevant Work :");
	theApp->ei_lblDuration = gtk_label_new("Duration :");
	theApp->ei_lblStartDate = gtk_label_new("Start Date :");
	theApp->ei_lblEndDate = gtk_label_new("End Date :");
	theApp->ei_lblResponsabilities = gtk_label_new("Responsabilities :");
	
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblRelevantWork, 400, 280);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblResponsabilities, 400, 310);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblDuration, 400,340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblStartDate, 400, 370);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblEndDate, 400, 400);
	
	gtk_widget_set_size_request(theApp->ei_finish, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_finish, 450, 430);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_relevantWork, 550, 280);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_responsabilities, 550, 310);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_duration, 550, 340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_startDate, 550, 370);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_endDate,550, 400);
	gtk_widget_show_all(theApp->appFrame);
}




int Control::createWindow(int argc, char** argv)
{
	/////////////////////////////////////////////////////
	//-----------Declaration of all the widgets------////
	/////////////////////////////////////////////////////
	
	WindowApp *theApp = new WindowApp();

	// initialize GTK+
	gtk_init(&argc, &argv);


	/////////////////////////////////////////////////////
	//-----------Create the window ------------------////
	/////////////////////////////////////////////////////
	



	theApp->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(theApp->window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(theApp->window), 400, 200);
	gtk_window_set_title(GTK_WINDOW(theApp->window), "Application Center");
	

	/////////////////////////////////////////////////////
	//-----------Add frame onto window---------------////
	/////////////////////////////////////////////////////
	theApp->appFrame = gtk_fixed_new();

	gtk_container_add(GTK_CONTAINER(theApp->window), theApp->appFrame);


	/////////////////////////////////////////////////////g_signal_connect_data: assertion `c_handler != NULL' failed
	//Make the application button and add to frame---////
	/////////////////////////////////////////////////////
	theApp->apply = gtk_button_new_with_label("Apply");
	gtk_widget_set_size_request(theApp->apply, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->apply, 50, 20);

	/////////////////////////////////////////////////////
	//------Make the login button and add to frame---////
	/////////////////////////////////////////////////////
	theApp->login = gtk_button_new_with_label("Login");
	gtk_widget_set_size_request(theApp->login, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->login, 50, 80);

	
	/////////////////////////////////////////////////////
	//------Create the Extra Info Text Boxes for Later---////
	/////////////////////////////////////////////////////
	
	//part 1
	theApp->ei_relatedCourse1 = gtk_entry_new();
	theApp->ei_term1= gtk_entry_new();
	theApp->ei_year1 = gtk_entry_new();
	theApp->ei_finalGrade = gtk_entry_new();

	//part2
	theApp->ei_relatedCourse2 = gtk_entry_new();
	theApp->ei_term2= gtk_entry_new();
	theApp->ei_year2 = gtk_entry_new();
	theApp->ei_supervisor = gtk_entry_new();

	//part 3
	theApp->ei_relevantWork = gtk_entry_new();
	theApp->ei_responsabilities = gtk_entry_new();
	theApp->ei_duration= gtk_entry_new();
	theApp->ei_startDate = gtk_entry_new();
	theApp->ei_endDate = gtk_entry_new();



	/////////////////////////////////////////////////////
	//------Create All Buttons and Combo Box -----////
	/////////////////////////////////////////////////////

	//initial
	theApp->submit = gtk_button_new_with_label("Submit");
	theApp->cancel = gtk_button_new_with_label("Cancel");
	theApp->combo =  gtk_combo_box_text_new();
	
	//part 1
	theApp->ei_continue = gtk_button_new_with_label("Continue");
	theApp->ei_repeat = gtk_button_new_with_label("Add Another");
	
	//part 2
	theApp->ei_continue2 = gtk_button_new_with_label("Continue");

	//part 3
	theApp->ei_finish = gtk_button_new_with_label("Finish");
	
	
	/////////////////////////////////////////////////////
	//------Make the Prompt Label and add to frame---////
	/////////////////////////////////////////////////////
	theApp->label = gtk_label_new("Click Apply to Choose Your Courses");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->label, 150, 58); 

	/////////////////////////////////////////////////////
	//----------Show all the widgets on the window---////
	/////////////////////////////////////////////////////
	gtk_widget_show_all(theApp->window);



	/////////////////////////////////////////////////////
	//Connect signals with each button as well as close////
	/////////////////////////////////////////////////////
	g_signal_connect(theApp->window, "destroy", G_CALLBACK (Control::cancel), NULL);

	g_signal_connect(theApp->apply, "clicked", G_CALLBACK(Control::makeApplication), theApp);

	g_signal_connect(theApp->submit, "clicked", G_CALLBACK(Control::getInfo), theApp);
	
	g_signal_connect(theApp->cancel, "clicked", G_CALLBACK(Control::cancel), NULL);

	g_signal_connect(GTK_COMBO_BOX(theApp->combo), "changed", G_CALLBACK   (Control::relatedCourses1), theApp);

	g_signal_connect(theApp->ei_continue, "clicked", G_CALLBACK(Control::relatedCourses2), theApp);

	g_signal_connect(theApp->ei_continue2, "clicked", G_CALLBACK(Control::workExperience), theApp);

	//part 1
	g_signal_connect (theApp->ei_relatedCourse1, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_year1, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_term1, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_finalGrade, "changed", G_CALLBACK (Control::quickCheck), theApp);

	//part 2
	g_signal_connect (theApp->ei_relatedCourse2, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_year2, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_term2, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_supervisor, "changed", G_CALLBACK (Control::quickCheck), theApp);

	
	//g_signal_connect(theApp->ei_repeat, "clicked", G_CALLBACK(Control::makeApplication), theApp);
	
	//g_signal_connect(theApp->login, "clicked", G_CALLBACK(admin), theApp);

	gtk_main();
	return 0;
}
