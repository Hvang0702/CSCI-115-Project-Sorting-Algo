#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

bool BruteFrc(vector<int> g, int sum) {
	int i, j;
	bool find = false;
	for ( i = 0; i < g.size() - 1; i++) {

		for ( j = i + 1; j < g.size(); j++) {

			if (g[i] + g[j] == sum) {

				find = true;
			}
		}
	}
	return find;
}

bool EffAlgo(vector<int> g, int sum) {
	int magi = 0;
	int mini = g[0];
	int middle = 0;
	int elementHolder = 0;
	int i;
	vector<int> miniList, middleList;
	bool checkss = false;
	for (int i = 0; i < g.size(); i++) {
		if (g[i] == 0) {
			checkss = true;
		}
	}
	for ( i = 0; i < g.size(); i++) {
		if (g[i] == sum / 2) {
			middle++;
			if (middle == 1) {
				elementHolder = i;
			}
			if (middle >= 2) {
				return true;
			}
		}
		if (g[i] <= sum / 2) {
			miniList.push_back(g[i]);
		}
		if (g[i] > sum / 2 && g[i] < sum) {
			middleList.push_back(g[i]);
		}
		if (g[i] == sum && checkss) {
			return true;
		}
		if (magi < g[i]) {
			magi = g[i];
		}
		if (mini > g[i]) {
			mini = g[i];
		}
	}
	if ((magi * 2 + 1) < sum) {
		return false;
	}
	if (mini > sum) {
		return false;
	}
	if (miniList[0] > miniList[miniList.size() - 1])
		for (int i = 0; i < miniList.size(); i++) {
			for (int j = 0; j < middleList.size(); j++) {
				if (miniList[i] + middleList[j] == sum) {
					return true;
				}
			}
		}
	else {
		for (int i = miniList.size() - 1; i >= 0; i--) {
			for (int j = 0; j < middleList.size(); j++) {
				if (miniList[i] + middleList[j] == sum) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {

	int i;
	clock_t Begin;
	clock_t end;
	double func;
	
	
	srand(time(0));
	
	vector<int> g; 		// 3 vectors for testing?
	vector<int> r;
	vector<int> z;
	int num, maxiNum, sum;		// Input number for tests 1 - 3
	

	// Test One for sorting or sorted? 
	cout << "Testing part 1 Sorted: " << endl;
	cout << "Enter number of elements in test 1: ";
	cin >> num;
	for ( i = 0; i <= num; i++) {
		g.push_back(i);
	}
	cout << "Enter Sum we are trying to find:    ";
	cin >> sum;
	cout << endl;
	cout << "Brute Force: ";

	Begin = clock();
	BruteFrc(g, sum);
	end = clock();

	func = double(end - Begin) / double(CLOCKS_PER_SEC);
	cout << BruteFrc(g, sum) << endl;
	cout << "First Test run time Brute Force: " << func << setprecision(8);
	cout << endl << endl;

	// Testing new or mroe efficient algo
	cout << "More Efficient Algo: ";
	Begin = clock();
	EffAlgo(g, sum);
	end = clock();

	func = double(end - Begin) / double(CLOCKS_PER_SEC);
	cout << EffAlgo(g, sum) << endl;
	cout << "Run time for Test 1 (More Efficient Algo): " << func << setprecision(8);
	cout << endl << endl;

	// Test Two Reverse Sorted 
	cout << "Testing part 2 for reverse: " << endl;
	cout << "Enter number of elements in test 2: ";
	cin >> num;
	for ( i = 0; i <= num; i++) {
		r.push_back(num - i);
	}
	cout << "Input Sum we are trying to find:    ";
	cin >> sum;
	cout << endl;
	cout << "Brute Force: ";

	Begin = clock();
	BruteFrc(r, sum);
	end = clock();

	func = double(end - Begin) / double(CLOCKS_PER_SEC);
	cout << BruteFrc(r, sum) << endl;
	cout << "Second Test run time Brute Force: " << func << setprecision(8);
	cout << endl << endl;


	cout << "More Efficient Algorithm: ";
	Begin = clock();
	EffAlgo(r, sum);
	end = clock();

	func = double(end - Begin) / double(CLOCKS_PER_SEC);
	cout << EffAlgo(r, sum) << endl;
	cout << "Run time for Test 2 (More Efficient Algo): " << func << setprecision(8);
	cout << endl << endl;


	// Test Tree Unsorted Random 
	cout << "Testing part 3 for unsorted: " << endl;
	cout << "Enter number of elements in test 3: ";
	cin >> num;

	cout << "Input number for random inputs: ";
	cin >> maxiNum;

	for ( i = 0; i <= num; i++) {
		z.push_back(rand() % (maxiNum + 1));
	}

	cout << "Input Sum we are trying to find:    ";
	cin >> sum;
	cout << endl;
	cout << "Brute Force Method: ";

	Begin = clock();
	BruteFrc(z, sum);
	end = clock();

	func = double(end - Begin) / double(CLOCKS_PER_SEC);
	cout << BruteFrc(z, sum) << endl;
	cout << "Third Test run time Brute Force: " << func << setprecision(8);
	cout << endl << endl;

	//Testing the more efficient algo
	cout << "More Efficient Algo: ";
	Begin = clock();
	EffAlgo(z, sum);
	end = clock();

	func = double(end - Begin) / double(CLOCKS_PER_SEC);
	cout << EffAlgo(z, sum) << endl;
	cout << "Run time for Test 3 (More Efficient Algo): " << func << setprecision(8);

	return 0;
}