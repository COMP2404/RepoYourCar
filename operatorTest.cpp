#include "Model/Job.h"
#include "Model/Course.h"
#include "Model/Student.h"
#include "Model/UndergradStudent.h"
#include "Model/GradStudent.h"
#include "Model/CourseQueue.h"
#include "Model/JobQueue.h"
#include "Model/GradApp.h"
#include "Model/UndergradApp.h"
#include "Model/Application.h"
#include "Model/AppQueue.h"

#include <string>
#include <iostream>
using namespace std;

//////PROTOTYPES/////
//SUBSCRIPT OPERATOR
void testSS(AppQueue&);
//TESTS FOR THE PLUS RELATED OPERATORS
void testPE1(AppQueue&);
void testPE2(AppQueue&);
void testP1(AppQueue&);
void testP2(AppQueue&);
//TESTS FOR THE MINUS RELATED OPERATORS
void testME1(AppQueue&);
void testME2(AppQueue&);
void testM1(AppQueue&);
void testM2(AppQueue&);
//TEST FOR THE NOT OPERATOR
void testN(AppQueue&);

int main(){
	//=========================================TEMPLATES FOR OBJECT PARAMETERS===============================================
	//GradStudent(string first, string last, string email, string studentnum, string research, string program, string supervisor)
	//GradApp(GradStudent *gs, int appNum, string course, string status)

	//UndergradStudent(int cgpa, int gpa, string fisrt, string last, string email, string major, int year, string studentnum)
	//UndergradApp(UndergradStudent *ugs, int appNum, string course, string appstatus)
	//=======================================================================================================================

	/////////////////////STUDENTS/////////////////////////
	GradStudent bill("Bill", "OReily", "baba@carleton.ca", "100928374", "Physics", "super-Jim");
	GradStudent monkeys("Arctic", "Monkeys", "telecaster@carleton.ca", "100934782", "CompSci", "visor");
	GradStudent fun("Fun", "-", "some@carleton.ca", "100828392", "Baking", "lolapalooza");
	GradStudent nana("Naena", "Lapsodpesia", "nights@carleton.ca", "100829372", "Music", "coolguy");
	UndergradStudent george(10, 11, "George", "Lamp", "lamp@carleton.ca", "InteriorLighting", 2, "100998877" );
	UndergradStudent syd(11, 7, "Syd", "Barrett", "shineon@carleton.ca", "Music", 2, "100829372" );
	UndergradStudent valerie(12, 9, "Valerie", "Dee", "goldontheceiling@carleton.ca", "Business", 2, "100346789" );
	UndergradStudent smith(1, 8, "Agent", "Smith", "anderson@carleton.ca", "Anderson", 2, "100101101" );
	////////////////////APPLICATIONS//////////////////////
	GradApp billApp(&bill, 10231, "COMP2401", "pending");
	GradApp monkeyApp(&monkeys, 10232, "COMP2406", "pending");
	GradApp funApp(&fun, 10233, "COMP2406", "pending");
	GradApp nanaApp(&nana, 10234, "COMP3803", "pending");
	UndergradApp georgeApp(&george, 20394, "COMP2404", "pending");
	UndergradApp sydApp(&syd, 20396, "COMP4000", "pending");
	UndergradApp valApp(&valerie, 20397, "COMP3001", "pending");
	UndergradApp smithApp(&smith, 20395, "COMP2404", "pending");

	//////////////////////THE QUEUE///////////////////////
	AppQueue queue;

	//////////////////////POPULATE////////////////////////
	queue.pushBack(&billApp, NULL);
	queue.pushBack(&monkeyApp, NULL);
	queue.pushBack(&funApp, NULL);
	queue.pushBack(&nanaApp, NULL);
	queue.pushBack(NULL, &georgeApp);
	queue.pushBack(NULL, &sydApp);
	queue.pushBack(NULL, &valApp);
	queue.pushBack(NULL, &smithApp);

	/*
	cout<<"\n\nTESTING NEW cOPY CTOR\n\n ";
	Application generalApp = nanaApp;
	cout << generalApp << endl;
	GradApp* copy = dynamic_cast<GradApp*>(&nanaApp);
	cout << *copy << endl;
	*/


	testSS(queue);
	
	testPE1(queue);

	testPE2(queue);

	testP1(queue);

	testP2(queue);

	testME1(queue);

	testME2(queue);

	testM1(queue);

	testM2(queue);

	testN(queue);


	cout<<endl<<endl<<endl;
	return 0;
}

//TEST SUBSCRiPT
void testSS(AppQueue& q){
	cout << "------ABOUT TO TEST THE SUBSCRIPT OPERATOR------" << endl << "." << endl << "." << endl << "." <<endl;
	cout << "------the applications from the queues print------ " << endl << q;
	cout << endl << "." << endl << "." << endl;

	for(int i=0; i< q.size(); i++){
		cout<< "--Printing the app at this subscript: " << i << " " << *(q[i]) << endl;//cascading in effect
	}
}

//TEST +=(Application)
void testPE1(AppQueue& q){
	cout << "------ABOUT TO TEST THE += APPLICATION------" << endl << "." << endl << "." << endl << "." <<endl;
	cout << "------the applications from the queues print------ " << endl << q;
	cout << endl << "." << endl << "." << endl;

	GradStudent castle("Castle", "Rook", "castle@carleton.ca", "100236374", "History", "some dude");
	UndergradStudent lilly(10, 10, "Lillian", "Wutang", "apatosaurus@carleton.ca", "Dinosaurs", 2, "100827348" );
	GradApp* castleApp = new GradApp(&castle, 10290, "COMP4000", "pending");
	UndergradApp* georgeApp = new UndergradApp(&lilly, 20362, "COMP1003", "pending");

	q += castleApp;
	q += georgeApp;

	cout << "---------The Queue with += Applications---------- " << endl << q;

}
//TEST +=(Queue)
void testPE2(AppQueue& q){
	cout << "------ABOUT TO TEST THE += QUEUE------" << endl << "." << endl << "." << endl << "." <<endl;
	cout << "------the new queues print------ " << endl ;
	cout << endl << "." << endl << "." << endl;
	AppQueue tQ;
	cout << tQ <<endl;

	tQ += q;
	cout<<"-------the previous queue has been added to the new queue-----------" <<endl;
	cout<< "--printing the new queue again" << endl << endl;
	cout<< tQ <<endl;

}
//TEST +(Application)
void testP1(AppQueue& q){
	cout << "------ABOUT TO TEST THE + APPLICATION------" << endl << "." << endl << "." << endl << "." <<endl;
	cout << "------making a new grad and undergrad application------ " << endl ;

	GradStudent grad("A", "Grad", "student@carleton.ca", "100991199", "Time Travel", "his son");
	UndergradStudent ugrad(11, 12, "An", "Undergrad", "noreply@carleton.ca", "Quantum Mechanics", 2, "10092843" );
	GradApp* gradapp = new GradApp(&grad, 10399, "COMP3808", "pending");
	UndergradApp* ugradapp = new UndergradApp(&ugrad, 20400, "COMP1406", "pending");

	cout << "---here they are---: " << endl << *ugradapp << endl << *gradapp << endl;
	cout << endl << "." << endl << "." << endl;
	cout << "--Setting new queue equal to old + both new applications" <<endl;
	AppQueue tQ;
	tQ = (q + gradapp); // + ugradapp;
	cout << "------------Here is the resulting queue---------------" <<endl;
	cout << tQ <<endl;
	
}

//TEST +(Queue)
void testP2(AppQueue& q){
	
}

//TEST -=(Application)
void testME1(AppQueue& q){
	
}
//TEST -=(Queue)
void testME2(AppQueue& q){
	
}
//TEST -(Application)
void testM1(AppQueue& q){
	
}
//TEST -(Queue)
void testM2(AppQueue& q){
	
}

//TEST LOGICAL NOT
void testN(AppQueue& q){
	/*
	cout << "------ABOUT TO TEST THE LOGICAL NOT------" << endl << "." << endl << "." << endl << "." <<endl;
	cout << "------the applications from the queues print before operation------ " << endl << q;
	cout << endl << "." << endl << "." << endl;

	!q;

	cout<<endl << "Should be an empty queue: " << endl << q;
	*/
}