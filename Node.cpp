#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

Node::Node(){
	next = NULL;
}

//==============================GETTERS==========================================
int* Node::getData() { return data; }
//===============================================================================

//Destructor:
Node::~Node(){

}
