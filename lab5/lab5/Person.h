#pragma once
#include "stdafx.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define NAMELENGTH 20
#define SURNAMELENGTH 30

enum Sex
{
	male = 1,
	female
};

class Person
{
public:
	

	char name[NAMELENGTH];
	char surname[SURNAMELENGTH];
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
		int i(0);
		for (; i < NAMELENGTH && Name[i]; ++i)
			name[i] = Name[i];

		name[i] = '\0';
	}

	void SetSurname(char Surname[])
	{
		int i(0);
		for (; i < SURNAMELENGTH && Surname[i]; ++i)
			surname[i] = Surname[i];

		surname[i] = '\0';
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