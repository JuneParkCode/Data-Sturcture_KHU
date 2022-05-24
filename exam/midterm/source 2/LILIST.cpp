#include <iostream>
#include "LILIST.h"

LILIST::LILIST()
{
	elem = NULL;
}

LILIST::~LILIST()
{
	// You have to implement this area, but do not do it at this time...
	//
}

int	LILIST::isLength(void)
{
	int	length;
	Node	*t;

	length = 0;
	t = elem;
	while(t != NULL) {
		length++;
		t = t->next;
	}
	return length;
}

void	LILIST::InsertList(char *clist)
{
	int	i, j;
	char	str[100];
	Node	*list, *node, *t;

	list = NULL;
	i = 0;
	i++;	// skip (
	// Make a linked list
	do {
		j = 0;
		while(isdigit(clist[i])) str[j++] = clist[i++];
		str[j] = '\0';
		while(isspace(clist[i])) ++i;
		// Implement Here
		//
		Node	*t;
		t = new Node;
		if (list == NULL)
			list = t;
		else
			node->next = t;
		t->item = atoi(str);
		t->next = NULL;
		t->sublist = NULL;
		node = t;
	} while(clist[i] != ')');
	// Implement Here
	//
	node = this->elem;
	while (node->next != NULL)
	{
		node = node->next;
	}
	t = new Node;
	t->item = -1;
	t->sublist = list;
	t->next = NULL;
	node->next = t;
}

void	LILIST::InsertItem(int v)
{
	// Implement Here
	//
	Node	*newNode;
	Node	*lastNode;

	newNode = new Node;
	newNode->item = v;
	newNode->sublist = NULL;
	newNode->next =NULL;
	if (this->elem == NULL)
	{
		this->elem = newNode;
	}
	else
	{
		lastNode = this->elem;
		while (lastNode->next != NULL)
		{
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
	}
}

void	LILIST::DeleteItem(int v)
{
	// Implement Here
	//
	Node	*prevNode;
	Node	*targetNode;

	prevNode = this->elem;
	if (prevNode && prevNode->item == v)
	{
		this->elem = prevNode->next;
		delete (prevNode);
		return ;
	}
	while (prevNode->next && prevNode->next->item != v)
	{
		prevNode = prevNode->next;
	}
	if (prevNode->next == NULL)
		return ;
	targetNode = prevNode->next;
	prevNode->next = targetNode->next;
	delete (targetNode);
}

int	LILIST::Sum1()
{
	// Implement Here
	//
	Node	*node;
	int		res;

	res = 0;
	node = this->elem;
	while (node)
	{
		res += node->item >= 0? node->item : 0;
		node = node->next;
	}
	return (res);
}

int	LILIST::Sum2()
{
	// Implement Here
	//
	Node	*node;
	int		res;

	res = 0;
	node = this->elem;
	while (node != NULL)
	{
		if (node->item < 0 && node->sublist != NULL)
		{
			Node	*subNode;

			subNode = node->sublist;
			while (subNode != NULL)
			{
				res += subNode->item;
				subNode = subNode->next;
			}
		}
		res += node->item >= 0 ? node->item : 0;
		node = node->next;
	}
	return (res);
}

void	LILIST::PrintRec(Node *t)
{
	while(t != NULL) {
		if(t->sublist != NULL) {
			std::cout << "(";
			PrintRec(t->sublist);
			std::cout << ") ";
		} else
			std::cout << t->item << " ";
		t = t->next;
	}
	std::cout << "\b";
}

void	LILIST::Print()
{
	std::cout << "Content: (";
	PrintRec(elem);
	std::cout << ")\n";
}
