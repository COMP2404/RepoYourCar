
#include <iostream>
using namespace std;
#include "CourseQueue.h"

///////////////////////////////
//	    CTOR	     //
///////////////////////////////
CourseQueue::CourseQueue() : head(NULL) {}

///////////////////////////////
//	  NODE CTOR	     //
///////////////////////////////
CourseQueue::CourseNode::CourseNode() : data(NULL), next(NULL) {}

///////////////////////////////
//	  NODE DTOR	     //
///////////////////////////////
CourseQueue::CourseNode::~CourseNode(){
	//do nothing, dont delete data
}






Course* CourseQueue::CourseNode::getData(){
	return data;
}



///////////////////////////////
//	    DTOR	     //
///////////////////////////////
CourseQueue::~CourseQueue(){
	/*
	cout<<"Destruction"<<endl;
	CourseNode* tmpNode = head;
	CourseNode* dNode;
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
CourseQueue::CourseQueue(CourseQueue& q){
	//cout << "IN COPY CTOR\n";
	if(q.head==NULL) return;


	CourseNode* tmp = q.head;//iteration node for original AppQueue
	head = new CourseNode();//head node for the new AppQueue

	CourseNode* nPrev;//to connect the nodes in q
	CourseNode* nTmp = head;//iteration node for q
	while(tmp->next!=NULL){	
		nTmp->data = tmp->data;//copy over the data from this queue to q
		nPrev = nTmp;//make prev node this node before moving on	
		tmp = tmp->next;//advance iteration node for source Queue
		CourseNode* node = new CourseNode();//make a new node for each existing node		
		nTmp = node;
		nPrev->next=nTmp;//connect the nodes in the new Queue	
	}

	nTmp->data = tmp->data;//for the last iteration since the loop wont evaluate on tmp->next==NULL
}

void CourseQueue::pushBack(CourseNode* node){	
	CourseNode* tmpNode = head;
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
CourseQueue::CourseNode* CourseQueue::popFront(){ 
	if(head==NULL) return NULL;//nothing in the list
	CourseNode* tmpNode = head;	
	head = head->next;//sets head to NULL if only one item in the list
	return tmpNode;
}

//returns the first item in the queue
CourseQueue::CourseNode* CourseQueue::front(){
	return head;
}

//returns a node with the application data inside it
CourseQueue::CourseNode* CourseQueue::createNode(Course *cor){
	CourseNode* tempNode = new CourseNode();
	tempNode->data = cor;
	tempNode->next = NULL;
	return tempNode;
}


void CourseQueue::print() const{
	CourseNode* tmp = head;
	while(tmp!=NULL){
		
	}
}

int CourseQueue::size() const{
	int i=0;
	CourseNode* tmp = head;
	while(tmp != NULL){
		i++;
		tmp=tmp->next;
	}
	return i;
}

//tests whether or not the queue is empty
bool CourseQueue::isEmpty(){
	return (head == NULL);
} 

