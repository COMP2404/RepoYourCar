#ifndef QUEUE_H
#define QUEUE_H

#include "Student.h"
#include "Application.h"
class Queue
{
  class Node
  {
    friend class Queue;
    public:

    private:
      Application* data;
      Node*    next;
  };

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

    //////////////
    Node* createNode(Application *); 

    void print() const;

  private:
    Node* head;
};



#endif
