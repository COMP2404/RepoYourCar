#ifndef QUEUE_H
#define QUEUE_H

#include "Application.h"
#include "Node.h"
/////////////////////////////////////////////////////////
//Template Queue class to store a collection of objects//
/////////////////////////////////////////////////////////
template <class T>
class Queue
{

  public:
    //Members
    Node<T>* head;	
    /////////////
    //Functions//
    /////////////
    //Templated Functions:
    Queue();
    ~Queue();
    Queue(Queue&);
    void     pushBack(T*); //adds an item to the back of the queue
    T*     popFront(); //removes the first item from the queue
    T*    front();
    bool     isEmpty();
    Node<T>*    createNode(T*);
    int      size() const;
    void     print() const;

    ///////////////////OPERATORS/////////////////////
    T* operator[](int);//returns application at index param
    Queue& operator+=(T*);//adds the application to the queue
    Queue& operator+=(Queue<T>&);//concatinates the incoming queue to *this
    Queue  operator+(T*);//makes new queue with += functionality
    Queue  operator+(Queue<T>&);//makes new queue with += functionality
    Queue& operator-=(T*);//removes this app from the queue if contained
    Queue& operator-=(Queue<T>&);//removes all elements from incoming queue from this if contained
    Queue  operator-(T*);//created new queue with all but incomint app
    Queue  operator-(Queue<T>&);//creates a new queue with all but apps from incoming 
    Queue& operator!();//logical not: empties the queue
    Queue& operator=(const Queue<T>&);
	
    //TO DO:
    //friend ostream&  operator<<(ostream&, AppQueue&);


    //Non templated functions:
    Queue<T>*    getPendingList(string);
    Queue<T>*    sortByGPA(void);
    Queue<T>*    sortAll(void);
    int          getNumCourses(void);
    bool         appExists(string);
    int          getIndex(Application*);
    Queue<T>*    getAppsByName(string, string);
    Queue<T>*    getAppsByCourse(string);
    Queue<T>*    getAssignedList();
    void         assignSuccesfulCandidate(Application*);
    T* getOriginal(Application*);
    bool         writeToFile(void);
    bool         saveSummaries(void);
        
};

/////////////////////////////////////
//TEMPLATED FUNCTION IMPLEMENTATION//
/////////////////////////////////////

template <class T>
Queue<T>::Queue(){
	head = NULL;
}

template <class T>
Queue<T>::~AppQueue(){
	//cout<<"Destruction"<<endl;
	Node<T>* tmpNode = head;
	Node<T>* dNode;
	//go through the list freeing all nodes
	while(tmpNode != NULL){		
		dNode=tmpNode;	
		//cout<<"about to advance in destructor"<<endl;
		tmpNode=tmpNode->next;
		//cout << "deleting node: " << endl;
		delete dNode;	
	}
}

template <class T>
Queue<T>::Queue<T>(Queue<T>& q){

	//VARS FOR NEW STUDENT AND APPLICATION
	string first, last, em, snum, res, pro, sup, major;
	int yr, cg, mg;
	//GradApp* ga;
	Application *theApp;
	//UndergradApp* ua;
	//cout << "IN COPY CTOR\n";
	if(q.head==NULL) return;


	Node<T>* tmp = q.head;//iteration node for original AppQueue
	head = new Node<T>();//head node for the new AppQueue

	Node<T>* nPrev;//to connect the nodes in q
	Node<T>* nTmp = head;//iteration node for q
	while(tmp != NULL){	

		//Replace the following commented section by Application->getBasicInfo
		//or something... Application->buildStudent too

/* 
		//GET BASIC iNFO
		first = tmp->data->getStuFirst();
		last = tmp->data->getStuLast();
		em = tmp->data->getStuEmail();
		snum = tmp->data->getStuID();

		if(tmp->data->getType() == "grad"){
			GradApp* tmpGApp = static_cast<GradApp*>(tmp->data);//now its a grad app
			//GET GRAD INFO
			res = tmpGApp->getStuArea();
			pro = tmpGApp->getStuProgram();
			sup = tmpGApp->getStuSuper();
			GradStudent* gs = new GradStudent(first, last, em, snum, res, pro, sup);
			ga = new GradApp(gs, tmpGApp->getApplicationNumber(), tmpGApp->getCourse(), tmpGApp->getStatus());
			nTmp->data = ga;
		}
		else{
			UndergradApp* tmpUApp = static_cast<UndergradApp*>(tmp->data);
			//GET UNDERGRAD INFO
			yr = tmpUApp->getStuYrStanding();
			cg = tmpUApp->getStuCGPA();
			mg = tmpUApp->getStuMGPA();
			major = tmpUApp->getStuMajor();
			UndergradStudent* us = new UndergradStudent(cg, mg, first, last, em, major, yr, snum);
			ua = new UndergradApp(us, tmpUApp->getApplicationNumber(), tmpUApp->getCourse(), tmpUApp->getStatus());
			nTmp->data = ua;
		}
*/	

		nPrev = nTmp;//make prev node this node before moving on	
		tmp = tmp->next;//advance iteration node for source Queue
		if(tmp != NULL){
			Node<T>* node = new Node<T>();//make a new node for each existing node		
			nTmp = node;
			nPrev->next=nTmp;
		}
		//connect the nodes in the new Queue	
	}

}

template <class T>
void Queue<T>::pushBack(T *theData){
	
	Node<T>* node = createNode(theData);
	Node<T>* tmpNode = head;
	if(head == NULL){
		head = node;		
		return;
	}
	
	//get the last node in the list
	while(tmpNode->next != NULL){
		tmpNode=tmpNode->next;
	}
	//concatinate the new node with the list
	tmpNode->next = node;
}

//removes the first item from the queue
template <class T>
T* Queue<T>::popFront(){ 
	if(head==NULL) return NULL;//nothing in the list
	Node<T>* tmpNode = head;	
	head = head->next;//sets head to NULL if only one item in the list
	return tmpNode->data;
}

//returns the first item in the queue
template <class T>
T* Queue<T>::front(){
	if(head==NULL) return NULL;
	return head->data;
}

//returns if the Queue is empty.
template <class T>
bool Queue<T>::isEmpty(){
	return(head==NULL);
}

//returns a node with the application data inside it
template <class T>
Node<T>* Queue<T>::createNode(T *theData){
	Node<T>* tempNode = new Node<T>();
	tempNode->data = theData;
	tempNode->next = NULL;
	return tempNode;
}

template <class T>
int Queue<T>::size() const{
  int count = 0;
  Node<T> tempNode = head;
  while (tempNode != NULL){
  ++count;
  tempNode = tempNode->next;
  }
  return count;
}

template <class T>
void Queue<T>::print() const{
  //impletment
}

//constructors + operators

////////////////////////////////////////////////////
//FUNCTION IMPLEMENTATIONS FOR APPLICATION QUEUES///
////////////////////////////////////////////////////

//return a subset Queue of pending applications by specified course code
template <class T>  // <-- Still need this here though, every time
Queue<T>* Queue<T>::getPendingList(string course){
	//------Get a copy of the working Queue-------
	bool all = false;
	if(course == "all" || course == "ALL") all = true;

	Queue<T>& copy = *this;

	Queue<T>* list = new Queue<T>(copy);//call copy contructor
	cout << "In Pending List" << endl;
	if(head == NULL){//the working AppQueue is empty
		//list->head = NULL;
		cout << "In Pending List" << endl;
		return list;
	}
	//------Make the head a wanted node--------	
	Node<T>* tmpNode = list->head;
	cout<<tmpNode->data->getCourse() << endl; //is application.
	while(tmpNode!=NULL){
		
		cout<< course<< endl;
		if( (tmpNode->data->getCourse().compare(course) == 0 || all) && (tmpNode->data->getStatus() == "PENDING" || tmpNode->data->getStatus() == "pending") ){
			cout << " adding the course " + tmpNode->data->getCourse() << endl;
			list->head = tmpNode;
			break;
		}
		tmpNode=tmpNode->next;
	}
	if(tmpNode == NULL){
		if(list->head->data->getCourse().compare(course) != 0){
			 Queue<T>* finalQ = new Queue<T>();
			return finalQ;
		}
	}
	//------Remove unwanted nodes from Queue------
	tmpNode = list->head;
	Node<T>* prevNode = tmpNode;

	while(tmpNode != NULL){
		if(tmpNode->data->getCourse().compare(course) != 0  && !all){//not same course
			
			prevNode->next = tmpNode->next;//cut out the node that doesnt belong			
		}
		else if(tmpNode->data->getStatus() != "PENDING" && tmpNode->data->getStatus() != "pending"){//its not pending
			prevNode->next = tmpNode->next;//cut out the node that doesnt belong
		}
		else{
			cout<< "prev to temp" << endl;
			prevNode=tmpNode;//advance iteration node
			cout<< "prev to temp2" << endl;
		}
		tmpNode=tmpNode->next;   //advance iteration node
	}
	
	return list;
}


template <class T>
Queue<T>* Queue<T>::sortByGPA(){
  //look at AppQueue.cpp
}

template <class T>
Queue<T>* Queue<T>::sortAll(){
	string allCourses[100];
	int numCourses = 0;

	ifstream inFile("courses.txt", ios::in);

	if (!inFile) {
		cout << "no file!!!" << endl;
	}	
	while (getline(inFile, allCourses[numCourses])) {
		cout << "Added a course!: " << numCourses << endl;
		numCourses++;		
	}

	string courseList[MAX_BUF];
	
	int theNum = 0;//index/counter for courseList
	cout<<"here we go\n";
	for(int k=0; k<40; k++){//for all Above courses^^
		if(appExists(allCourses[k])){
			courseList[theNum++] = allCourses[k];
			cout<<"found a course: " << allCourses[k] <<endl;
		}
	}
	/////////////////////////FIRST PART//////////////////////////
	cout<<"here we go2\n";
	int i=0;//index for numCourses(first dimension)
	int j=0;//index for appArr
	bool swapped;
	int count = size();
	int courses = getNumCourses();
	Queue<T>* sorted = new Queue<T>();//new linked list in sorted order

	Node<T>* tmp = head;

	//GradApp* tempGApp;
	//UndergradApp* tempUApp;
	Application* tempApp;

	//Application* appArr[MAX_BUF];//2D-list of applications to be sorted..all courses and all applications of that course.
	cout<<"here we go3\n";
	//arrays for undergrads and grads
	int unum = 0;
	Application* unders[MAX_BUF];
	int gnum = 0;
	Application* grads[MAX_BUF];
	//-----------GET A LIST OF APPLICATIONS SORTED BY COURSE----------//
	//----------ASSIGN THE APPLICATIONS TO APParrays BASED ON APPLICANT GRAD/UNDERGRAD-------------//
	for(i=0; i<theNum; i++){//for all courses
		tmp = head;
		while(tmp != NULL){
			if(tmp->data->getCourse().compare(courseList[i]) == 0){
				if(tmp->data->getType() == "grad")
					grads[gnum++] = tmp->data;

				else
					unders[unum++] = tmp->data;
			}
			tmp=tmp->next;		
		}
	}
	//-----------SORT THE UNDERGRAD APPLICATIONS BY GPA------------//
	cout<<"here we go5\n";
	for(int i=unum-1; i>=0; i--){//BSORT
                swapped = false;
                for(int j=0; j<i; j++){//this swaps them if they shoud be
			if(unders[j]->getCourse().compare(unders[j+1]->getCourse()) == 0){//if they arent in the same course dont sort them by GPA, move on
		                if(unders[j]->getStuMGPA() > unders[j+1]->getStuMGPA()){
		                        tempApp = unders[j+1];
		                        unders[j+1] = unders[j];
		                        unders[j]=tempApp;
		                        swapped=true;
		                }
			}
                }
                if(!swapped) break;
        }
	//-----------SORT THE GRAD APPLICATIONS BY ALPHA------------//
	cout<<"here we go6\n";
	for(int i=gnum-1; i>=0; i--){//BSORT
                swapped = false;
                for(int j=0; j<i; j++){//this swaps them if they shoud be
			if(grads[j]->getCourse().compare(grads[j+1]->getCourse()) == 0){//if they arent in the same course dont sort them by Name, move on

		                if(grads[j]->getStuArea() > grads[j+1]->getStuArea()){

		                        tempApp = grads[j+1];
		                        grads[j+1] = grads[j];
		                        grads[j]=tempApp;
		                        swapped=true;
		                }
			}
                }
                if(!swapped) break;
        }
	//-----------FINALLY, PUSH THESE EFFERS TO THE SORTED QUEUE!--------------//
	cout<<"here we go7\n";
	for(int i=0; i<gnum; i++){	
		//cout << "d\n";
		sorted->pushBack(grads[i]);
	}
	for(int i=0; i<unum; i++){	
		//cout << "d\n";
		sorted->pushBack(unders[i]);
	}
	
	cout<<"went!\n";
	return sorted;
	
}

template <class T>
int Queue<T>::getNumCourses(){
	bool in = false;
	string contained[MAX_BUF];
	Node<T>* tmp = head;

	if(isEmpty()) return 0;//no courses cause no thangs at all
	int num = 0;

	while(tmp != NULL){
		in = false;//not contained
		for(int i=0; i<MAX_BUF; i++) {
			if(contained[i].compare(tmp->data->getCourse()) == 0){ // ??getcourse??
				in = true;
				break;
			}
		}
		if(!in){
			contained[num++] = tmp->data->getCourse();
		}
		tmp=tmp->next;
	}

	return num;
}

template <class T>
bool Queue<T>::appExists(string app){
	Node<T>* tmp = head;
	while(tmp != NULL){
		//cout<< tmp->data->getCourse() << endl;
		if(tmp->data->getCourse().compare(app) == 0)
			return true;
		tmp = tmp->next;
	}
	return false;
}

template <class T>
int Queue<T>::getIndex(Application* app){
	Node<T>* tmp = head;
	int i = 0;
	while(tmp != NULL){//for all applications
		if( *(tmp->data) == *app)//if it satisfies the application's '=='
			return i;//this is it's index
		tmp = tmp->next;
	}
	return -1;
}

template <class T>
Queue<T>* Queue<T>::getAppsByName(string name, string last){
	//Application* ga;
	//Application* ua;
	Application* theApp;
	Node<T>* tmp = head;
	Queue<T>* nQ = new Queue<T>();//this will only hold applications from a specific person
	while(tmp != NULL){//for all applications
			theApp = (tmp->data);
			if(theApp->getStuName() == name && theApp->getStuLast() == last){//if they are by the target person
				nQ->pushBack(tmp->data);
			}
		tmp = tmp->next;
	}
	return nQ;
}

template <class T>
Queue<T>* Queue<T>::getAppsByCourse(string course){
	//------Get a copy of the working Queue-------
	
	Queue<T>& copy = *this;

	Queue<T>* list = new Queue<T>(copy);//call copy contructor
	if(head == NULL){//the working AppQueue is empty
		//list->head = NULL;
		return list;
	}
	//------Make the head a wanted node--------	
	Node<T>* tmpNode = list->head;
	while(tmpNode!=NULL){

		if(tmpNode->data->getCourse().compare(course) == 0 ){
			cout << tmpNode->data->getCourse() << endl;
			list->head = tmpNode;
			break;
		}
		tmpNode=tmpNode->next;
	}
	if(tmpNode == NULL){
		if(list->head->data->getCourse().compare(course) != 0){
			 Queue<T>* finalQ = new Queue<T>();
			return finalQ;
		}
	}
	//------Remove unwanted nodes from Queue------
	tmpNode = list->head;
	Node<T>* prevNode = tmpNode;

	while(tmpNode != NULL){
		if(tmpNode->data->getCourse().compare(course) != 0){//not same course
			prevNode->next = tmpNode->next;//cut out the node that doesnt belong			
		}
		else{
			prevNode=tmpNode;//advance iteration node
		}
		tmpNode=tmpNode->next;   //advance iteration node
	}
	
	return list;
}

template <class T>
Queue<T>* Queue<T>::getAssignedList(){
	//------Get a queue of assigned applications-------
	
	Queue<T>* Q = new Queue<T>();
	//GradApp* ga;
	//UndergradApp* ua;
	Application *theApp;
	Node<T>* tmpNode = head;

	while(tmpNode != NULL){
		if(tmpNode->data->getStatus() == "ASSIGNED" || tmpNode->data->getStatus() == "assigned"){
				theApp = tmpNode->data;
				Q->pushBack(theApp);
		}	
		tmpNode = tmpNode->next;
	}
	return Q;
}

template <class T>
void Queue<T>::assignSuccesfulCandidate(Application* app){
	Queue<T>* otherApps;

	app = getOriginal(app);//app is not the copy and is now the original

		Application* theApp = app;
		otherApps = getAppsByName(theApp->getStuName(), theApp->getStuLast());

	Node<T>* tmp = otherApps->head;//this queue has all the applications by that person
	while(tmp != NULL){
		tmp->data->operator-();//USE operator-() to assign status to closed
		tmp = tmp->next;
	}

	app->operator+();//use operator+() to assign the winning app status to "assigned"

}

template <class T>
T* Queue<T>::getOriginal(Application* app){
	
	//GradApp* ga;
	//UndergradApp* ua;
	Application* theApp;
	Node<T>* tmp = head;
	while(tmp != NULL){//for all applications
		if(*app == *(tmp->data)){
			return tmp->data;//return the original application that matches input parameter
		}
		tmp = tmp->next;
	}
	return NULL;
	
}

template <class T>
bool Queue<T>::writeToFile(){
	//UndergradApp* ua;
	Application *theApp;
	//GradApp* ga;
	//THIS WILL NOT BE APPEND...OVERWRITING OLD FILE WITH CURRENT APPLICATIONS
	ofstream out("Applications.txt");

	Node<T>* tmp = head;
	while(tmp != NULL){
			theApp = tmp->data;
			theApp->printModifiedApp(out);
		tmp = tmp->next;
	}
	return true;
}

template <class T>
bool Queue<T>::saveSummaries(){
	cout << "SS1\n";
	char theInput[200];
	string input[100];//string array for each Application
	//UndergradApp* uga;
	Application *theApp;
	//GradApp* ga;
	
	cout << "SS2\n";
	//THIS WILL NOT BE APPEND...OVERWRITING OLD FILE WITH CURRENT APPLICATIONS
	ofstream out("Summaries.txt" , ios::in|ios::app);
	cout << "SS3\n";
	if(!out.is_open()){
		cout << "Could not open Summaries.txt\n";
		return false;//Error opening file
	} 

	string s1,s2,s3,s4,s5,s6,s7 ,s8,s9,s10,s11;
	cout << "SS4\n";
	Queue<T> qCopy = *this;//COPY CTOR

	Application* app = qCopy.popFront();	
	cout << "SS5\n";
	int i = 0;
	//FOR ALL APPLICATIONS IN COPY OF THIS QUEUE:
	while(app != NULL){
		cout << "SS6\n";
		std::stringstream ss1; 
		std::stringstream ss2; 
		std::stringstream ss3;

		//the following commented section is to be replaced by a "print summary" function
		// inside Application. printSummary() has not been implemented.

		//input[i] = theApp->printSummary();

 
/*
		if(app->getType() == "grad"){
			cout << "SS6.2\n";
			ga = static_cast<GradApp*>(app);
			s1 = ga->getStuFirst();
			//cout << s1 << endl;
			s2 = ga->getStuLast();
			s6 = ga->getStuEmail();
			s7 = ga->getStuID();
			s9 = ga->getStuArea();
			s10 = ga->getStuProgram();
			s11 = ga->getStuSuper();
			input[i] = "Course: " + ga->getCourse() +  " Grad: " + s1 + " " + s2 +  "  | Email: " + s6 + "  |  ID: " + s7 + "  | Area: " + s9 + "  |  Program:  "  + s10 + " |  Supervisor:  " + s11;
		}
		else{
			cout << "SS7\n";
			uga = static_cast<UndergradApp*>(app);	
			s1 = uga->getStuFirst();
			cout << s1 << endl;
			s2 = uga->getStuLast();
				 
			ss1 << uga->getStuYrStanding();
			s3 = ss1.str();
			s4 = uga->getStuMajor();
			ss2 << uga->getStuCGPA();
			s5 = ss2.str();
			s6 = uga->getStuEmail();
			s7 = uga->getStuID();
			ss3 << uga->getStuMGPA();
			s8 = ss3.str();
			input[i] = "Course: " + uga->getCourse() + " Undergrad: " + s1 + " " + s2 + " in Year: " + s3 + "  |  Major: " + s4 + "  |  CGPA: " + s5  + "  |  GPA:  " + s8 + "  |  Email: " + s6 + "  |  ID: " + s7;
		}
*/
		cout << "SS8\n";
			 
			
		//theInput = input[i];
		//get a new application from the copy of *this queue
		i++;
		app = qCopy.popFront();	
		cout << "SS9\n";
		if(app != NULL){
			cout << "SS10\n";
			theApp = app;
		}
		

	}

	out << "===================================================================SUMMARIES:==========================================================================\n";
	for(int j=0; j<i; j++){
		cout << "SS: " << j <<endl;
		out << input[j] << endl;//output each string for a summary
		out << "=======================================================================================================================================================\n";
	}
	out << endl << endl;
	return true;
}

///////////////////////
//TEMPLATED OPERATORS//
//////////////////////

template <class T>
T* Queue<T>::operator[](int index){
	//returns application at index param
	if(index < 0 || index > size()) return NULL;//exception should be thrown
	int i=0;//counter index
	Node<T>* tmp = head;
	while(tmp != NULL){
		if(i++ == index){
			return tmp->data;
		}
		tmp = tmp->next;
	}
	return NULL;//should never get here...in case of fault
}

/*

Needs Application->getBasicInfo to be implemented first

template <class T>
Queue<T>& AppQueue::operator=(const Queue<T>& rhs){
	//cout<<"*************************************************************************************************\n";
	//VARS FOR NEW STUDENT AND APPLICATION
	string first, last, em, snum, res, pro, sup, major;
	int yr, cg, mg;
	//GradApp* ga;
	Application *theApp;
	//UndergradApp* ua;
	//cout << "IN COPY CTOR\n";
	if(rhs.head==NULL){
		this->operator!();//empty this queue to match the rhs
		return *this;	
	} 


	Node<T>* tmp = rhs.head;//iteration node for original AppQueue
	head = new Node<T>();//head node for the new AppQueue

	Node<T>* nPrev;//to connect the nodes in q
	Node<T>* nTmp = head;//iteration node for q
	while(tmp != NULL){	
		//GET BASIC iNFO
		first = tmp->data->getStuFirst();
		last = tmp->data->getStuLast();
		em = tmp->data->getStuEmail();
		snum = tmp->data->getStuID();
		if(tmp->data->getType() == "grad"){
			GradApp* tmpGApp = static_cast<GradApp*>(tmp->data);//now its a grad app
			//GET GRAD INFO
			res = tmpGApp->getStuArea();
			pro = tmpGApp->getStuProgram();
			sup = tmpGApp->getStuSuper();
			GradStudent* gs = new GradStudent(first, last, em, snum, res, pro, sup);
			ga = new GradApp(gs, tmpGApp->getApplicationNumber(), tmpGApp->getCourse(), tmpGApp->getStatus());
			nTmp->data = ga;
		}
		else{
			UndergradApp* tmpUApp = static_cast<UndergradApp*>(tmp->data);
			//GET UNDERGRAD INFO
			yr = tmpUApp->getStuYrStanding();
			cg = tmpUApp->getStuCGPA();
			mg = tmpUApp->getStuMGPA();
			major = tmpUApp->getStuMajor();
			UndergradStudent* us = new UndergradStudent(cg, mg, first, last, em, major, yr, snum);
			ua = new UndergradApp(us, tmpUApp->getApplicationNumber(), tmpUApp->getCourse(), tmpUApp->getStatus());
			nTmp->data = ua;
		}
	
		nPrev = nTmp;//make prev node this node before moving on	
		tmp = tmp->next;//advance iteration node for source Queue
		if(tmp != NULL){
			AppNode* node = new AppNode();//make a new node for each existing node		
			nTmp = node;
			nPrev->next=nTmp;
		}
		//connect the nodes in the new Queue	
	}
	//cout<<"***************************************************************************************************\n";
	return *this;
}
*/

template <class T>
Queue<T>& Queue<T>::operator+=(T* theData){
	//adds the application to the queue
	pushBack(theData);
	return *this;//enable cascading
}

template <class T>
Queue<T>& Queue<T>::operator+=(Queue<T>& q){
	//concatinates the incoming queue to *this
	Node<T>* tmp = q.head;

	while(tmp != NULL){//for all items of q
		*this += tmp->data;//call data version of operator+=
		tmp = tmp->next;
	}

	return *this;//cascade
}

template <class T>
Queue<T> Queue<T>::operator+(T* theData){
	//makes new queue with += functionality
	//cout << "in +app" <<endl;
	Queue<T> nQ;
	nQ += *this;//assign all elements from this to new queue
	nQ += theData;//add the incoming app to new queue

	return nQ;
}

template <class T>
Queue<T> Queue<T>::operator+(Queue<T>& qu){
	//makes new queue with += functionality
	Queue<T> nQ;//create new queue
	nQ += *this;//populate the new queue with current elements
	nQ += qu;//concatinate current(new) queue with incoming queue

	return nQ;
}

template <class T>
Queue<T>& Queue<T>::operator-=(T* app){
	//removes this app from the queue if contained
	Node<T>* tmp = head;
	Node<T>* prev = head;
	while(tmp != NULL){
		if (*(tmp->data) == *app){//found the app to remove
			if(tmp == head)//head is the one to be removed
				head = tmp->next;
			else
				prev->next = tmp->next;//cut out the current node

			//delete tmp;//clean up memory for node and application
		}
		prev = tmp;
		tmp = tmp->next;
	}	
	return *this;
}

template <class T>
Queue<T>& Queue<T>::operator-=(Queue<T>& q){
	//removes all elements from incoming queue from this if contained
	Node<T>* tmp = q.head;
	//for all elements of the incoming queue:
	while(tmp != NULL){
		*this -= tmp->data;//call operator above
		tmp = tmp->next;
	}
	
	return *this;//cascading
}

template <class T>
Queue<T> Queue<T>::operator-(T* app){
	//created new queue with all but incoming app
	Queue<T> nq;
	nq += *this;//fill the new queue with all elements of this qeue
	nq -= app;//use operator-=(Application*) defined above

	return nq;
}

template <class T>
Queue<T> Queue<T>::operator-(Queue<T>& q){
	//creates a new queue with all but apps from incoming 
	Queue<T> nq;

	nq += *this;//fill it with this stuff

	nq -= q;//use the -=(AppQueue&) operator defined above

	return nq;
}

template <class T>
Queue<T>& Queue<T>::operator!(){
	//logical not: empties the queue
	Node<T>* curr = head;
	Node<T>* prev;
	head = NULL;//Queue is now, for all intents and purposes, empty.

	//Cleanup like after a crazy party:
	while(curr != NULL){
		prev = curr;
		curr = curr->next;
		delete prev;

	}
}



#endif
