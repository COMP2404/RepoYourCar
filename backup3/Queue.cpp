#include <iostream>
using namespace std;
#include "Queue.h"

///////////////////////////////
//	    CTOR	     //
///////////////////////////////
Queue::Queue() : head(NULL) {}

///////////////////////////////
//	  NODE CTOR	     //
///////////////////////////////
Queue::Node::Node() : data(NULL), next(NULL) {}

///////////////////////////////
//	  NODE DTOR	     //
///////////////////////////////
Queue::Node::~Node(){
	//do nothing, dont delete data
}

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

//return a subset Queue of pending applications by specified course code
Queue* Queue::getPendingList(string course){
	//------Get a copy of the working Queue-------
	
	Queue& copy = *this;

	Queue* list = new Queue(copy);//call copy contructor

	if(head == NULL){//the working Queue is empty
		//list->head = NULL;
		return list;
	}
	//------Make the head a wanted node--------	
	Node* tmpNode = list->head;
	while(tmpNode!=NULL){
		if(tmpNode->data->getCourse().compare(course) == 0 && tmpNode->data->getStatus() == "pending"){
			list->head = tmpNode;
			break;
		}
		tmpNode=tmpNode->next;
	}
	//------Remove unwanted nodes from Queue------
	Node* prevNode = tmpNode;

	while(tmpNode != NULL){
		if(tmpNode->data->getCourse().compare(course) != 0){//not same course
			prevNode->next = tmpNode->next;//cut out the node that doesnt belong			
		}
		else if(tmpNode->data->getStatus() != "pending"){//its not pending
			prevNode->next = tmpNode->next;//cut out the node that doesnt belong
		}
		else{
			prevNode=tmpNode;//advance iteration node
		}
		tmpNode=tmpNode->next;   //advance iteration node
	}
	
	return list;
}

void Queue::print() const{
	Node* tmp = head;
	while(tmp!=NULL){
		if(tmp->data != NULL)
			cout << "Application ID: " << tmp->data->getApplicationNumber() << " Name: " << tmp->data->getStuFirst() << " " << tmp->data->getStuLast() << endl;
		tmp=tmp->next;
	}
}
