#include "Lab2.h"

int main() {

	while (true) {
		int choice = 0;
		std::cin >> choice;

		switch (choice) {
		case 0: std::cin >> choice;
			break;
		case 3: Task1();
			break;
		default: std::system("pause");
			break;
		}
	}
}
