#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T>
class Node
{
	//friend class Queue<T>;
	public:
		Node<T>();
		~Node<T>();
		Node<T> *next;

		T* getData(void);

		//useless..only need the getData function for overriding
		T* data;
};

template<class T>
Node<T>::Node(){
  data = NULL;
  next = NULL;
}

template<class T>
Node<T>::~Node(){}

template <class T>
T* Node<T>::getData(){
  return data;
}

#endif