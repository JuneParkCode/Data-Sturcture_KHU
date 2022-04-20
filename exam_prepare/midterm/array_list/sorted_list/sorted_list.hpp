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
	size = 0;
	curPos = -1;
}

template <class ItemType>
SortedList<ItemType>::SortedList(int maxSize)
{
	this->maxSize = maxSize;
	size = 0;
	curPos = -1;
}

template <class ItemType>
SortedList<ItemType>::SortedList(SortedList<ItemType> &otherList)
{
	this->maxSize = otherList.getMaxSize();
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
    bool    found;
    int     start;
    int     mid;
    int     end;
    int     pos;

	if (this->isFull())
		throw (FULL_LIST);
    /* binary search ... */
    found = false;
    start = 0;
    end = size;
    while (!found && start < end)
    {
        mid = (start + end) / 2;
        switch (compare((this->data)[mid]))
        {
        case LESS:
            end = mid;
            break;
        case GREATER:
            start = mid;
            break;
        case EQUAL:
            found = true;
            pos = mid;
            break;
        }
    }
    
}

/*
	post	: 리스트에 item 과 같은 값을 갖는 데이터 중 하나만 삭제됨
*/
template <class ItemType>
void SortedList<ItemType>::deleteItem(ItemType item)
{
	int			pos;
	ItemType	temp;

	if (this->isEmpty())
		throw (EMPTY_LIST);

}

/*
	post	: 리스트에 item 과 같은 값을 갖는 데이터 모두가 삭제됨
*/
template <class ItemType>
void SortedList<ItemType>::deleteItemAll(ItemType item)
{
	int			pos;
	ItemType	temp;

	if (this->isEmpty())
		throw (EMPTY_LIST);
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
		this->insertItem(otherList.getNextItem);
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