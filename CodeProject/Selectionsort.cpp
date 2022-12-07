// Lab 3 Selection (115)
// Maiger Xiong
// 9/20/22

#include <iostream>
using namespace std;

void selectSort(int arr[]) {
	for (int i = 0; i < 199; i++) {
		int min = i;
		for (int j = i + 1; j < 200; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

void halfSort(int arr[]) {
	for (int i = 0; i < 99; i++) {
		int min = i;
		for (int j = i + 1; j < 100; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

int main()
{
	clock_t begin, end;
	int array1[200];
	cout << "Enter 200 integers: " << endl;
	for (int i = 0; i < 200; i++) {
		array1[i] = rand() % 1001;
		cout << array1[i] << " ";
	}
	cout << endl;

	begin = clock();

	selectSort(array1);
	halfSort(array1);

	cout << endl;
	
	cout << "Sorted array: " << endl;
	for (int i = 0; i < 200; i++) {
		cout << array1[i] << " ";
	}
	cout << endl;
	cout << endl;
	
	cout << "Half sorted array: " << endl;
	for (int i = 0; i < 200; i++) {
		cout << array1[i] << " ";
	}
	
	cout << endl;
	cout << endl;
	
	cout << "Reversed array: " << endl;
	for (int i = 199; i >= 0; i--) {
		cout << array1[i] << " ";
	}

	cout << endl;
	end = clock();
	cout << endl;
	double execution_time = double(end - begin) / double(CLOCKS_PER_SEC);
	cout << "Execution time: " << execution_time << " seconds";

	//each part should work, some parts need to be commented out so it does not interfere with certain functions

	return 0;
}