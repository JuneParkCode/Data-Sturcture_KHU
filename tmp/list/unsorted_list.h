#ifndef UNSORTED_LIST_H
# define UNSORTED_LIST_H
// DS - Unsorted list using temp
// 2022.03.10
// Author : Park Sungjun
# define MAX_SIZE 1000
# include "item_type.h"
class	unsorted_list
{
private:
	ItemType	info[MAX_SIZE];
public:
	// transformers
	void	MakeEmpty();
	void	InsertItem(ItemType &item);
	void	DeleteItem(ItemType &item);
	// observers
	bool	IsFull() const;
	int		Lengthls() const;
	void	RetrieveItem(ItemType &item, bool &found);
	// iterators
	void	ResetList();
	void	GetNextItem();
}
#endif`
