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

	q.head = new Node();//head node for the new Queue

	Node* qPrev;//to connect the nodes in q
	Node* qTmp = q.head;//iteration node for q

	while(tmp->next!=NULL){	
		qTmp->data = tmp->data;//copy over the data from this queue to q
		qPrev = qTmp;//make prev node this node before moving on		
		tmp = tmp->next;
		Node* node = new Node();//make a new node for each existing node		
		qTmp = node;
		qPrev->next=qTmp;//connect the nodes in the new Queue	
		
	}
	qTmp->data = tmp->data;//for the last iteration since the loop wont evaluate on tmp->next==NULL
}
///////////////////////////////////////////
//	      MEMBER FUNCTIONS    	 //
///////////////////////////////////////////
void Queue::pushBack(Node* node){	
	Node* tmpNode = head;
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

//tests whether or not the queue is empty
bool Queue::isEmpty(){
	return (head == NULL);
} 
