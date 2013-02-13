#ifndef COURSEQUEUE_H
#define COURSEQUEUE_H

#include "Course.h"

class CourseQueue
{
  class CourseNode
  {
    friend class CourseQueue;
    public:
	Course* getData(void);
      CourseNode();
      ~CourseNode();
    private:
      Course* data;
      CourseNode*    next;
  };

  public:
    CourseQueue();
    ~CourseQueue();
    CourseQueue(CourseQueue&);
    /////////////////////////////////////////////////
    //  adds an item to the back of the queue      //
    //  @param:  Node*			           //
    //  returns: void			           //
    //  <runtime> 0(Queue.size) </runtime>         //
    /////////////////////////////////////////////////
    void  pushBack(CourseNode*); //adds an item to the back of the queue

    /////////////////////////////////////////////////
    //  removes and returns the first item         //
    //  @param:  void			           //
    //  returns: Node*			           //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    CourseNode* popFront(); //removes the first item from the queue

    /////////////////////////////////////////////////
    //  returns the first item in the queue        //
    //  @param:  void			           //
    //  returns: Node*			           //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    CourseNode* front();

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
    CourseNode* createNode(Course* );


    /////////////////////////////////////////////////
    //  returns the number of elements in the Queue//
    //  @param:  void       		   	   //
    //  returns: int	 			   //
    //  <runtime> 0(n) </runtime>                  //
    /////////////////////////////////////////////////
    int size() const;

    void print() const;

  private:
    CourseNode* head;
};



#endif
