#include "Control.h"

//#include "Queue.h"
//`pkg-config gtkmm-3.0 --cflags --libs`

using namespace std;
Application* apples;
int THIS_BUF = 1000;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//Error Window that will pop up
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Control::popWindow(string s, WindowApp *theApp){
	theApp->error_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(theApp->error_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(theApp->error_window), 400, 200);
	//gtk_window_resize(GTK_WINDOW(theApp->window), 600,300);
	gtk_window_set_title(GTK_WINDOW(theApp->error_window), "ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	
	theApp->error_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(theApp->error_window), theApp->error_frame);

	theApp->error_dismiss = gtk_button_new_with_label("Dismiss");
	gtk_widget_set_size_request(theApp->error_dismiss , 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->error_frame), theApp->error_dismiss , 100, 100);	
	const gchar* message;
	message = s.c_str();
	theApp->error_message = gtk_label_new(message);
	gtk_fixed_put(GTK_FIXED(theApp->error_frame), theApp->error_message, 10, 10); 


	gtk_widget_show_all(theApp->error_window);

	g_signal_connect(theApp->error_dismiss, "clicked", G_CALLBACK (Control::closePopWindow), theApp);
}

void Control::closePopWindow(GtkWidget *widget, WindowApp *theApp){
	gtk_widget_destroy(theApp->error_window);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//have the admin page come up
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Control::adminPage(GtkWidget *widget, WindowApp *theApp){

	theApp->admin_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(theApp->admin_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(theApp->admin_window), 400, 200);
	
	gtk_window_set_title(GTK_WINDOW(theApp->admin_window), "Admin Window");
	
	theApp->admin_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(theApp->admin_window), theApp->admin_frame);

	theApp->admin_viewSummary = gtk_button_new_with_label("View Summary Of Pending Applications");
	gtk_widget_set_size_request(theApp->admin_viewSummary, 150, 35);
	gtk_fixed_put(GTK_FIXED(theApp->admin_frame), theApp->admin_viewSummary , 100, 50);

	theApp->admin_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(theApp->admin_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->admin_frame), theApp->admin_cancel , 100, 150);
	
	gtk_widget_show_all(theApp->admin_window);

	g_signal_connect(theApp->admin_viewSummary, "clicked", G_CALLBACK (Control::viewSummary), theApp);
	g_signal_connect(theApp->admin_cancel, "clicked", G_CALLBACK (Control::closeAdminPage), theApp);
	
	

	

}

void Control::closeAdminPage(GtkWidget *widget, WindowApp *theApp){
	
	gtk_widget_destroy(theApp->admin_window);
}

void Control::studentPage(GtkWidget *widget, WindowApp *theApp){
	theApp->student_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(theApp->student_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(theApp->student_window), 400, 200);
	
	gtk_window_set_title(GTK_WINDOW(theApp->student_window), "Student Window");
	
	theApp->student_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(theApp->student_window), theApp->student_frame);

	theApp->student_edit = gtk_button_new_with_label("Edit Application");
	gtk_widget_set_size_request(theApp->student_edit , 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->student_frame), theApp->student_edit  , 20, 50);

	theApp->student_apply = gtk_button_new_with_label("New Application");
	gtk_widget_set_size_request(theApp->student_apply, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->student_frame), theApp->student_apply , 150, 50);

	theApp->student_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(theApp->student_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->student_frame), theApp->student_cancel , 60, 150);
	
	gtk_widget_show_all(theApp->student_window);

	g_signal_connect(theApp->student_apply, "clicked", G_CALLBACK (Control::makeApplication), theApp);
	g_signal_connect(theApp->student_cancel, "clicked", G_CALLBACK (Control::closeStudentPage), theApp);
}

void Control::closeStudentPage(GtkWidget *widget, WindowApp *theApp){
	gtk_widget_destroy(theApp->student_window);
}

void Control::prepareNewStudentApp(GtkWidget *widget, WindowApp *theApp){
	
	
	
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//View Summary of Pending Apps
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Control::viewSummary(GtkWidget *widget, WindowApp *theApp){
	gtk_widget_destroy(theApp->admin_window);
	gtk_widget_destroy(theApp->appFrame);
	theApp->appFrame = gtk_fixed_new();
	
	
	theApp->admin_combo =  gtk_combo_box_text_new();
	
	theApp->admin_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(theApp->admin_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->admin_cancel , 100, 150);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->admin_combo, 50, 50);
	theApp->summary_combo =  gtk_combo_box_text_new();
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->summary_combo, 50, 100);
	
	gtk_container_add(GTK_CONTAINER(theApp->window), theApp->appFrame);
	
	gtk_widget_show_all(theApp->window);

	

	char text[THIS_BUF];
	string courses[800];



	ifstream inFile("courses.txt", ios::in);

	if (!inFile) {
		cout<<"Could not open file"<<endl;
		exit(1);
	}	
	while (!inFile.eof()) {
		inFile.getline(text, THIS_BUF);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->admin_combo), text);
	}
	g_signal_connect(theApp->admin_cancel, "clicked", G_CALLBACK (Control::submitToMain), theApp);
	g_signal_connect(GTK_COMBO_BOX(theApp->admin_combo), "changed", G_CALLBACK   (Control::updateCombo), theApp);
}

void Control::updateCombo(GtkWidget *widget, WindowApp *theApp){
	
	//gtk_widget_destroy(theApp->summary_combo);

	
	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(theApp->summary_combo));
	const gchar* theCourse;
 	theCourse = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(theApp->admin_combo));
	string courseString;
	courseString = (theCourse);
	
	AppQueue* qCopy = theApp->appQueue.getPendingList(courseString);//call copy constructor
	
	//char s1[100], s2[100], s3[100], s4[100], s5[100], s6[100], s7[100];
	string s1,s2,s3,s4,s5,s6,s7 ,s8;
	
	//int length = qCopy->size();
	
	char theInput[200];
	string input[100];//string array for each Application
	
	AppQueue::AppNode* tmpNode = qCopy->popFront();
	 int i = 0;
	//for(int i=0; i<length; i++){
	while(tmpNode != NULL){
		
		if(tmpNode->data != NULL){
			std::stringstream ss1; 
			std::stringstream ss2; 
			std::stringstream ss3; 
			
			s1 = tmpNode->data->getStuFirst();
			cout << s1 << endl;
			s2 = tmpNode->data->getStuLast();
			 
			ss1 << tmpNode->data->getStuYrStanding();
			s3 = ss1.str();
			s4 = tmpNode->data->getStuMajor();
			ss2 << tmpNode->data->getStuCGPA();
			s5 = ss2.str();
			s6 = tmpNode->data->getStuEmail();
			s7 = tmpNode->data->getStuID();
			ss3 << tmpNode->data->getStuMGPA();
			s8 = ss3.str();
			
		 
			input[i] = "Student: " + s1 + " " + s2 + "   in Year: " + s3 + "    |   Major: " + s4 + "  |  CGPA: " + s5  + "   |  GPA:  " + s8 + "   |  Email: " + s6 + "   |   ID: " + s7;
			//theInput = input[i];
			strcpy(theInput,input[i].c_str());
			gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->summary_combo), theInput);
			i++;
			tmpNode = qCopy->popFront();
		}
		else{
			tmpNode = NULL;
		}
		
	}
	
	
	gtk_widget_show_all(theApp->window);

}







//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
							//make the application
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Control::makeApplication(GtkWidget *widget, WindowApp *theApp)
{
	/////////////////////////////////////////////////
	//--Creates new frame and adds it onto the window---//
	/////////////////////////////////////////////////
 	gtk_widget_destroy(theApp->student_window);
	gtk_widget_destroy(theApp->appFrame);
	theApp->appFrame = gtk_fixed_new();
	gtk_window_resize(GTK_WINDOW(theApp->window), 400,600);
	

	theApp->combo =  gtk_combo_box_text_new();
	theApp->fName = gtk_entry_new();
	theApp->lName = gtk_entry_new();
	theApp->major = gtk_entry_new();
	theApp->gpa = gtk_entry_new();
	theApp->email = gtk_entry_new();
	theApp->year = gtk_entry_new();
	theApp->cgpa = gtk_entry_new();
	theApp->stuNum = gtk_entry_new();


	
	char text[THIS_BUF];
	string courses[800];

	ifstream inFile("courses.txt", ios::in);

	if (!inFile) {
		cout<<"Could not open file"<<endl;
		return 0;
	}	
	while (!inFile.eof()) {
		inFile.getline(text, THIS_BUF);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->combo), text);
	}
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->combo, 200, 200);
	/////////////////////////////////////////////////
	//--Creates text Boxes and submit\cancel buttons---//
	/////////////////////////////////////////////////
	//theApp->combo = combo;
	
	
	
	/////////////////////////////////////////////////
	//--Puts text boxes onto the new frame---------//
	/////////////////////////////////////////////////
	
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

	
	theApp->submit = gtk_button_new_with_label("Submit");
	theApp->cancel = gtk_button_new_with_label("Cancel");

	
	gtk_widget_set_size_request(theApp->submit, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->submit, 50, 530);
	gtk_widget_set_size_request(theApp->cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->cancel, 200, 530);

	theApp->info_label = gtk_label_new("Please Enter Info Below");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->info_label, 150, 58);
	gtk_container_add(GTK_CONTAINER(theApp->window), theApp->appFrame);
	/////////////////////////////////////////////////
	//--Show all widgets on new frame---------//
	/////////////////////////////////////////////////
	gtk_widget_show_all(theApp->window);

	 
	

	g_signal_connect(theApp->submit, "clicked", G_CALLBACK(Control::getInfo), theApp);
	
	g_signal_connect(theApp->cancel, "clicked", G_CALLBACK(Control::submitToMain), theApp);
	g_signal_connect(GTK_COMBO_BOX(theApp->combo), "changed", G_CALLBACK   (Control::relatedCourses1), theApp);
  	return 0;
}







//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
						//main form error checking
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Control::errorCheck(string* course, string* first, string* last, string* mgpa, string* gpa, string* email, string* year, string* major, string* stunum, WindowApp *theApp){

	bool good = true;
	int mg;
	int cg;
	int yr;
	unsigned invalidF = (*first).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'");
	unsigned invalidL = (*last).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'");
	string stringToFind1("@carleton.ca");
	unsigned validChars1 = (*email).find(stringToFind1);
	unsigned invalidE = (*major).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ- ");
	unsigned validStu = (*stunum).find_first_not_of("0123456789");
	unsigned validGPA = (*gpa).find_first_not_of("0123456789");
	unsigned validCGPA = (*mgpa).find_first_not_of("0123456789");
	  
	mg = atoi(mgpa->c_str());	
	cg = atoi(gpa->c_str());
	yr = atoi(year->c_str());

	if(course->length() == 0){
		cout << "Course is empty" <<endl;
		Control::popWindow("Choose a course", theApp);
		return !good;
		
	}
		
	else if(first->length() == 0){
		cout << "First name is empty" <<endl;
		Control::popWindow("First name is empty", theApp);
		return !good;
	}
                
		
	else if(last->length() == 0){
		cout << "Last Name is Empty" <<endl;
		Control::popWindow("Last Name is Empty", theApp);
		return !good;
	}
                
	else if(mgpa->length() == 0){
		cout << "MGPA is empty" <<endl;
		Control::popWindow("MGPA is empty", theApp);
		return !good;
	}
                
	else if(gpa->length() == 0){
		cout << "GPA is empty" <<endl;
		Control::popWindow("GPA is empty", theApp);
		return !good;
	}
                
	else if(email->length() == 0){
		cout << "Email is Empty" <<endl;
		Control::popWindow("Email is Empty", theApp);
		return !good;
	}
                	
	else if(year->length() == 0){
		cout << "year is Empty" <<endl;
		Control::popWindow("year is Empty", theApp);
		return !good;
	}
               
	else if(major->length() == 0){
		cout << "Major is Empty" <<endl;
		Control::popWindow("Major is Empty", theApp);
		return !good;
	}
                
	else if(stunum->length() == 0){
		cout << "Student Number is Empty" <<endl;
		Control::popWindow("Student Number is Empty", theApp);
		return !good;
	}

	else if (validGPA != string::npos) {
		cout << "You entered a non-alphabetical character, " << (*gpa)[validGPA];
		cout << ", at position " << validGPA << endl;
			
		Control::popWindow("Please Enter a valid GPA", theApp);
		return !good;
		
   	}
	else if (validCGPA != string::npos) {
		cout << "You entered a non-alphabetical character, " << (*mgpa)[validCGPA];
		cout << ", at position " << validCGPA << endl;
			
		Control::popWindow("Please Enter a valid CGPA", theApp);
		return !good;
		
   	}
	
		
	else if(mg < 0 || mg > 12){
		Control::popWindow("Enter a GPA between 0 and 12", theApp);
		return !good;
	}
	else if(cg < 0 || cg > 12){
		Control::popWindow("Enter a CGPA between 0 and 12", theApp);
		return !good;
	}
	else if (yr < 1 || yr > 4) {
		cout << "Year standing must be either 1, 2, 3, or 4. Please try again" << endl; 
		Control::popWindow("Year standing must be either 1, 2, 3, or 4.", theApp);
		return !good;
	}
	
	
  
	else if (invalidF != string::npos) {
		cout << "You entered a non-alphabetical character, " << (*first)[invalidF];
		cout << ", at position " << invalidF << endl;
			
		Control::popWindow("You entered a non-alphabetical character in first name", theApp);
		return !good;
		
   	}


	
  
	else if (invalidL != string::npos) {
		cout << "You entered a non-alphabetical character, " << (*last)[invalidL];
		cout << ", at position " << invalidL << endl;
		Control::popWindow("You entered a non-alphabetical character in last name", theApp);
		return !good;
   	}


	

	else if (validChars1 == string::npos) {
		cout << "Invalid e-mail address. Please enter your Carleton e-mail address (yourname@carleton.ca) to register." << endl;
		Control::popWindow("Invalid e-mail address. Please enter your Carleton e-mail address (yourname@carleton.ca) to register.", theApp);
		return !good;
	}

	
  
	else if (invalidE != string::npos) {
		cout << "You entered a non-alphabetical character, " << (*major)[invalidE];
		cout << ", at position " << invalidE << endl;
		Control::popWindow("You entered a non-alphabetical character in major", theApp);
		return !good;
   	 }


	
	else if (validStu != string::npos) {
		cout << "You entered a character which is not a number between 0-9: " << (*stunum)[validStu];
		cout << ", at position " << validStu << "Please re-enter your student number." << endl;
		Control::popWindow("Your student number contains invalid characters", theApp);
		return !good;
    	}

	else if ((*stunum).length() != 9) {
		cout << "A valid student number has exactly 9 characters. Please re-enter your student number." << endl;
		Control::popWindow("A valid student number has exactly 9 characters.", theApp);
		return !good;
	}
	
	cout << "Its getting to here" << endl;


		

	

	return good;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
					//get info gets content from main text boxes
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int Control::getInfo(GtkWidget *widget, WindowApp *theApp){
	

	const gchar *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
	double c, g;
	int num;
	s1 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(theApp->combo));
	if(s1==NULL)
		s1="";
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
	
        
	
    	if (Control::errorCheck(&string1,&string2,&string3,&string4,&string5,&string6,&string7, &string8, &string9, theApp))
	{
		//Create a new student
		c = atof(s4);
		g = atof(s5);
		num = atoi(s7);




		/////////////////////////////////////////////////////
		//-----------Create new submission window -------////
		/////////////////////////////////////////////////////

		theApp->submitWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_position(GTK_WINDOW(theApp->submitWindow), GTK_WIN_POS_CENTER);
	
		gtk_window_set_default_size(GTK_WINDOW(theApp->submitWindow), 250, 100);
		gtk_window_set_title(GTK_WINDOW(theApp->submitWindow), "Submit Page");
	
	

		/////////////////////////////////////////////////////
		//-----------Add frame onto window---------------////
		/////////////////////////////////////////////////////
		theApp->submitFrame = gtk_fixed_new();
	

		gtk_container_add(GTK_CONTAINER(theApp->submitWindow), theApp->submitFrame);

		//submission page
		theApp->submitFinish = gtk_button_new_with_label("Finish");
		theApp->submitRepeat = gtk_button_new_with_label("Make Another");

	
		gtk_widget_set_size_request(theApp->submitFinish, 80, 35);
		gtk_fixed_put(GTK_FIXED(theApp->submitFrame), theApp->submitFinish, 30, 20);

	
		gtk_widget_set_size_request(theApp->submitRepeat, 80, 35);
		gtk_fixed_put(GTK_FIXED(theApp->submitFrame), theApp->submitRepeat, 150, 20);

		gtk_widget_show_all(theApp->submitWindow);

		g_signal_connect (theApp->submitFinish, "clicked", G_CALLBACK (Control::killSubmitWindow), theApp);
		g_signal_connect (theApp->submitRepeat, "clicked", G_CALLBACK (Control::submitToRepeat), theApp);

		Control::submit(&string1,&string2,&string3,c,g,&string6,num, &string8, &string9, theApp);
		
		//submit(string*, string*, string*, int, int, string*, int, string*);
	}
	
	return 0;
}

void Control::killSubmitWindow(GtkWidget *widget, WindowApp *theApp){
	gtk_widget_destroy(theApp->submitWindow);
	submitToMain(widget,theApp);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//submit application once error checking is done

//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Control::submit(string* course, string* first, string* last, int mgpa, int gpa, string* email, int year, string* major, string* stunum, WindowApp *theApp){
	static int applicationNum = 1;

	Student* s = new Student(gpa, mgpa, *first, *last, *email, *major, year, *stunum);
	//theApp->studentRepeat = s;

	Application *a = new Application(s, applicationNum++, *course, "PENDING");
	a->setRelatedCourses(theApp->cQRelated);
	a->setRelatedTAPositions(theApp->cQTa);
	a->setRelatedWorkEXP(theApp->jQRelated);
	
	theApp->studentApp = a;
	theApp->appQueue.pushBack(theApp->appQueue.createNode(a));
	//theApp->appQueue.isEmpty();
	//apples = a;

	//Control::printApp(a);
	if(!a->printApp())
		return false;

	
	return true;
}

void Control::cancel(){
	exit(1);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
				//load the applications from a file
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Control::loadApplications(){
	char text[80];

	ifstream inFile("Applications.txt", ios::in);

	//Variables used to build an application
	int     a, cgpa, mgpa, y;
	string  c, s, f, l, e, m, i;
	CourseQueue *aCourseQueue = new CourseQueue();
	CourseQueue *bCourseQueue = new CourseQueue();
	JobQueue *jQueue = new JobQueue();	

	//Varibles used to build a course
	int cYear;
	string cSuper, cTitle, cTerm;	

	//Variables used to build a job
	string jTitle, jDuration, jStart, jEnd;
	string anArray[100];
	
  	if (!inFile) {
    		cout<<"Could not open file"<<endl;
    		exit(1);
  	}
	string wtf = "relatedONE";
	while (!inFile.eof()) {
		//read an entire application
		inFile.getline(text, THIS_BUF);
		cout << "got this text: " << text << endl;
		a = atoi(text);
		inFile.getline(text, THIS_BUF);
		cout << "got this text: " << text << endl;
		c = text;
		inFile.getline(text, THIS_BUF);
		cout << "got this text: " << text << endl;
		s = text;
		inFile.getline(text, THIS_BUF);
		cout << "got this text: " << text << endl;
		cgpa = atoi(text);
		inFile.getline(text, THIS_BUF);
		cout << "got this text: " << text << endl;
		mgpa = atoi(text);
		inFile.getline(text, THIS_BUF);
		cout << "got this text: " << text << endl;
		f = text;
		inFile.getline(text, THIS_BUF);
		cout << "got this text: " << text << endl;
		l = text;
		inFile.getline(text, THIS_BUF);
		cout << "got this text: " << text << endl;
		e = text;
		inFile.getline(text, THIS_BUF);
		cout << "got this text: " << text << endl;
		m = text;
		inFile.getline(text, THIS_BUF);
		cout << "got this text: " << text << endl;
		y = atoi(text);
		inFile.getline(text, THIS_BUF);
		cout << "got this text: " << text << endl;
		i = text;

		//read the related courses
		cout << "SLEEPING" << endl;
		sleep(1);
		cout << "READING RELATED COURSES " << endl;
		while (1){ //untill you get to the TA positions
			inFile.getline(text, THIS_BUF);
			cout << "TEXT IT GOT, BREAKING ON 'RELATED TA POSITIONS': " << text << endl;
			sleep(1);
			if(strcmp(text, "RELATED TA POSITIONS") == 0)
			{
				break;
				cout << "breaking..." << endl;
			}
			cTitle = text;

			if(strcmp(text, "relatedONE") == 0)
			{
				cout << "wtf..." << endl;
			}

			cout << "SHOULD BE COURSE TITLE: " << cTitle << endl;
			inFile.getline(text, THIS_BUF);
			cout << "SHOULD BE FINAL GRADE: " << text << endl;
			cSuper = text;
			inFile.getline(text, THIS_BUF);
			cout << "SHOULD BE YEAR: " << text << endl;			
			cYear = atoi(text);
			inFile.getline(text, THIS_BUF);
			cout << "SHOULD BE TERM: " << text << endl;
			cTerm = text;
			cout << "CREATING COURSE AND PUSHING: " << endl;
			//make a course with the information and "N/A" supervisor
			Course *cor = new Course(cTitle, cYear, cTerm, "N/A", cSuper);
			cout << "COURSE CREATED " << endl;
			cout << "NOW PUSHING " << endl;
			aCourseQueue->pushBack(aCourseQueue->createNode(cor));	
			cout << "DONE" << endl;
		sleep(1);		
		}

		//read the related TA positions
		while (1){
			inFile.getline(text, THIS_BUF);
			if(strcmp(text, "WORK EXP") ==0)
			{
				break;
				cout << "breaking..." << endl;
			}
			cTitle = text;
			inFile.getline(text, THIS_BUF);
			cSuper = text;
			inFile.getline(text, THIS_BUF);
			cYear = atoi(text);
			inFile.getline(text, THIS_BUF);
			cTerm = text;
			//make a course with the information and "N/A" grade
			Course *bcor = new Course(cTitle, cYear, cTerm, cSuper, "N/A");
			bCourseQueue->pushBack(bCourseQueue->createNode(bcor));	
			
		}
		//read the related Work EXP
		while (1){
			inFile.getline(text, THIS_BUF);
			if(strcmp(text, "******") ==0)
			{
				break;
				cout << "breaking..." << endl;
			}
			jTitle = text;
			inFile.getline(text, THIS_BUF);
			jDuration = text;
			inFile.getline(text, THIS_BUF);
			jStart = text;
			inFile.getline(text, THIS_BUF);
			jEnd = text;
			

			Job *aJob = new Job(jTitle, "NONE", jDuration, jStart, jEnd);
			jQueue->pushBack(jQueue->createNode(aJob));
			
		}

		//NOW initialise an application

		Student *stu = new Student(cgpa, mgpa, f, l, e, m, y, i);

		Application *newApp = new Application(stu, a, c, s);
		newApp->setRelatedCourses(aCourseQueue);
		newApp->setRelatedTAPositions(bCourseQueue);
		newApp->setRelatedWorkEXP(jQueue);
		applicationList.pushBack(applicationList.createNode(newApp));
		
			
  	}
 
}









//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
				//set up the Sets of related Data
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Control::relatedCourses1(GtkWidget *widget, WindowApp *theApp){


	//resize the window to accomodate the new widgets
	gtk_window_resize(GTK_WINDOW(theApp->window), 800,600);
	theApp->extra = true;
	theApp->page = 1;
	
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
	
	//part 1
	theApp->ei_relatedCourse1 = gtk_entry_new();
	theApp->ei_term1= gtk_entry_new();
	theApp->ei_year1 = gtk_entry_new();
	theApp->ei_finalGrade = gtk_entry_new();
	
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_relatedCourse1, 550, 280);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_term1, 550, 310);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_year1, 550, 340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_finalGrade, 550, 370);



	/////////////////////////////////////////////////////
	//-----------Attach Buttons To Frame -------------////
	/////////////////////////////////////////////////////

	theApp->ei_continue = gtk_button_new_with_label("Continue");
	theApp->ei_repeat = gtk_button_new_with_label("Add Another");

	gtk_widget_set_size_request(theApp->ei_continue, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_continue, 450, 430);
	
	gtk_widget_set_size_request(theApp->ei_repeat, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_repeat, 550, 430);
	gtk_widget_show_all(theApp->appFrame);


	/////////////////////////////////////////////////////
	//-----------Make Buttons Not Clickable-------------////
	/////////////////////////////////////////////////////

	gtk_widget_set_sensitive(theApp->ei_continue, FALSE);
	gtk_widget_set_sensitive(theApp->submit, FALSE);
	gtk_widget_set_sensitive(theApp->ei_repeat, FALSE);
	gtk_widget_set_sensitive(theApp->combo, FALSE);

	g_signal_connect (theApp->ei_relatedCourse1, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_year1, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_term1, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_finalGrade, "changed", G_CALLBACK (Control::quickCheck), theApp);





	g_signal_connect(theApp->ei_continue, "clicked", G_CALLBACK(Control::moveOn), theApp);
	

	g_signal_connect(theApp->ei_repeat, "clicked", G_CALLBACK(Control::addAnother), theApp);
	

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
	gtk_widget_destroy(theApp->ei_repeat);

	theApp->page = 2;

	//part2
	theApp->ei_relatedCourse2 = gtk_entry_new();
	theApp->ei_term2= gtk_entry_new();
	theApp->ei_year2 = gtk_entry_new();
	theApp->ei_supervisor = gtk_entry_new();


	/////////////////////////////////////////////////////
	//-----------New Buttons, labels and entries------////
	/////////////////////////////////////////////////////
	theApp->ei_lblSupervisor = gtk_label_new("Supervisor :");

	theApp->ei_repeat2 = gtk_button_new_with_label("Add Another");
	
	
	//part 2
	theApp->ei_continue2 = gtk_button_new_with_label("Continue");

	

	
	gtk_widget_set_size_request(theApp->ei_continue2, 80, 35);

	gtk_widget_set_size_request(theApp->ei_repeat2, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_repeat2, 550, 430);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_continue2, 450, 430);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_relatedCourse2, 550, 280);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_term2, 550, 310);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_year2, 550, 340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_supervisor, 550, 370);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblSupervisor, 400, 370);
	gtk_widget_set_sensitive(theApp->ei_continue2, FALSE);
	gtk_widget_set_sensitive(theApp->ei_repeat2, FALSE);
	gtk_widget_show_all(theApp->appFrame);

	//part 2
	g_signal_connect (theApp->ei_relatedCourse2, "changed", G_CALLBACK (Control::quickCheck2), theApp);
	g_signal_connect (theApp->ei_year2, "changed", G_CALLBACK (Control::quickCheck2), theApp);
	g_signal_connect (theApp->ei_term2, "changed", G_CALLBACK (Control::quickCheck2), theApp);
	g_signal_connect (theApp->ei_supervisor, "changed", G_CALLBACK (Control::quickCheck2), theApp);
	
	g_signal_connect(theApp->ei_continue2, "clicked", G_CALLBACK(Control::moveOn2), theApp);
	g_signal_connect(theApp->ei_repeat2, "clicked", G_CALLBACK(Control::addAnother2), theApp);
	
	
	
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
	gtk_widget_destroy(theApp->ei_repeat2);

	theApp->page = 3;
	


	/////////////////////////////////////////////////////
	//-----------New Buttons, labels and entries------////
	/////////////////////////////////////////////////////

	theApp->ei_lblRelevantWork = gtk_label_new("Relevant Work :");
	theApp->ei_lblDuration = gtk_label_new("Duration :");
	theApp->ei_lblStartDate = gtk_label_new("Start Date (dd/mm/yr) :");
	theApp->ei_lblEndDate = gtk_label_new("End Date (dd/mm/yr) :");
	theApp->ei_lblResponsabilities = gtk_label_new("Responsabilities :");
	
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblRelevantWork, 400, 280);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblResponsabilities, 400, 310);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblDuration, 400,340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblStartDate, 400, 370);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblEndDate, 400, 400);

	//part 3
	theApp->ei_relevantWork = gtk_entry_new();
	theApp->ei_responsabilities = gtk_entry_new();
	theApp->ei_duration= gtk_entry_new();
	theApp->ei_startDate = gtk_entry_new();
	theApp->ei_endDate = gtk_entry_new();

	//part 3
	theApp->ei_finish = gtk_button_new_with_label("Finish");
	theApp->ei_repeat3 = gtk_button_new_with_label("Add Another");
	
	gtk_widget_set_size_request(theApp->ei_finish, 80, 35);
	gtk_widget_set_size_request(theApp->ei_repeat3, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_repeat3, 550, 430);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_finish, 450, 430);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_relevantWork, 550, 280);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_responsabilities, 550, 310);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_duration, 550, 340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_startDate, 550, 370);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_endDate,550, 400);
	gtk_widget_set_sensitive(theApp->ei_finish, FALSE);
	gtk_widget_set_sensitive(theApp->ei_repeat3, FALSE);
	gtk_widget_show_all(theApp->appFrame);


	//part 3
	g_signal_connect (theApp->ei_startDate, "changed", G_CALLBACK (Control::quickCheck3), theApp);
	g_signal_connect (theApp->ei_endDate, "changed", G_CALLBACK (Control::quickCheck3), theApp);
	g_signal_connect (theApp->ei_relevantWork, "changed", G_CALLBACK (Control::quickCheck3), theApp);
	g_signal_connect (theApp->ei_responsabilities, "changed", G_CALLBACK (Control::quickCheck3), theApp);
	g_signal_connect (theApp->ei_duration, "changed", G_CALLBACK (Control::quickCheck3), theApp);
	g_signal_connect(theApp->ei_finish, "clicked", G_CALLBACK(Control::moveOn3), theApp);
	g_signal_connect(theApp->ei_repeat3, "clicked", G_CALLBACK(Control::addAnother3), theApp);
}



void Control::moveOn(GtkWidget *widget, WindowApp *theApp){
	theApp->moveOn = true;
	quickCheck(widget,theApp); //checks if the app can move on to next page

}
void Control::moveOn2(GtkWidget *widget, WindowApp *theApp){
	theApp->moveOn = true;
	quickCheck2(widget,theApp);

}
void Control::moveOn3(GtkWidget *widget, WindowApp *theApp){
	theApp->moveOn = true;
	quickCheck3(widget,theApp);

}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//quick check: check if the extra info boxes are empty and other error checking
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
		theApp->checkGood = true;
		gtk_widget_set_sensitive(theApp->ei_continue, TRUE);
		gtk_widget_set_sensitive(theApp->ei_repeat, TRUE);
		
		if(theApp->moveOn){
			int yr = atoi(string2.c_str());
			unsigned validRC1 = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  			unsigned validterm1 = (string3).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned grade = (string4).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			if (validRC1 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRC1];
				cout << ", at position " << validRC1 << endl;
				Control::popWindow("You entered a non-alphabetical character in Related Courses", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
  
			else if (validterm1 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm1];
				cout << ", at position " << validterm1 << endl;
				Control::popWindow("You entered a non-alphabetical character in term", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (grade != string::npos) {
				cout << "Please Enter a Letter Grade" << endl;
				Control::popWindow("Please Enter a Letter Grade", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				Control::popWindow("Year must be between 1990 and 2013", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
			}
			
			if(theApp->checkGood){
				Course* cor = new Course(string1, yr, string3, "N/A", string4);
				theApp->cQRelated = new CourseQueue();
				theApp->cQRelated->pushBack(theApp->cQRelated->createNode(cor));
				theApp->moveOn = false;
				relatedCourses2(widget, theApp);
			}
		}
		
		
	}
}

void Control::quickCheck2(GtkWidget *widget, WindowApp *theApp){
	

	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
	
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relatedCourse2));
	
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_year2));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_term2));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_supervisor));        
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""){
		theApp->checkGood = true;
		gtk_widget_set_sensitive(theApp->ei_continue2, TRUE);
		gtk_widget_set_sensitive(theApp->ei_repeat2, TRUE);
		if(theApp->moveOn){
			int yr = atoi(string2.c_str());


			unsigned validRC2 = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validterm2 = (string3).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned supervisor = (string4).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  
			if (validRC2 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRC2];
				cout << ", at position " << validRC2 << endl;
				Control::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
  
			else if (validterm2 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm2];
				cout << ", at position " << validterm2 << endl;
				Control::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (supervisor != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string4)[supervisor];
				cout << ", at position " << supervisor << endl;
				Control::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
				
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				Control::popWindow("Year must be between 1990 and 2013", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
				
			}

			if(theApp->checkGood){
				Course* cor = new Course(string1, yr, string3, string4, "N/A");
			
				theApp->cQTa = new CourseQueue();
				theApp->cQTa->pushBack(theApp->cQTa->createNode(cor));

				theApp->moveOn = false;
				workExperience(widget, theApp);
			}
		}
		
		
	}
}

void Control::quickCheck3(GtkWidget *widget, WindowApp *theApp){
	

	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="";
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relevantWork));
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_responsabilities));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_duration)); 
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_startDate));
	s5 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_endDate));
	       
	  
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	string5 = (s5);
	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""&& string5 != ""){
		gtk_widget_set_sensitive(theApp->ei_finish, TRUE);
		gtk_widget_set_sensitive(theApp->ei_repeat3, TRUE);
		theApp->checkGood = true;
		if(theApp->moveOn){
			


			unsigned validRW = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validresp = (string2).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validdur = (string2).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned startDate = (string4).find_first_not_of("0123456789/");
			unsigned endDate = (string5).find_first_not_of("0123456789/");
  
			if (validRW != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRW];
				cout << ", at position " << validRW << endl;
				Control::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
  
			else if (validresp != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string2)[validresp];
				cout << ", at position " << validresp << endl;
				Control::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}
			
			else if (validdur != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validdur];
				cout << ", at position " << validdur << endl;
				Control::popWindow("You entered a non-alphabetical character", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (startDate != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string4)[startDate];
				cout << ", at position " << startDate << endl;
				Control::popWindow("Wrong Format for Start Date", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			
			else if (endDate != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string5)[endDate];
				cout << ", at position " << endDate << endl;
				Control::popWindow("Wrong Format for End Date", theApp);
				theApp->checkGood = false;
				theApp->moveOn = false;
		   	}

			if(theApp->checkGood){
				Job* job = new Job(s1, s2, s3, s4, s5);
				theApp->jQRelated = new JobQueue();
				theApp->jQRelated->pushBack(theApp->jQRelated->createNode(job));

				theApp->moveOn = false;
				finishExtra(widget, theApp);
			}
		}
		
	}
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//when the user wants to continue to next set of extra info and finish
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Control::finishExtra(GtkWidget *widget, WindowApp *theApp){
		
	
	/////////////////////////////////////////////////////
	//-----------Remove Old Labels and text entires--////
	/////////////////////////////////////////////////////
	gtk_widget_destroy(theApp->ei_lblRelevantWork);
	gtk_widget_destroy(theApp->ei_lblDuration);
	gtk_widget_destroy(theApp->ei_lblStartDate);
	gtk_widget_destroy(theApp->ei_lblEndDate);
	gtk_widget_destroy(theApp->ei_lblResponsabilities);
	
	gtk_widget_destroy(theApp->ei_finish);
	gtk_widget_destroy(theApp->ei_repeat3);
	gtk_widget_destroy(theApp->ei_relevantWork);
	gtk_widget_destroy(theApp->ei_responsabilities);
	gtk_widget_destroy(theApp->ei_duration);
	gtk_widget_destroy(theApp->ei_startDate);
	gtk_widget_destroy(theApp->ei_endDate);

	gtk_window_resize(GTK_WINDOW(theApp->window), 400,600);
	gtk_widget_set_sensitive(theApp->submit, TRUE);
	theApp->extra =false;

}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//add another: user chooses to add another set of extra info
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Control::addAnother(GtkWidget *widget, WindowApp *theApp){
	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="";
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relatedCourse1));
	
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_year1));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_term1));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_finalGrade)); 
	       
	  
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);

	Course* cor = new Course(string1, 1, string3, "N/A", string4);
	theApp->cQRelated->pushBack(theApp->cQRelated->createNode(cor));
	

	gtk_entry_set_text(GTK_ENTRY(theApp->ei_relatedCourse1), "");
	gtk_entry_set_text(GTK_ENTRY(theApp->ei_year1), "");
	gtk_entry_set_text(GTK_ENTRY(theApp->ei_term1), "");
	gtk_entry_set_text(GTK_ENTRY(theApp->ei_finalGrade), "");

	gtk_widget_set_sensitive(theApp->ei_continue, FALSE);

	gtk_widget_set_sensitive(theApp->ei_repeat, FALSE);

	gtk_widget_set_sensitive(theApp->ei_repeat, FALSE);


}

void Control::addAnother2(GtkWidget *widget, WindowApp *theApp){
	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="";
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relatedCourse2));
	
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_year2));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_term2));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_supervisor));  
	       
	
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);

	gtk_entry_set_text(GTK_ENTRY(theApp->ei_relatedCourse2), "");
	gtk_entry_set_text(GTK_ENTRY(theApp->ei_year2), "");
	gtk_entry_set_text(GTK_ENTRY(theApp->ei_term2), "");
	gtk_entry_set_text(GTK_ENTRY(theApp->ei_supervisor), "");
	gtk_widget_set_sensitive(theApp->ei_continue2, FALSE);
	gtk_widget_set_sensitive(theApp->ei_repeat2, FALSE);
	
}

void Control::addAnother3(GtkWidget *widget, WindowApp *theApp){
	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="";
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_relevantWork));
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_responsabilities));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_duration)); 
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_startDate));
	s5 = gtk_entry_get_text(GTK_ENTRY(theApp->ei_endDate));
	       
	  
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	string5 = (s5);

	
	gtk_entry_set_text(GTK_ENTRY(theApp->ei_relevantWork), "");
	gtk_entry_set_text(GTK_ENTRY(theApp->ei_responsabilities), "");
	gtk_entry_set_text(GTK_ENTRY(theApp->ei_duration), "");
	gtk_entry_set_text(GTK_ENTRY(theApp->ei_startDate), "");
	gtk_entry_set_text(GTK_ENTRY(theApp->ei_endDate), "");

	gtk_widget_set_sensitive(theApp->ei_finish, FALSE);
	gtk_widget_set_sensitive(theApp->ei_repeat3, FALSE);
}






















//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
		//submission page : return to main menu
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Control::submitToMain(GtkWidget *widget,WindowApp *theApp){
	/*
	gtk_window_resize(GTK_WINDOW(theApp->window), 400,200);
	gtk_widget_destroy(theApp->fName);
	gtk_widget_destroy(theApp->lName);
	gtk_widget_destroy(theApp->major);
	gtk_widget_destroy(theApp->gpa);
	gtk_widget_destroy(theApp->cgpa);
	gtk_widget_destroy(theApp->email);
	gtk_widget_destroy(theApp->year);
	gtk_widget_destroy(theApp->stuNum);
	gtk_widget_destroy(theApp->lblfName);
	gtk_widget_destroy(theApp->lbllName);
	gtk_widget_destroy(theApp->lblMajor);
	gtk_widget_destroy(theApp->lblGpa);
	gtk_widget_destroy(theApp->lblCgpa);
	gtk_widget_destroy(theApp->lblEmail);
	gtk_widget_destroy(theApp->lblYear);
	gtk_widget_destroy(theApp->lblstuNum);
	gtk_widget_destroy(theApp->submit);
	gtk_widget_destroy(theApp->cancel);
	
	gtk_widget_destroy(theApp->combo);

	if(theApp->extra){
		if(theApp->page == 1){
			gtk_widget_destroy(theApp->ei_relatedCourse1);
			gtk_widget_destroy(theApp->ei_term1);
			gtk_widget_destroy(theApp->ei_year1);
			gtk_widget_destroy(theApp->ei_finalGrade);

			gtk_widget_destroy(theApp->ei_lblFinalGrade);
			gtk_widget_destroy(theApp->ei_lblRelatedCourse);
			
			gtk_widget_destroy(theApp->ei_lblTerm);
			gtk_widget_destroy(theApp->ei_lblYear);
			gtk_widget_destroy(theApp->ei_continue);
			gtk_widget_destroy(theApp->ei_repeat);
			gtk_widget_destroy(theApp->submitWindow);
		}
		else if(theApp->page == 2){
			gtk_widget_destroy(theApp->ei_relatedCourse2);
			gtk_widget_destroy(theApp->ei_term2);
			gtk_widget_destroy(theApp->ei_year2);
			gtk_widget_destroy(theApp->ei_supervisor);	
	
			gtk_widget_destroy(theApp->ei_lblRelatedCourse);
			gtk_widget_destroy(theApp->ei_lblSupervisor);
			gtk_widget_destroy(theApp->ei_lblTerm);
			gtk_widget_destroy(theApp->ei_lblYear);
			gtk_widget_destroy(theApp->ei_continue2);
			gtk_widget_destroy(theApp->ei_repeat2);
			gtk_widget_destroy(theApp->submitWindow);
		}
		else if(theApp->page == 3){
			gtk_widget_destroy(theApp->ei_lblRelevantWork);
			gtk_widget_destroy(theApp->ei_lblDuration);
			gtk_widget_destroy(theApp->ei_lblStartDate);
			gtk_widget_destroy(theApp->ei_lblEndDate);
			gtk_widget_destroy(theApp->ei_lblResponsabilities);
	
			gtk_widget_destroy(theApp->ei_finish);
			gtk_widget_destroy(theApp->ei_repeat3);
			gtk_widget_destroy(theApp->ei_relevantWork);
			gtk_widget_destroy(theApp->ei_responsabilities);
			gtk_widget_destroy(theApp->ei_duration);
			gtk_widget_destroy(theApp->ei_startDate);
			gtk_widget_destroy(theApp->ei_endDate);
			gtk_widget_destroy(theApp->submitWindow);

		}
		
	}
	*/
	gtk_widget_destroy(theApp->appFrame);
	Control::mainMenu(widget,theApp);
	


}
		



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
		//submission page create another application
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Control::submitToRepeat(GtkWidget *widget,WindowApp *theApp){
	gtk_widget_set_sensitive(theApp->combo, TRUE);
	gtk_widget_hide(theApp->submitWindow);

}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//Create the Main Menu
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Control::mainMenu(GtkWidget *widget, WindowApp *theApp){
	/////////////////////////////////////////////////////
	//-----------Create the window ------------------////
	/////////////////////////////////////////////////////
	

	gtk_window_resize(GTK_WINDOW(theApp->window), 400,200);

	


	/////////////////////////////////////////////////////
	//-----------Add frame onto window---------------////
	/////////////////////////////////////////////////////
	theApp->appFrame = gtk_fixed_new();
	theApp->admin_frame = gtk_fixed_new();

	gtk_container_add(GTK_CONTAINER(theApp->window), theApp->appFrame);


	/////////////////////////////////////////////////////
	//Make the application button and add to frame---////
	/////////////////////////////////////////////////////

	theApp->btnStudent = gtk_button_new_with_label("Student");
	gtk_widget_set_size_request(theApp->btnStudent, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->btnStudent, 50, 20);	

	theApp->apply = gtk_button_new_with_label("Apply");
	gtk_widget_set_size_request(theApp->apply, 80, 35);


	/////////////////////////////////////////////////////
	//------Make the login button and add to frame---////
	/////////////////////////////////////////////////////
	theApp->login = gtk_button_new_with_label("Admin");
	gtk_widget_set_size_request(theApp->login, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->login, 50, 80);


	
	
	/////////////////////////////////////////////////////
	//------Make the Prompt Label and add to frame---////
	/////////////////////////////////////////////////////
	theApp->label = gtk_label_new("Choose a Menu Option");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->label, 150, 58); 



	/////////////////////////////////////////////////////
	//----------Show all the widgets on the window---////
	/////////////////////////////////////////////////////
	theApp->moveOn = false;
	theApp->extra = false;
	gtk_widget_show_all(theApp->window);



	/////////////////////////////////////////////////////
	//Connect signals with each button as well as close////
	/////////////////////////////////////////////////////
	g_signal_connect(theApp->window, "destroy", G_CALLBACK (Control::cancel), theApp);

	g_signal_connect(theApp->btnStudent, "clicked", G_CALLBACK(Control::studentPage), theApp);

	
	g_signal_connect(theApp->login, "clicked", G_CALLBACK(Control::adminPage), theApp);

}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
		//create the main window
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Control::createWindow(int argc, char** argv)
{
	
	WindowApp *theApp = new WindowApp();

	// initialize GTK+
	gtk_init(&argc, &argv);
	theApp->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//loadApplications();
	gtk_window_set_position(GTK_WINDOW(theApp->window), GTK_WIN_POS_CENTER);
	
	gtk_window_set_default_size(GTK_WINDOW(theApp->window), 400, 200);
	//gtk_window_resize(GTK_WINDOW(theApp->window), 600,300);
	gtk_window_set_title(GTK_WINDOW(theApp->window), "Main Menu");
	Control::mainMenu(theApp->window, theApp);
	

	gtk_main();
	return 0;
}
