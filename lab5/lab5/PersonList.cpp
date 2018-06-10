#include "stdafx.h"


//считывание данных о человеке
void PersonList::ReadingPerson()
{
	char name[NAMELENGTH];
	char surname[SURNAMELENGTH];
	int age;
	Sex sex;

	cout << endl << "Enter the person name, pls (long up to 20):";
	cin >> name;

	cout << endl << "Enter the person surname, pls (long up to 30):";
	cin >> surname;

	int sexOfPerson;
	do
	{
		cout << ("Enter the person sex, pls (male = 1,female = 2): ");
		cin >> sexOfPerson;
	} while (sexOfPerson != 1 && sexOfPerson != 2); //Проверка допустимости значения

	sex = (Sex)sexOfPerson;

	do
	{
		cout << "Enter the person age, pls (0 - 150):";
		cin >> age;
	} while (age < 0 || age > 150); //Проверка корректности возраста
		
	Add(new Person(name, surname, age, sex));
}

int PersonList::GetCount()
{
	return _count;
}

void PersonList::SetCount(int count)
{
	_count = count;
}

//Добавление записи в конец
void PersonList::Add(Person *person)
{
	PersonListItem *item = new PersonListItem(person);

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

//Добавление человека с рандомными данными
void PersonList::RandomPersonAdd()
{
	string name[] { "Mark", "Jack", "Ken", "Anton", "John", "Jorj", "Den", "Bill",
		"Alexa", "Amy", "Grace", "Jane", "Jasmine", "Ella", "Clara" };
	string surname[] {"Bishep", "Macey", "Alsopp", "Fisher", "Farrell", "Taft", "Porter",
		"Finch", "Waller", "Sherlok", "Roberts", "Waller", "Hawkins", "Wood", "Turner"};
	
	// srand должен подкулючить программист в main, иначе,
	// если сранддить тут, то дебаггер неправильно себя ведет
	int randomNameIndex = rand() % 14; //Случайный индекс для имени
	int randomSurnameIndex = rand() % 14; //Случайный индекс для фамилии

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

	Add(new Person(*randPerson));

	delete randPerson;
}

//Создание человека с рандомными данными
Person *PersonList::MakeRandomPerson(char *name, char *surname, int randomNameIndex)
{
	Person *randPerson = new Person;

	//Заполнение данными
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

	/*Было
	if (randomNameIndex > 7)
	{
		randPerson->sex = female;
	}
	else
	{
		randPerson->sex = male;
	}*/
	// Стало
	randPerson->SetSex((randomNameIndex > 7) ? female : male);
	
	return randPerson;
}

//Поиск человека по указанному индексу
Person* PersonList::Find(int index)
{
	if (index < 0)
		return nullptr;

	int i(0);
	PersonListItem* item(_head);
	while (i < index)
	{
		if (item == nullptr)
			return nullptr;

		item = item->next;
		++i;
	}

	return item->GetValue();
}

//Возвращает индекс человека, если он есть в списке 
int PersonList::IndexOf(Person* person)
{
	PersonListItem* item = _head;
	int index(0);
	while (item)
	{
		if (*(item->GetValue()->name) == *(person->name)
			&& (item->GetValue()->age == (person->age))
			&& (item->GetValue()->sex == (person->sex))
			&& (*(item->GetValue()->surname) == *(person->surname)))
		{
			return index;
		}
		++index;
		item = item->next;
	}
	return -1;
}

//Удаление элемента списка
void PersonList::Remove(Person *person)
{
	PersonListItem *item(_head);
	while (item)
	{
		if (*(item->GetValue()->name) == *(person->name)
			&& (item->GetValue()->age == (person->age))
			&& (item->GetValue()->sex == (person->sex))
			&& (*(item->GetValue()->surname) == *(person->surname)))
		{
			if (_head == item)
			{
				if (item->next)
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
void PersonList::RemoveAt(int index)
{
	Person *person = Find(index);
	Remove(person);
}

//Очистка списка
void PersonList::Clear()
{
	PersonListItem *listPointer(_head);
	if (listPointer)
	{
		while (listPointer->next)
		{
			listPointer = listPointer->next;

			delete listPointer->previous;
			listPointer->previous = nullptr;
		}
	
		delete listPointer;
		listPointer = nullptr;
	}

	_head = nullptr;
	_tail = nullptr;
	SetCount(0);
}

//Вывести запись
void PersonList::OutputNote(PersonListItem list, int count)
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

//Вывести список
void PersonList::OutputList()
{
	cout << endl;
	PersonListItem* item(_head);
	int i(1);
	while (item)
	{
		OutputNote(*item, i);
		item = item->next;
		++i;
	}

	if (!_head)
	{
		cout << "Head = NULL \t Tail = NULL " << endl;
	}
}