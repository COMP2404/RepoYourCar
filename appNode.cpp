#include "appNode.h"
#include <string>
#include <iostream>
using namespace std;

appNode::appNode(){
	data = NULL;
}

//==============================GETTERS==========================================
Application* appNode::getData() { return data; }
//===============================================================================

//Destructor:
appNode::~appNode(){

}
