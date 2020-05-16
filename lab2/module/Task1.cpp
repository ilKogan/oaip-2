#include <iostream>
#include <time.h> 

using namespace std;

struct Time {
	clock_t start;
	clock_t end;
	clock_t duration;
};

enum MODE {
	BUBBLE,
	QUICK
};

void printTime(string name, Time time) {
	cout << endl;
	cout << name << endl;
	cout << "Start time:  " << time.start << endl;
	cout << "End time:  " << time.end << endl;
	cout << "Duration:  " << time.duration << " tick | "<<(float)time.duration/CLOCKS_PER_SEC<<" seconds"<< endl;
	cout << endl;
}

void sortBubble(int* arr, int size) {
	int tmp;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
}

void sortQuick(int* arr,int left,int right) {
	int l_hold = left;
	int r_hold = right;

	int point = arr[left];

	while (left < right) {
		while ((arr[right] >= point) && (left < right)) {
			right--;
		}

		if (left != right) {
			arr[left] = arr[right];
			left++;
		}

		while ((arr[left] <= point) && (left < right)) {
			left++;
		}

		if (left != right) {
			arr[right] = arr[left];
			right--;
		}

	}

	arr[left] = point;
	point = left;
	left = l_hold;
	right = r_hold;

	if (left < point) {
		sortQuick(arr, left, point - 1);
	}

	if (right > point) {
		sortQuick(arr, point + 1, right);
	}

	
}

void fillArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		srand(i);
		arr[i] = rand() % 10;
	}
}

Time choiceCheckSort(int* arr,int size, MODE mode) {
	Time timeSort;

	switch (mode) {
	case BUBBLE:	
			timeSort.start = clock();

			sortBubble(arr, size);

			timeSort.end = clock();
			timeSort.duration = timeSort.end - timeSort.start;
			printTime("BUBBLE", timeSort);
			return timeSort;
		
		break;
	case QUICK:	
			timeSort.start = clock();

			sortQuick(arr,0,size - 1);

			timeSort.end = clock();
			timeSort.duration = timeSort.end - timeSort.start;
			printTime("QUICK", timeSort);
			return timeSort;
		break;
	default: cout<<"Not supported!";
		break;
	}

}



void Task1() {


	int numbers[5000];

	fillArr(numbers, 5000);

	choiceCheckSort(numbers, 5000, BUBBLE);

	fillArr(numbers, 5000);

	choiceCheckSort(numbers, 5000, QUICK);
}



