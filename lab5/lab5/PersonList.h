#pragma once
#include "stdafx.h"

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
class List;

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

	//добвить человека из списка по индексу +
	void AddAt(T1 *item, int index)
	{
		ListItem<T1> *itemOnDesiredIndex(_head);
		ListItem<T1> *itemForAdd = new ListItem<T1>(item);

		if (!_head && !index || GetCount() && index == GetCount()+1) // ≈сли список пустой или эленет прос€т добавить в хвост
		{
			Add(item);
			return;
		}
		else if (_head && !index) // ≈сли не пустой, и прос€т добавить в начало
		{
			itemForAdd->next = _head;
			itemForAdd->previous = nullptr;
			_head->previous = itemForAdd;
			_head = itemForAdd;
			SetCount(GetCount() + 1);
			return;
		}
		else if (GetCount() && index == GetCount()) // ѕрос€т добавить на место последнего элемента
		{
			itemForAdd->previous = _tail->previous;
			_tail->previous->next = itemForAdd;
			_tail->previous = itemForAdd;
			itemForAdd->next = _tail;
			SetCount(GetCount() + 1);
			return;
		}
		else if (index < 0 || index > GetCount()) // ≈сли индекс вне диапозона
			throw "Index out range";

		for (int i(1); i < index - 1; itemOnDesiredIndex = itemOnDesiredIndex->next);// »щем элемент с нашим индексом

		itemForAdd->previous = itemOnDesiredIndex->previous;
		itemOnDesiredIndex->previous->next = itemForAdd;
		itemOnDesiredIndex->previous = itemForAdd;
		itemForAdd->next = itemOnDesiredIndex;
	}
	//найти человека по указанному индексу +
	T1* Find(int index)
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
	//вернуть индекс человека, если он есть в списке +
	int IndexOf(T1 *person) {
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
	//удалить человека из списка +
	void Remove(T1 *person)
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
	//удалить человека из списка по индексу +
	void RemoveAt(int index)
	{
		T1 *person = Find(index);
		Remove(person);
	}
	//очистить список +
	void Clear()
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

	//получить количество элементов +
	int GetCount()
	{
		return _count;
	}
	//установить количество элементов+
	void SetCount(int count)
	{
		_count = count;
	}

	void RandomPersonAdd()
	{
		string name[]{ "Mark", "Jack", "Ken", "Anton", "John", "Jorj", "Den", "Bill",
			"Alexa", "Amy", "Grace", "Jane", "Jasmine", "Ella", "Clara" };
		string surname[]{ "Bishep", "Macey", "Alsopp", "Fisher", "Farrell", "Taft", "Porter",
			"Finch", "Waller", "Sherlok", "Roberts", "Waller", "Hawkins", "Wood", "Turner" };

		
		int randomNameIndex = rand() % 14;
		int randomSurnameIndex = rand() % 14;

		string NAME = name[randomNameIndex];
		size_t sizeName = strlen(name[randomNameIndex].c_str()) + 1;
		char *charName = new char[sizeName + 1];
		strcpy_s(charName, sizeName, NAME.c_str());

		string SURNAME = surname[randomSurnameIndex];
		size_t sizeSurname = strlen(surname[randomSurnameIndex].c_str()) + 1;
		char *charSurname = new char[sizeSurname + 1];
		strcpy_s(charSurname, sizeSurname, SURNAME.c_str());


		Person *randPerson = MakeRandomPerson(charName, charSurname, randomNameIndex);

		delete[] charName; charName = nullptr;
		delete[] charSurname; charSurname = nullptr;
		Person** persPtr = new Person*(new Person(*randPerson));
		Add(persPtr);

		delete randPerson; randPerson = nullptr;
	}
	Person* MakeRandomPerson(char *name, char *surname, int randomNameIndex)
	{
		Person *randPerson = new Person;

		int i(0);
		for (; i < NAMELENGTH && name[i]; ++i)
			randPerson->name[i] = name[i];
		randPerson->name[i] = '\0';

		int j(0);
		for (; i < SURNAMELENGTH && surname[j]; ++j)
			randPerson->surname[j] = surname[j];
		randPerson->surname[j] = '\0';

		int years = 15 + rand() % 100;
		randPerson->SetAge(years);

		randPerson->SetSex((randomNameIndex > 7) ? female : male);

		return randPerson;
	}

	//добавить человека в список +
	void Add(T1 *person)
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

};