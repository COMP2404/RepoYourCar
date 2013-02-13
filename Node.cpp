#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

///////////////////////////////
//	     CTOR	     //
///////////////////////////////
Node::Node() : data(NULL), next(NULL) {}

///////////////////////////////
//	     DTOR	     //
///////////////////////////////
Node::~Node(){
	//do nothing, dont delete data
}

//==============================GETTERS==========================================
int* Node::getData() { return data; }
//===============================================================================

