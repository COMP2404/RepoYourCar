#include "GradAppPage.h"
GradAppPage::GradAppPage(){
	this->form = new GradForm();
	//this->theApp = theApp;
	//theApp->gradAppPage->form = new GradForm();
	cout << "new grad app page made" <<endl;
}
void GradAppPage::draw(WindowApp *windowApp){
	//gradApp = true;
	cout << "draws" <<endl;
	//page->form = new GradForm();
	windowApp->gradAppPage->form->draw(windowApp->gradAppPage->form);
	
	//form->ei_repeat2 = gtk_button_new_with_label("Add Another");
	//gtk_fixed_put(GTK_FIXED(form->appFrame), form->ei_repeat2, 550, 430); 
	//gtk_widget_show_all(form->window);

	g_signal_connect(windowApp->gradAppPage->form->submit, "clicked", G_CALLBACK(GradAppPage::getInfo), windowApp);
	
	g_signal_connect(windowApp->gradAppPage->form->cancel, "clicked", G_CALLBACK(GradAppPage::close), windowApp);
	g_signal_connect(GTK_COMBO_BOX(windowApp->gradAppPage->form->combo), "changed", G_CALLBACK (GradAppPage::related2), windowApp);
  	
}

void GradAppPage::close(GtkWidget *widget, WindowApp *page){
	//gtk_widget_destroy(windowApp->gradAppPage->window);
}
void GradAppPage::related2(GtkWidget *widget, WindowApp *app){

	RelatedCoursesTwoForm *relatedCourses2 = new RelatedCoursesTwoForm();
	relatedCourses2->create(app,true);
	g_signal_connect(app->gradAppPage->form->ei_continue2, "clicked", G_CALLBACK(RelatedCoursesTwoForm::nextPageGrad), app);
	g_signal_connect(app->gradAppPage->form->ei_repeat2 , "clicked", G_CALLBACK(RelatedCoursesTwoForm::addAnotherGrad), app);
}

void GradAppPage::workExp(WindowApp* app){
	WorkExperienceForm *workExperience = new WorkExperienceForm();
	workExperience->create(app,true);
	g_signal_connect(app->gradAppPage->form->ei_finish, "clicked", G_CALLBACK(WorkExperienceForm::finishGrad), app);
	g_signal_connect(app->gradAppPage->form->ei_repeat3 , "clicked", G_CALLBACK(WorkExperienceForm::addAnotherGrad), app);

}
void GradAppPage::getInfo(GtkWidget *widget, WindowApp *app){
	

	const gchar *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="", string10="", string11="", string12="";
	double c, g;
	int num;

		
		s1 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(app->gradAppPage->form->combo));
		if(s1==NULL)
			s1="";

		s2 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(app->gradAppPage->form->grad_research_combo));
		if(s2==NULL)
			s2="";
		s3 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(app->gradAppPage->form->grad_program_combo));
		if(s3==NULL)
			s3="";
		s4 = gtk_entry_get_text(GTK_ENTRY(app->gradAppPage->form->fName));
		
		s5 = gtk_entry_get_text(GTK_ENTRY(app->gradAppPage->form->lName));
		//s4 = gtk_entry_get_text(GTK_ENTRY(page->form->gpa));
		//s5 = gtk_entry_get_text(GTK_ENTRY(page->form->cgpa));        
	    s6 = gtk_entry_get_text(GTK_ENTRY(app->gradAppPage->form->email));
		//s7 = gtk_entry_get_text(GTK_ENTRY(page->form->year));
		s7 = gtk_entry_get_text(GTK_ENTRY(app->gradAppPage->form->grad_sup));
		s8 = gtk_entry_get_text(GTK_ENTRY(app->gradAppPage->form->stuNum));
		string1 = (s1);
		string2 = (s4);
		string3 = (s5);
		//string4 = (s4);
		//string5 = (s5);
		string6 = (s6);
		string9 = (s8);
		string10 = (s2);
		string11 = (s3);
		string12 = (s7);

		app->gradAppPage->formData = new GradAppData(string2, string3,string6,string9,string1,string10,string11,string12);
		//1 string* course, 2 string* first, 3 string* last, 4 string* mgpa, 
		//5 string* gpa, 6 string* email, 7 string* year, 8 string* major, 
		//9 string* stunum, 10 string* areas, 11 string* program, 12 string* supervisor, WindowApp *form
		app->gradAppPage->errorCheck(app);
}
void GradAppPage::errorCheck(WindowApp *app){
	GradErrorCheck eCheck;
	if(eCheck.check(app->gradAppPage->formData)){
		cout<<"YAY!"<<endl;
		submit(app);

	}
		

	else
		cout<<"check failed!"<<endl;
}
void GradAppPage::submit(WindowApp *app){
	GradSubmitWindow *submitWindow = new GradSubmitWindow();
	submitWindow->draw(submitWindow);
	g_signal_connect (submitWindow->submitFinish, "clicked", G_CALLBACK (GradSubmitWindow::close), submitWindow);
	AppManager::submitGradApp(app);
}

