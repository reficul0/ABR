#pragma once
#include "stdafx.h"

#include "PersonList.h"
#include "PersonList.h"

enum class Category
{
	NotSet = 0,
	Double = 1,
	PersonPtr = 2,
	DoubleArr = 3,
	DoubleList = 4,
	Exit = 5
};

template <typename T1>
class List
{
private: 
	template <typename T1>
	class ListItem
	{
	private:
		T1 *_value;
	public:
		ListItem<T1>* next;
		ListItem<T1>* previous;

		ListItem() 
		{
			_value = nullptr;
			next = nullptr;
			previous = nullptr;
		}

		ListItem(T1* item)
		{
			_value = item;
			next = nullptr;
			previous = nullptr;
		}
		
		T1* GetValue()
		{
			return _value;
		}
	};

	ListItem<T1>* _head; //указатель на голову списка 
	ListItem<T1>* _tail; //указатель на конец списка
	int _count;    //количество элементов в списке 

public: 
	List()
	{
		_count = 0;
		_head = nullptr;
		_tail = nullptr;
	}
	~List()
	{
		Clear();
	}

	void Add(T1 *person);  //добавить человека в список +
	void AddAt(T1 *person, int index);  //добвить человека из списка по индексу +
	T1* Find(int index);  //найти человека по указанному индексу +
	int IndexOf(T1 *person);  //вернуть индекс человека, если он есть в списке +
	void Remove(T1 *person);  //удалить человека из списка +
	void RemoveAt(int index);  //удалить человека из списка по индексу +
	void Clear();    //очистить список +
	int GetCount();   //получить количество элементов +
	void SetCount(int count); //установить количество элементов+

	void OutputNote(ListItem<T1> list, int count);
	void OutputList(Category categoryName);
};