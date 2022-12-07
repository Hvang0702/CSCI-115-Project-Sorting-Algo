#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void exchange(vector<int>& A, int i, int j) {
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void max_heapify(vector<int>& A, int i, int n) {		// maintain max-heap property of parent > children
	int l, r, largest;
	l = 2 * i + 1;									    // index of left child = 2i
	r = 2 * i + 2;								        // index of right child = 2i + 1

	if (l < n && A[l] > A[i]) {					        // if left child > root
		largest = l;							        // left child is new largest
	} else {
		largest = i;							        // else largest is root
	}

    if (r < n && A[r] > A[largest]) {			        // if right child > root
		largest = r;							        // right child is new largest
	}

	if(largest != i) {							        // if largest is not root
		exchange(A, i, largest);				        // root "floats down" the subtree
		max_heapify(A, largest, n);				        // recursively restore max-heap property on subtrees
	}
}

void build_max_heap(vector<int>& A, int n) { 		    // create max-heap from unordered input array
	for (int i = n / 2 - 1; i >= 0; i--) {		        // calls max-heapify on all internal nodes A[0..n/2-1]
        max_heapify(A, i, n);
    }
}

void heapsort(vector<int>& A, int n) {
	build_max_heap(A, n);

	for(int i = n - 1; i > 0; i--) {			        // until 1 node is left
        exchange(A, 0, i);						        // swap root with last node
        max_heapify(A, 0, i);					        // restore max-heap property on smaller heap
    }
}

void print(vector<int> A, int n) {
    for (int i = 0; i < n; i++) {
    	cout << A[i] << " ";
	}
    cout << endl;
}

int main() {
    int n;
    clock_t t;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n);


    for(int i = 0; i < n; i++) {
    	A[i] = i;
	}

    for(int i = 0; i < n; i++) {
    	B[i] = rand() % 100;
	}


	for(int i = n-1, j = 0; i >= 0; i--, j++) {
    	C[i] = j;
	}

    //print(A, n);
    t = clock();
    heapsort(A, n);
    t = clock() - t;
    cout << "(Ascending) Worst Case Time: " << (double)t/CLOCKS_PER_SEC << " seconds" << endl;
    //print(A, n);


    //print(B, n);
    t = clock();
    heapsort(B, n);
    t = clock() - t;
    cout << "(Random) Average Case Time: " << (double)t/CLOCKS_PER_SEC << " seconds" << endl;
    //print(B, n);


    //print(C, n);
    t = clock();
    heapsort(C, n);
    t = clock() - t;
    cout << "(Descending) Best Case Time: " << (double)t/CLOCKS_PER_SEC << " seconds" << endl;
    //print(C, n);


	return 0;
}

