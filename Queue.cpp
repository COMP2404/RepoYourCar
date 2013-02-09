#include <iostream>
using namespace std;
#include "Queue.h"

///////////////////////////////
//	    CTOR	     //
///////////////////////////////
Queue::Queue() : head(NULL) {}
///////////////////////////////
//	    DTOR	     //
///////////////////////////////
Queue::~Queue(){
	Node* tmpNode = head;
	Node* dNode;
	//go through the list freeing all nodes
	while(tmpNode != NULL){		
		dNode=tmpNode;
		tmpNode=tmpNode->next;
		delete dNode;	
	}
}
///////////////////////////////
//	  COPY CTOR	     //
///////////////////////////////
Queue::Queue(Queue& q){
	if(head==NULL) return;
	Node* tmp = head;//iteration node for original Queue

	Node* qHead = new Node();//head node for the new Queue
	qHead->data = head->data;//copy the data to the new Queue's head

	Node* qTmp = qHead;//iteration node for q

	while(tmp!=NULL){	
		Node* node = new Node();//make a new node for each existing node		
		qTmp = node;
		qTmp->data = tmp->data;
		tmp = tmp->next;
	}
}

void Queue::pushBack(Node* node){	
	Node* tmpNode = head;
	if(head == NULL) return;
	
	//get the last node in the list
	while(tmpNode->next != NULL){
		tmpNode=tmpNode->next;
	}
	//concatinate the new node with the list
	tmpNode->next = node;

}
//removes the first item from the queue
Queue::Node* Queue::popFront(){ 
	if(head==NULL) return NULL;//nothing in the list
	Node* tmpNode = head;	
	head = head->next;//sets head to NULL if only one item in the list
	return tmpNode;
}

//returns the first item in the queue
Queue::Node* Queue::front(){
	return head;
}

//returns a node with the application data inside it
Queue::Node* Queue::createNode(Application *theApp){
	Node* tempNode = new Node();
	tempNode->data = theApp;
	tempNode->next = NULL;
	return tempNode;
}

//tests whether or not the queue is empty
bool Queue::isEmpty(){
	return (head == NULL);
} 
