#include "stdafx.h"

#include "Person.h"
#include "PersonList.h"

template <typename T1>
int List<T1>::GetCount()
{
	return _count;
}

template <typename T1>
void List<T1>::SetCount(int count)
{
	_count = count;
}


//Добавление записи в конец
template <typename T1>
void List<T1>::Add(T1 *person)
{
	ListItem<T1> *item = new ListItem<T1>(person);

	if (_head)
	{
		item->previous = _tail;
		_tail->next = item;
		_tail = item;
	}
	else
		_head = _tail = item;

	SetCount(GetCount() + 1);
}

template <typename T1>
//Поиск человека по указанному индексу
T1* List<T1>::Find(int index)
{
	if (index < 0)
		return nullptr;

	int i(0);
	ListItem<T1>* item(_head);
	while (i < index)
	{
		if (item == nullptr)
			return nullptr;

		item = item->next;
		++i;
	}

	
	return item ? item->GetValue() : nullptr;
}


//Возвращает индекс человека, если он есть в списке 
template <typename T1>
int List<T1>::IndexOf(T1* person)
{
	ListItem<T1>* item = _head;
	int index(0);
	while (item)
	{
		if (item->GetValue() == person)
		{
			return index;
		}
		++index;
		item = item->next;
	}
	return -1;
}


//Удаление элемента списка
template <typename T1>
void List<T1>::Remove(T1 *person)
{
	ListItem<T1> *item(_head);
	while (item)
	{
		if (item->GetValue() == person)
		{
			if (_head == item)
			{
				if (!item->next)
				{
					_head = nullptr;
					_tail = nullptr;
					SetCount(GetCount() - 1);
					break;
				}

				_head->next->previous = nullptr;
				_head = _head->next;
				SetCount(GetCount() - 1);
				break;
			}

			if (_tail == item)
			{
				_tail->previous->next = nullptr;
				_tail = _tail->previous;
				SetCount(GetCount() - 1);
				break;
			}

			if (_head != item && _tail != item)
			{
				item->previous->next = item->next;
				item->next->previous = item->previous;
				SetCount(GetCount() - 1);
				break;
			}
		}
		item = item->next;
	}
}


//Удаление элемента списка по индексу
template <typename T1>
void List<T1>::RemoveAt(int index)
{
	T1 *person = Find(index);
	Remove(person);
}

template<typename T1>
void List<T1>::Clear()
{
	ListItem<T1> *listPointer(_head);
	if (listPointer)
	{
		while (listPointer->next)
		{
			listPointer = listPointer->next;
			listPointer->previous = nullptr;
		}

		delete listPointer;
		listPointer = nullptr;
	}

	_head = nullptr;
	_tail = nullptr;
	SetCount(0);
}


template <typename T1>
//Вывести запись
void List<T1>::OutputNote(ListItem<T1> list, int count)
{
	cout << "Note №" << count << endl;
	cout << "Name: " << list.GetValue()->name << endl;
	cout << "Surmane: " << list.GetValue()->surname << endl;
	cout << "Age: " << list.GetValue()->age << endl;
	cout << "Sex: ";

	// БЫЛО
	//if (list.GetValue()->sex == male)
	//	cout << "Male";
	//else
	//	cout << "Female";
	// Стало
	list.GetValue()->sex == male 
					? cout << "Male"
					: cout << "Female";

	cout << endl << endl;
}

template <typename T1>
//Вывести список
void List<T1>::OutputList(Category categoryName)
{
	switch (categoryName)
	{
	case Category::Double:
		for (int i(0); i < GetCount(); ++i)
		{
			if (Find(i))
			{
				double findResult = *Find(i);
				cout << "Arr[" << i + 1 << "] = " << findResult << endl;
			}
			else
				cout << "Arr[" << i + 1 << "] =  nan" << endl;
			
		}
		cout << endl;
		break;
	case Category::PersonPtr:
		break;
	case Category::DoubleArr:
		break;
	case Category::DoubleList:
		break;
	case Category::Exit:
		return;
	default:
		break;
	}
}