
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
/*
	cout<<"Destruction"<<endl;
	AppNode* tmpNode = head;
	AppNode* dNode;
	//go through the list freeing all nodes
	while(tmpNode != NULL){		
		dNode=tmpNode;	
		cout<<"about to advance in destructor"<<endl;
		tmpNode=tmpNode->next;//THIS IS RAGETASTIC
		cout << "deleting node: " << endl;
		delete dNode;	
	}
*/
}

///////////////////////////////
//	  COPY CTOR	     //
///////////////////////////////

AppQueue::AppQueue(AppQueue& q){
	//cout << "IN COPY CTOR\n";
	if(q.head==NULL) return;


	AppNode* tmp = q.head;//iteration node for original AppQueue
	head = new AppNode();//head node for the new AppQueue

	AppNode* nPrev;//to connect the nodes in q
	AppNode* nTmp = head;//iteration node for q
	while(tmp->next!=NULL){	
		//Application* newApp;
		//*newApp = *(tmp->data);//MAKE A COMPY OF THE DATA***
		//nTmp->data = newApp;//copy over the data from this queue to q
		nTmp->data = tmp->data;		
		nPrev = nTmp;//make prev node this node before moving on	
		tmp = tmp->next;//advance iteration node for source Queue
		AppNode* node = new AppNode();//make a new node for each existing node		
		nTmp = node;
		nPrev->next=nTmp;//connect the nodes in the new Queue	
	}

	//for the last iteration since the loop wont evaluate on tmp->next==NULL
	//Application* newApp;
	//*newApp = *(tmp->data);//MAKE A COMPY OF THE DATA***
	//nTmp->data = newApp;//copy over the data from this queue to q
	nTmp->data = tmp->data;
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
	
	AppQueue& copy = *this;

	AppQueue* list = new AppQueue(copy);//call copy contructor

	if(head == NULL){//the working AppQueue is empty
		//list->head = NULL;
		return list;
	}
	//------Make the head a wanted node--------	
	AppNode* tmpNode = list->head;
	cout<<tmpNode->data->getCourse() << endl;
	while(tmpNode!=NULL){
		
		cout<< course<< endl;
		if(tmpNode->data->getCourse().compare(course) == 0 && tmpNode->data->getStatus() == "PENDING"){
			
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
			cout<<tmpNode->data->getCourse() << endl;
			prevNode->next = tmpNode->next;//cut out the node that doesnt belong			
		}
		else if(tmpNode->data->getStatus() != "PENDING"){//its not pending
			prevNode->next = tmpNode->next;//cut out the node that doesnt belong
		}
		else{
			prevNode=tmpNode;//advance iteration node
		}
		tmpNode=tmpNode->next;   //advance iteration node
	}
	
	return list;
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

	Application* tempApp;
	Application* appArr[count];//list of applications to be sorted
	//-----------GET A LIST OF APPLICATIONS----------//
	while(tmp != NULL){	
		appArr[i++] = tmp->data;		
		tmp = tmp->next;
	}
	//-----------SORT THE APPLICATIONS BY GPA------------//
	/*for(int i=count-1; i>=0; i--){//BSORT
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
        }*/

	for(int i=0; i<count; i++){	
		//cout << "d\n";
		//sorted->pushBack(appArr[i]);
	}

	//delete [] *appArr;//clean up the mess

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

AppQueue* AppQueue::sortAll(){
	string allCourses[] = {"Comp1001", "Comp1004", "Comp1005", "Comp1006", "Comp1405", "Comp1406", "Comp1501", "Comp1601", "Comp1805", "Comp1807", "Comp2001", "Comp2002", "Comp2004", "Comp2006", "Comp2401", "Comp2402", 
			       "Comp2404", "Comp2406", "Comp2501", "Comp2601", "Comp2804", "Comp2807", "Comp3000", "Comp3002", "Comp3004", "Comp3005", "Comp3007", "Comp3008", "Comp3203", "Comp3308", "Comp3501", "Comp3601", 
			       "Comp3802", "Comp3803", "Comp3804", "Comp3805", "Comp3806", "Comp3807", "Comp3999", "Comp4000", "serf"};
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

	Application* tempApp;
	Application* appArr[MAX_BUF];//2D-list of applications to be sorted..all courses and all applications of that course.
	cout<<"here we go3\n";
	//-----------GET A LIST OF APPLICATIONS SORTED BY COURSE----------//
	for(i=0; i<theNum; i++){//for all courses
		tmp = head;
		while(tmp != NULL){
			if(tmp->data->getCourse().compare(courseList[i]) == 0)
				appArr[j++] = tmp->data;
			tmp=tmp->next;		
		}
	}
	//arrays for undergrads and grads
	int unum = 0;
	Application* unders[MAX_BUF];
	int gnum = 0;
	Application* grads[MAX_BUF];
	//----------ASSIGN THE APPLICATIONS TO BASED ON APPLICANT GRAD/UNDERGRAD-------------//
	cout<<"here we go4\n";
	for(int k=0; k<j; k++){//for all applications
		if(appArr[k]->getStuYrStanding() == 5)
			grads[gnum++] = appArr[k];
		else
			unders[unum++] = appArr[k];
	}
	//-----------SORT THE APPLICATIONS BY GPA------------//
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
	cout<<"here we go6\n";
	for(int i=gnum-1; i>=0; i--){//BSORT
                swapped = false;
                for(int j=0; j<i; j++){//this swaps them if they shoud be
			if(grads[j]->getCourse().compare(grads[j+1]->getCourse()) == 0){//if they arent in the same course dont sort them by GPA, move on
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
	for(int i=0; i<unum; i++){	
		//cout << "d\n";
		sorted->pushBack(unders[i]);
	}
	for(int i=0; i<gnum; i++){	
		//cout << "d\n";
		sorted->pushBack(grads[i]);
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

