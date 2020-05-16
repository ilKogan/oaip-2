#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//12 
//ќпределить функцию, котора€, игнориру€ исходное деление файла на строки,
//переформатирует его, разбива€ на строки так, чтобы кажда€ строка оканчивалась
//Ђ; ї, или содержала 60 символов, если среди них нет Ђ; ї.

void formatText(string fileName) {
	ifstream in(fileName);

	string tmpLine;
	string tmpText;
	string result;
	int indexLastEndl = 0;

	while(getline(in, tmpLine)){
		tmpText += tmpLine;
		tmpText += ' ';
	}
	in.close();

	ofstream out(fileName);

	for (int i = 0; i < tmpText.size(); i++) {
		if (tmpText[i] == ';') {
			indexLastEndl = i;
			result += tmpText[i];
			result += "\n";
		} else if (i == (indexLastEndl + 60)) {
			indexLastEndl = i;
			result += tmpText[i];
			result += "\n";
		} else {
			result += tmpText[i];
		}
	}
	out << result;
}

void Task12() {
	formatText("TextFormat.txt");
}

