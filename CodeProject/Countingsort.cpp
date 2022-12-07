// Lab 5 Counting (115)
// Maiger Xiong
// 10/11/22

#include <iostream>
using namespace std;

void countS(int array[], int s, int limit) {
	int outcome[s];
	int auxArr[limit];

	for (int i = 0; i < limit; i++) {
		auxArr[i] = 0;
	}

	for (int i = 0; i < s; i++) {
		++auxArr[array[i]];
	}

	for (int i = 1; i < limit; i++) {
		auxArr[i] = auxArr[i] + auxArr[i - 1];
	}

	for (int i = 0; i < s; i++) {
		outcome[--auxArr[array[i]]] = array[i];
	}

	for (int i = 0; i < s; i++) {
		array[i] = outcome[i];
	}
}

int main()
{
	clock_t begin, end;
	int sizeOfArr;
	cout << "Input size of array: ";
	cin >> sizeOfArr;
	int lim = sizeOfArr;
	cout << endl;
	int myArr[sizeOfArr];
	cout << "Input values: ";
	cout << endl;
	for (int i = 0; i < sizeOfArr; i++) {
		myArr[i] = rand() % sizeOfArr;
		cout << myArr[i] << " ";
	}

	cout << endl;
	begin = clock();
	countS(myArr, sizeOfArr, lim);

	cout << "Sorted Array: " << endl;
	for (int i = 0; i < sizeOfArr; i++) {
		cout << myArr[i] << " ";
	}
	end = clock();

	cout << endl;
	double execution_time = double(end - begin) / double(CLOCKS_PER_SEC);
	cout << "Execution time: " << execution_time << " seconds";

	return 0;
}