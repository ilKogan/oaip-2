#include "Lab1.h"


int main() {

	while (true) {
		int choice = 0;
		std::cin >> choice;

		switch (choice) {
		case 0: std::cin >> choice;
			break;
		case 4: Task4();
			break;
		case 10: Task10();
			break;
		case 12: Task12();
			break;
		default: std::system("pause");
			break;
		}
	}
}
