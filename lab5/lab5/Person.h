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

	Person() {}

	Person(char Name[], char Surname[], int Age, Sex Sex)
	{
		SetName(Name);
		SetSurname(Surname);
		SetAge(Age);
		SetSex(Sex);
	}

	~Person() {}

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

	virtual char* GetDescription()
	{
		const int punctuationMarksCount(3)
				 , spacesCount (5)
				 , yearsOldLength(9)
				 , sexLength(sex == male ? 4 : 6);

		int ageLength(0);
		for (int number(age); number; ++ageLength)
		{
			number /= 10;
		}

		int nameLength(0);
		for (; name[nameLength]; ++nameLength);

		int surnameLength(0);
		for (; surname[surnameLength]; ++surnameLength);
		
		if (ageLength == 0
			|| nameLength == 0
			|| surnameLength == 0)
		{
			throw "Wrong person data";
		}

		int descriptionLength = nameLength + surnameLength 
								+ ageLength + punctuationMarksCount 
								+ spacesCount + yearsOldLength
								+ sexLength;

		char* description = new char[descriptionLength + 1];

		int currentLength = nameLength;
		strcpy_s(description, currentLength + 1, name);
		description[currentLength] = ' ';

		strcpy_s(description + currentLength + 1, surnameLength + 1, surname);
		currentLength += surnameLength;
		description[++currentLength] = ',';
		description[++currentLength] = ' ';
		
		string ageStr = std::to_string(age);
		strcpy_s(description + currentLength + 1, ageLength + 1, ageStr.c_str());
		currentLength += ageLength;
		description[++currentLength] = ' ';

		string yearsOldStr = "years old";
		strcpy_s(description + currentLength + 1, yearsOldLength + 1, yearsOldStr.c_str());
		currentLength += yearsOldLength;
		description[++currentLength] = ',';
		description[++currentLength] = ' ';

		string sexStr = (sex == male) ? "male" : "female";
		strcpy_s(description + currentLength + 1, sexLength + 2, sexStr.c_str());
		currentLength += sexLength;
		description[++currentLength] = '.';
	}
};