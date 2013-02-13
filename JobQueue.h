#ifndef JOBQUEUE_H
#define JOBQUEUE_H

#include "Job.h"

class JobQueue
{
  class JobNode
  {
    friend class JobQueue;
    public:
      JobNode();
      ~JobNode();
    private:
      Job* data;
      JobNode*    next;
  };

  public:
    JobQueue();
    ~JobQueue();
    JobQueue(JobQueue&);
    /////////////////////////////////////////////////
    //  adds an item to the back of the queue      //
    //  @param:  Node*			           //
    //  returns: void			           //
    //  <runtime> 0(Queue.size) </runtime>         //
    /////////////////////////////////////////////////
    void  pushBack(JobNode*); //adds an item to the back of the queue

    /////////////////////////////////////////////////
    //  removes and returns the first item         //
    //  @param:  void			           //
    //  returns: Node*			           //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    JobNode* popFront(); //removes the first item from the queue

    /////////////////////////////////////////////////
    //  returns the first item in the queue        //
    //  @param:  void			           //
    //  returns: Node*			           //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    JobNode* front();

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
    JobNode* createNode(Job*);


    /////////////////////////////////////////////////
    //  returns the number of elements in the Queue//
    //  @param:  void       		   	   //
    //  returns: int	 			   //
    //  <runtime> 0(n) </runtime>                  //
    /////////////////////////////////////////////////
    int size() const;

    void print() const;

  private:
    JobNode* head;
};



#endif
