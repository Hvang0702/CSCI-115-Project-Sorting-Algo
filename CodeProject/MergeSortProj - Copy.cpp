#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int sum = 0;

//merge sort with vector for output of the sorted array
void merge2Vector(vector<int>& arr, int l, int m, int r) {

	vector<int> tp;//temp
	int i;
	int j;
	i = l;
	j = m + 1;

	while (i <= m && j <= r) {
		if (arr[i] <= arr[j]) {
			tp.push_back(arr[i]);
			++i;
		}
		else {
			tp.push_back(arr[j]);
			++j;
		}
	}

	while (i <= m) {
		tp.push_back(arr[i]);
		++i;
	}
	while (j <= r) {
		tp.push_back(arr[j]);
		++j;
	}
	for (int i = l; i <= r; ++i) {
		arr[i] = tp[i - l];
	}

}

void MergeSortVec(vector<int>& arr, int l, int r) { //Merge sort vector 

	if (l < r) {
		int m = (l + r) / 2;
		MergeSortVec(arr, l, m);
		MergeSortVec(arr, m + 1, r);
		merge2Vector(arr, l, m, r);
	}
}

//Used for the cases
void mergeBegin(int array[], int const l, int const m, int const r) {
	auto const yes = m - l + 1;
	auto const no = r - m;

	auto* Larr = new int[yes];
	auto* Rarr = new int[no];

	int i;
	for (i = 0; i < yes; i++) {
		Larr[i] = array[l + i];
	}

	int j;
	for (j = 0; j < no; j++) {
		Rarr[j] = array[m + 1 + j];
	}

	auto indxyes = 0;
	auto indxno = 0;
	int indxmerge = l;

	while (indxyes < yes && indxno < no) {
		if (Larr[indxyes] <= Rarr[indxno]) {
			array[indxmerge] = Larr[indxyes];
			indxyes++;
			sum++;
		}
		else {
			array[indxmerge] = Rarr[indxno];
			indxno++;
			sum++;
		}
		indxmerge++;
	}

	while (indxyes < yes) {
		array[indxmerge] = Larr[indxyes];
		indxyes++;
		indxmerge++;
		sum++;
	}

	while (indxno < no) {
		array[indxmerge] = Rarr[indxno];
		indxno++;
		indxmerge++;
		sum++;
	}

}

//Merge Sort
void mergeSort(int array[], int s, int f)
{
	if (s >= f)
		return; // Returns recursively

	auto mid = s + (f - s) / 2; //Finding the middle point to divide into two halfs

	mergeSort(array, s, mid); //Calling mergesort for first half

	mergeSort(array, mid + 1, f); //Calling mergeSort for second half

	mergeBegin(array, s, mid, f); //Merging the two halves sorted in step 2 and 3
}

void printArrVec(vector<int>& arr, int s) { //used for displaying the list in order
	int i;

	for (i = 0; i < s; i++) {
		cout << arr[i] << " ";
	}

} //Used for vector

void printArr(int Merarray[], int s) { 
	int i;

	for (i = 0; i < s; i++) {
		cout << Merarray[i] << " ";
	}
} 

int main() {

	clock_t timeStartAgain, timeEndAgain;

	int num;
	vector<int>arr;
	cout << "Enter num of integers for Merge Array from 1 - 100000: ";
	cin >> num;
	arr = vector<int>(num);

	timeStartAgain = clock(); //Start 
	for (int i = 0; i < num; i++) {
		int ran = (rand() % 100000); //range of 0 to 100000
		arr[i] = ran;
	}

	cout << "Initial array is: " << endl;
	printArrVec(arr, num);
	cout << endl;

	MergeSortVec(arr, 0, num - 1);
	cout << endl;

	cout << "Sorted Merge array is: " << endl;
	printArrVec(arr, num);

	timeEndAgain = clock(); //Finish clock

	double time_spent4M = ((double)timeEndAgain - (double)timeStartAgain) / CLOCKS_PER_SEC;
	cout << endl;
	cout << setprecision(4) << fixed << "Time taken: " << endl << time_spent4M << " seconds";
	cout << endl << endl;

	/*
	int array[200]; //List is sorted
	cout << "Random 200 integers" << endl;
	for(i = 0; i < 200; i++){
		array[i] = rand()%1000;
		cout << array[i] << " ";
	}
	cout << endl;

	mergeSort(array, 0, 200 - 1);

	cout << endl;


	cout << "Sorted Merge Array: " << endl;
	for(i = 0; i < 200; i++){
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "Reversed sorted array:" << endl;
	for(i = 199; i>= 0; i--){
		cout << array[i] << " ";
	}
	cout << endl;
	*/
	clock_t time;
	int i;
	int n;
	vector<int>arrA;
	cout << "Enter the number of data elements to be sorted: ";		//user input
	cin >> n;
	arrA = vector<int>(n);

	time = clock();

	for (i = 0; i < n; i++) {
		cout << "Enter elements " << i + 1 << ": ";
		cin >> arrA[i];
	}
	MergeSortVec(arrA, 0, n - 1);

	//Print sorted data

	cout << "Sorted Array: " << endl;
	for (i = 0; i < n; i++) {
		cout << arrA[i] << " ";
	}
	time = clock() - time;
	cout << "Time taken: " << (float)time / CLOCKS_PER_SEC << " seconds" << endl;
	cout << endl;

	clock_t timeBC; 

	timeBC = clock();
																			//Merge Sort Cases
	int Merarray[] = { 10, 20, 30, 40, 50 };								//List is sorted (Best Case)
	int arrM = sizeof(Merarray) / sizeof(Merarray[0]);

	cout << "Merge Sort is: " << endl;
	printArr(Merarray, arrM);

	mergeSort(Merarray, 0, arrM - 1);
	cout << endl;

	cout << "Completed Merge Sort (List is sorted): " << endl;
	printArr(Merarray, arrM);

	timeBC = clock() - timeBC;
	cout << "Time taken: " << (float)timeBC / CLOCKS_PER_SEC << " seconds" << endl;
	cout << endl;
	
	clock_t timeAC;
	timeAC = clock();
	int Merarray2[] = { 10, 20, 30, 60, 50, 40 };							//List is half sorted (average case)
	int arr2 = sizeof(Merarray2) / sizeof(Merarray2[0]);

	cout << "Merge Sort is: " << endl;
	printArr(Merarray2, arr2);

	mergeSort(Merarray2, 0, arr2 - 1);
	cout << endl;

	cout << "Completed Merge Sort (Half sorted): " << endl;
	printArr(Merarray2, arr2);

	timeAC = clock() - timeAC;
	cout << "Time taken: " << (float)timeAC / CLOCKS_PER_SEC << " seconds" << endl;
	cout << endl;

	clock_t timeWC;
	timeWC = clock();
	int Merarray3[] = { 1, 3, 5, 7, 2, 4, 6, 8 };							//List is reversed (worst case) resulting in maximum comparisons
	int arr3 = sizeof(Merarray3) / sizeof(Merarray3[0]);

	cout << "Merge Sort is: " << endl;
	printArr(Merarray3, arr3);

	mergeSort(Merarray3, 0, arr3 - 1);
	cout << endl;

	cout << "Completed Merge Sort (List is Reversed): " << endl;
	printArr(Merarray3, arr3);

	timeWC = clock() - timeWC;
	cout << "Time taken: " << (float)timeWC / CLOCKS_PER_SEC << " seconds" << endl;
	cout << endl;
	
	return 0;
}
