#pragma once
template <typename T>
class Wlist
{
public:
	WNode<T>* head;
	WNode<T>* tail;
	int size;

	Wlist();
	~Wlist();

	void push_back(T value);
	int get_size()

};

template <typename T>
class WNode
{
public :
	
	T data;
	WNode<t>* next;

	WNode(T value);
	~WNode();
};

