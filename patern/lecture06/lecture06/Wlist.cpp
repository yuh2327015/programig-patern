#include "Wlist.h"

template <typename T>
Wlist<T>::Wlist()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <typename T>
Wlist<T>::~Wlist()
{
	
}

template <typename T>
WNode<T>::WNode(T vvalue)
{
	data = value;
}

template <typename T>
WNode<T>::~WNode()
{
	
}

template <typename T>
void Wlist<T>::push_back(T value)
{
	WNode<T>* newNode
}