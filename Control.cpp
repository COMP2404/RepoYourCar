#include "Control.h"

// http://stackoverflow.com/questions/2862509/free-object-widget-in-gtk
//`pkg-config gtkmm-3.0 --cflags --libs`

using namespace std;

int Control::makeApplication(GtkWidget *widget, WindowApp *theApp)
{
	/////////////////////////////////////////////////
	//--Creates new frame and adds it onto the window---//
	/////////////////////////////////////////////////
	
	
	theApp->combo =        gtk_combo_box_text_new();
	
	
	
 	
	
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
	if(s1 == NULL)
		s1 = "Unkown";
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


bool Control::submit(string* course, string* first, string* last, int cgpa, int gpa, string* email, int year, string* major, string* stunum){
	static int applicationNum = 1;

	Student* s = new Student(cgpa, gpa, *first, *last, *email, *major, year, *stunum);
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

int Control::freeMemory(GtkWidget *widget, WindowApp *theApp){
	gtk_widget_destroy(theApp->);
}

/*
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

*/

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
	

	theApp->submit = gtk_button_new_with_label("Submit");
	theApp->cancel = gtk_button_new_with_label("Cancel");
	
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

	//g_signal_connect(theApp->login, "clicked", G_CALLBACK(admin), theApp);

	gtk_main();
	return 0;
}
