#include <iostream>
#include "LinkedList.h"

int main()
{
	List l;
	l.insert(0, 0);
	l.insert(1, 1);
	l.insert(3, 2);
	l.insert(2, 2);
	l.insert(3, 4);
	l.print();
	l.reverse();
	l.print();
	Node* curr=l.middleNode();
	return 0;
}
