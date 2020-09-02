#include "Lab3.h"

int main() {

	while (true) {
		int choice = 0;
		std::cin >> choice;

		switch (choice) {
		case 0: std::cin >> choice;
			break;
		case 3: Task3();
			break;
		case 4: Task4();
			break;
		default: std::system("pause");
			break;
		}
	}
}
