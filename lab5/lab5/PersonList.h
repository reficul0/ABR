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

	PersonListItem *_head; //указатель на голову списка 
	PersonListItem *_tail; //указатель на конец списка
	int _count;    //количество элементов в списке 

public: 
	PersonList()
	{
		_count = 0;
	}
	void Add(Person *person);  //добавить человека в список +
	Person *Find(int index);  //найти человека по указанному индексу +
	int IndexOf(Person *person);  //вернуть индекс человека, если он есть в списке +
	void Remove(Person *person);  //удалить человека из списка +
	void RemoveAt(int index);  //удалить человека из списка по индексу +
	void Clear();    //очистить список +
	int GetCount();   //получить количество элементов +
	void SetCount(int count); //установить количество элементов+
	void ReadingPerson(); //считываниие данных+
	void RandomPersonAdd(); //добавление человека с рандомными данными +
	Person *MakeRandomPerson(char *name, char *surname, int randomNameIndex); //создание человека с рандомными данными +


	void OutputNote(PersonListItem list, int count);
	void OutputList();

	void InputPerson (PersonListItem *Person);
};
