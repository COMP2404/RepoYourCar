#include "RelatedCoursesOneForm.h"

void RelatedCoursesOneForm::create(WindowApp *app){
	
	//resize the window to accomodate the new widgets
	gtk_window_resize(GTK_WINDOW(app->uGradAppPage->form->window), 800,600);
	
	/////////////////////////////////////////////////////
	//-----------Put Labels on Entries---------------////
	/////////////////////////////////////////////////////
	
	app->uGradAppPage->form->ei_lblRelatedCourse = gtk_label_new("Related Course :");
	app->uGradAppPage->form->ei_lblTerm = gtk_label_new("Term :");
	app->uGradAppPage->form->ei_lblYear = gtk_label_new("Year (1990-Present):");
	app->uGradAppPage->form->ei_lblFinalGrade = gtk_label_new("Final Grade (Letter):");

	/////////////////////////////////////////////////////
	//-----------Attach Labels To Frame -------------////
	/////////////////////////////////////////////////////
	
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_lblRelatedCourse, 400, 280);
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_lblTerm, 400, 310);
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_lblYear, 400,340);
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_lblFinalGrade, 400, 370);


	/////////////////////////////////////////////////////
	//-----------Attach Entries To Frame -------------////
	/////////////////////////////////////////////////////
	
	//part 1
	app->uGradAppPage->form->ei_relatedCourse1 = gtk_entry_new();
	app->uGradAppPage->form->ei_term1= gtk_entry_new();
	app->uGradAppPage->form->ei_year1 = gtk_entry_new();
	app->uGradAppPage->form->ei_finalGrade = gtk_entry_new();
	
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_relatedCourse1, 550, 280);
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_term1, 550, 310);
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_year1, 550, 340);
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_finalGrade, 550, 370);



	/////////////////////////////////////////////////////
	//-----------Attach Buttons To Frame -------------////
	/////////////////////////////////////////////////////

	app->uGradAppPage->form->ei_continue = gtk_button_new_with_label("Continue");
	app->uGradAppPage->form->ei_repeat = gtk_button_new_with_label("Add Another");
	app->uGradAppPage->form->chkExperience = gtk_check_button_new_with_label("No Experience");
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->chkExperience, 450, 480);

	gtk_widget_set_size_request(app->uGradAppPage->form->ei_continue, 80, 35);
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_continue, 450, 430);
	
	gtk_widget_set_size_request(app->uGradAppPage->form->ei_repeat, 80, 35);
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_repeat, 550, 430);
	

	gtk_widget_set_sensitive(app->uGradAppPage->form->submit, FALSE);
	/////////////////////////////////////////////////////
	//-----------Make Buttons Not Clickable-------------////
	/////////////////////////////////////////////////////
	if(!app->canEdit){
		gtk_widget_set_sensitive(app->uGradAppPage->form->ei_relatedCourse1, FALSE);
		gtk_widget_set_sensitive(app->uGradAppPage->form->ei_term1, FALSE);
		gtk_widget_set_sensitive(app->uGradAppPage->form->ei_year1, FALSE);
		gtk_widget_set_sensitive(app->uGradAppPage->form->ei_finalGrade, FALSE);
		gtk_widget_set_sensitive(app->uGradAppPage->form->ei_continue, FALSE);
		gtk_widget_set_sensitive(app->uGradAppPage->form->ei_repeat, FALSE);
		gtk_widget_set_sensitive(app->uGradAppPage->form->chkExperience, FALSE);

		app->uGradAppPage->form->nextApp = gtk_button_new_with_label("Next App");
		app->uGradAppPage->form->prevApp = gtk_button_new_with_label("Prev App");
		app->uGradAppPage->form->nextSection = gtk_button_new_with_label("Next Section");
		app->uGradAppPage->form->nextPage = gtk_button_new_with_label("Next Page");
		app->uGradAppPage->form->prevSection = gtk_button_new_with_label("Prev Section");
		app->uGradAppPage->form->prevPage = gtk_button_new_with_label("Prev Page");

		//gtk_widget_set_size_request(app->uGradAppPage->form->ei_continue, 80, 35);
		//gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_continue, 450, 430);
		gtk_widget_set_size_request(app->uGradAppPage->form->nextApp, 80, 35);
		gtk_widget_set_size_request(app->uGradAppPage->form->prevApp, 80, 35);
		gtk_widget_set_size_request(app->uGradAppPage->form->nextSection, 80, 35);
		gtk_widget_set_size_request(app->uGradAppPage->form->nextPage, 80, 35);
		gtk_widget_set_size_request(app->uGradAppPage->form->prevSection, 80, 35);
		gtk_widget_set_size_request(app->uGradAppPage->form->prevPage, 80, 35);

		gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->nextApp, 545, 550);
		gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->prevApp, 460, 550);
		gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->nextSection, 550, 500);
		gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->nextPage, 640, 500);
		gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->prevSection, 465, 500);
		//gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->prevPage, 380, 500);
	}




	gtk_widget_show_all(app->uGradAppPage->form->appFrame);
	
}

bool RelatedCoursesOneForm::errorCheck(WindowApp *theApp){
	
	

	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
	
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse1));
	
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year1));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term1));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_finalGrade));        
      
	string1 = (s1);
	string2 = (s2);
	
	string3 = (s3);
	string4 = (s4);
	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""){
		
		
		
			int yr = atoi(string2.c_str());
			unsigned validRC1 = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
  			unsigned validterm1 = (string3).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned grade = (string4).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			
			if (validRC1 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRC1];
				cout << ", at position " << validRC1 << endl;
				RelatedCoursesOneForm::popWindow("You entered a non-alphabetical character in Related Courses");
				return false;
		   	}
			
  
			else if (validterm1 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm1];
				cout << ", at position " << validterm1 << endl;
				RelatedCoursesOneForm::popWindow("You entered a non-alphabetical character in term");
				return false;
		   	}

			
			else if (grade != string::npos) {
				cout << "Please Enter a Letter Grade" << endl;
				RelatedCoursesOneForm::popWindow("Please Enter a Letter Grade");
				return false;return false;
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				RelatedCoursesOneForm::popWindow("Year must be between 1990 and 2013");
				return false;
			}
			return true;
		}else{
			return false;
		}
		
		
	


}
void RelatedCoursesOneForm::addAnother(GtkWidget* widget,WindowApp* theApp){
	if(errorCheck(theApp)){
		const gchar *s1, *s2, *s3, *s4, *s5;
		string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
		s1 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse1));
		
		s2 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year1));
		s3 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term1));
		s4 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_finalGrade));        
	      
		string1 = (s1);
		string2 = (s2);
		string3 = (s3);
		string4 = (s4);


		int yr = atoi(string2.c_str());
		Course* cor = new Course(string1, yr, string3, "N/A", string4);
		theApp->cQRelated->pushBack(cor);

		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse1), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year1), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term1), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_finalGrade), "");
		if(theApp->editUMode)
			UnderGradAppPage::editNextCourse(theApp);
	}
	else{

	}
}
void RelatedCoursesOneForm::viewNextPage(GtkWidget* widget,WindowApp* theApp){
	RelatedCoursesOneForm::cleanup(theApp);
 	UnderGradAppPage::related2(widget,theApp);
 	UnderGradAppPage::fillInTA(theApp);
}
void RelatedCoursesOneForm::viewPrevSection(GtkWidget* widget,WindowApp* theApp){
	if(theApp->uGradAppPage->form->rCourses || theApp->editUApp->rCourses){

		theApp->uGradAppPage->relatedCourse = new Queue<Course>(*(theApp->editUApp->relatedCourses));
		int theSize = 0;
		if(theApp->uGradAppPage->relatedCourse->size() != 0){
			theSize = theApp->uGradAppPage->relatedCourse->size();
		}
		
		
		if(theApp->uGradAppPage->rCIndex > 0 ){
			cout<< theApp->uGradAppPage->rCIndex <<endl;
			theApp->uGradAppPage->rCIndex--;
			Course *course = (*(theApp->uGradAppPage->relatedCourse))[theApp->uGradAppPage->rCIndex];
			stringstream ss;
			ss << course->getYear();
			string year = ss.str();
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse1), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year1), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term1), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_finalGrade), "");

			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year1), year.c_str());
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse1), course->getTitle().c_str());
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term1), course->getTerm().c_str());
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_finalGrade), course->getFinal().c_str());
			
		}
	}

}
void RelatedCoursesOneForm::viewNextSection(GtkWidget* widget,WindowApp* theApp){

	if(theApp->uGradAppPage->form->rCourses || theApp->editUApp->rCourses){

		theApp->uGradAppPage->relatedCourse = new Queue<Course>(*(theApp->editUApp->relatedCourses));
		int theSize = 0;
		if(theApp->uGradAppPage->relatedCourse->size() != 0){
			theSize = theApp->uGradAppPage->relatedCourse->size();
		}
		
		
		if(theApp->uGradAppPage->rCIndex < theSize -1){
			cout<< theApp->uGradAppPage->rCIndex <<endl;
			theApp->uGradAppPage->rCIndex++;
			Course *course = (*(theApp->uGradAppPage->relatedCourse))[theApp->uGradAppPage->rCIndex];
			stringstream ss;
			ss << course->getYear();
			string year = ss.str();
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse1), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year1), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term1), "");
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_finalGrade), "");

			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year1), year.c_str());
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse1), course->getTitle().c_str());
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term1), course->getTerm().c_str());
			gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_finalGrade), course->getFinal().c_str());
			
		}
	}
}



void RelatedCoursesOneForm::nextPage(GtkWidget* widget,WindowApp* theApp){
 	if(errorCheck(theApp)){
 		const gchar *s1, *s2, *s3, *s4, *s5;
		string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
		s1 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse1));
		
		s2 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year1));
		s3 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term1));
		s4 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_finalGrade));        
	      
		string1 = (s1);
		string2 = (s2);
		string3 = (s3);
		string4 = (s4);


		int yr = atoi(string2.c_str());
		Course* cor = new Course(string1, yr, string3, "N/A", string4);
		theApp->cQRelated->pushBack(cor);
		theApp->uGradAppPage->form->rCourses = true;
 		RelatedCoursesOneForm::cleanup(theApp);
 		UnderGradAppPage::related2(widget,theApp);
 	}
 	else{

 	}
}

void RelatedCoursesOneForm::cleanup(WindowApp* app){
	gtk_widget_destroy(app->uGradAppPage->form->ei_repeat);
	gtk_widget_destroy(app->uGradAppPage->form->ei_continue);
	gtk_widget_destroy(app->uGradAppPage->form->ei_relatedCourse1);
	gtk_widget_destroy(app->uGradAppPage->form->ei_term1);
	gtk_widget_destroy(app->uGradAppPage->form->ei_year1);
	gtk_widget_destroy(app->uGradAppPage->form->ei_finalGrade);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblRelatedCourse);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblTerm);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblYear);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblFinalGrade);
	gtk_widget_destroy(app->uGradAppPage->form->chkExperience);
	if(!app->canEdit){
		gtk_widget_destroy(app->uGradAppPage->form->nextApp);
		gtk_widget_destroy(app->uGradAppPage->form->prevApp);
		gtk_widget_destroy(app->uGradAppPage->form->nextSection);
		gtk_widget_destroy(app->uGradAppPage->form->nextPage);
		gtk_widget_destroy(app->uGradAppPage->form->prevSection);
		gtk_widget_destroy(app->uGradAppPage->form->prevPage);

	}
}
void RelatedCoursesOneForm::close(GtkWidget* widget, WindowApp* app){
	//app->uGradAppPage->form->experience = false;
	app->uGradAppPage->form->rCourses = false;
	//gtk_window_resize(GTK_WINDOW(app->uGradAppPage->form->window), 400,600);
	//gtk_widget_set_sensitive(app->uGradAppPage->form->submit, TRUE);
	RelatedCoursesOneForm::cleanup(app);
	UnderGradAppPage::related2(NULL, app);
}


void RelatedCoursesOneForm::RelatedCoursesOneForm::popWindow(string s){
	GtkWidget* error_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(error_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(error_window), 400, 200);
	
	gtk_window_set_title(GTK_WINDOW(error_window), "ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	
	GtkWidget* error_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(error_window), error_frame);

	GtkWidget* error_dismiss = gtk_button_new_with_label("Dismiss");
	gtk_widget_set_size_request(error_dismiss , 80, 35);
	gtk_fixed_put(GTK_FIXED(error_frame), error_dismiss , 100, 100);	
	const gchar* message;
	message = s.c_str();
	GtkWidget* error_message = gtk_label_new(message);
	gtk_fixed_put(GTK_FIXED(error_frame), error_message, 10, 10); 


	gtk_widget_show_all(error_window);

	g_signal_connect(error_dismiss, "clicked", G_CALLBACK (RelatedCoursesOneForm::closePopWindow), error_window);
	
}

void RelatedCoursesOneForm::closePopWindow(GtkWidget *widget, GtkWidget *window){
	gtk_widget_destroy(window);
}