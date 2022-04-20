#ifndef UNSORTED_LIST_HPP
# define UNSORTED_LIST_HPP

#include <new>
#include <cstddef>

class FULL_LIST{};
class EMPTY_LIST{};

template <class ItemType>
class UnsortedList
{
private:
	ItemType	*data;
	int			curPos;
	int			size;
	int			maxSize;
public:
	UnsortedList();
	UnsortedList(int maxSize);
	UnsortedList(UnsortedList<ItemType> &otherList);
	~UnsortedList();
	int			getLength() const;
	int			getMaxSize() const;
	bool		isFull() const;
	bool		isEmpty() const;
	void		resetList();
	void		insertItem(ItemType item);
	void		deleteItem(ItemType item);
	void		deleteItemAll(ItemType item);
	bool		retrieveItem(ItemType item);
	void		copyList(UnsortedList<ItemType> &otherList);
	bool		getNextItem(ItemType &item);
	void		operator=(UnsortedList<ItemType> &otherList);
};

template <class ItemType>
UnsortedList<ItemType>::UnsortedList()
{
	this->maxSize = 100;
	size = 0;
	curPos = -1;
}

template <class ItemType>
UnsortedList<ItemType>::UnsortedList(int maxSize)
{
	this->maxSize = maxSize;
	size = 0;
	curPos = -1;
}

template <class ItemType>
UnsortedList<ItemType>::UnsortedList(UnsortedList<ItemType> &otherList)
{
	this->maxSize = otherList.getMaxSize();
	size = 0;
	curPos = -1;
	this->copyList(otherList);
}

template <class ItemType>
UnsortedList<ItemType>::~UnsortedList()
{
	delete (this->data);
}

template <class ItemType>
int	UnsortedList<ItemType>::getLength() const
{
	return (this->size);
}

template <class ItemType>
int	UnsortedList<ItemType>::getMaxSize() const
{
	return (this->maxSize);
}

template <class ItemType>
bool UnsortedList<ItemType>::isEmpty() const
{
	return (this->size == 0);
}

template <class ItemType>
bool UnsortedList<ItemType>::isFull() const
{
	return (this->size == this->maxSize);
}

template <class ItemType>
void UnsortedList<ItemType>::resetList()
{
	this->curPos = -1;
}

template <class ItemType>
void UnsortedList<ItemType>::insertItem(ItemType item)
{
	if (this->isFull())
		throw (FULL_LIST);
	++(this->curPos);
	data[this->curPos] = item;
	++(this->size);
}

/*
	post	: 리스트에 item 과 같은 값을 갖는 데이터 중 하나만 삭제됨
*/
template <class ItemType>
void UnsortedList<ItemType>::deleteItem(ItemType item)
{
	int			pos;
	ItemType	temp;

	if (this->isEmpty())
		throw (EMPTY_LIST);
	pos = 0;
	while (pos < size && data[pos] != item)
	{
		++pos;
	}
	if (pos == size)
		return ;
	temp = data[(this->size)];
	data[(this->size)] = data[pos];
	data[pos] = temp;
	--(this->size);
}

/*
	post	: 리스트에 item 과 같은 값을 갖는 데이터 모두가 삭제됨
*/
template <class ItemType>
void UnsortedList<ItemType>::deleteItemAll(ItemType item)
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
bool UnsortedList<ItemType>::retrieveItem(ItemType item)
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
void UnsortedList<ItemType>::copyList(UnsortedList<ItemType> &otherList)
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
bool	UnsortedList<ItemType>::getNextItem(ItemType &item)
{
	if (this->curPos >= this->size)
		return (false);
	++(this->curPos);
	item = (this->data)[this->curPos];
	return (true);
}

/* if this->maxSize < otherList.maxSize : UNDEFINED */
template <class ItemType>
void	UnsortedList<ItemType>::operator=(UnsortedList<ItemType> &otherList)
{
	this->copyList(otherList);
}
#endif
