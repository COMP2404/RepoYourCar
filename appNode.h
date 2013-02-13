#ifndef APPNODE_H
#define APPNODE_H
#include "Node.h"
#include "Application.h"
//#include "Application.h"
//#include "Course.h"
//#include "Job.h"

using namespace std;

class appNode : public Node
{
	//friend class Queue;

	public:
	appNode();
	~appNode();
	Application* getData(void);

	private:
	Application *data;
  };

#endif
