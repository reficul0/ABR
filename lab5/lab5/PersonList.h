#pragma once
#include "Person.h"
#include <random>

class PersonList
{
private: 
	class PersonListItem
	{
	private:
		Person *Value = nullptr;
	public:
		PersonListItem(Person* person)
		{
			Value = person;
		}
		PersonListItem *Next = nullptr;
		PersonListItem *Previous = nullptr;
		Person *GetValue()
		{
			return Value;
		}
	};

	PersonListItem *_head; //��������� �� ������ ������ 
	PersonListItem *_tail; //��������� �� ����� ������
	int _count;    //���������� ��������� � ������ 

public: 
	PersonList()
	{
		_count = 0;
	}
	void Add(Person *person);  //�������� �������� � ������ +
	Person *Find(int index);  //����� �������� �� ���������� ������� +
	int IndexOf(Person *person);  //������� ������ ��������, ���� �� ���� � ������ +
	void Remove(Person *person);  //������� �������� �� ������ +
	void RemoveAt(int index);  //������� �������� �� ������ �� ������� +
	void Clear();    //�������� ������ +
	int GetCount();   //�������� ���������� ��������� +
	void SetCount(int count); //���������� ���������� ���������+
	void ReadingPerson(); //����������� ������+
	void RandomPersonAdd(); //���������� �������� � ���������� ������� +
	Person *MakeRandomPerson(char *name, char *surname, int randomNameIndex); //�������� �������� � ���������� ������� +


	void OutputNote(PersonListItem list, int count);
	void OutputList();

	void InputPerson (PersonListItem *Person);
};
