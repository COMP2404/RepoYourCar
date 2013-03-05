
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
		tmpNode=tmpNode->next;//THIS IS CAUSING SEG FAULTS!!!
		cout << "deleting node: " << dNode->data->getCourse() << endl;
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
		nTmp->data = tmp->data;//copy over the data from this queue to q
		nPrev = nTmp;//make prev node this node before moving on	
		tmp = tmp->next;//advance iteration node for source Queue
		AppNode* node = new AppNode();//make a new node for each existing node		
		nTmp = node;
		nPrev->next=nTmp;//connect the nodes in the new Queue	
	}

	nTmp->data = tmp->data;//for the last iteration since the loop wont evaluate on tmp->next==NULL
}

void AppQueue::pushBack(Application* app){	
	AppNode* node = createNode(app);
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
AppQueue::AppNode* AppQueue::createNode(Application *theApp){
	AppNode* tempNode = new AppNode();
	tempNode->data = theApp;
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

	return sorted;
}

void AppQueue::print() const{
	AppNode* tmp = head;
	while(tmp!=NULL){
		if(tmp->data != NULL)
			cout << "Application ID: " << tmp->data->getApplicationNumber() << " Name: " << tmp->data->getStuFirst() << " " << tmp->data->getStuLast() << " gpa: " << tmp->data->getStuCGPA() << endl;
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

