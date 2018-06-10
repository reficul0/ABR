#pragma once
#include "stdafx.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

enum Sex
{
	male = 1,
	female
};

class Person
{
public:
	char name[20];
	char surname[30];
	int age;
	Sex sex;

	Person()
	{ }

	Person(char Name[], char Surname[], int Age, Sex Sex)
	{
		SetName(Name);
		SetSurname(Surname);
		SetAge(Age);
		SetSex(Sex);
	}
	void SetName(char Name[])
	{
		for (int i = 0; i < 20; i++)
		{
			name[i] = Name[i];
			if (Name[i] == '\0')
				break;
		}
	}
	void SetSurname(char Surname[])
	{
		for (int i = 0; i < 30; i++)
		{
			surname[i] = Surname[i];
			if (Surname[i] == '\0')
				break;
		}
	}

	void SetAge(int Age)
	{
		age = Age;
	}
	void SetSex(Sex Sex)
	{
		sex = Sex;
	}
};