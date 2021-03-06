#ifndef SORTED_LIST_HPP
# define SORTED_LIST_HPP

#include <new>
#include <cstddef>

class FULL_LIST{};
class EMPTY_LIST{};

enum RelationType  {LESS, GREATER, EQUAL};

template <class ItemType>
RelationType compare(ItemType a, ItemType b)
{
  if (a < b)
    return LESS;
  else if (a > b)
    return GREATER;
  else return EQUAL;
}

template <class ItemType>
class SortedList
{
private:
	ItemType	*data;
	int			curPos;
	int			size;
	int			maxSize;
public:
	SortedList();
	SortedList(int maxSize);
	SortedList(SortedList<ItemType> &otherList);
	~SortedList();
	int			getLength() const;
	int			getMaxSize() const;
	bool		isFull() const;
	bool		isEmpty() const;
	void		resetList();
	void		insertItem(ItemType item);
	void		deleteItem(ItemType item);
	void		deleteItemAll(ItemType item);
	bool		retrieveItem(ItemType item);
	void		copyList(SortedList<ItemType> &otherList);
	bool		getNextItem(ItemType &item);
	void		operator=(SortedList<ItemType> &otherList);
};

template <class ItemType>
SortedList<ItemType>::SortedList()
{
	this->maxSize = 100;
	this->data = new ItemType(this->maxSize);
	size = 0;
	curPos = -1;
}

template <class ItemType>
SortedList<ItemType>::SortedList(int maxSize)
{
	this->maxSize = maxSize;
	this->data = new ItemType(this->maxSize);
	size = 0;
	curPos = -1;
}

template <class ItemType>
SortedList<ItemType>::SortedList(SortedList<ItemType> &otherList)
{
	this->maxSize = otherList.getMaxSize();
	this->data = new ItemType(this->maxSize);
	size = 0;
	curPos = -1;
	this->copyList(otherList);
}

template <class ItemType>
SortedList<ItemType>::~SortedList()
{
	delete (this->data);
}

template <class ItemType>
int	SortedList<ItemType>::getLength() const
{
	return (this->size);
}

template <class ItemType>
int	SortedList<ItemType>::getMaxSize() const
{
	return (this->maxSize);
}

template <class ItemType>
bool SortedList<ItemType>::isEmpty() const
{
	return (this->size == 0);
}

template <class ItemType>
bool SortedList<ItemType>::isFull() const
{
	return (this->size == this->maxSize);
}

template <class ItemType>
void SortedList<ItemType>::resetList()
{
	this->curPos = -1;
}

template <class ItemType>
void SortedList<ItemType>::insertItem(ItemType item)
{
    bool	found;
	int		pos;

    /* binary search ... */
    found = false;
	pos = 0;
    while (!found && pos < this->size)
    {
        switch (compare((this->data)[pos], item))
        {
			case	GREATER:
			case	EQUAL:
					found = true;
					break;
			case	LESS:
					++pos;
					break;
        }
    }
    for (int i = this->size; i > pos; --i)
	{
		(this->data)[i] = (this->data)[i - 1];
	}
	(this->data)[pos] = item;
	++(this->size);
}

/*
	post	: ???????????? item ??? ?????? ?????? ?????? ????????? ??? ????????? ?????????
*/
template <class ItemType>
void SortedList<ItemType>::deleteItem(ItemType item)
{
	bool    found;
    int     start;
    int     mid;
    int     end;
    int     pos;

    /* binary search ... */
    found = false;
    start = 0;
    end = size;
    while (!found && start < end)
    {
        mid = (start + end) / 2;
        pos = mid;
        switch (compare((this->data)[mid]))
        {
        case LESS:
            end = mid - 1;
            break;
        case GREATER:
            start = mid + 1;
            break;
        case EQUAL:
            found = true;
            break;
        }
    }
    for (int i = pos; i < this->size; ++i)
	{
		(this->data)[i] = (this->data)[i + 1];
	}
	--(this->size);
}

/*
	post	: ???????????? item ??? ?????? ?????? ?????? ????????? ????????? ?????????
*/
template <class ItemType>
void SortedList<ItemType>::deleteItemAll(ItemType item)
{
	int			pos;
	ItemType	temp;

	pos = 0;
	while (pos < size && data[pos] != item)
	{
		temp = data[(this->size)];
		data[(this->size)] = data[pos];
		data[pos] = temp;
		--(this->size);
	}
}

template <class ItemType>
bool SortedList<ItemType>::retrieveItem(ItemType item)
{
	int			pos;
	ItemType	temp;

	pos = 0;
	while (pos < size && data[pos] != item)
	{
		++pos;
	}
	return (pos < size && data[pos] == item);
}

template <class ItemType>
void SortedList<ItemType>::copyList(SortedList<ItemType> &otherList)
{
	int	pos;
	
	pos = 0;
	this->size = 0;
	otherList.resetList();
	while (pos < size)
	{
		this->insertItem(otherList.getNextItem());
		++pos;
	}
}

template <class ItemType>
bool	SortedList<ItemType>::getNextItem(ItemType &item)
{
	if (this->curPos >= this->size)
		return (false);
	++(this->curPos);
	item = (this->data)[this->curPos];
	return (true);
}

/* if this->maxSize < otherList.maxSize : UNDEFINED */
template <class ItemType>
void	SortedList<ItemType>::operator=(SortedList<ItemType> &otherList)
{
	this->copyList(otherList);
}
#endif