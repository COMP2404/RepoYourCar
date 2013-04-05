#include "UnderGradAppPage.h"
#include <sstream>
UnderGradAppPage::UnderGradAppPage(){
	this->form = new UnderGradForm();
}

//draw the form

void UnderGradAppPage::draw(WindowApp *windowApp){
	//gradApp = false;
	windowApp->uGradAppPage->form->experience = true;
	windowApp->uGradAppPage->form->draw(windowApp);
	g_signal_connect(windowApp->uGradAppPage->form->submit, "clicked", G_CALLBACK(UnderGradAppPage::getInfo), windowApp);	
	g_signal_connect(windowApp->uGradAppPage->form->cancel, "clicked", G_CALLBACK(UnderGradAppPage::close), windowApp);
	g_signal_connect(GTK_COMBO_BOX(windowApp->uGradAppPage->form->combo), "changed", G_CALLBACK   (UnderGradAppPage::related1), windowApp);

}

void UnderGradAppPage::close(GtkWidget *widget, WindowApp *page){
	gtk_widget_destroy(page->uGradAppPage->form->window);
}



//EXTRA INFO PAGES
void UnderGradAppPage::related1(GtkWidget *widget, WindowApp *app){
	RelatedCoursesOneForm *relatedCourses1 = new RelatedCoursesOneForm();
	relatedCourses1->create(app);
	g_signal_connect(app->uGradAppPage->form->ei_continue, "clicked", G_CALLBACK(RelatedCoursesOneForm::nextPage), app);
	g_signal_connect(app->uGradAppPage->form->ei_repeat , "clicked", G_CALLBACK(RelatedCoursesOneForm::addAnother), app);
	g_signal_connect(app->uGradAppPage->form->chkExperience , "toggled", G_CALLBACK(RelatedCoursesOneForm::close), app);
	if(!app->canEdit){
		app->uGradAppPage->rCIndex = 0;
		
		g_signal_connect(app->uGradAppPage->form->nextSection, "clicked", G_CALLBACK(RelatedCoursesOneForm::viewNextSection), app);
		g_signal_connect(app->uGradAppPage->form->nextPage , "clicked", G_CALLBACK(RelatedCoursesOneForm::viewNextPage), app);
		g_signal_connect(app->uGradAppPage->form->prevSection, "clicked", G_CALLBACK(RelatedCoursesOneForm::viewPrevSection), app);
		//g_signal_connect(app->uGradAppPage->form->prevPage , "clicked", G_CALLBACK(RelatedCoursesOneForm::viewPrevPage), app);
		if(app->canCycle){
			g_signal_connect(app->uGradAppPage->form->nextApp, "clicked", G_CALLBACK(AppManager::nextApp), app);
			g_signal_connect(app->uGradAppPage->form->prevApp , "clicked", G_CALLBACK(AppManager::prevApp), app);
		}
	}

}
void UnderGradAppPage::related2(GtkWidget *widget, WindowApp *app){
	RelatedCoursesTwoForm *relatedCourses2 = new RelatedCoursesTwoForm();
	relatedCourses2->create(app,false);
	g_signal_connect(app->uGradAppPage->form->ei_continue2, "clicked", G_CALLBACK(RelatedCoursesTwoForm::nextPageUGrad), app);
	g_signal_connect(app->uGradAppPage->form->ei_repeat2 , "clicked", G_CALLBACK(RelatedCoursesTwoForm::addAnotherUGrad), app);
	g_signal_connect(app->uGradAppPage->form->chkExperience , "toggled", G_CALLBACK(RelatedCoursesTwoForm::closeU), app);
	if(!app->canEdit){
		app->uGradAppPage->rTAIndex = 0;
		g_signal_connect(app->uGradAppPage->form->nextSection, "clicked", G_CALLBACK(RelatedCoursesTwoForm::viewNextUSection), app);
		g_signal_connect(app->uGradAppPage->form->nextPage , "clicked", G_CALLBACK(RelatedCoursesTwoForm::viewNextUPage), app);
		g_signal_connect(app->uGradAppPage->form->prevSection, "clicked", G_CALLBACK(RelatedCoursesTwoForm::viewPrevUSection), app);
		g_signal_connect(app->uGradAppPage->form->prevPage , "clicked", G_CALLBACK(RelatedCoursesTwoForm::viewPrevUPage), app);
		
		if(app->canCycle){
			g_signal_connect(app->uGradAppPage->form->nextApp, "clicked", G_CALLBACK(AppManager::nextApp), app);
			g_signal_connect(app->uGradAppPage->form->prevApp , "clicked", G_CALLBACK(AppManager::prevApp), app);
		
		}
	}
	if(app->editUMode && app->canEdit){
		UnderGradAppPage::fillInTA(app);
	}
}
void UnderGradAppPage::workExp(WindowApp *app){
	WorkExperienceForm *workExperience = new WorkExperienceForm();
	workExperience->create(app,false);
	g_signal_connect(app->uGradAppPage->form->ei_finish, "clicked", G_CALLBACK(WorkExperienceForm::finishUGrad), app);
	g_signal_connect(app->uGradAppPage->form->ei_repeat3 , "clicked", G_CALLBACK(WorkExperienceForm::addAnotherUGrad), app);
	g_signal_connect(app->uGradAppPage->form->chkExperience , "toggled", G_CALLBACK(WorkExperienceForm::closeU), app);
	if(!app->canEdit){
		app->uGradAppPage->rWXPIndex = 0;
		//g_signal_connect(app->uGradAppPage->form->nextApp, "clicked", G_CALLBACK(WorkExperienceForm::nextPage), app);
		//g_signal_connect(app->uGradAppPage->form->prevApp , "clicked", G_CALLBACK(WorkExperienceForm::addAnother), app);
		g_signal_connect(app->uGradAppPage->form->nextSection, "clicked", G_CALLBACK(WorkExperienceForm::viewNextUSection), app);
		//g_signal_connect(app->uGradAppPage->form->nextPage , "clicked", G_CALLBACK(WorkExperienceForm::viewNextUPage), app);
		g_signal_connect(app->uGradAppPage->form->prevSection, "clicked", G_CALLBACK(WorkExperienceForm::viewPrevUSection), app);
		g_signal_connect(app->uGradAppPage->form->prevPage , "clicked", G_CALLBACK(WorkExperienceForm::viewPrevUPage), app);
		if(app->canCycle){
			g_signal_connect(app->uGradAppPage->form->nextApp, "clicked", G_CALLBACK(AppManager::nextApp), app);
			g_signal_connect(app->uGradAppPage->form->prevApp , "clicked", G_CALLBACK(AppManager::prevApp), app);
		
		}
	}
	if(app->editUMode && app->canEdit){
		UnderGradAppPage::fillInWorkExp(app);
	}
}





//get the info from the main fields
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


//submit the data after being checked for errors
void UnderGradAppPage::submit(WindowApp *app){
	app->uSubmitWindow = new UGradSubmitWindow();
	app->uSubmitWindow->draw(app->uSubmitWindow);
	g_signal_connect (app->uSubmitWindow->submitFinish, "clicked", G_CALLBACK (UGradSubmitWindow::close), app);
	g_signal_connect (app->uSubmitWindow->submitRepeat, "clicked", G_CALLBACK (UGradSubmitWindow::close), app);
	AppManager::submitUGradApp(app);

}



//if viewing or editing, this will to fill in the extra data
void UnderGradAppPage::fillInData(Application* app,WindowApp *theApp){
	theApp->uGradAppPage->edit = true;
	UndergradApp *editApp = dynamic_cast<UndergradApp*>(app);
	theApp->editUApp = editApp;

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
	UnderGradAppPage::fillInRelated(theApp);	
}
void UnderGradAppPage::fillInRelated(WindowApp* theApp){
	if(theApp->uGradAppPage->form->rCourses || theApp->editUApp->rCourses){  //this will check if the queue exists
		theApp->uGradAppPage->relatedCourse = new Queue<Course>(*(theApp->editUApp->relatedCourses));	
		cout<<theApp->uGradAppPage->relatedCourse->size() <<endl;
		Course *course = theApp->uGradAppPage->relatedCourse->popFront();
		stringstream ss;
		ss << course->getYear();
		string year = ss.str();
		
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year1), year.c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse1), course->getTitle().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term1), course->getTerm().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_finalGrade), course->getFinal().c_str());
	}
}
void UnderGradAppPage::fillInTA(WindowApp* theApp){
	if(theApp->uGradAppPage->form->rTA || theApp->editUApp->rTA){
		theApp->uGradAppPage->relatedTA = new Queue<Course>(*(theApp->editUApp->relatedTAPositions));	
		cout<<theApp->uGradAppPage->relatedTA->size() <<endl;
		Course *course = theApp->uGradAppPage->relatedTA->popFront();
		stringstream ss;
		ss << course->getYear();
		string year = ss.str();
		
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year2), year.c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse2), course->getTitle().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term2), course->getTerm().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_supervisor), course->getSupervisor().c_str());
	}
}
void UnderGradAppPage::fillInWorkExp(WindowApp* theApp){
	if(theApp->uGradAppPage->form->rWorkExp || theApp->editUApp->rWorkExp){
		theApp->uGradAppPage->workExpQueue = new Queue<Job>(*(theApp->editUApp->relatedWorkEXP));	
		cout<<theApp->uGradAppPage->workExpQueue->size() <<endl;
		Job *job = theApp->uGradAppPage->workExpQueue->popFront();
		
		
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relevantWork), job->getJobTitle().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_responsabilities), job->getTasks().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_duration), job->getDuration().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_startDate), job->getStartDate().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_endDate), job->getEndDate().c_str());
	}
}



//edit the next extra info of that type if the user has added more than one
void UnderGradAppPage::editNextCourse(WindowApp *theApp){
	if(!theApp->uGradAppPage->relatedCourse->isEmpty()){
		
		Course *course = theApp->uGradAppPage->relatedCourse->popFront();
		stringstream ss;
		ss << course->getYear();
		string year = ss.str();
		
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year1), year.c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse1), course->getTitle().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term1), course->getTerm().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_finalGrade), course->getFinal().c_str());
	}
	else{
		cout << "thing is empty?" << endl;
	}
}



void UnderGradAppPage::editNextRelated(WindowApp *theApp){
	if(!theApp->uGradAppPage->relatedTA->isEmpty()){
		
		Course *course = theApp->uGradAppPage->relatedTA->popFront();
		stringstream ss;
		ss << course->getYear();
		string year = ss.str();
		
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year2), year.c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse2), course->getTitle().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term2), course->getTerm().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_supervisor), course->getSupervisor().c_str());
	}
	else{
		cout << "thing is empty?" << endl;
	}
}
void UnderGradAppPage::editNextJob(WindowApp *theApp){
	if(!theApp->uGradAppPage->workExpQueue->isEmpty()){
		
		Job *job = theApp->uGradAppPage->workExpQueue->popFront();
	
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relevantWork), job->getJobTitle().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_responsabilities), job->getTasks().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_duration), job->getDuration().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_startDate), job->getStartDate().c_str());
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_endDate), job->getEndDate().c_str());
	}
}