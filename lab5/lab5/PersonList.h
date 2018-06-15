#pragma once
#include "stdafx.h"
#include <random>

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
		
		template <class T1>
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
	T1* Find(int index);  //����� �������� �� ���������� ������� +
	int IndexOf(T1 *person);  //������� ������ ��������, ���� �� ���� � ������ +
	void Remove(T1 *person);  //������� �������� �� ������ +
	void RemoveAt(int index);  //������� �������� �� ������ �� ������� +
	void Clear();    //�������� ������ +
	int GetCount();   //�������� ���������� ��������� +
	void SetCount(int count); //���������� ���������� ���������+

	void OutputNote(ListItem<T1> list, int count);
	void OutputList();
};