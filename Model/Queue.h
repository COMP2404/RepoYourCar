#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue
{

  public:
    Queue();
    ~Queue();
    Queue(Queue&);
    /////////////////////////////////////////////////
    //  adds an item to the back of the queue      //
    //  @param:  Node*			           //
    //  returns: void			           //
    //  <runtime> 0(Queue.size) </runtime>         //
    /////////////////////////////////////////////////
    void  pushBack(Node*); //adds an item to the back of the queue

    /////////////////////////////////////////////////
    //  removes and returns the first item         //
    //  @param:  void			           //
    //  returns: Node*			           //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    Node* popFront(); //removes the first item from the queue

    /////////////////////////////////////////////////
    //  returns the first item in the queue        //
    //  @param:  void			           //
    //  returns: Node*			           //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    Node* front();

    /////////////////////////////////////////////////
    //  checks if queue is empty                   //
    //  @param:  void			           //
    //  returns: boolean: true if empty else false //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    bool  isEmpty();

    /////////////////////////////////////////////////
    //  creates a Node<Application>                //
    //  @param:  Application		           //
    //  returns: Node ptr			   //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    //Node* createNode(Application*); 

    /////////////////////////////////////////////////
    //gets a subset Queue of pending apps by course//
    //  @param:  string: course #	           //
    //  returns: Queue of pending apps in course # //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    Queue* getPendingList(string);

    /////////////////////////////////////////////////
    //  gets a sorted copy of the Queue passed in  //
    //  @param:  void       		           //
    //  returns: Queue* 			   //
    //  <runtime> 0(n^2) </runtime>                //
    /////////////////////////////////////////////////
    Queue* sortByGPA(void);

    /////////////////////////////////////////////////
    //  returns the number of elements in the Queue//
    //  @param:  void       		   	   //
    //  returns: int	 			   //
    //  <runtime> 0(n) </runtime>                  //
    /////////////////////////////////////////////////
    int size() const;

    void print() const;

    Node* head;
};



#endif
