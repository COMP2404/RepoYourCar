//YARR, This be the base Queue.

//Drop the base!

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
	/*
	cout<<"Destruction"<<endl;
	Node* tmpNode = head;
	Node* dNode;
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
Queue::Queue(Queue& q){
	//cout << "IN COPY CTOR\n";
	if(q.head==NULL) return;


	Node* tmp = q.head;//iteration node for original Queue
	head = new Node();//head node for the new Queue

	Node* nPrev;//to connect the nodes in q
	Node* nTmp = head;//iteration node for q
	while(tmp->next!=NULL){	
		nTmp->data = tmp->data;//copy over the data from this queue to q
		nPrev = nTmp;//make prev node this node before moving on	
		tmp = tmp->next;//advance iteration node for source Queue
		Node* node = new Node();//make a new node for each existing node		
		nTmp = node;
		nPrev->next=nTmp;//connect the nodes in the new Queue	
	}

	nTmp->data = tmp->data;//for the last iteration since the loop wont evaluate on tmp->next==NULL
}

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
Node* Queue::popFront(){ 
	if(head==NULL) return NULL;//nothing in the list
	Node* tmpNode = head;	
	head = head->next;//sets head to NULL if only one item in the list
	return tmpNode;
}

//returns the first item in the queue
Node* Queue::front(){
	return head;
}


//tests whether or not the queue is empty
bool Queue::isEmpty(){
	return (head == NULL);
} 

int Queue::size() const{
	int i=0;
	Node* tmp = head;
	while(tmp != NULL){
		i++;
		tmp=tmp->next;
	}
	return i;
}

