#ifndef NODE_H
#define NODE_H
//#include "Application.h"
//#include "Course.h"
//#include "Job.h"

using namespace std;

class Node
{
	//friend class Queue;

	public:
	Node();
	~Node();
	Node *next;

	int* getData(void);

	private:
	//useless..only need the getData function for overriding
	int *data;
  };

#endif
