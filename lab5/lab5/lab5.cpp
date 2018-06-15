#include "stdafx.h"

#include "Person.h"
#include "PersonList.h"
#include "PersonList.cpp"

template <typename T>
void ProofOfWork(List<T>* list, const Category categoryName)
{
	switch (categoryName)
	{
	case Category::NotSet:
		throw "Category not set.";
	case Category::Double:
	{
		for (int i(1); i < 6; ++i)
		{
			double *data = new double(i);
			list->Add(data);
		}
		list->OutputList(categoryName);
		list->RemoveAt(2);
		list->OutputList(categoryName);
		break;
	}
	case Category::PersonPtr:
	{
		/*for (int i(1); i < 6; ++i)
		{
			Person *data = new Person();
			list->Add(data);
		}*/
		break;
	}
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
				ProofOfWork(list1, Category::Double);
				break;
			}
			case Category::PersonPtr:
			{
				List<Person*> *list1 = new List<Person*>;
				//ProofOfWork(list1, Category::PersonPtr);
				break;
			}
			case Category::DoubleArr:
			{
				List<double[5]> *list1 = new List<double[5]>;
				//ProofOfWork(list1, Category::DoubleArr);
				break;
			}
			case Category::DoubleList:
			{
				List<List<double>> *list1 = new List<List<double>>;
				//ProofOfWork(list1, Category::DoubleList);
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

