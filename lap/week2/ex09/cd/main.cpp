#include <iostream>
#include "ItemType.h"
#include "unsorted.h"
using namespace std;

int	main(void)
{
	UnsortedType	*newList = new UnsortedType;
	ItemType		item;
	int				location;

	newList -> ResetList();
	for (int i = 0; i < 10; ++i)
	{
		item.Initialize(i % 5);
		newList -> InsertItem(item);
	}
	location = 0;
	newList -> ResetList();
	while (location < newList -> LengthIs())
	{
		newList -> GetNextItem(item);
		item.Print(cout);
		cout <<endl;
		location++;
	}
	item.Initialize(2);
	newList -> DeleteItem(item);
	newList -> ResetList();
	location = 0;
	while (location < newList -> LengthIs())
	{
		newList -> GetNextItem(item);
		item.Print(cout);
		location++;
	}
	return (0);
}
