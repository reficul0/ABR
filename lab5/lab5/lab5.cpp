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
	case Category::PersonPtr:
	case Category::DoubleArr:
		for (int i(0); i < list->GetCount(); ++i)
		{
			if (list->Find(i))
			{
				auto findResult = *(list->Find(i));
				cout << "List[" << i << "] = ";

				if (Category::DoubleArr != categoryName)
				{
					cout << findResult << endl;
				}
				else
				{
					auto *doubleArr = list->Find(i);
					cout << "{ " << doubleArr[0];
					for (int j(1); j < 5; ++j)
					{
						cout << ", " << doubleArr[j];
					}
					cout << " }" << endl;
				}
			}
			else
				cout << "List[" << i << "] =  nan" << endl;

		}
		cout << endl;
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

		const int listFinalLength(5),
				  indexForProofRemove(2),
				  indexForProofAdd(4);

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
				
				for (int i(1); i < listFinalLength+1 ; ++i)
				{
					double* data = new double(i);
					list1->Add(data);
				}
				OutputList(Category::Double, list1);

				list1->RemoveAt(indexForProofRemove);
				OutputList(Category::Double, list1);
				
				list1->AddAt(new double(3), indexForProofAdd);
				OutputList(Category::Double, list1);

				break;
			}
			case Category::PersonPtr:
			{
				List<Person*> *list1 = new List<Person*>;
				for (int i(0); i < listFinalLength; ++i)
				{
					list1->RandomPersonAdd();
				}
				OutputList(Category::PersonPtr, list1);

				list1->RemoveAt(indexForProofRemove);
				OutputList(Category::PersonPtr, list1);

				auto randPerson = list1->MakeRandomPerson("RandomName", "RandomSurname", 1);
				list1->AddAt(&randPerson, indexForProofAdd);
				OutputList(Category::PersonPtr, list1);

				break;
			}
			case Category::DoubleArr:
			{
				const int arrayLength(5);

				List<double> *list1 = new List<double>;
				for (double i(0); i < listFinalLength; ++i)
				{
					list1->Add(new double[arrayLength] { i, i+1, i+2, i+3, i+4 });
				}
				OutputList(Category::DoubleArr, list1);

				list1->RemoveAt(indexForProofRemove);
				OutputList(Category::DoubleArr, list1);

				double *arr = new double[arrayLength] { 1., 2., 3., 4., 5. };
				if (!arr)
					throw "Memory leack";

				list1->AddAt(arr, indexForProofAdd);
				OutputList(Category::DoubleArr, list1);
				break;
			}
			case Category::DoubleList:
			{
				//List<List<double>> *list1 = new List<List<double>>;
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

