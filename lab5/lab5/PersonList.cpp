#include "stdafx.h"


//���������� ������ � ��������
void PersonList::ReadingPerson()
{
	char name[20];
	char surname[40];
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
	} while (sexOfPerson != 1 && sexOfPerson != 2); //�������� ������������ ��������

	switch (sexOfPerson)
	{
	case 1:
		sex = male;
		break;
	case 2:
		sex = female;
		break;
	}

	do
	{
		cout << "Enter the person age, pls (0 - 150):";
		cin >> age;
	} while (age < 0 || age > 150); //�������� ������������ ��������
		
	this->Add(new Person(name, surname, age, sex));
}

int PersonList::GetCount()
{
	return (_count);
}

void PersonList::SetCount(int count)
{
	_count = count;
}

//���������� ������ � �����
void PersonList::Add(Person *person)
{
	PersonListItem *item = new PersonListItem(person);

	if (_head != nullptr)
	{
		item->Previous = _tail;
		_tail->Next = item;
		_tail = item;
	}
	else
		_head = _tail = item;

	this->SetCount(GetCount() + 1);
}

//���������� �������� � ���������� �������
void PersonList::RandomPersonAdd()
{
	string name[] { "Mark", "Jack", "Ken", "Anton", "John", "Jorj", "Den", "Bill",
		"Alexa", "Amy", "Grace", "Jane", "Jasmine", "Ella", "Clara" };
	string surname[] {"Bishep", "Macey", "Alsopp", "Fisher", "Farrell", "Taft", "Porter",
		"Finch", "Waller", "Sherlok", "Roberts", "Waller", "Hawkins", "Wood", "Turner"};
	
	int randomNameIndex = rand() % 14; //��������� ������ ��� �����
	printf("%d", randomNameIndex);
	int randomSurnameIndex = rand() % 14; //��������� ������ ��� �������


	string NAME = name[randomNameIndex];
	size_t sizeName = strlen(name[randomNameIndex].c_str()) + 1;
	char *charName = new char[sizeName + 1];
	strcpy_s(charName, sizeName, NAME.c_str());
	

	string SURNAME = surname[randomSurnameIndex];
	size_t sizeSurname = strlen(surname[randomSurnameIndex].c_str()) + 1;
	char *charSurname = new char[sizeSurname + 1];
	strcpy_s(charSurname, sizeSurname, SURNAME.c_str());
	

	Person *randPerson = MakeRandomPerson(charName, charSurname, randomNameIndex);
	delete[] charName;
	delete[] charSurname;

	/*cout << "���������� � �������� :" << endl;
	cout << randPerson->name << " " << randPerson->surname << endl;
	cout << randPerson->age << " ���" << endl;
	switch (randPerson->sex)
	{
	case 1:
		cout << "male" << endl;
		break;
	case 2:
		cout << "female" << endl;
		break;
	}*/
	Add(new Person(*randPerson));

	delete randPerson;
}

//�������� �������� � ���������� �������
Person *PersonList::MakeRandomPerson(char *name, char *surname, int randomNameIndex)
{
	Person *randPerson = new Person;

	//���������� �������
	for (int i = 0; i < 20; i++)
	{
		randPerson->name[i] = name[i];
		if (!name[i])
			break;
	}
	for (int i = 0; i < 20; i++)
	{
		randPerson->surname[i] = surname[i];
		if (!surname[i])
			break;
	}

	int years = 15 + rand() % 100;
	randPerson->age = years;

	if (randomNameIndex > 7)
	{
		randPerson->sex = female;
	}
	else
	{
		randPerson->sex = male;
	}

	return (randPerson);
}

//����� �������� �� ���������� �������
Person* PersonList::Find(int index)
{
	if (index < 0)
	{
		return nullptr;
	}
	int i = 0;
	PersonListItem *item = _head;
	while (i < index)
	{
		if (item == nullptr)
		{
			return nullptr;
		}
		item = item->Next;
		i++;
	};
	return item->GetValue();
}

//���������� ������ ��������, ���� �� ���� � ������ 
int PersonList::IndexOf(Person *person)
{
	PersonListItem *item = _head;
	int index = 0;
	while (item != nullptr)
	{
		if (*(item->GetValue()->name) == *(person->name) &&
			(*(item->GetValue()->surname) == *(person->surname)) &&
			(item->GetValue()->age == (person->age)) &&
			(item->GetValue()->sex == (person->sex)))
		{
			return index;
		}
		index++;
		item = item->Next;
	}
	return -1;
}

//�������� �������� ������
void PersonList::Remove(Person *person)
{
	PersonListItem *item = _head;
	while (item != nullptr)
	{
		if (*(item->GetValue()->name) == *(person->name) &&
			(*(item->GetValue()->surname) == *(person->surname)) &&
			(item->GetValue()->age == (person->age)) &&
			(item->GetValue()->sex == (person->sex)))
		{
			if (_head == item)
			{
				if (item->Next == nullptr)
				{
					_head = nullptr;
					_tail = nullptr;
					this->SetCount(GetCount() - 1);
					break;
				}
				_head->Next->Previous = nullptr;
				_head = _head->Next;
				this->SetCount(GetCount() - 1);
				break;
			}

			if (_tail == item)
			{
				_tail->Previous->Next = nullptr;
				_tail = _tail->Previous;
				this->SetCount(GetCount() - 1);
				break;
			}

			if (_head != item && _tail != item)
			{
				item->Previous->Next = item->Next;
				item->Next->Previous = item->Previous;
				this->SetCount(GetCount() - 1);
				break;
			}
		}
		item = item->Next;
	}
}

//�������� �������� ������ �� �������
void PersonList::RemoveAt(int index)
{
	Person *person = Find(index);
	Remove(person);
}

//������� ������
void PersonList::Clear()
{
	PersonListItem *listPointer = _head;
	while (listPointer->Next != NULL)
	{
		listPointer = listPointer->Next;
		delete listPointer->Previous;
	}
	delete listPointer;
	
	_head = nullptr;
	_tail = nullptr;
	SetCount(0);
}

//������� ������
void PersonList::OutputNote(PersonListItem list, int count)
{
	cout << "Note �" << count << endl;
	cout << "Name: " << list.GetValue()->name << endl;
	cout << "Surmane: " << list.GetValue()->surname << endl;
	cout << "Age: " << list.GetValue()->age << endl;
	cout << "Sex: ";

	if (list.GetValue()->sex == male)
	{
		cout << "Male";
	}
	else
	{
		cout << "Female";
	}
	cout << endl << endl;
}

//������� ������
void PersonList::OutputList()
{
	cout << endl;
	PersonListItem* item = _head;
	int i = 1;
	while (item != nullptr)
	{
		OutputNote(*item, i);
		item = item->Next;
		i++;
	}

	if (_head == nullptr)
	{
		cout << "Head = NULL \t Tail = NULL " << endl;
	}
}