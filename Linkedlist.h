#pragma once
#include"user.h"

//template <class T>
class Node
{
public:
	Node* next;
	user value;
	Node();
	Node(user val);
};

//template <class T>
class LinkedList
{
	int count=0;
	Node* head;
	Node* tail;
public:
	LinkedList();
	int Length();
	user At(int);
	void InsertAt(int, user);
	void Append(user);
	void DeleteAt(int);
	bool find(string nationalId);
	~LinkedList(void);
};

