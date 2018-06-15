#include "stdafx.h"

#include "Person.h"
#include "PersonList.h"
#include "PersonList.cpp"

template <typename T>
void OutputList(Category categoryName, List<T>* list)
{
	switch (categoryName)
	{
	case Category::Double:
	{
		for (int i(0); i < list->GetCount(); ++i)
		{
			if (list->Find(i))
			{
				auto findResult = *(list->Find(i));
				cout << "List[" << i + 1 << "] = " << findResult << endl;
			}
			else
				cout << "List[" << i + 1 << "] =  nan" << endl;

		}
		cout << endl;
		break;
	}
	case Category::PersonPtr:
		for (int i(1); i < list->GetCount(); ++i)
		{
			if (list->Find(i))
			{
				auto findResult = list->Find(i);
				cout << "List[" << i << "] = " << findResult << endl;

			}
			else
			{
				cout << "nan" << endl;
			}
		}
		cout << endl;
		break;
	case Category::DoubleArr:
		break;
	case Category::DoubleList:
		break;
	case Category::Exit:
		return;
	default:
		break;
	}
}

template <typename T1>
void ProofOfWork(const Category categoryName, List<T1>* list)
{
	switch (categoryName)
	{
	case Category::Double:
		
	case Category::PersonPtr:
		
	case Category::NotSet:
		throw "Category not set.";
		break;
	case Category::DoubleArr:
		break;
	case Category::DoubleList:
		break;
	case Category::Exit:
		return;
	default:
		break;
	}
}

int main()
{
	try
	{
		srand(time(NULL));
		setlocale(LC_ALL, "Rus");
		
		Category userChoice(Category::NotSet);
		while (userChoice != Category::Exit)
		{
			string categoryTable = "1. Demonstrate on double\n2. Demonstrate on *Person\n3. Demonstrate on double[5]\n4. Demonstrate on List<double>\n5. Exit\n-- - Choose 1 - 4: ";
			puts(categoryTable.c_str());

			int userChoiceInt(0);
			cin >> userChoiceInt;
			userChoice = static_cast<Category>(userChoiceInt);
			
			switch (userChoice)
			{
			case Category::NotSet:
				throw "Category not set.";
			case Category::Double:
			{
				List<double> *list1 = new List<double>;
				for (int i(1); i < 6; ++i)
				{
					double* data = new double(i);
					list1->Add(data);
				}
				OutputList(Category::Double, list1);
				list1->RemoveAt(2);
				OutputList(Category::Double, list1);
				list1->AddAt(new double(3), 4);
				OutputList(Category::Double, list1);
				break;
				break;
			}
			case Category::PersonPtr:
			{
				List<Person*> *list1 = new List<Person*>;
				for (int i(1); i < 6; ++i)
				{
					list1->RandomPersonAdd();
				}
				OutputList(Category::PersonPtr, list1);
				list1->RemoveAt(2);
				OutputList(Category::PersonPtr, list1);
				auto randPerson = list1->MakeRandomPerson("Name", "Surname", 1);
				list1->AddAt(&randPerson, 4);
				OutputList(Category::PersonPtr, list1);
				break;
			}
			case Category::DoubleArr:
			{
				List<double[5]> *list1 = new List<double[5]>;
				//ProofOfWork(Category::DoubleArr);
				break;
			}
			case Category::DoubleList:
			{
				List<List<double>> *list1 = new List<List<double>>;
				//ProofOfWork(Category::DoubleList);
				break;
			}
			case Category::Exit:
				return 0;
			default:
				throw "Error.";
			}
		}


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

