
#include <iostream>
using namespace std;
#include "JobQueue.h"

///////////////////////////////
//	    CTOR	     //
///////////////////////////////
JobQueue::JobQueue() : head(NULL) {}

///////////////////////////////
//	  NODE CTOR	     //
///////////////////////////////
JobQueue::JobNode::JobNode() : data(NULL), next(NULL) {}

///////////////////////////////
//	  NODE DTOR	     //
///////////////////////////////
JobQueue::JobNode::~JobNode(){
	//do nothing, dont delete data
}

///////////////////////////////
//	    DTOR	     //
///////////////////////////////
JobQueue::~JobQueue(){
	/*
	cout<<"Destruction"<<endl;
	JobNode* tmpNode = head;
	JobNode* dNode;
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
JobQueue::JobQueue(JobQueue& q){
	//cout << "IN COPY CTOR\n";
	if(q.head==NULL) return;


	JobNode* tmp = q.head;//iteration node for original AppQueue
	head = new JobNode();//head node for the new AppQueue

	JobNode* nPrev;//to connect the nodes in q
	JobNode* nTmp = head;//iteration node for q
	while(tmp->next!=NULL){	
		nTmp->data = tmp->data;//copy over the data from this queue to q
		nPrev = nTmp;//make prev node this node before moving on	
		tmp = tmp->next;//advance iteration node for source Queue
		JobNode* node = new JobNode();//make a new node for each existing node		
		nTmp = node;
		nPrev->next=nTmp;//connect the nodes in the new Queue	
	}

	nTmp->data = tmp->data;//for the last iteration since the loop wont evaluate on tmp->next==NULL
}

void JobQueue::pushBack(JobNode* node){	
	JobNode* tmpNode = head;
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
JobQueue::JobNode* JobQueue::popFront(){ 
	if(head==NULL) return NULL;//nothing in the list
	JobNode* tmpNode = head;	
	head = head->next;//sets head to NULL if only one item in the list
	return tmpNode;
}

//returns the first item in the queue
JobQueue::JobNode* JobQueue::front(){
	return head;
}

//returns a node with the application data inside it
JobQueue::JobNode* JobQueue::createNode(Job *job){
	JobNode* tempNode = new JobNode();
	tempNode->data = job;
	tempNode->next = NULL;
	return tempNode;
}


void JobQueue::print() const{
	JobNode* tmp = head;
	while(tmp!=NULL){
		
	}
}

int JobQueue::size() const{
	int i=0;
	JobNode* tmp = head;
	while(tmp != NULL){
		i++;
		tmp=tmp->next;
	}
	return i;
}

//tests whether or not the queue is empty
bool JobQueue::isEmpty(){
	return (head == NULL);
} 


Job* JobQueue::JobNode::getData(){
	return data;
}
