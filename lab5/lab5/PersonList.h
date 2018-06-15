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

	ListItem<T1>* _head; //��������� �� ������ ������ 
	ListItem<T1>* _tail; //��������� �� ����� ������
	int _count;    //���������� ��������� � ������ 

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

	void Add(T1 *person);  //�������� �������� � ������ +
	void AddAt(T1 *person, int index);  //������� �������� �� ������ �� ������� +
	T1* Find(int index);  //����� �������� �� ���������� ������� +
	int IndexOf(T1 *person);  //������� ������ ��������, ���� �� ���� � ������ +
	void Remove(T1 *person);  //������� �������� �� ������ +
	void RemoveAt(int index);  //������� �������� �� ������ �� ������� +
	void Clear();    //�������� ������ +
	int GetCount();   //�������� ���������� ��������� +
	void SetCount(int count); //���������� ���������� ���������+

	void OutputNote(ListItem<T1> list, int count);
	void OutputList(Category categoryName);
};