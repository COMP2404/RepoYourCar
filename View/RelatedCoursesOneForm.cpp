#include "RelatedCoursesOneForm.h"

void RelatedCoursesOneForm::create(WindowApp *app){
	
	//resize the window to accomodate the new widgets
	gtk_window_resize(GTK_WINDOW(app->uGradAppPage->form->window), 800,600);
	
	/////////////////////////////////////////////////////
	//-----------Put Labels on Entries---------------////
	/////////////////////////////////////////////////////
	
	app->uGradAppPage->form->ei_lblRelatedCourse = gtk_label_new("Related Course :");
	app->uGradAppPage->form->ei_lblTerm = gtk_label_new("Term :");
	app->uGradAppPage->form->ei_lblYear = gtk_label_new("Year :");
	app->uGradAppPage->form->ei_lblFinalGrade = gtk_label_new("Final Grade :");

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

	gtk_widget_set_size_request(app->uGradAppPage->form->ei_continue, 80, 35);
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_continue, 450, 430);
	
	gtk_widget_set_size_request(app->uGradAppPage->form->ei_repeat, 80, 35);
	gtk_fixed_put(GTK_FIXED(app->uGradAppPage->form->appFrame), app->uGradAppPage->form->ei_repeat, 550, 430);
	gtk_widget_show_all(app->uGradAppPage->form->appFrame);


	/////////////////////////////////////////////////////
	//-----------Make Buttons Not Clickable-------------////
	/////////////////////////////////////////////////////

	
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
			unsigned validRC1 = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  			unsigned validterm1 = (string3).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned grade = (string4).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			
			if (validRC1 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRC1];
				cout << ", at position " << validRC1 << endl;
				//WindowApp::popWindow("You entered a non-alphabetical character in Related Courses", theApp);
				return false;
		   	}
			
  
			else if (validterm1 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm1];
				cout << ", at position " << validterm1 << endl;
				//WindowApp::popWindow("You entered a non-alphabetical character in term", theApp);
				return false;
		   	}

			
			else if (grade != string::npos) {
				cout << "Please Enter a Letter Grade" << endl;
				//WindowApp::popWindow("Please Enter a Letter Grade", theApp);
				return false;return false;
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				//WindowApp::popWindow("Year must be between 1990 and 2013", theApp);
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
		
	}
	else{

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
}