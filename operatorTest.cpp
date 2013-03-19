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
	cout << "For maximum clarity, please enlarge your window to the fullest\n\n";
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
	UndergradApp* lApp = new UndergradApp(&lilly, 20362, "COMP1003", "pending");

	cout << "----created applications for Castle and Lillian----\n";

	q += castleApp;
	q += lApp;

	cout << "---------The Queue with += on the new applications---------- " << endl << q;

}
//TEST +=(Queue)
void testPE2(AppQueue& q){
	cout << "------ABOUT TO TEST THE += QUEUE------" << endl << "." << endl << "." << endl << "." <<endl;
	cout << "------Making a new queue:------ " << endl ;
	cout << endl << "." << endl << "." << endl;
	AppQueue tQ;
	cout << tQ <<endl;

	cout << "Adding a couple applications to the queue (Dick and Jane):\n";
	/////////////////////STUDENTS/////////////////////////
	GradStudent dick("Richard", "Dick", "rick@carleton.ca", "100726374", "Chemistry", "Bobby-tables");
	UndergradStudent jane(10, 11, "Jane", "LastName", "jane@carleton.ca", "Biology", 2, "100992677" );
	////////////////////APPLICATIONS//////////////////////
	GradApp* dickApp = new GradApp(&dick, 10413, "COMP3308", "pending");
	UndergradApp* janeApp = new UndergradApp(&jane, 20412, "COMP1001", "pending");
	//push them to the new queue:
	tQ.pushBack(dickApp, NULL);
	tQ.pushBack(NULL, janeApp);

	cout << "-----here is the queue with dick and jane:-----\n" << tQ << endl;

	cout << "-----here is another queue:------\n" << q << endl << endl;

	cout<<"-----adding this queue to the smaller queue:-------" <<endl;
	tQ += q;//TEST THE += OPERATOR FOR QUEUE&
	cout<< "---printing the result queue" << endl << endl;
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
	cout << "---Setting new queue equal to old + both new applications---" <<endl;
	AppQueue tQ;
	//tQ = (q + gradapp); // + ugradapp;
	cout << "------------Here is the resulting queue---------------" <<endl;
	//cout << tQ <<endl;
	
}

//TEST +(Queue)
void testP2(AppQueue& q){
	
}

//TEST -=(Application)
void testME1(AppQueue& q){
	cout << "------ABOUT TO TEST THE -= APPLICATION------" << endl << "." << endl << "." << endl << "." <<endl;
	cout << "------the applications from the queues print------ " << endl << q;
	cout << endl << "." << endl << "." << endl;

	GradStudent castle("Castle", "Rook", "castle@carleton.ca", "100236374", "History", "some dude");
	UndergradStudent lilly(10, 10, "Lillian", "Wutang", "apatosaurus@carleton.ca", "Dinosaurs", 2, "100827348" );
	//these applications already exist in the queue as per the applications '==' operator.
	GradApp* castleApp = new GradApp(&castle, 10290, "COMP4000", "pending");
	UndergradApp* georgeApp = new UndergradApp(&lilly, 20362, "COMP1003", "pending");

	//remove them from the queue
	q -= castleApp;
	q -= georgeApp;

	cout << "---------The Queue after -= Castle and Lillian applications---------- " << endl << q;

	cout <<"------A huge success! now trying again with the FUN application-----\n";

	GradStudent fun("Fun", "-", "some@carleton.ca", "100828392", "Baking", "lolapalooza");
	GradApp* funApp = new GradApp(&fun, 10233, "COMP2406", "pending");

	q -= funApp;

	cout << "---------The Queue after -= FUN application---------- " << endl << q;
}
//TEST -=(Queue)
void testME2(AppQueue& q){
	cout << "------ABOUT TO TEST THE -= QUEUE------" << endl << "." << endl << "." << endl << "." <<endl;
	cout << "------the applications from the queues print------ " << endl << q;

	cout << "------building some applications and inserting them in a new queue\n";
	///////////////////STUDENTS///////////////////////////
	GradStudent bill("Bill", "OReily", "baba@carleton.ca", "100928374", "Physics", "super-Jim");
	GradStudent monkeys("Arctic", "Monkeys", "telecaster@carleton.ca", "100934782", "CompSci", "visor");
	GradStudent nana("Naena", "Lapsodpesia", "nights@carleton.ca", "100829372", "Music", "coolguy");
	GradStudent someguy("honey nut", "cheerios", "cheerio@carleton.ca", "100726209", "Health Sciences", "Dr. Oz");
	UndergradStudent george(10, 11, "George", "Lamp", "lamp@carleton.ca", "InteriorLighting", 2, "100998877" );
	UndergradStudent syd(11, 7, "Syd", "Barrett", "shineon@carleton.ca", "Music", 2, "100829372" );
	UndergradStudent valerie(12, 9, "Valerie", "Dee", "goldontheceiling@carleton.ca", "Business", 2, "100346789" );
	UndergradStudent smith(1, 8, "Agent", "Smith", "anderson@carleton.ca", "Anderson", 2, "100101101" );
	UndergradStudent oogly(12, 12, "Oogly", "Woogly", "oogly@carleton.ca", "Culinary Arts", 3, "100363672");
	////////////////////APPLICATIONS//////////////////////
	GradApp* billApp = new GradApp(&bill, 10231, "COMP2401", "pending");
	GradApp* monkeyApp = new GradApp(&monkeys, 10232, "COMP2406", "pending");
	GradApp* nanaApp = new GradApp(&nana, 10234, "COMP3803", "pending");
	GradApp* someApp = new GradApp(&someguy, 10888, "COMP1406", "pending");
	UndergradApp* georgeApp = new UndergradApp(&george, 20394, "COMP2404", "pending");
	UndergradApp* sydApp = new UndergradApp(&syd, 20396, "COMP4000", "pending");
	UndergradApp* valApp = new UndergradApp(&valerie, 20397, "COMP3001", "pending");
	UndergradApp* smithApp = new UndergradApp(&smith, 20395, "COMP2404", "pending");
	UndergradApp* ooglyApp = new UndergradApp(&oogly, 21000, "COMP2001", "pending");

	//A queue for the apps
	AppQueue qu;
	//Push all these apps to the queue
	qu.pushBack(billApp, NULL);
	qu.pushBack(monkeyApp, NULL);
	qu.pushBack(nanaApp, NULL);
	qu.pushBack(someApp, NULL);
	qu.pushBack(NULL,  georgeApp);
	//qu.pushBack(NULL,  sydApp);
	qu.pushBack(NULL,  valApp);
	qu.pushBack(NULL,  smithApp);
	qu.pushBack(NULL,  ooglyApp);

	cout << "---The queue is loaded, here it is: notice it has a couple applications not in the target queue\n";
	cout << qu;
	cout << "---Here is the target Queue:\n" << q;
	cout << "---Performing target -= new\n";
	q -= qu;
	cout << "---here is the result...it should only have syd's application\n" << q; 

	//empty the queue
	q -= sydApp;
	cout << "---and now it should be empty...\n" << q << endl;

}
//TEST -(Application)
void testM1(AppQueue& q){
	
}
//TEST -(Queue)
void testM2(AppQueue& q){
	
}

//TEST LOGICAL NOT
void testN(AppQueue& q){
	
	cout << "------ABOUT TO TEST THE LOGICAL NOT------" << endl << "." << endl << "." << endl << "." <<endl;
	cout << "------Populating the queue...(generating dinos!)------\n";

	///////////////////STUDENTS///////////////////////////
	GradStudent steg("Stegasaurus", "", "dino1@carleton.ca", "100628374", "Dinosaurs", "");
	GradStudent apat("Apatosaurus", "", "dino2@carleton.ca", "100623374", "Dinosaurs", "");
	GradStudent lamb("Lambeosaur", "", "dino3@carleton.ca", "100628374", "Dinosaurs", "");

	UndergradStudent pac(12, 9, "Pachycephalasaurus", "", "dino4@carleton.ca", "Dinosaurs", 3, "100386789" );
	UndergradStudent rex(1, 8, "Nano-Tyrannosaur", "", "dino5@carleton.ca", "Anderson", 3, "100101199" );
	UndergradStudent ank(12, 12, "Ankylosaurus", "", "dino6@carleton.ca", "Culinary Arts", 4, "100367672");
	////////////////////APPLICATIONS//////////////////////
	GradApp* stegA = new GradApp(&steg, 10388, "COMP2401", "pending");
	GradApp* apatA = new GradApp(&apat, 10389, "COMP2406", "pending");
	GradApp* lambA = new GradApp(&lamb, 10390, "COMP3803", "pending");

	UndergradApp* pacA = new UndergradApp(&pac, 20323, "COMP3001", "pending");
	UndergradApp* rexA = new UndergradApp(&rex, 20311, "COMP2404", "pending");
	UndergradApp* ankA = new UndergradApp(&ank, 22001, "COMP2001", "pending");

	//A queue for the apps
	AppQueue qu;
	//Push all these apps to the queue
	q.pushBack(stegA, NULL);
	q.pushBack(apatA, NULL);
	q.pushBack(lambA, NULL);

	q.pushBack(NULL,  pacA);
	q.pushBack(NULL,  rexA);
	q.pushBack(NULL,  ankA);


	cout << "------the applications from the queues print before operation------ " << endl << q;
	cout << endl << "." << endl << "." << endl;

	cout << "---Emptying the queue with !Queue operator---\n";
	//empty the queue
	!q;

	cout<< endl << "---Should be an empty queue---: " << endl << q;

	cout<< endl << "Ensuring the queue is still functional by re-adding a couple applications\n";
	//re-add a couple apps to q:
	q.pushBack(NULL, pacA);
	q.pushBack(stegA, NULL);
	
	cout << "---queue should now have two applications:---\n" << q <<endl;

}