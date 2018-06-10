#pragma once
#include "Person.h"
#include <random>

class PersonList
{
private: 
	class PersonListItem
	{
	private:
		Person *_value;
	public:
		PersonListItem * next;
		PersonListItem* previous;

		PersonListItem() 
		{
			_value = nullptr;
			next = nullptr;
			previous = nullptr;
		}

		PersonListItem(Person* person)
		{
			_value = person;
			next = nullptr;
			previous = nullptr;
		}
		
		Person* GetValue()
		{
			return _value;
		}
	};

	PersonListItem* _head; //��������� �� ������ ������ 
	PersonListItem* _tail; //��������� �� ����� ������
	int _count;    //���������� ��������� � ������ 

public: 
	PersonList()
	{
		_count = 0;
		_head = nullptr;
		_tail = nullptr;
	}

	void Add(Person *person);  //�������� �������� � ������ +
	Person* Find(int index);  //����� �������� �� ���������� ������� +
	int IndexOf(Person *person);  //������� ������ ��������, ���� �� ���� � ������ +
	void Remove(Person *person);  //������� �������� �� ������ +
	void RemoveAt(int index);  //������� �������� �� ������ �� ������� +
	void Clear();    //�������� ������ +
	int GetCount();   //�������� ���������� ��������� +
	void SetCount(int count); //���������� ���������� ���������+
	void ReadingPerson(); //����������� ������+
	void RandomPersonAdd(); //���������� �������� � ���������� ������� +
	Person* MakeRandomPerson(char* name, char* surname, int randomNameIndex); //�������� �������� � ���������� ������� +


	void OutputNote(PersonListItem list, int count);
	void OutputList();
};
