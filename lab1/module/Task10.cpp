#include <iostream>
#include <fstream>
#include <string>


//10 
//Скопировать из файла F1 в 
//файл F2 все строки, которые не содержат цифры.
//Подсчитать количество строк, которые начинаются 
//на букву «А» в файле F2.

using namespace std;


void createFiles(string name, string content) {
	ofstream oFile(name);
	oFile << content;
	oFile.close();
}

bool checkLineToNumber(string line) {
	for (int i = 0; i < line.size(); i++) {
		if (line[i] < 57 && line[i] > 49) {
			return false;
		}
	}
	return true;
}

void copyLineFileToFileCondition(string file1, string file2, bool(*func)(string)) {
	ifstream in(file1);
	ofstream out(file2);

	string tmp;
	string line;

	while (getline(in, line)) {
		if (func(line)) {
			tmp += line;
			tmp += "\n";
		}
	}

	out << tmp;

	in.close();
	out.close();
}

int numbersLineBeginToChar(string fileName, char ch) {
	ifstream in(fileName);
	string line;
	int countLine = 0;

	while (getline(in, line)) {
		if (line[0] == toupper(ch) || line[0] == tolower(ch)) {
			countLine++;
		}
	}
	return countLine;
}


void Task10() {
	bool (*condition)(string);
	condition = checkLineToNumber;

	string str = "Somethink a23\n"
		"Where; is my mind\n"
		"Sector 4235-A;-235\n"
		"Dead; end\n"
		"alice what do you think?\n"
		"apple\n"
		"8-Universe ";

	int countLineWithA;

	createFiles("File1.txt", str);
	createFiles("File2.txt", "");
	copyLineFileToFileCondition("File1.txt", "File2.txt", condition);
	countLineWithA = numbersLineBeginToChar("File2.txt", 'A');

	cout << countLineWithA;

}



