#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#pragma warning(disable : 4996)

using namespace std;

#define NAME "Name"
#define EXTENSION ".txt"
#define SEPARATOR "/"

void createManyFile(char* Name, int numberFiles, char* extension, string (*func)(int, int)) {
	ofstream file;
	char source[20];
	for (int i = 0; i <= numberFiles; i++) {
		char num[5];
		itoa(i, num, 10);
		strcpy(source, Name);
		strcat(source, num);
		strcat(source, extension);
		file.open((char*)source, ios_base::out);
		file << func(i, numberFiles);
		file.close();
	}
}
//FIX THIS
char* randomDate(int yearBegin, int yearEnd) {
	char date[15];
	yearEnd -= yearBegin;

	srand(time(0));
	char year[5];
	char month[3];
	char day[3];
	itoa(rand() % yearEnd + yearBegin, year, 10);
	itoa(rand() % 12 + 1, month, 10);
	itoa(rand() % 30 + 1, day, 10);
	strcpy(date, day);
	strcat(date, SEPARATOR);
	strcat(date, month);
	strcat(date, SEPARATOR);
	strcat(date, year);
	strcat(date, "\n");

	return date;
}

string fillDataTime(int num, int max) {
	string ret = "";
	switch (num) {
	case 0:
		for (int i = 0; i < max; i++) {
			ret = randomDate(1984, 2030);
		}
		break;
	default:
		break;
	}
	return ret;
}

void Task4() {
	char name[10] = NAME;
	char extension[5] = EXTENSION;

	string (*ptrFunc)(int, int);
	ptrFunc = &fillDataTime;

	createManyFile(name, 3, extension, ptrFunc);
}



