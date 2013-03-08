#include "WindowApp.h"
#include "Control.h"
/*WindowApp::WindowApp(){
	setfName("");
	setlName("");
	setMajor("");
	setGpa("");
	setEmail("");
	setYear("");
}

WindowApp::~WindowApp(){
	
}*/




void WindowApp::setfName(string s){
	strfName = s;
}
void WindowApp::setlName(string s){
	strlName = s;
}
void WindowApp::setMajor(string s){
	strMajor  = s;
}
void WindowApp::setGpa(string s){
	strGpa  = s;
}
void WindowApp::setCgpa(string s){
	strCgpa  = s;
}
void WindowApp::setEmail(string s){
	strEmail = s;
}
void WindowApp::setYear(string s){
	strYear = s;
}
void WindowApp::setStuNum(string s){
	strStuNum = s;
}

string WindowApp::getfName(){
	return strfName;
}
string WindowApp::getlName(){
	return strlName;
}
string WindowApp::getMajor(){
	return strMajor;
}
string WindowApp::getGpa(){
	return strGpa;
}
string WindowApp::getEmail(){
	return strEmail;
}
string WindowApp::getYear(){
	return strYear;
}
string WindowApp::getCgpa(){
	return strCgpa;
}
string WindowApp::getStuNum(){
	return strStuNum;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//have the admin page come up
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void WindowApp::adminPage(GtkWidget *widget, WindowApp *theApp){

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

	g_signal_connect(theApp->admin_viewSummary, "clicked", G_CALLBACK (WindowApp::viewSummaryChoice), theApp);
	g_signal_connect(theApp->admin_cancel, "clicked", G_CALLBACK (WindowApp::closeAdminPage), theApp);

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//View Summary of Pending Apps
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void WindowApp::viewSummary(GtkWidget *widget, WindowApp *theApp){
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

	

	char text[800];
	string courses[800];



	ifstream inFile("courses.txt", ios::in);

	if (!inFile) {
		cout<<"Could not open file"<<endl;
		exit(1);
	}	
	while (!inFile.eof()) {
		inFile.getline(text, 800);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->admin_combo), text);
	}
	g_signal_connect(theApp->admin_cancel, "clicked", G_CALLBACK (Control::submitToMain), theApp);
	g_signal_connect(GTK_COMBO_BOX(theApp->admin_combo), "changed", G_CALLBACK   (WindowApp::updateCombo), theApp);
}

void WindowApp::mainMenu(GtkWidget *widget, WindowApp *theApp){
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

	g_signal_connect(theApp->btnStudent, "clicked", G_CALLBACK(WindowApp::studentPage), theApp);

	
	g_signal_connect(theApp->login, "clicked", G_CALLBACK(WindowApp::adminPage), theApp);

}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//Error Window that will pop up
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WindowApp::popWindow(string s, WindowApp *theApp){
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

	g_signal_connect(theApp->error_dismiss, "clicked", G_CALLBACK (WindowApp::closePopWindow), theApp);
}

void WindowApp::closePopWindow(GtkWidget *widget, WindowApp *theApp){
	gtk_widget_destroy(theApp->error_window);
}
void WindowApp::closeAdminPage(GtkWidget *widget, WindowApp *theApp){
	
	gtk_widget_destroy(theApp->admin_window);
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
							//make the application
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int WindowApp::makeApplication(GtkWidget *widget, WindowApp *theApp)
{
	theApp->gradApp = false;
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


	
	char text[800];
	string courses[800];

	ifstream inFile("courses.txt", ios::in);

	if (!inFile) {
		cout<<"Could not open file"<<endl;
		return 0;
	}	
	while (!inFile.eof()) {
		inFile.getline(text, 800);
		
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
	g_signal_connect(GTK_COMBO_BOX(theApp->combo), "changed", G_CALLBACK   (WindowApp::relatedCourses1), theApp);
  	return 0;
}



int WindowApp::makeGradApplication(GtkWidget *widget, WindowApp *theApp)
{
	theApp->gradApp = true;
	/////////////////////////////////////////////////
	//--Creates new frame and adds it onto the window---//
	/////////////////////////////////////////////////
 	gtk_widget_destroy(theApp->student_window);
	gtk_widget_destroy(theApp->appFrame);
	theApp->appFrame = gtk_fixed_new();
	gtk_window_resize(GTK_WINDOW(theApp->window), 400,600);
	
//their general information, including student number, first and last names, email address, main research area
//(selected from a preconfigured list), program (MCS or PhD), and supervisor name
	theApp->combo =  gtk_combo_box_text_new();
	theApp->grad_research_combo =  gtk_combo_box_text_new();
	theApp->grad_program_combo =  gtk_combo_box_text_new();
	theApp->fName = gtk_entry_new();
	theApp->lName = gtk_entry_new();
	theApp->email = gtk_entry_new();
	theApp->grad_sup = gtk_entry_new();
	theApp->stuNum = gtk_entry_new();

	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->grad_program_combo), "MCS");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->grad_program_combo), "PHD");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->grad_program_combo, 200, 300);


	char text[800];
	string courses[800];

	ifstream inFile("courses.txt", ios::in);

	if (!inFile) {
		cout<<"Could not open courses file"<<endl;
		return 0;
	}	
	while (!inFile.eof()) {
		inFile.getline(text, 800);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->combo), text);
	}
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->combo, 200, 200);


	char text2[800];
	string areas[800];

	ifstream inFile2("gradResearch.txt", ios::in);

	if (!inFile2) {
		cout<<"Could not open Grad Research file"<<endl;
		return 0;
	}	
	while (!inFile2.eof()) {
		inFile2.getline(text2, 800);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->grad_research_combo), text2);
	}
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->grad_research_combo, 200, 250);
	



	/////////////////////////////////////////////////
	//--Creates text Boxes and submit\cancel buttons---//
	/////////////////////////////////////////////////
	//theApp->combo = combo;
	
	
	
	/////////////////////////////////////////////////
	//--Puts text boxes onto the new frame---------//
	/////////////////////////////////////////////////
	
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->fName, 150, 340);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lName, 150, 370);
	//gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->major, 150, 340);
	//gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->gpa, 150, 370);
	//gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->cgpa, 150, 400);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->email, 150, 400);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->grad_sup, 150, 430);
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->stuNum, 150, 460);

	/////////////////////////////////////////////////
	//--Puts labels onto the new frame---------//
	/////////////////////////////////////////////////

	theApp->lblpickCourse = gtk_label_new("Pick Course :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblpickCourse, 30, 200); 
	theApp->lblpickArea = gtk_label_new("Study Area :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblpickArea, 30, 250);
	theApp->lblpickProgram = gtk_label_new("Grad Program:");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblpickProgram, 30, 300);
	
	theApp->lblfName = gtk_label_new("First Name :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblfName, 30, 340); 
	theApp->lbllName = gtk_label_new("Last Name :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lbllName, 30, 370);
	theApp->lblEmail = gtk_label_new("Email Address:");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblEmail, 30, 400);
	//theApp->lblGpa = gtk_label_new("GPA :");
	//gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblGpa, 30, 370);
	//theApp->lblCgpa = gtk_label_new("CGPA :");
	//gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblCgpa, 30, 400);
	theApp->lbl_grad_sup = gtk_label_new("Supervisor :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lbl_grad_sup, 30, 430);
	//theApp->lblYear = gtk_label_new("Year :");
	//gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblYear, 30, 460);
	theApp->lblstuNum = gtk_label_new("Student Number :");
	gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->lblstuNum, 30, 460);

	

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
	g_signal_connect(GTK_COMBO_BOX(theApp->combo), "changed", G_CALLBACK   (WindowApp::relatedCourses2), theApp);
  	return 0;
}





void WindowApp::viewSummaryChoice(GtkWidget*widget, WindowApp *theApp){
	theApp->summary_choice_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(theApp->summary_choice_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(theApp->summary_choice_window), 400, 200);
	//gtk_window_resize(GTK_WINDOW(theApp->window), 600,300);
	gtk_window_set_title(GTK_WINDOW(theApp->summary_choice_window), "Make a Choice!");
	
	theApp->summary_choice_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(theApp->summary_choice_window), theApp->summary_choice_frame);

	theApp->btnOneCourse = gtk_button_new_with_label("One Course");
	gtk_widget_set_size_request(theApp->btnOneCourse , 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->summary_choice_frame), theApp->btnOneCourse , 50, 100);	


	theApp->btnAllCourses = gtk_button_new_with_label("All Courses");
	gtk_widget_set_size_request(theApp->btnAllCourses , 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->summary_choice_frame), theApp->btnAllCourses , 150, 100);	
	
	const gchar* message;
	//message = s.c_str();
	//theApp->summaryMessage = gtk_label_new(message);
	//gtk_fixed_put(GTK_FIXED(theApp->error_frame), theApp->error_message, 10, 10); 


	gtk_widget_show_all(theApp->summary_choice_window);

	g_signal_connect(theApp->btnOneCourse, "clicked", G_CALLBACK (WindowApp::closeSummaryChoice), theApp);
	g_signal_connect(theApp->btnAllCourses, "clicked", G_CALLBACK (WindowApp::closeSummaryChoice), theApp);
}

void WindowApp::closeSummaryChoice(GtkWidget *widget, WindowApp *theApp){
	if(widget == theApp->btnOneCourse)
		theApp->allCourses = false;
	else
		theApp->allCourses = true;
	gtk_widget_destroy(theApp->summary_choice_window);
	WindowApp::viewSummary(widget,theApp);
}








void WindowApp::updateCombo(GtkWidget *widget, WindowApp *theApp){
	
	//gtk_widget_destroy(theApp->summary_combo);

	cout << "Updating Combo" << endl;
	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(theApp->summary_combo));
	cout << "Removed Text" << endl;
	const gchar* theCourse;
 	theCourse = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(theApp->admin_combo));
	string courseString;
	courseString = (theCourse);
	
	//AppQueue* qCopy = theApp->appQueue.sortAll();

	cout << "Getting Pending List" << endl;
	AppQueue* qCopy = theApp->appQueue.getPendingList(courseString);//call copy constructor
	if(!theApp->appQueue.isEmpty()){
		cout << "Sorting by GPA" << endl;
		//qCopy = qCopy->sortByGPA();
	}
			
	cout << "Got Pending List" << endl;
	//char s1[100], s2[100], s3[100], s4[100], s5[100], s6[100], s7[100];
	string s1,s2,s3,s4,s5,s6,s7 ,s8,s9,s10,s11;
	
	//int length = qCopy->size();
	
	char theInput[200];
	string input[100];//string array for each Application
	Application* tmpApp = NULL;
	Application* app;
    
	GradApp* ga = NULL;
	UndergradApp *uga = NULL;
	
	if(qCopy != NULL){
		app = (qCopy->popFront());
		cout << "Popped Front" << endl;
		
		
	}
		 

	if(app->getType() == "grad"){
		ga = static_cast<GradApp*>(app);
		cout << "Got Type" << endl;
		cout << ga->getStuArea() << endl;

	}
	else{
		uga = dynamic_cast<UndergradApp*>(app);
	}
	 int i = 0;
	//for(int i=0; i<length; i++){
	while(app != NULL){
		std::stringstream ss1; 
		std::stringstream ss2; 
		std::stringstream ss3;
		if(app->getType() == "grad"){
			s1 = ga->getStuFirst();
			//cout << s1 << endl;
			s2 = ga->getStuLast();
			s6 = ga->getStuEmail();
			s7 = ga->getStuID();
			s9 = ga->getStuArea();
			s10 = ga->getStuProgram();
			s11 = ga->getStuSuper();
			input[i] = "Grad:   " + s1 + " " + s2 +  "   |  Email: " + s6 + "   |   ID: " + s7 + "    |   Area:  " + s9 + "   |   Program:  "  + s10 + "  |   Supervisor:  " + s11;
		}
		else{

				
			s1 = uga->getStuFirst();
			cout << s1 << endl;
			s2 = uga->getStuLast();
				 
			ss1 << uga->getStuYrStanding();
			s3 = ss1.str();
			s4 = uga->getStuMajor();
			ss2 << uga->getStuCGPA();
			s5 = ss2.str();
			s6 = uga->getStuEmail();
			s7 = uga->getStuID();
			ss3 << uga->getStuMGPA();
			s8 = ss3.str();
			input[i] = "Undergrad: " + s1 + " " + s2 + "   in Year: " + s3 + "    |   Major: " + s4 + "  |  CGPA: " + s5  + "   |  GPA:  " + s8 + "   |  Email: " + s6 + "   |   ID: " + s7;
		}

			
		 
		
		//theInput = input[i];
		strcpy(theInput,input[i].c_str());
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->summary_combo), theInput);
		i++;
		app = qCopy->popFront();	
		if(app != NULL){
			if(app->getType() == "grad"){
				ga = static_cast<GradApp*>(app);
				cout << "Got Type" << endl;
				cout << ga->getStuArea() << endl;

			}
			else{
				uga = dynamic_cast<UndergradApp*>(app);
			}
		}
		
	}
	
	
	gtk_widget_show_all(theApp->window);

}



void WindowApp::studentPage(GtkWidget *widget, WindowApp *theApp){
	theApp->student_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(theApp->student_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(theApp->student_window), 550, 200);
	
	gtk_window_set_title(GTK_WINDOW(theApp->student_window), "Student Window");
	
	theApp->student_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(theApp->student_window), theApp->student_frame);

	theApp->student_edit = gtk_button_new_with_label("Edit Application");
	gtk_widget_set_size_request(theApp->student_edit , 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->student_frame), theApp->student_edit  , 20, 50);

	theApp->student_apply = gtk_button_new_with_label("New Undergrad Application");
	gtk_widget_set_size_request(theApp->student_apply, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->student_frame), theApp->student_apply , 150, 50);

	theApp->grad_apply = gtk_button_new_with_label("New Graduate Application");
	gtk_widget_set_size_request(theApp->grad_apply, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->student_frame), theApp->grad_apply , 350, 50);

	theApp->student_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(theApp->student_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->student_frame), theApp->student_cancel , 60, 150);
	
	gtk_widget_show_all(theApp->student_window);

	g_signal_connect(theApp->student_apply, "clicked", G_CALLBACK (WindowApp::makeApplication), theApp);
	g_signal_connect(theApp->grad_apply, "clicked", G_CALLBACK (WindowApp::makeGradApplication), theApp);
	g_signal_connect(theApp->student_cancel, "clicked", G_CALLBACK (WindowApp::closeStudentPage), theApp);
}

void WindowApp::closeStudentPage(GtkWidget *widget, WindowApp *theApp){
	gtk_widget_destroy(theApp->student_window);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
				//set up the Sets of related Data
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WindowApp::relatedCourses1(GtkWidget *widget, WindowApp *theApp){


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


void WindowApp::relatedCourses2(GtkWidget *widget, WindowApp *theApp){

	/////////////////////////////////////////////////////
	//-----------Remove Old Text Entries\Labels------////
	/////////////////////////////////////////////////////
	
	if(theApp->gradApp){
		

		theApp->ei_lblRelatedCourse = gtk_label_new("Related Course :");
		theApp->ei_lblTerm = gtk_label_new("Term :");
		theApp->ei_lblYear = gtk_label_new("Year :");
		

		/////////////////////////////////////////////////////
		//-----------Attach Labels To Frame -------------////
		/////////////////////////////////////////////////////
		
		gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblRelatedCourse, 400, 280);
		gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblTerm, 400, 310);
		gtk_fixed_put(GTK_FIXED(theApp->appFrame), theApp->ei_lblYear, 400,340);
	}
	else if(!theApp->gradApp){
		gtk_widget_destroy(theApp->ei_relatedCourse1);
		gtk_widget_destroy(theApp->ei_term1);
		gtk_widget_destroy(theApp->ei_year1);
		gtk_widget_destroy(theApp->ei_finalGrade);

		gtk_widget_destroy(theApp->ei_lblFinalGrade);
		gtk_widget_destroy(theApp->ei_continue);
		gtk_widget_destroy(theApp->ei_repeat);
	}
	

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


void WindowApp::workExperience(GtkWidget *widget, WindowApp *theApp){
	
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
