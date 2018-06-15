#include "stdafx.h"

#include "Person.h"
#include "PersonList.h"
#include "PersonList.cpp"


int main()
{
	try
	{
		srand(time(NULL));
		setlocale(LC_ALL, "Rus");
		List<Person> *list1 = new List<Person>;
		List<Person> *list2 = new List<Person>;
		
		Person a;
		list1->Add(&a);
		list1->Add(&a);
		cout << list1->GetCount() << endl;
		cout << list1->IndexOf(0) << endl;
		list1->Remove(&a);
		cout << list1->GetCount() << endl;
		cout << list1->IndexOf(0) << endl;

		system("pause");
	}
	catch (char* str)
	{
		puts(str);
	}
	catch (...)
	{
		puts("Error");
	}

}

