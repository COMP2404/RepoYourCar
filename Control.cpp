#include "Control.h"

//`pkg-config gtkmm-3.0 --cflags --libs`

using namespace std;

int Control::makeApplication(GtkWidget *widget, WindowApp *theApp)
{
	/////////////////////////////////////////////////
	//--Creates new frame and adds it onto the window---//
	/////////////////////////////////////////////////

	//theApp->appFrame = gtk_fixed_new();
	//gtk_container_add(GTK_CONTAINER(theApp->frame), theApp->appFrame);


	/////////////////////////////////////////////////
	//--Creates text Boxes and submit\cancel buttons---//
	/////////////////////////////////////////////////
	theApp->fName = gtk_entry_new();
	theApp->lName = gtk_entry_new();
	theApp->major = gtk_entry_new();
	theApp->gpa = gtk_entry_new();
	theApp->email = gtk_entry_new();
	theApp->year = gtk_entry_new();
	theApp->submit = gtk_button_new_with_label("Submit");
	theApp->cancel = gtk_button_new_with_label("Cancel");
	
	/////////////////////////////////////////////////
	//--Puts text boxes onto the new frame---------//
	/////////////////////////////////////////////////
	gtk_window_resize(GTK_WINDOW(theApp->window), 400,600);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->fName, 150, 220);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lName, 150, 250);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->major, 150, 280);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->gpa, 150, 310);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->email, 150, 340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->year, 150, 370);

	/////////////////////////////////////////////////
	//--Puts labels onto the new frame---------//
	/////////////////////////////////////////////////
	theApp->lblfName = gtk_label_new("First Name :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblfName, 30, 220); 
	theApp->lbllName = gtk_label_new("Last Name :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lbllName, 30, 250);
	theApp->lblMajor = gtk_label_new("Major :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblMajor, 30, 280);
	theApp->lblGpa = gtk_label_new("GPA :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblGpa, 30, 310);
	theApp->lblEmail = gtk_label_new("Email Address :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblEmail, 30, 340);
	theApp->lblYear = gtk_label_new("Year :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblYear, 30, 370);

	/////////////////////////////////////////////////
	//--Puts buttons onto the new frame---------//
	/////////////////////////////////////////////////
	gtk_widget_set_size_request(theApp->submit, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->submit, 50, 500);
	gtk_widget_set_size_request(theApp->cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->cancel, 200, 500);

	/////////////////////////////////////////////////
	//--Show all widgets on new frame---------//
	/////////////////////////////////////////////////
	gtk_widget_show_all(theApp->appFrame);
	
	gtk_label_set_text(GTK_LABEL(theApp->label), "Please Enter Info Below");
	
  	return 0;
}

bool Control::errorCheck(string* course, string* first, string* last, string* mgpa, string* gpa, string* email, string* year, string* major){

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
	
	mg = atoi(mgpa->c_str());	
	cg = atoi(gpa->c_str());
	yr = atoi(year->c_str());	

	if(mg < 0 || mg > 12)
		good = false;
	if(cg < 0 || cg > 12)
		good = false;
	if(yr < 0 )
		good = false;

	bool ok = false;
	if(good) 
		ok = submit(course, first, last, mg, cg, email, yr, major);
	return ok;
}


void getInfo(WindowApp *theApp){
	//const gchar * s1 = gtk_entry_get_text(GTK_ENTRY(theApp->lName));
	//theApp->setfName("Hello");
	//const gchar *s2 = (theApp->getfName()).c_str();
	
	//gtk_entry_set_text(GTK_ENTRY(theApp->lName), s2);

	const gchar *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8;
	
	double c, g;
	int num;
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->fName));
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->lName));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->major));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->gpa));
	s5 = s4;        
        s6 = gtk_entry_get_text(GTK_ENTRY(theApp->email));
        s7 = gtk_entry_get_text(GTK_ENTRY(theApp->year));
	string string1(s1);
	string string2(s2);
	string string3(s3);
	string string4(s4);
	//string string5(s5);
	string string6(s6);
	string string7(s7);
	string string8(s8);
	
	//s8 will be student number
	//s8 = s7;
        /*
	
    	if (errorCheck(&s1,&s2,&s3,&s4,&s5,&s6,&s7, &s8))
	{
		//Create a new student
		c = atof(s4.c_str());
		g = atof(s5.c_str());
		num = atoi(s7.c_str());

//		Student joe(c,g,s1,s2,s6,s3,num,s8);
		Student *newStu = new Student(c, g, s1, s2, s6, s3, num, s8);
		
	//Use it to make an application
	Application *newApp = new Application(newStu, 1007, "CompSci", "Pending");
	}*/
	//submit(s
}


bool Control::submit(string* course, string* first, string* last, int mgpa, int gpa, string* email, int year, string* major){
	static int applicationNum = 1;

	Student* s = new Student(gpa, gpa, *first, *last, *email, *major, year);
	Application* a = new Application(s, applicationNum++, *course);
	Control::printApp(a);
	//if(!printApp(a))
	//	return false;
	return true;
}

bool Control::printApp(Application* app){
	ofstream outFile("Application.txt", ios::out);

  	if (!outFile) {
   		//ios::out<<"Could not open file"<<endl;
   		return false;
	}

	outFile << "\t\tAPPLICANTION FORM:\n" << endl;
	outFile << "Applying for TA for class: " << app->getCourse() << " Application id: " << app->getApplicationNumber() << endl;
	outFile << "======================APPLICANT INFORMATION======================="<<endl;
	outFile << "Applicant name: " << app->getApplicant()->getFirst() << " " << app->getApplicant()->getLast() << endl;
	outFile << "Applicant email: " << app->getApplicant()->getEmail() << endl;
	outFile << "Applicant student number: " << app->getApplicant()->getStudentNumber() << endl;
	
	return true;
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
	//gtk_window_set_default_size(GTK_WINDOW(theApp->window), 400, 200);
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
	g_signal_connect(theApp->window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	g_signal_connect(theApp->apply, "clicked", G_CALLBACK(Control::makeApplication), theApp);

	g_signal_connect(theApp->submit, "clicked", G_CALLBACK(Control::getInfo), theApp);

	//g_signal_connect(theApp->login, "clicked", G_CALLBACK(admin), theApp);

	gtk_main();
	return 0;
}
