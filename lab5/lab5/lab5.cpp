#include "stdafx.h"
#include<iostream>
#include<ctime>

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	PersonList *list1 = new PersonList;
	PersonList *list2 = new PersonList;

	int countOfPerson = 3;
	for (int i(0); i < countOfPerson; i++)
	{
		list1->RandomPersonAdd();
		list2->RandomPersonAdd();
	}

	cout << "\t\tList 1:" << endl;
	list1->OutputList();
	cout << "\t\tList 2:" << endl;
	list2->OutputList();
	system("pause");

	cout << "Add a note to the list1:" << endl;
	list1->ReadingPerson();
	cout << "\t\tList 1:" << endl;
	list1->OutputList();
	system("pause");

	cout << "Copying the second person from the first list to the end of second:" << endl;
	list2->Add(list1->Find(1)); 
	cout << "\t\tList 1:" << endl;
	list1->OutputList();
	cout << "\t\tList 2:" << endl;
	list2->OutputList();
	system("pause");

	cout << "Delete the second person from the first list:" << endl;
	list1->RemoveAt(1);
	cout << "\t\tList 1:" << endl;
	list1->OutputList();
	cout << "\t\tList 2:" << endl;
	list2->OutputList();
	system("pause");

	cout << "Remove the second list..." << endl;
	list2->Clear();
	cout << "\t\tList 2:" << endl;
	list2->OutputList();
	system("pause");

}

