#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
	//friend class Queue;
	public:
		Node();
		~Node();
		Node *next;

		int* getData(void);

		//useless..only need the getData function for overriding
		int *data;
};

#endif
