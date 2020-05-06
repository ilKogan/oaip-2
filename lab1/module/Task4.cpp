#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

//4 ƒан строковый файл с именем NameS, 
//содержащий даты в формате "день/мес€ц/год", 
//причем под день и мес€ц отводитс€ по две позиции, 
//а под год Ц четыре.—оздать файлы целых чисел с именами Name1 и Name2,
//содержащие соответственно значени€[дней и мес€цев]; [дней и лет] ;
//[мес€цев и лет] дл€ дат из исходного строкового файла(в том же пор€дке).

using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

enum VIEWMODE {
	DMY,
	DM,
	DY,
	MY
};

enum GETMODE {
	DAY,
	MONTH,
	YEAR
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


int convertStrToint(string str,GETMODE mode) {
	string day = str.substr(0, 2);
	string month = str.substr(3, 2);
	string year = str.substr(6, 9);

	switch (mode) {
	case DAY: return stoi(day);
		break;
	case MONTH:return stoi(month);
		break;
	case YEAR:return stoi(year);
		break;
	default:
		break;
	}

	return 0;
}
string convertDateToStr(Date date, char separate, VIEWMODE mode) {
	string day = to_string(date.day);
	string month = to_string(date.month);
	string year = to_string(date.year);
	string strDate;

	if (day.size() == 1) {
		day = "0" + day;
	}

	if (month.size() == 1) {
		month = "0" + month;
	}

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
Date convertStrToDate(string date, char separate, VIEWMODE mode) {

	int day = 0;
	int month = 0;
	int year = 0;

	switch (mode) {
	case DMY:
		day = convertStrToint(date,DAY);
		month = convertStrToint(date, MONTH);
		year = convertStrToint(date,YEAR);
		break;
	case DM:
		day = convertStrToint(date, DAY);
		month = convertStrToint(date, MONTH);
		year = -1;
		break;
	case DY:
		day = convertStrToint(date, DAY);
		month = -1;
		year = convertStrToint(date, YEAR);

		break;
	case MY:
		day = -1;
		month = convertStrToint(date, MONTH);
		year = convertStrToint(date, YEAR);
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
void fillRandomDatesForFile(string fileName, int count, int yearBegin, int yearEnd, VIEWMODE mode) {
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

Date setNewFormatDate(Date date, VIEWMODE mode) {
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
Date getDatefromFile(string name, int pos, VIEWMODE mode) {
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

void getAllDatesfromFile(string name, Date* arr, int size, VIEWMODE mode) {
	for (int i = 0; i < size; i++) {
		arr[i] = getDatefromFile(name, i, mode);
	}
}
void setAllNewFormatDates(string name, Date* dates, int size, VIEWMODE mode) {
	string strDates = "";
	for (int i = 0; i < size; i++) {
		dates[i] = setNewFormatDate(dates[i], mode);
		strDates += convertDateToStr(dates[i], '/', mode);
		strDates += "\n";
	}
	createFile(name, strDates);
}



void Task4() {
	Date dates[5];


	fillRandomDatesForFile("Task4_Day-Month-Year.txt", 5, 1984, 2010, DMY);
	getAllDatesfromFile("Task4_Day-Month-Year.txt", dates, 5, DMY);
	setAllNewFormatDates("Task4_Day-Month.txt", dates, 5, DM);
}

