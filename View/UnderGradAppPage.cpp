#include "UnderGradAppPage.h"
#include <sstream>
UnderGradAppPage::UnderGradAppPage(){
	this->form = new UnderGradForm();
}

void UnderGradAppPage::draw(WindowApp *windowApp){
	//gradApp = false;
	
	windowApp->uGradAppPage->form->draw();

	 
	

	g_signal_connect(windowApp->uGradAppPage->form->submit, "clicked", G_CALLBACK(UnderGradAppPage::getInfo), windowApp);
	
	g_signal_connect(windowApp->uGradAppPage->form->cancel, "clicked", G_CALLBACK(UnderGradAppPage::close), windowApp);
	g_signal_connect(GTK_COMBO_BOX(windowApp->uGradAppPage->form->combo), "changed", G_CALLBACK   (UnderGradAppPage::related1), windowApp);
  	//return;
}
void UnderGradAppPage::close(GtkWidget *widget, WindowApp *app){
	//gtk_widget_destroy(page->form->window);
}
void UnderGradAppPage::related1(GtkWidget *widget, WindowApp *app){
	RelatedCoursesOneForm *relatedCourses1 = new RelatedCoursesOneForm();
	relatedCourses1->create(app);
	g_signal_connect(app->uGradAppPage->form->ei_continue, "clicked", G_CALLBACK(RelatedCoursesOneForm::nextPage), app);
	g_signal_connect(app->uGradAppPage->form->ei_repeat , "clicked", G_CALLBACK(RelatedCoursesOneForm::addAnother), app);

}
void UnderGradAppPage::related2(GtkWidget *widget, WindowApp *app){
	RelatedCoursesTwoForm *relatedCourses2 = new RelatedCoursesTwoForm();
	relatedCourses2->create(app,false);
	g_signal_connect(app->uGradAppPage->form->ei_continue2, "clicked", G_CALLBACK(RelatedCoursesTwoForm::nextPageUGrad), app);
	g_signal_connect(app->uGradAppPage->form->ei_repeat2 , "clicked", G_CALLBACK(RelatedCoursesTwoForm::addAnotherUGrad), app);

}
void UnderGradAppPage::workExp(WindowApp *app){
	WorkExperienceForm *workExperience = new WorkExperienceForm();
	workExperience->create(app,false);
	g_signal_connect(app->uGradAppPage->form->ei_finish, "clicked", G_CALLBACK(WorkExperienceForm::finishUGrad), app);
	g_signal_connect(app->uGradAppPage->form->ei_repeat3 , "clicked", G_CALLBACK(WorkExperienceForm::addAnotherUGrad), app);

}
void UnderGradAppPage::getInfo(GtkWidget *widget, WindowApp *windowApp){
	const gchar *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="", string10="", string11="", string12="";
	double c, g;
	int num;
	
		
		s1 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(windowApp->uGradAppPage->form->combo));
		if(s1==NULL)
			s1="";
		s2 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->fName));
		
		s3 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->lName));
		s4 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->gpa));
		s5 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->cgpa));        
	    s6 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->email));
		s7 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->year));
		s8 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->major));
		s9 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->stuNum));
		string1 = (s1);
		string2 = (s2); //first
		string3 = (s3); //last
		string4 = (s4); //gpa
		string5 = (s5); //cgpa
		string6 = (s6); //email
		string7 = (s7); //year
		string8 = (s8); // major
		string9 = (s9); //stunum

		windowApp->uGradAppPage->formData = new UGradAppData(string2, string3, string8,string4,string5,string6,string7,string9, string1);
		windowApp->uGradAppPage->errorCheck(windowApp);
}
void UnderGradAppPage::errorCheck(WindowApp *app){
	UGradErrorCheck eCheck;
	if(eCheck.check(app->uGradAppPage->formData)){
		cout<<"YAY!"<<endl;
		submit(app);
	}
		
	else
		cout<<"check failed!"<<endl;
}
void UnderGradAppPage::submit(WindowApp *app){
	UGradSubmitWindow *submitWindow = new UGradSubmitWindow();
	submitWindow->draw(submitWindow);
	g_signal_connect (submitWindow->submitFinish, "clicked", G_CALLBACK (UGradSubmitWindow::close), submitWindow);
	AppManager::submitUGradApp(app);

}
void UnderGradAppPage::fillInData(Application* app,WindowApp *theApp){
	theApp->uGradAppPage->edit = true;
	UndergradApp *editApp = dynamic_cast<UndergradApp*>(app);
	theApp->editUApp = editApp;

	//string CGPA,GPA,major,year;
	//CGPA = "" + editApp->getStuCGPA;

	gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(theApp->uGradAppPage->form->combo), (editApp->getCourse()).c_str());
	gtk_combo_box_set_active(GTK_COMBO_BOX(theApp->uGradAppPage->form->combo),0); 
	
	gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->fName), (editApp->getStuFirst()).c_str());
	gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->lName), (editApp->getStuLast()).c_str());
	gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->email), (editApp->getStuEmail()).c_str());

	int nu = editApp->getStuMGPA();
	string mgpa = static_cast<ostringstream*>( &(ostringstream() << nu) )->str();

	int ni = editApp->getStuCGPA();
	string gpa = static_cast<ostringstream*>( &(ostringstream() << ni) )->str();

	int yr = editApp->getStuYrStanding();
	string year = static_cast<ostringstream*>( &(ostringstream() << yr) )->str();
	gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->cgpa), (gpa.c_str()) );

	gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->gpa), (mgpa.c_str()) );
	gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->major), (editApp->getStuMajor()).c_str());
	gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->year), (year.c_str()));
	gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->stuNum), (editApp->getStuID()).c_str());

	
}