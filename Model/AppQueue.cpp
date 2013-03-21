
#include <iostream>
using namespace std;
#include "AppQueue.h"

///////////////////////////////
//	    CTOR	     //
///////////////////////////////
AppQueue::AppQueue() : head(NULL) {}

///////////////////////////////
//	  NODE CTOR	     //
///////////////////////////////
AppQueue::AppNode::AppNode() : data(NULL), next(NULL) {}

///////////////////////////////
//	  NODE DTOR	     //
///////////////////////////////
AppQueue::AppNode::~AppNode(){
	//do nothing, dont delete data
}

///////////////////////////////
//	    DTOR	     //
///////////////////////////////

AppQueue::~AppQueue(){
	//cout<<"Destruction"<<endl;
	AppNode* tmpNode = head;
	AppNode* dNode;
	//go through the list freeing all nodes
	while(tmpNode != NULL){		
		dNode=tmpNode;	
		//cout<<"about to advance in destructor"<<endl;
		tmpNode=tmpNode->next;
		//cout << "deleting node: " << endl;
		delete dNode;	
	}
}

///////////////////////////////
//	  COPY CTOR	     //
///////////////////////////////
/*
AppQueue::AppQueue(AppQueue& q){

	//VARS FOR NEW STUDENT AND APPLICATION
	string first, last, em, snum, res, pro, sup, major;
	int yr, cg, mg;
	GradApp* ga;
	UndergradApp* ua;
	//cout << "IN COPY CTOR\n";
	if(q.head==NULL) return;


	AppNode* tmp = q.head;//iteration node for original AppQueue
	head = new AppNode();//head node for the new AppQueue

	AppNode* nPrev;//to connect the nodes in q
	AppNode* nTmp = head;//iteration node for q
	while(tmp != NULL){	
		//GET BASIC iNFO
		Application* ta = new Application(*(tmp->data));//call copy constructor for application
		nTmp->data = ta;//assign the copied data

		nPrev = nTmp;//make prev node this node before moving on	
		tmp = tmp->next;//advance iteration node for source Queue
		if(tmp != NULL){
			AppNode* node = new AppNode();//make a new node for each existing node		
			nTmp = node;
			nPrev->next=nTmp;
		}
		//connect the nodes in the new Queue	
	}

}
*/

AppQueue::AppQueue(AppQueue& q){

	//VARS FOR NEW STUDENT AND APPLICATION
	string first, last, em, snum, res, pro, sup, major;
	int yr, cg, mg;
	GradApp* ga;
	UndergradApp* ua;
	//cout << "IN COPY CTOR\n";
	if(q.head==NULL) return;


	AppNode* tmp = q.head;//iteration node for original AppQueue
	head = new AppNode();//head node for the new AppQueue

	AppNode* nPrev;//to connect the nodes in q
	AppNode* nTmp = head;//iteration node for q
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

}

Application* AppQueue::operator[](int index){
	//returns application at index param
	if(index < 0 || index > size()) return NULL;//exception should be thrown
	int i=0;//counter index
	AppNode* tmp = head;
	while(tmp != NULL){
		if(i++ == index){
			return tmp->data;
		}
		tmp = tmp->next;
	}
	return NULL;//should never get here...in case of fault
}

AppQueue& AppQueue::operator=(const AppQueue& rhs){
	//cout<<"*************************************************************************************************\n";
	//VARS FOR NEW STUDENT AND APPLICATION
	string first, last, em, snum, res, pro, sup, major;
	int yr, cg, mg;
	GradApp* ga;
	UndergradApp* ua;
	//cout << "IN COPY CTOR\n";
	if(rhs.head==NULL){
		this->operator!();//empty this queue to match the rhs
		return *this;	
	} 


	AppNode* tmp = rhs.head;//iteration node for original AppQueue
	head = new AppNode();//head node for the new AppQueue

	AppNode* nPrev;//to connect the nodes in q
	AppNode* nTmp = head;//iteration node for q
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

AppQueue& AppQueue::operator+=(Application* app){
	//adds the application to the queue
	if(app->getType() == "grad"){
		GradApp* ga = dynamic_cast<GradApp*>(app);
		pushBack(ga, NULL);
	}else{
		UndergradApp* ua = dynamic_cast<UndergradApp*>(app);
		pushBack(NULL, ua);
	}
	return *this;//enable cascading
}

AppQueue& AppQueue::operator+=(AppQueue& q){
	//concatinates the incoming queue to *this
	AppNode* tmp = q.head;

	while(tmp != NULL){//for all items of q
		*this += tmp->data;//call data version of operator+=
		tmp = tmp->next;
	}

	return *this;//cascade
}

AppQueue AppQueue::operator+(Application* app){
	//makes new queue with += functionality
	//cout << "in +app" <<endl;
	AppQueue nQ;
	nQ += *this;//assign all elements from this to new queue
	nQ += app;//add the incoming app to new queue

	return nQ;
}

AppQueue AppQueue::operator+(AppQueue& qu){
	//makes new queue with += functionality
	AppQueue nQ;//create new queue
	nQ += *this;//populate the new queue with current elements
	nQ += qu;//concatinate current(new) queue with incoming queue

	return nQ;
}

AppQueue& AppQueue::operator-=(Application* app){
	//removes this app from the queue if contained
	AppNode* tmp = head;
	AppNode* prev = head;
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

AppQueue& AppQueue::operator-=(AppQueue& q){
	//removes all elements from incoming queue from this if contained
	AppNode* tmp = q.head;
	//for all elements of the incoming queue:
	while(tmp != NULL){
		*this -= tmp->data;//call operator above
		tmp = tmp->next;
	}
	
	return *this;//cascading
}

AppQueue AppQueue::operator-(Application* app){
	//created new queue with all but incoming app
	AppQueue nq;
	nq += *this;//fill the new queue with all elements of this qeue
	nq -= app;//use operator-=(Application*) defined above

	return nq;
}

AppQueue AppQueue::operator-(AppQueue& q){
	//creates a new queue with all but apps from incoming 
	AppQueue nq;

	nq += *this;//fill it with this stuff

	nq -= q;//use the -=(AppQueue&) operator defined above

	return nq;
}

AppQueue& AppQueue::operator!(){
	//logical not: empties the queue
	AppNode* curr = head;
	AppNode* prev;
	head = NULL;//Queue is now, for all intents and purposes, empty.

	//Cleanup like after a crazy party:
	while(curr != NULL){
		prev = curr;
		curr = curr->next;
		delete prev;

	}
}

ostream& operator<<(ostream& out, AppQueue& q){
	if(q.isEmpty()) out << "The Queue is empty"<<endl;
	AppQueue::AppNode* tmp = q.head; 
	while(tmp != NULL){
		out << *(tmp->data) << endl;;
		tmp = tmp->next;
	}
	return out;
}

void AppQueue::pushBack(GradApp *ga, UndergradApp *uga){
	
	AppNode* node = createNode(ga, uga);
	AppNode* tmpNode = head;
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
Application* AppQueue::popFront(){ 
	if(head==NULL) return NULL;//nothing in the list
	AppNode* tmpNode = head;	
	head = head->next;//sets head to NULL if only one item in the list
	return tmpNode->data;
}

//returns the first item in the queue
Application* AppQueue::front(){
	if(head==NULL) return NULL;
	return head->data;
}

//returns a node with the application data inside it
AppQueue::AppNode* AppQueue::createNode(GradApp *ga, UndergradApp *uga){
	AppNode* tempNode = new AppNode();
	if(ga != NULL)
		tempNode->data = ga;
	else{
		tempNode->data = uga;
	}
	tempNode->next = NULL;
	return tempNode;
}

//return a subset Queue of pending applications by specified course code
AppQueue* AppQueue::getPendingList(string course){
	//------Get a copy of the working Queue-------
	bool all = false;
	if(course == "all" || course == "ALL") all = true;

	AppQueue& copy = *this;

	AppQueue* list = new AppQueue(copy);//call copy contructor
	cout << "In Pending List" << endl;
	if(head == NULL){//the working AppQueue is empty
		//list->head = NULL;
		cout << "In Pending List" << endl;
		return list;
	}
	//------Make the head a wanted node--------	
	AppNode* tmpNode = list->head;
	cout<<tmpNode->data->getCourse() << endl;
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
			 AppQueue* finalQ = new AppQueue();
			return finalQ;
		}
	}
	//------Remove unwanted nodes from Queue------
	tmpNode = list->head;
	AppNode* prevNode = tmpNode;

	while(tmpNode != NULL){
		if(tmpNode->data->getCourse().compare(course) != 0){//not same course
			
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

AppQueue* AppQueue::getAppsByCourse(string course){
	//------Get a copy of the working Queue-------
	
	AppQueue& copy = *this;

	AppQueue* list = new AppQueue(copy);//call copy contructor
	if(head == NULL){//the working AppQueue is empty
		//list->head = NULL;
		return list;
	}
	//------Make the head a wanted node--------	
	AppNode* tmpNode = list->head;
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
			 AppQueue* finalQ = new AppQueue();
			return finalQ;
		}
	}
	//------Remove unwanted nodes from Queue------
	tmpNode = list->head;
	AppNode* prevNode = tmpNode;

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

AppQueue* AppQueue::getAssignedList(){
	//------Get a queue of assigned applications-------
	
	AppQueue* Q = new AppQueue();
	GradApp* ga;
	UndergradApp* ua;
	AppNode* tmpNode = head;

	while(tmpNode != NULL){
		if(tmpNode->data->getStatus() == "ASSIGNED" || tmpNode->data->getStatus() == "assigned"){
			if(tmpNode->data->getType() == "grad"){
				ga = dynamic_cast<GradApp*>(tmpNode->data);
				Q->pushBack(ga, NULL);
			}
			else{
				ua = dynamic_cast<UndergradApp*>(tmpNode->data);
				Q->pushBack(NULL, ua);
			}
		}	
		tmpNode = tmpNode->next;
	}
	return Q;
}

/*AppQueue* AppQueue::getPendingList(string course){
        //------Get a copy of the working Queue-------
       
        AppQueue& copy = *this;
 
        AppQueue* list = new AppQueue(copy);//call copy contructor
 
        int goodCount=0;
        AppNode goodOnes[list->size()];
               
        AppNode* tmpNode = list->head;
	
        while(tmpNode!=NULL){
                if(tmpNode->data->getCourse().compare(course) == 0 &&   tmpNode->data->getStatus() == "PENDING"){
                        goodOnes[goodCount++] = *tmpNode;
                }
                tmpNode=tmpNode->next;
        }
 
        AppQueue* finalQ = new AppQueue();
        for(int j=0; j<goodCount; j++){
                finalQ->pushBack(&goodOnes[j]);
        }
 
        return finalQ;
 
}*/



AppQueue* AppQueue::sortByGPA(){
	int i=0;//index for appArr
	bool swapped;
	int count = size();

	AppQueue* sorted = new AppQueue();//new linked list in sorted order

	AppNode* tmp = head;

	/*UndergradApp* tempApp;
	UndergradApp* appArr[count];//list of applications to be sorted
	//-----------GET A LIST OF APPLICATIONS----------//
	while(tmp != NULL){	
		appArr[i++] = tmp->data;		
		tmp = tmp->next;
	}
	//-----------SORT THE APPLICATIONS BY GPA------------//
	for(int i=count-1; i>=0; i--){//BSORT
                swapped = false;
                for(int j=0; j<i; j++){//this swaps them if they shoud be
                        if(appArr[j]->getStuMGPA() > appArr[j+1]->getStuMGPA()){
                                tempApp = appArr[j+1];
                                appArr[j+1] = appArr[j];
                                appArr[j]=tempApp;
                                swapped=true;
                        }
                }
                if(!swapped) break;
        }

	for(int i=0; i<count; i++){	
		//cout << "d\n";
		sorted->pushBack(appArr[i]);
	}

	//delete [] *appArr;//clean up the mess
	*/
	return sorted;
}
int AppQueue::getNumCourses(){
	bool in = false;
	string contained[MAX_BUF];
	AppNode* tmp = head;
	if(isEmpty()) return 0;//no courses cause no thangs at all

	int num = 0;

	while(tmp != NULL){
		in = false;//not contained
		for(int i=0; i<MAX_BUF; i++) {
			if(contained[i].compare(tmp->data->getCourse()) == 0){
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

bool AppQueue::appExists(string app){
	AppNode* tmp = head;
	while(tmp != NULL){
		//cout<< tmp->data->getCourse() << endl;
		if(tmp->data->getCourse().compare(app) == 0)
			return true;
		tmp = tmp->next;
	}
	return false;
}
int AppQueue::getIndex(Application* app){
	AppNode* tmp = head;
	int i = 0;
	while(tmp != NULL){//for all applications
		if( *(tmp->data) == *app)//if it satisfies the application's '=='
			return i;//this is it's index
		tmp = tmp->next;
	}
	return -1;
}

AppQueue* AppQueue::getAppsByName(string name){
	GradApp* ga;
	UndergradApp* ua;
	AppNode* tmp = head;
	AppQueue* nQ = new AppQueue();//this will only hold applications from a specific person
	while(tmp != NULL){//for all applications
		if(tmp->data->getType() == "grad"){
			ga = dynamic_cast<GradApp*>(tmp->data);
			if(ga->getStuName() == name){//if they are by the target person
				nQ->pushBack(dynamic_cast<GradApp*>(tmp->data), NULL);
			}
		}else{
			ua = dynamic_cast<UndergradApp*>(tmp->data);
			if(ua->getStuName() == name){//if they are by the target person
				nQ->pushBack(NULL, dynamic_cast<UndergradApp*>(tmp->data));
			}	
		}
		tmp = tmp->next;
	}
	return nQ;
}

Application* AppQueue::getOriginal(Application* app){
	
	GradApp* ga;
	UndergradApp* ua;
	AppNode* tmp = head;
	while(tmp != NULL){//for all applications
		if(*app == *(tmp->data)){
			return tmp->data;//return the original application that matches input parameter
		}
		tmp = tmp->next;
	}
	return NULL;
	
}

void AppQueue::assignSuccesfulCandidate(Application* app){
	AppQueue* otherApps;

	app = getOriginal(app);//app is not the copy and is now the original

	if(app->getType() == "grad"){
		GradApp* ga = dynamic_cast<GradApp*>(app);
		otherApps = getAppsByName(ga->getStuName());
	}else{
		UndergradApp* ua = dynamic_cast<UndergradApp*>(app);
		otherApps = getAppsByName(ua->getStuName());
	}

	AppNode* tmp = otherApps->head;//this queue has all the applications by that person
	while(tmp != NULL){
		tmp->data->operator-();//USE operator-() to assign status to closed
		tmp = tmp->next;
	}

	app->operator+();//use operator+() to assign the winning app status to "assigned"

}

AppQueue* AppQueue::sortAll(){
	string allCourses[] = {"COMP1001", "COMP1004", "COMP1005", "COMP1006", "COMP1405", "COMP1406", "COMP1501", "COMP1601", 
			       "COMP1805", "COMP1807", "COMP2001", "COMP2002", "COMP2004", "COMP2006", "COMP2401", "COMP2402", 
			       "COMP2404", "COMP2406", "COMP2501", "COMP2601", "COMP2804", "COMP2807", "COMP3000", "COMP3002",
 			       "COMP3004", "COMP3005", "COMP3007", "COMP3008", "COMP3203", "COMP3308", "COMP3501", "COMP3601", 
			       "COMP3802", "COMP3803", "COMP3804", "COMP3805", "COMP3806", "COMP3807", "COMP3999", "COMP4000" };
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
	AppQueue* sorted = new AppQueue();//new linked list in sorted order

	AppNode* tmp = head;

	GradApp* tempGApp;
	UndergradApp* tempUApp;
	//Application* appArr[MAX_BUF];//2D-list of applications to be sorted..all courses and all applications of that course.
	cout<<"here we go3\n";
	//arrays for undergrads and grads
	int unum = 0;
	UndergradApp* unders[MAX_BUF];
	int gnum = 0;
	GradApp* grads[MAX_BUF];
	//-----------GET A LIST OF APPLICATIONS SORTED BY COURSE----------//
	//----------ASSIGN THE APPLICATIONS TO APParrays BASED ON APPLICANT GRAD/UNDERGRAD-------------//
	for(i=0; i<theNum; i++){//for all courses
		tmp = head;
		while(tmp != NULL){
			if(tmp->data->getCourse().compare(courseList[i]) == 0){
				if(tmp->data->getType() == "grad")
					grads[gnum++] = static_cast<GradApp*>(tmp->data);

				else
					unders[unum++] = static_cast<UndergradApp*>(tmp->data);
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
		                        tempUApp = unders[j+1];
		                        unders[j+1] = unders[j];
		                        unders[j]=tempUApp;
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

		                        tempGApp = grads[j+1];
		                        grads[j+1] = grads[j];
		                        grads[j]=tempGApp;
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
		sorted->pushBack(grads[i], NULL);
	}
	for(int i=0; i<unum; i++){	
		//cout << "d\n";
		sorted->pushBack(NULL, unders[i]);
	}
	
	cout<<"went!\n";
	return sorted;
	
}

void AppQueue::print() const{
	AppNode* tmp = head;
	while(tmp!=NULL){
		if(tmp->data != NULL)
//			cout << "Application ID: " << tmp->data->getApplicationNumber() << " Name: " << tmp->data->getStuFirst() << " " << tmp->data->getStuLast() << " gpa: " << tmp->data->getStuCGPA() << endl;
		tmp=tmp->next;
	}
}

int AppQueue::size() const{
	int i=0;
	AppNode* tmp = head;
	while(tmp != NULL){
		i++;
		tmp=tmp->next;
	}
	return i;
}

//tests whether or not the queue is empty
bool AppQueue::isEmpty(){
	return (head == NULL);
} 


