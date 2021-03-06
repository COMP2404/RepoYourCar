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
	windowApp->gradAppPage->form->draw(windowApp->gradAppPage->form, windowApp);

	g_signal_connect(windowApp->gradAppPage->form->submit, "clicked", G_CALLBACK(GradAppPage::getInfo), windowApp);
	
	g_signal_connect(windowApp->gradAppPage->form->cancel, "clicked", G_CALLBACK(GradAppPage::close), windowApp);
	
	g_signal_connect(GTK_COMBO_BOX(windowApp->gradAppPage->form->combo), "changed", G_CALLBACK (GradAppPage::related2), windowApp);
  	
}

void GradAppPage::close(GtkWidget *widget, WindowApp *page){
	//page->editGApp = false;
	gtk_widget_destroy(page->gradAppPage->form->window);
}

void GradAppPage::related2(GtkWidget *widget, WindowApp *app){

	RelatedCoursesTwoForm *relatedCourses2 = new RelatedCoursesTwoForm();
	relatedCourses2->create(app,true);

	g_signal_connect(app->gradAppPage->form->ei_continue2, "clicked", G_CALLBACK(RelatedCoursesTwoForm::nextPageGrad), app);
	g_signal_connect(app->gradAppPage->form->ei_repeat2 , "clicked", G_CALLBACK(RelatedCoursesTwoForm::addAnotherGrad), app);
	g_signal_connect(app->gradAppPage->form->chkExperience , "toggled", G_CALLBACK(RelatedCoursesTwoForm::closeG), app);
	if(!app->canEdit){
		app->gradAppPage->rTAIndex = 0;

		g_signal_connect(app->gradAppPage->form->nextSection, "clicked", G_CALLBACK(RelatedCoursesTwoForm::viewNextGSection), app);
		g_signal_connect(app->gradAppPage->form->nextPage , "clicked", G_CALLBACK(RelatedCoursesTwoForm::viewNextGPage), app);
		g_signal_connect(app->gradAppPage->form->prevSection, "clicked", G_CALLBACK(RelatedCoursesTwoForm::viewPrevGSection), app);

		if(app->canCycle){
			g_signal_connect(app->gradAppPage->form->nextApp, "clicked", G_CALLBACK(AppManager::nextApp), app);
			g_signal_connect(app->gradAppPage->form->prevApp , "clicked", G_CALLBACK(AppManager::prevApp), app);
		
		}
	}
	if(app->editGMode && app->canEdit){
		GradAppPage::fillInRelated(app);
	}
}

void GradAppPage::workExp(WindowApp* app){
	WorkExperienceForm *workExperience = new WorkExperienceForm();
	workExperience->create(app,true);
	
	g_signal_connect(app->gradAppPage->form->ei_finish, "clicked", G_CALLBACK(WorkExperienceForm::finishGrad), app);
	g_signal_connect(app->gradAppPage->form->ei_repeat3 , "clicked", G_CALLBACK(WorkExperienceForm::addAnotherGrad), app);
	g_signal_connect(app->gradAppPage->form->chkExperience , "toggled", G_CALLBACK(WorkExperienceForm::closeG), app);

	if(!app->canEdit){
		app->gradAppPage->rWXPIndex = 0;

		g_signal_connect(app->gradAppPage->form->nextSection, "clicked", G_CALLBACK(WorkExperienceForm::viewNextGSection), app);

		g_signal_connect(app->gradAppPage->form->prevSection, "clicked", G_CALLBACK(WorkExperienceForm::viewPrevGSection), app);
		g_signal_connect(app->gradAppPage->form->prevPage , "clicked", G_CALLBACK(WorkExperienceForm::viewPrevGPage), app);
		if(app->canCycle){

			g_signal_connect(app->gradAppPage->form->nextApp, "clicked", G_CALLBACK(AppManager::nextApp), app);
			g_signal_connect(app->gradAppPage->form->prevApp , "clicked", G_CALLBACK(AppManager::prevApp), app);
		
		}
	}
	if(app->editGMode && app->canEdit){
		GradAppPage::fillInWorkExp(app);
	}
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
       
	    s6 = gtk_entry_get_text(GTK_ENTRY(app->gradAppPage->form->email));

		s7 = gtk_entry_get_text(GTK_ENTRY(app->gradAppPage->form->grad_sup));
		s8 = gtk_entry_get_text(GTK_ENTRY(app->gradAppPage->form->stuNum));
		string1 = (s1);
		string2 = (s4);
		string3 = (s5);

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

	app->gSubmitWindow = new GradSubmitWindow();
	app->gSubmitWindow->draw(app->gSubmitWindow);

	g_signal_connect (app->gSubmitWindow->submitFinish, "clicked", G_CALLBACK (GradSubmitWindow::close), app);
	g_signal_connect (app->gSubmitWindow->submitRepeat, "clicked", G_CALLBACK (GradSubmitWindow::close), app);
	AppManager::submitGradApp(app);
}
void GradAppPage::fillInData(Application* app, WindowApp *theApp){

	theApp->gradAppPage->edit = true;
	GradApp *editApp = dynamic_cast<GradApp*>(app);
	theApp->editGApp = editApp;
	
	gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(theApp->gradAppPage->form->grad_program_combo), (editApp->getStuProgram()).c_str());
	gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(theApp->gradAppPage->form->grad_research_combo), (editApp->getStuArea()).c_str());
	gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(theApp->gradAppPage->form->combo), (editApp->getCourse()).c_str());

	gtk_combo_box_set_active(GTK_COMBO_BOX(theApp->gradAppPage->form->grad_program_combo),0); 
	gtk_combo_box_set_active(GTK_COMBO_BOX(theApp->gradAppPage->form->grad_research_combo),0); 
	gtk_combo_box_set_active(GTK_COMBO_BOX(theApp->gradAppPage->form->combo),0); 
	
	gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->fName), (editApp->getStuFirst()).c_str());
	gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->lName), (editApp->getStuLast()).c_str());
	gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->email), (editApp->getStuEmail()).c_str());
	gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->grad_sup), (editApp->getStuSuper()).c_str());
	gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->stuNum), (editApp->getStuID()).c_str());

	GradAppPage::fillInRelated(theApp);
}

void GradAppPage::fillInRelated(WindowApp* theApp){
		
	if(theApp->gradAppPage->form->rTA || theApp->editGApp->rTA){
		theApp->gradAppPage->relatedQueue = new Queue<Course>(*(theApp->editGApp->relatedTAPositions));	
		cout<<theApp->gradAppPage->relatedQueue->size() <<endl;
		Course *course = theApp->gradAppPage->relatedQueue->popFront();
		stringstream ss;
		ss << course->getYear();
		string year = ss.str();
		
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_year2), year.c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_relatedCourse2), course->getTitle().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_term2), course->getTerm().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_supervisor), course->getSupervisor().c_str());
	}
	
}
void GradAppPage::fillInWorkExp(WindowApp* theApp){
	if(theApp->gradAppPage->form->rWorkExp || theApp->editGApp->rWorkExp){
		theApp->gradAppPage->workExpQueue = new Queue<Job>(*(theApp->editGApp->relatedWorkEXP));	
		Job *job = theApp->gradAppPage->workExpQueue->popFront();
		cout<<"inside fill in work" <<endl;
	//	Job *job = jobQueue->popFront();
		//cout << job->getStartDate() << endl;
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_relevantWork), job->getJobTitle().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_responsabilities), job->getTasks().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_duration), job->getDuration().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_startDate), job->getStartDate().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_endDate), job->getEndDate().c_str());
	}
	//Job* job = new Job(s1, s2, s3, s4, s5);
	//windowApp->jQRelated->pushBack(job);

}
void GradAppPage::editNextRelated(WindowApp *theApp){
	if(!theApp->gradAppPage->relatedQueue->isEmpty()){
		
		Course *course = theApp->gradAppPage->relatedQueue->popFront();
		stringstream ss;
		ss << course->getYear();
		string year = ss.str();
		
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_year2), year.c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_relatedCourse2), course->getTitle().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_term2), course->getTerm().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_supervisor), course->getSupervisor().c_str());
	}
	else{
		cout << "thing is empty?" << endl;
	}
}
void GradAppPage::editNextJob(WindowApp *theApp){
	if(!theApp->gradAppPage->workExpQueue->isEmpty()){
		
		Job *job = theApp->gradAppPage->workExpQueue->popFront();
	
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_relevantWork), job->getJobTitle().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_responsabilities), job->getTasks().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_duration), job->getDuration().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_startDate), job->getStartDate().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_endDate), job->getEndDate().c_str());
	}
}
