#include <iostream>
#include <fstream>
#include <string>
#include <time.h>


using namespace std;

#define SEPARATE '/'
#define NUL "0"
#define NEXTLINE '\n'
#define DELETE_MARK -2
#define SEPARATE_MARK -1

enum MODE {
	DAY,
	MONTH,
	YEAR
};

void createFile(string name, string content) {
	ofstream oFile(name);
	oFile << content;
	oFile.close();
}
string readFile(string name) {
	string temp;
	string line;
	ifstream iFile(name);
	while (getline(iFile, line)) {
		temp += line += "\n";
	}
	iFile.close();
	return temp;
}
void writeFile(string name, string content) {
	ofstream oFile;
	oFile.open(name, ios_base::app | ios_base::ate);
	oFile << content;
	oFile.close();
}

int countLineFile(string name) {
	string tmp = readFile(name);
	int ret = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == NEXTLINE) {
			ret++;
		}
	}
	return ret;
}

void get2DArrfromString(int** output, string source, int size1, int size2) {

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (source[j] != SEPARATE) {
				//Fast convert char to int
				output[i][j] = (source[j] - 48);
			} else {
				output[i][j] = SEPARATE_MARK;
			}
		}
	}
}
void delete2DArr(int** arr, int size2) {
	for (int i = 0; i < size2; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

int** create2DArr(int size, int size2) {
	int** ptrArr = new int* [size];
	for (int i = 0; i < size; i++) {
		ptrArr[i] = new int[size2];
	}
	return ptrArr;
}

void clearCertainElementDate(int** numDate,int size,int size2, MODE mode) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size2; j++) {
			switch (mode) {
			case DAY: 
				if (j == 0 || j == 1) {
					numDate[i][j] = DELETE_MARK;
				}
				break;
			case MONTH:
				if (j == 3 || j == 4) {
					numDate[i][j] = DELETE_MARK;
				}
				break;
			case YEAR:
				if (j > 5 && j < 10) {
					numDate[i][j] = DELETE_MARK;
				}
				break;
			default:
				break;
			}
		}
	}
}

void getStringfrom2DArr(string* strDate, int** numDate,int size, int size2) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size2 - 1; j++) {
			if (numDate[i][j] == DELETE_MARK) {
				continue;
			} else if(numDate[i][j] == SEPARATE_MARK) {
				strDate[j] = SEPARATE;
			} else {
//TODO: FIX ERROR.
				strDate[j] = numDate[i][j];
			}
		}
	}
}

void deleteDateElement(string name, MODE mode) {
	string tmpStrDate = readFile(name);
	int countLines = countLineFile(name);
	const int countCharLine = 10;
	int** ptrNumDate = create2DArr(countLines, countCharLine);
	string* ptrStrDate = &tmpStrDate;

	get2DArrfromString(ptrNumDate, tmpStrDate, countLines, countCharLine);
	clearCertainElementDate(ptrNumDate, countLines, countCharLine,mode);
	getStringfrom2DArr(ptrStrDate, ptrNumDate, countLines, countCharLine);
	createFile(name, tmpStrDate);
	delete2DArr(ptrNumDate, countCharLine);
	delete[] ptrStrDate;
}


void fillRandomDate(string name, int count, int yearBegin, int yearEnd) {
	string date;
	string year;
	string month;
	string day;

	yearEnd -= yearBegin;
	for (int i = 0; i < count; i++) {
		srand(time(0) + i);
		day = to_string(rand() % 30 + 1);
		month = to_string(rand() % 12 + 1);
		year = to_string(rand() % yearEnd + yearBegin);

		if (day.size() == 1) {
			day = (NUL + day);
		}
		if (month.size() == 1) {
			month = (NUL + month);
		}


		date += day += SEPARATE;
		date += month += SEPARATE;
		date += year += NEXTLINE;

		writeFile(name, date);
		date.clear();
	}
}


void Task4() {

	createFile("Name.txt", "");
	fillRandomDate("Name.txt", 10, 1945, 2001);
	deleteDateElement("Name.txt",DAY);

	//void(*ptrFunc)(MODE,int,ofstream, ifstream);
	//ptrFunc = &fileDateManipulation;
	//createAndFillFiles(name, 3, extension, ptrFunc);
}




//
//void createAndFillFiles(char* Name, int numberFiles, char* extension, void(*func)(MODE, int,ofstream,ifstream)) {
//	ofstream outputFile;
//	ifstream inputFile;
//	char source[20];
//	for (int i = 0; i <= numberFiles; i++) {
//		char num[5];
//		itoa(i, num, 10);
//		strcpy(source, Name);
//		strcat(source, num);
//		strcat(source, extension);
//		outputFile.open((char*)source, ios_base::out);
//		func(static_cast<MODE>(i), numberFiles, outputFile, inputFile);
//		outputFile.close();
//		inputFile.close();
//	}
//}
////FIX THIS
//string randomDate(int yearBegin, int yearEnd,string separator) {
//	string date;
//	yearEnd -= yearBegin;
//
//	srand(time(0));
//	string year;
//	string month;
//	string day;
//	year = to_string(rand() % yearEnd + yearBegin);
//	month = to_string(rand() % 12 + 1);
//	day = to_string(rand() % 30 + 1);
//	date.append(day);
//	date.append(separator);
//	date.append(month);
//	date.append(separator);
//	date.append(year);
//	date.append("\n");
//
//	return date;
//}
//
//void fileDateManipulation(MODE mode, int max, ofstream fileOut,ifstream fileInput) {
//	string temp = "";
//	switch (mode) {
//	case RANDOM_DATE:
//		for (int i = 0; i < max; i++) {
//			temp += randomDate(1984, 2030,SEPARATOR);
//		}
//		fileOut << temp;
//		temp.clear();
//		break;
//	case DAY_MONTH:
//		break;
//	case DAY_YEAR:
//		break;
//	case MONTH_YEAR:
//		break;
//	default:
//		break;
//	}
//}