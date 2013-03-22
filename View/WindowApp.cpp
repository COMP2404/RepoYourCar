#include "WindowApp.h"
#include "../Control/Control.h"
#include "AdminPage.h"






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

int WindowApp::applicationNum;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//have the admin page come up
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void WindowApp::adminPage(GtkWidget *widget, WindowApp *theApp){

	AdminManager *admin = new AdminManager(theApp);
	//g_signal_connect(theApp->admin_viewSummary, "clicked", G_CALLBACK (WindowApp::viewSummaryChoice), theApp);
	//g_signal_connect(theApp->admin_cancel, "clicked", G_CALLBACK (WindowApp::closeAdminPage), theApp);
	
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//View Summary of Pending Apps
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void WindowApp::viewSummary(GtkWidget *widget, WindowApp *theApp){
	
}


void WindowApp::viewSummaryChoice(GtkWidget*widget, WindowApp *theApp){
	
}

void WindowApp::closeSummaryChoice(GtkWidget *widget, WindowApp *theApp){
	if(widget == theApp->btnOneCourse)
		theApp->allCourses = false;
	else{
		theApp->allCourses = true;
		
	}
		
	gtk_widget_destroy(theApp->summary_choice_window);
	WindowApp::viewSummary(widget,theApp);
}



void WindowApp::updateCombo(GtkWidget *widget, WindowApp *theApp){
	
	//gtk_widget_destroy(theApp->summary_combo);

	cout << "Updating Combo" << endl;
	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(theApp->summary_combo));
	cout << "Removed Text" << endl;
	
	AppQueue* qCopy = new AppQueue(theApp->appQueue);
	
	//AppQueue* qCopy = theApp->appQueue.sortAll();
	if(theApp->allCourses){
		qCopy = qCopy->sortAll();
		
		gtk_widget_set_sensitive(theApp->admin_combo, FALSE);
	}
	else{
		const gchar* theCourse;
	 	theCourse = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(theApp->admin_combo));
		string courseString;
		courseString = (theCourse);
		cout << courseString << endl;
		qCopy = theApp->appQueue.getPendingList(courseString);
		qCopy = qCopy->sortAll();
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
	
	 int i = 0;
	//for(int i=0; i<length; i++){
	while(app != NULL){
		std::stringstream ss1; 
		std::stringstream ss2; 
		std::stringstream ss3;
		if(app->getType() == "grad"){
			ga = static_cast<GradApp*>(app);
			s1 = ga->getStuFirst();
			//cout << s1 << endl;
			s2 = ga->getStuLast();
			s6 = ga->getStuEmail();
			s7 = ga->getStuID();
			s9 = ga->getStuArea();
			s10 = ga->getStuProgram();
			s11 = ga->getStuSuper();
			input[i] = "Course: " + ga->getCourse() +  "   Grad:   " + s1 + " " + s2 +  "   |  Email: " + s6 + "   |   ID: " + s7 + "    |   Area:  " + s9 + "   |   Program:  "  + s10 + "  |   Supervisor:  " + s11;
		}
		else{

			uga = static_cast<UndergradApp*>(app);	
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
			input[i] = "Course:  " + uga->getCourse() + "   Undergrad: " + s1 + " " + s2 + "   in Year: " + s3 + "    |   Major: " + s4 + "  |  CGPA: " + s5  + "   |  GPA:  " + s8 + "   |  Email: " + s6 + "   |   ID: " + s7;
		}

			
		 
		
		//theInput = input[i];
		strcpy(theInput,input[i].c_str());
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->summary_combo), theInput);
		i++;
		app = qCopy->popFront();	
		if(app != NULL){
			if(app->getType() == "grad"){
				ga = static_cast<GradApp*>(app);
				

			}
			else{
				uga = dynamic_cast<UndergradApp*>(app);
			}
		}
		
	}
	
	
	gtk_widget_show_all(theApp->window);

}








void WindowApp::mainMenu(GtkWidget *widget, WindowApp *theApp){
	
	theApp->main = new MainMenu();
	theApp->main->draw();
	//g_signal_connect(window, "destroy", G_CALLBACK (Control::cancel), theApp);

	g_signal_connect(theApp->main->btnStudent, "clicked", G_CALLBACK(WindowApp::studentPage), theApp);

	
	g_signal_connect(theApp->main->login, "clicked", G_CALLBACK(WindowApp::adminPage), theApp);
	/*

	g_signal_connect(theApp->window, "destroy", G_CALLBACK (Control::cancel), theApp);

	g_signal_connect(theApp->btnStudent, "clicked", G_CALLBACK(WindowApp::studentPage), theApp);

	
	g_signal_connect(theApp->login, "clicked", G_CALLBACK(WindowApp::adminPage), theApp);
	*/
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//Error Window that will pop up
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WindowApp::popWindow(string s, WindowApp *theApp){
	
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

	theApp->appMan = new AppManager(false,theApp);
	theApp->stuPage->close();
	/*theApp->gradApp = false;
	

	g_signal_connect(theApp->submit, "clicked", G_CALLBACK(Control::getInfo), theApp);
	
	g_signal_connect(theApp->cancel, "clicked", G_CALLBACK(Control::submitToMain), theApp);
	g_signal_connect(GTK_COMBO_BOX(theApp->combo), "changed", G_CALLBACK   (WindowApp::relatedCourses1), theApp);
  	return 0;*/
}



int WindowApp::makeGradApplication(GtkWidget *widget, WindowApp *theApp)
{
	theApp->appMan = new AppManager(true,theApp);
	//theApp->gradPage = new GradAppPage();
	//theApp->gradPage->draw(theApp);
	theApp->stuPage->close();

	//g_signal_connect(submit, "clicked", G_CALLBACK(Control::getInfo), theApp);
	
	//g_signal_connect(theApp->gradPage->cancel, "clicked", G_CALLBACK(GradAppPage::close), theApp->gradPage);
	//g_signal_connect(GTK_COMBO_BOX(combo), "changed", G_CALLBACK   (WindowApp::relatedCourses2), theApp);
	/*
	g_signal_connect(theApp->submit, "clicked", G_CALLBACK(Control::getInfo), theApp);
	
	g_signal_connect(theApp->cancel, "clicked", G_CALLBACK(Control::submitToMain), theApp);
	g_signal_connect(GTK_COMBO_BOX(theApp->combo), "changed", G_CALLBACK   (WindowApp::relatedCourses2), theApp);
  	return 0;*/
}









void WindowApp::studentPage(GtkWidget *widget, WindowApp *theApp){
	theApp->stuPage = new StudentPage();
	theApp->stuPage->draw();


	g_signal_connect(theApp->stuPage->student_apply, "clicked", G_CALLBACK (WindowApp::makeApplication), theApp);
	g_signal_connect(theApp->stuPage->grad_apply, "clicked", G_CALLBACK (WindowApp::makeGradApplication), theApp);
	g_signal_connect(theApp->stuPage->student_edit, "clicked", G_CALLBACK (WindowApp::editStudent), theApp);
	/*
	

	g_signal_connect(theApp->student_apply, "clicked", G_CALLBACK (WindowApp::makeApplication), theApp);
	g_signal_connect(theApp->grad_apply, "clicked", G_CALLBACK (WindowApp::makeGradApplication), theApp);
	g_signal_connect(theApp->student_cancel, "clicked", G_CALLBACK (WindowApp::closeStudentPage), theApp);
	*/
}

void WindowApp::closeStudentPage(GtkWidget *widget, WindowApp *theApp){
	//gtk_widget_destroy(theApp->student_window);

}

void WindowApp::editStudent(GtkWidget *widget, WindowApp *theApp){
	gtk_widget_destroy(theApp->stuPage->student_frame);
	theApp->stuPage->chooseApp(theApp);
}

void WindowApp::submitGradApp(WindowApp* theApp){
	
	cout<<"submitting grad app" <<endl;
	//static int applicationNum = 1;

	Student* s ;
	//theApp->studentRepeat = s;
	GradStudent *gs = NULL;
	//UndergradStudent *ugs = NULL;
	//Application *a;
	GradApp *ga = NULL;
	UndergradApp *uga = NULL;

	string first,last,email,stunum,areas,program,supervisor,course;
	first = theApp->gradAppPage->formData->first;
	last = theApp->gradAppPage->formData->last;
	email = theApp->gradAppPage->formData->email;
	areas = theApp->gradAppPage->formData->areas;
	program = theApp->gradAppPage->formData->program;
	supervisor = theApp->gradAppPage->formData->supervisor;
	stunum = theApp->gradAppPage->formData->stuNum;
	course = theApp->gradAppPage->formData->course;
	
	
	gs = new GradStudent(first, last, email, stunum, areas, program, supervisor);
	//a  = new Application(gs, ugs,applicationNum++, *course, "PENDING");
	ga = new GradApp(gs, applicationNum++, course, "PENDING");
	ga->setRelatedTAPositions(theApp->cQTa);
	ga->setRelatedWorkEXP(theApp->jQRelated);
	theApp->appQueue.pushBack(ga, uga);
	if(!ga->printApp(true))
			return;
	
	
	

}
void WindowApp::submitUGradApp(WindowApp* theApp){
	

	//static int applicationNum = 1;

	Student* s ;
	//theApp->studentRepeat = s;
	GradStudent *gs = NULL;
	UndergradStudent *ugs = NULL;
	//Application *a;
	GradApp *ga = NULL;
	UndergradApp *uga = NULL;

	string first,last,email, major,year,stunum;
	first = theApp->uGradAppPage->formData->first;
	last = theApp->uGradAppPage->formData->last;
	email = theApp->uGradAppPage->formData->email;
	major = theApp->uGradAppPage->formData->gmajor;
	year = theApp->uGradAppPage->formData->year;
	stunum = theApp->uGradAppPage->formData->stuNum;
	
	cout << "pushing ugrad app" << endl;
	ugs = new UndergradStudent(atoi((theApp->uGradAppPage->formData->GPA).c_str()), atoi((theApp->uGradAppPage->formData->CGPA).c_str()), first, last, email, major, atoi(year.c_str()), stunum);
	//a  = new Application(gs, ugs, applicationNum++, *course, "PENDING");
	//uga = new UndergradApp(ugs, applicationNum++, *course, "PENDING");
	uga = new UndergradApp(ugs, applicationNum++, theApp->uGradAppPage->formData->course, "PENDING");
	uga->setRelatedCourses(theApp->cQRelated);
	uga->setRelatedTAPositions(theApp->cQTa);
	uga->setRelatedWorkEXP(theApp->jQRelated);
	theApp->appQueue.pushBack(ga, uga);
	if(!uga->printApp(true))
			return;

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
				//set up the Sets of related Data
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WindowApp::relatedCourses1(GtkWidget *widget, WindowApp *theApp){

	/*
	

	g_signal_connect (theApp->ei_relatedCourse1, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_year1, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_term1, "changed", G_CALLBACK (Control::quickCheck), theApp);
	g_signal_connect (theApp->ei_finalGrade, "changed", G_CALLBACK (Control::quickCheck), theApp);





	g_signal_connect(theApp->ei_continue, "clicked", G_CALLBACK(Control::moveOn), theApp);
	

	g_signal_connect(theApp->ei_repeat, "clicked", G_CALLBACK(Control::addAnother), theApp);
	
	*/
}


void WindowApp::relatedCourses2(GtkWidget *widget, WindowApp *theApp){
/*
	//part 2
	g_signal_connect (theApp->ei_relatedCourse2, "changed", G_CALLBACK (Control::quickCheck2), theApp);
	g_signal_connect (theApp->ei_year2, "changed", G_CALLBACK (Control::quickCheck2), theApp);
	g_signal_connect (theApp->ei_term2, "changed", G_CALLBACK (Control::quickCheck2), theApp);
	g_signal_connect (theApp->ei_supervisor, "changed", G_CALLBACK (Control::quickCheck2), theApp);
	
	g_signal_connect(theApp->ei_continue2, "clicked", G_CALLBACK(Control::moveOn2), theApp);
	g_signal_connect(theApp->ei_repeat2, "clicked", G_CALLBACK(Control::addAnother2), theApp);
	
	
	*/
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


void WindowApp::submitToMain(GtkWidget* widget, WindowApp* theApp){
	gtk_widget_destroy(theApp->appFrame);
	WindowApp::mainMenu(NULL,theApp);
	
}
