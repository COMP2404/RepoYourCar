#include "WindowApp.h"
#include "../Control/Control.h"
#include "AdminPage.h"




int WindowApp::applicationNum;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//have the admin page come up
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void WindowApp::adminPage(GtkWidget *widget, WindowApp *theApp){

	AdminManager *admin = new AdminManager(theApp);

	
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//have the mainmenu come up
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WindowApp::mainMenu(GtkWidget *widget, WindowApp *theApp){
	
	theApp->main = new MainMenu();
	theApp->main->draw();

	g_signal_connect(theApp->main->btnStudent, "clicked", G_CALLBACK(WindowApp::studentPage), theApp);
	g_signal_connect(theApp->main->login, "clicked", G_CALLBACK(WindowApp::adminPage), theApp);
	
}







//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
							//make the application
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int WindowApp::makeApplication(GtkWidget *widget, WindowApp *theApp)
{
	theApp->canEdit = true;
	theApp->appMan = new AppManager(false,theApp);
	theApp->stuPage->close();
}



int WindowApp::makeGradApplication(GtkWidget *widget, WindowApp *theApp)
{
	theApp->canEdit = true;
	theApp->appMan = new AppManager(true,theApp);
	theApp->stuPage->close();

}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//have the student page come up
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowApp::studentPage(GtkWidget *widget, WindowApp *theApp){
	theApp->stuPage = new StudentPage();
	theApp->stuPage->draw(theApp);

	g_signal_connect(theApp->stuPage->student_apply, "clicked", G_CALLBACK (WindowApp::makeApplication), theApp);
	g_signal_connect(theApp->stuPage->grad_apply, "clicked", G_CALLBACK (WindowApp::makeGradApplication), theApp);
	g_signal_connect(theApp->stuPage->student_edit, "clicked", G_CALLBACK (WindowApp::editStudent), theApp);
	g_signal_connect(theApp->stuPage->student_cancel, "clicked", G_CALLBACK (WindowApp::closeStudentPage), theApp);

}

void WindowApp::closeStudentPage(GtkWidget *widget, WindowApp *theApp){
	gtk_widget_destroy(theApp->stuPage->student_window);

}


void WindowApp::editStudent(GtkWidget *widget, WindowApp *theApp){
	gtk_widget_destroy(theApp->stuPage->student_frame);
	theApp->stuPage->chooseApp(theApp);
}






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//submit Apps to main queue
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WindowApp::submitGradApp(WindowApp* theApp){
	//these are to be pushed to related queues incase the user has no info:
	Queue<Course>* quco = new Queue<Course>();
	Queue<Job>*    qujo = new Queue<Job>();//no, not the dog

	bool rTA=false, rWorkExp=false;
	cout<<"submitting grad app" <<endl;
	

	Student* s ;
	
	GradStudent *gs = NULL;
	
	GradApp *ga = NULL;
	UndergradApp *uga = NULL;

	//get all info 

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
	ga = new GradApp(gs, theApp->currAppNumber++, course, "PENDING");

	ofstream outFile("ApplicationNumber.txt", ios::out);

    if (!outFile) {
 
            return;
    }
  	
  	outFile << theApp->currAppNumber << endl;
	
	if(theApp->gradAppPage->form->rTA){
		ga->setRelatedTAPositions(theApp->cQTa);
		ga->rTA = true;
		rTA = true;
	}
	else{
		ga->setRelatedTAPositions(quco);//your queue is empty, no related stuff
		ga->rTA = false;
	}

	if(theApp->gradAppPage->form->rWorkExp){
		ga->setRelatedWorkEXP(theApp->jQRelated);
		ga->rWorkExp = true;
		rWorkExp = true;
	}
	else{
		ga->setRelatedWorkEXP(qujo);//hold this, and get a job while youre at it!
		ga->rWorkExp = false;
	}

	if(theApp->editGMode){
		//replace the original application with this newly made one
		theApp->appQueue.replaceOriginal(theApp->originalApp, ga);
		//update the state of database to include this change
		theApp->appQueue.writeToFile();
	}	
	else{
		//User is making a new grad application
		cout << "Making a new one\n";
		theApp->appQueue.pushBack(ga);//was commented out...
		if(!ga->printApp(true, rTA,rWorkExp))
			return;
	}


}
void WindowApp::submitUGradApp(WindowApp* theApp){
	
	bool rCourses=false, rTA=false, rWorkExp=false;
	

	Student* s ;
	
	GradStudent *gs = NULL;
	UndergradStudent *ugs = NULL;
	
	GradApp *ga = NULL;
	UndergradApp *uga = NULL;

	//Queues with nothing in them for default related info:
	Queue<Course>* quco = new Queue<Course>();
	Queue<Course>* quta = new Queue<Course>();
	Queue<Job>*    qujo = new Queue<Job>();


	//get the info from the form

	string first,last,email, major,year,stunum;
	first = theApp->uGradAppPage->formData->first;
	last = theApp->uGradAppPage->formData->last;
	email = theApp->uGradAppPage->formData->email;
	major = theApp->uGradAppPage->formData->gmajor;
	year = theApp->uGradAppPage->formData->year;
	stunum = theApp->uGradAppPage->formData->stuNum;

	//push the ugrad app to back of queue
	
	cout << "pushing ugrad app" << endl;
	ugs = new UndergradStudent(atoi((theApp->uGradAppPage->formData->GPA).c_str()), atoi((theApp->uGradAppPage->formData->CGPA).c_str()), first, last, email, major, atoi(year.c_str()), stunum);
	uga = new UndergradApp(ugs, theApp->currAppNumber++, theApp->uGradAppPage->formData->course, "PENDING");


	//get the application number and save latest one to file
	ofstream outFile("ApplicationNumber.txt", ios::out);

    if (!outFile) {
          
            return;
    }
  	
  	outFile << theApp->currAppNumber << endl;


  	//set the flags for if each part of related info actually exists or not
	if(theApp->uGradAppPage->form->rCourses){
		uga->setRelatedCourses(theApp->cQRelated);
		uga->rCourses = true;
		rCourses = true;	
	}
	else{
		uga->setRelatedCourses(quco);//give it something so its a valid queue
		uga->rCourses = false;
	}


	if(theApp->uGradAppPage->form->rTA){
		uga->setRelatedTAPositions(theApp->cQTa);
		uga->rTA = true;
		rTA = true;
	}
	else{
		uga->setRelatedTAPositions(quta);//give it something so its able to writeToFile properly
		uga->rTA = false;
	}



	if(theApp->uGradAppPage->form->rWorkExp){
		uga->setRelatedWorkEXP(theApp->jQRelated);
		uga->rWorkExp = true;
		rWorkExp = true;
	}
	else{
		uga->setRelatedWorkEXP(qujo);//give it something so it doesnt seg fault
		uga->rWorkExp = false;
	}


	if(theApp->editUMode){
		cout<< "--The app being edited is:\n"<< *(theApp->originalApp) <<endl;
		cout<< "--with this new app:\n"<< *uga <<endl;
		theApp->appQueue.replaceOriginal(theApp->originalApp, uga);
		//Overwrite the database with the newly edited application:
		theApp->appQueue.writeToFile();
	}
	else{
		//They are making an original application
		theApp->appQueue.pushBack(uga);//was commented out
		if(!uga->printApp(true,rCourses,rTA,rWorkExp))
			return;
	}

	

}

