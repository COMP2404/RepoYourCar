#ifndef APPQUEUE_H
#define APPQUEUE_H

//#include "Queue.h"
#include "Application.h"
#include "GradApp.h"
#include "UndergradApp.h"

//#include "Student.h"
//#include "Control.h"

class AppQueue
{
	friend class Control;
    friend class WindowApp;
 class AppNode
  {
    friend class AppQueue;
	friend class Control;
    friend class WindowApp;
    public:
      AppNode();
      ~AppNode();
    private:
      Application* data;
      AppNode*    next;
  };

  public:
    AppQueue();
    ~AppQueue();
    AppQueue(AppQueue&);
    /////////////////////////////////////////////////
    //  adds an item to the back of the queue      //
    //  @param:  Node*			           //
    //  returns: void			           //
    //  <runtime> 0(Queue.size) </runtime>         //
    /////////////////////////////////////////////////
    void  pushBack(GradApp*, UndergradApp*); //adds an item to the back of the queue

    /////////////////////////////////////////////////
    //  removes and returns the first item         //
    //  @param:  void			           //
    //  returns: Node*			           //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    Application* popFront(); //removes the first item from the queue

    /////////////////////////////////////////////////
    //  returns the first item in the queue        //
    //  @param:  void			           //
    //  returns: Node*			           //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    Application* front();

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
    AppNode* createNode(GradApp *, UndergradApp*);

    /////////////////////////////////////////////////
    //gets a subset Queue of pending apps by course//
    //  @param:  string: course #	           //
    //  returns: Queue of pending apps in course # //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    AppQueue* getPendingList(string);

    /////////////////////////////////////////////////
    //  gets a sorted copy of the Queue (this)     //
    //  @param:  void       		           //
    //  returns: Queue* 			   //
    //  <runtime> 0(n^2) </runtime>                //
    /////////////////////////////////////////////////
    AppQueue* sortByGPA(void);

    /////////////////////////////////////////////////
    //  makes a sorted copy of 'this' queue        //
    //  @param:  void       		           //
    //  returns: Queue* 			   //
    //  <runtime> 0(n^2) </runtime>                //
    /////////////////////////////////////////////////
    AppQueue* sortAll(void);

    /////////////////////////////////////////////////
    //  gets number of courses being applied for   //
    //  @param:  void			           //
    //  returns: int				   //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    int getNumCourses(void);

    /////////////////////////////////////////////////
    // checks if theres an app for a certain course//
    //  @param:  void			           //
    //  returns: boolean: true if empty else false //
    //  <runtime> 0(1) </runtime>                  //
    /////////////////////////////////////////////////
    bool appExists(string);

    /////////////////////////////////////////////////
    //  returns the number of elements in the Queue//
    //  @param:  void       		   	   //
    //  returns: int	 			   //
    //  <runtime> 0(n) </runtime>                  //
    /////////////////////////////////////////////////
    int size() const;

    void print() const;

  private:
    AppNode* head;
};



#endif
