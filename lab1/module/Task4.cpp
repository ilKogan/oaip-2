#include <iostream>
#include <fstream>
#include <string>
#include <time.h>


using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

enum MODE {
	DMY,
	DM,
	DY,
	MY
};

void createFile(string name, string content) {
	ofstream oFile(name);
	oFile << content;
	oFile.close();
}
Date createDate(int day, int month, int year) {
	Date newDate;

	newDate.day = day;
	newDate.month = month;
	newDate.year = year;
	return newDate;
}

//TODO: FIX convertStrToInt 
int convertStrToint(int beginPos, string str, int dimen = 10) {
	int ret = 0;
	int dim = dimen;
	for (int i = beginPos; ; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			ret += ret * 10 + (str[i] - '0') * dim;
		}
		dim /= 10;

		if (dim == 1) {
			ret += ret * 10 + (str[i] - '0') * dim;
			break;
		}
	}
	return ret;
}
string convertDateToStr(Date date, char separate, MODE mode) {
	string day = to_string(date.day);
	string month = to_string(date.month);
	string year = to_string(date.year);
	string strDate;

	switch (mode) {
	case DMY:
		strDate += day;
		strDate += separate;
		strDate += month;
		strDate += separate;
		strDate += year;
		break;
	case DM:
		strDate += day;
		strDate += separate;
		strDate += month;
		break;
	case DY:
		strDate += day;
		strDate += separate;
		strDate += year;
		break;
	case MY:
		strDate += month;
		strDate += separate;
		strDate += year;
		break;
	default:
		break;
	}
	return strDate;
}
Date convertStrToDate(string date, char separate, MODE mode) {

	int day = 0;
	int month = 0;
	int year = 0;

	switch (mode) {
	case DMY:
		day = convertStrToint(0, date, 10);
		month = convertStrToint(3, date, 10);
		year = convertStrToint(6, date, 1000);
		break;
	case DM:
		day = convertStrToint(0, date, 10);
		month = convertStrToint(3, date, 10);
		year = -1;
		break;
	case DY:
		day = convertStrToint(0, date, 10);
		month = -1;
		year = convertStrToint(3, date, 1000);

		break;
	case MY:
		day = -1;
		month = convertStrToint(0, date, 10);
		year = convertStrToint(3, date, 1000);
		break;
	default:
		break;
	}
	return createDate(day, month, year);
}


Date randomDate(int yearBegin, int yearEnd) {
	Date date;
	yearEnd -= yearBegin;
	date.year = rand() % yearEnd + yearBegin;
	date.month = rand() % 12 + 1;
	date.day = rand() % 30 + 1;

	return date;
}
void fillRandomDatesForFile(string fileName, int count, int yearBegin, int yearEnd, MODE mode) {
	string text = "";

	for (int i = 0; i < count; i++) {
		srand(i);
		Date tmpDate = createDate(0, 0, 0);
		tmpDate = randomDate(yearBegin, yearEnd);
		text += convertDateToStr(tmpDate, '/', mode);
		text += "\n";
	}

	createFile(fileName, text);
}

Date setNewFormatDate(Date date, MODE mode) {
	Date ret = date;
	switch (mode) {
	case DM:
		ret.year = -1;
		break;
	case DY:
		ret.month = -1;
		break;
	case MY:
		ret.day = -1;
		break;
	default:
		break;
	}
	return ret;
}
Date getDatefromFile(string name, int pos, MODE mode) {
	string line;
	int position = 0;

	ifstream iFile(name);

	while (getline(iFile, line)) {
		if (position == pos) {
			return convertStrToDate(line, '/', mode);
		}
		position++;
	}

	iFile.close();
}

void getAllDatesfromFile(string name, Date* arr, int size, MODE mode) {
	for (int i = 0; i < size; i++) {
		arr[i] = getDatefromFile(name, i, mode);
	}
}
void setAllNewFormatDates(string name, Date* dates, int size, MODE mode) {
	string strDates = "";
	for (int i = 0; i < size; i++) {
		dates[i] = setNewFormatDate(dates[i], mode);
		strDates = convertDateToStr(dates[i], '/', mode);
		strDates += "\n";
	}
	createFile(name, strDates);
}



void Task4() {
	Date dates[10];
	const string FILE_NAME = "Name.txt";

	fillRandomDatesForFile(FILE_NAME, 10, 1984, 2010, DMY);
	getAllDatesfromFile(FILE_NAME, dates, 10, DMY);
	setAllNewFormatDates(FILE_NAME, dates, 10, DM);

}



