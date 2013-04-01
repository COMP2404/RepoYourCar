#include "Control.h"
#include <iostream>
//#include "Queue.h"
//`pkg-config gtkmm-3.0 --cflags --libs`

using namespace std;
Application* apples;
int THIS_BUF = 1000;








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
			//submit application once error checking is done

//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Control::submit(string* course, string* first, string* last, int mgpa, int gpa, string* email, int year, string* major, string* stunum, string* area, string* program, string* supervisor, WindowApp *theApp){

	Student* s ;
	//theApp->studentRepeat = s;
	GradStudent *gs = NULL;
	UndergradStudent *ugs = NULL;
	//Application *a;
	GradApp *ga = NULL;
	UndergradApp *uga = NULL;
	if(theApp->gradApp){
		cout << "pushing grad app" << endl;
		gs = new GradStudent(*first, *last, *email, *stunum, *area, *program, *supervisor);
		//a  = new Application(gs, ugs,applicationNum++, *course, "PENDING");
		ga = new GradApp(gs, theApp->applicationNum++, *course, "PENDING");
		//ga->setRelatedTAPositions(theApp->cQTa);
		//ga->setRelatedWorkEXP(theApp->jQRelated);
		//theApp->appQueue.pushBack(ga);
		if(!ga->printApp(true))
				return false;
	}
	else{
		cout << "pushing ugrad app" << endl;
		ugs = new UndergradStudent(gpa, mgpa, *first, *last, *email, *major, year, *stunum);
		//a  = new Application(gs, ugs, applicationNum++, *course, "PENDING");
		//uga = new UndergradApp(ugs, applicationNum++, *course, "PENDING");
		uga = new UndergradApp(ugs, theApp->applicationNum++, *course, "PENDING");
	//	uga->setRelatedCourses(theApp->cQRelated);
	//	uga->setRelatedTAPositions(theApp->cQTa);
	//	uga->setRelatedWorkEXP(theApp->jQRelated);
		//theApp->appQueue.pushBack(uga);
		if(!uga->printApp(true))
				return false;
	}
	//Application *a = new Application(s, applicationNum++, *course, "PENDING");
	
	
	//theApp->studentApp = a;
	//theApp->appQueue.pushBack(a);
	//theApp->appQueue.isEmpty();
	

	//Control::printApp(a);
	//if(!a->printApp(theApp->gradApp))
	//	return false;

	
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



void Control::loadApplications(WindowApp *theApp){
	char text[80];

	ifstream inFile("Applications.txt", ios::in);

	//Variables used to build an application
	int     a, cgpa, mgpa, y;
	string  c, s, f, l, e, m, i, program, area, supervisor;
	bool aGrad;
	//CourseQueue *aCourseQueue = new CourseQueue();
	//CourseQueue *bCourseQueue = new CourseQueue();
	//JobQueue *jQueue = new JobQueue();	

	//Varibles used to build a course
	int cYear;
	string cSuper, cTitle, cTerm;	

	//Variables used to build a job
	string jTitle, jDuration, jStart, jEnd, jTasks;
	string anArray[100];
	
  	if (!inFile) {
    		cout<<"Could not open file"<<endl;
    		return;
  	}

	while (!inFile.eof()) {
		Queue<Course>* relatedC = new Queue<Course>();
		Queue<Course>* relatedT = new Queue<Course>();
		Queue<Job>*    relatedJ = new Queue<Job>();
		
		inFile.getline(text, THIS_BUF); // application type
		
		if (strlen(text) == 0){
			break;
		}		

		//if(strcmp(text, "ENDOFFILEMARKER") == 0){
	//		break;
	//	}

		if(strcmp(text, "underGrad") == 0)
		{	
			cout << "UNDERGRADUATE APP" << endl;
			aGrad = false;
			inFile.getline(text, THIS_BUF); // application number  
			a = atoi(text);
			theApp->applicationNum = a;
			inFile.getline(text, THIS_BUF); // application course
			 
			c = text;
			inFile.getline(text, THIS_BUF); // application status
			 
			s = text;
			inFile.getline(text, THIS_BUF); // cGPA
			 
			cgpa = atoi(text);
			inFile.getline(text, THIS_BUF); // mGPA
			 
			mgpa = atoi(text);
			inFile.getline(text, THIS_BUF); // First Name
			 
			f = text;
			inFile.getline(text, THIS_BUF); // Last Name
			 
			l = text;
			inFile.getline(text, THIS_BUF); // Email
			 
			e = text;
			inFile.getline(text, THIS_BUF); // Major
			 
			m = text;
			inFile.getline(text, THIS_BUF); // Year Standing
			
			y = atoi(text);
			inFile.getline(text, THIS_BUF); // Student Number
			
			i = text;
				
		}
		else{
			aGrad = true;
			inFile.getline(text, THIS_BUF); // application number 
		
			a = atoi(text);
			inFile.getline(text, THIS_BUF); // application course
			
			c = text;
			inFile.getline(text, THIS_BUF); // application status
			
			s = text;
			inFile.getline(text, THIS_BUF); // program
			
			program = text;
			
			inFile.getline(text, THIS_BUF); // area
			
			area = text;
			inFile.getline(text, THIS_BUF); // First Name
			
			f = text;
			inFile.getline(text, THIS_BUF); // Last Name
			
			l = text;
			inFile.getline(text, THIS_BUF); // Email
			
			e = text;
			inFile.getline(text, THIS_BUF); // supervisor
			
			supervisor = text;
			inFile.getline(text, THIS_BUF); // Student Number
			
			i = text;
		}	
		
		//read an entire application
		
		
		

		//read the related courses
		
		
		if (!aGrad){
		
			while (1){ //untill you get to the TA positions
				inFile.getline(text, THIS_BUF);
				
				if(strcmp(text, "RELATEDTAPOSITIONS") == 0)
				{	
					
					break;
					
				}
				cTitle = text;

				
				inFile.getline(text, THIS_BUF);
				
				cSuper = text;
				inFile.getline(text, THIS_BUF);
						
				cYear = atoi(text);
				inFile.getline(text, THIS_BUF);
				
				cTerm = text;
				
				//make a course with the information and "N/A" supervisor
				Course *cor = new Course(cTitle, cYear, cTerm, "N/A", cSuper);
				
				relatedC->pushBack(cor);	
				
					
			}
		
		}
		else{
			inFile.getline(text, THIS_BUF); //be sure to read the header
		}			

		//read the related TA positions
		
		
		while (1){

			inFile.getline(text, THIS_BUF);			
				
					
			if(strcmp(text, "WORKEXP") ==0)
			{
				
				break;
				
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
			relatedT->pushBack(bcor);	
			
		}
		//read the related Work EXP
		
		while (1){
			inFile.getline(text, THIS_BUF);
					
			if(strcmp(text, "ENDAPP") ==0)
			{
				
				break;
				
			}
			
			jTitle = text;
			inFile.getline(text, THIS_BUF);
			jTasks = text;
			
			inFile.getline(text, THIS_BUF);
			jDuration = text;
			
			inFile.getline(text, THIS_BUF);
			jStart = text;
			
			inFile.getline(text, THIS_BUF);
			jEnd = text;
			

			Job *aJob = new Job(jTitle, jTasks, jDuration, jStart, jEnd);
			relatedJ->pushBack(aJob);
			
		}

		//NOW initialise an application
		
		GradApp *ga = NULL;
		UndergradApp *uga = NULL;
		if(aGrad){
			GradStudent *stu = new GradStudent(f, l, e, i, area, program, supervisor);
			ga = new GradApp(stu, a,c,s);
			ga->setRelatedTAPositions(relatedT);
			ga->setRelatedWorkEXP(relatedJ);
			theApp->appQueue.pushBack(ga);
		}
		else{
			
			UndergradStudent *stu = new UndergradStudent(cgpa, mgpa, f, l, e, m, y, i);
			uga = new UndergradApp(stu,a,c,s);
			uga->setRelatedCourses(relatedC);
			uga->setRelatedTAPositions(relatedT);
			uga->setRelatedWorkEXP(relatedJ);
			theApp->appQueue.pushBack(uga);
		}
		
			
  	}
 
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************************************************************************************************//
		//create the main window
//**********************************************************************************************************************************************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Control::createWindow(int argc, char** argv)
{
	cout << "In Control CreateWindow" <<endl;
	WindowApp *theApp = new WindowApp();
	theApp->cQRelated = new Queue<Course>();
	theApp->cQTa = new Queue<Course>();
	theApp->jQRelated = new Queue<Job>();
	
	// initialize GTK+
	gtk_init(&argc, &argv);
	loadApplications(theApp);
	/*theApp->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	//cout << "app loaded" << endl;
	gtk_window_set_position(GTK_WINDOW(theApp->window), GTK_WIN_POS_CENTER);
	
	gtk_window_set_default_size(GTK_WINDOW(theApp->window), 400, 200);
	//gtk_window_resize(GTK_WINDOW(theApp->window), 600,300);
	gtk_window_set_title(GTK_WINDOW(theApp->window), "Main Menu");
	//cout << "Calling WindowApp mani menu" <<endl;*/
	WindowApp::mainMenu(NULL, theApp);
	

	gtk_main();
	return 0;
}
