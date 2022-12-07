#include <iostream>
#include <chrono>
#include <array>
using namespace std;
using namespace std::chrono;



void display(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void counting_sort(int arr[], int n)
{
//Find max
    int max = arr[0];
    for (int i = 1; i < n; i++) {
    if (arr[i] > max)
      max = arr[i];
    }
    //Initialise count array and output array
    int C[max+1];
    int output[n];


    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) {
        C[i] = 0;
      }
      //Count of each element
    for (int i = 0; i < n; i++) {
        C[arr[i]]++;
    }

    //Cumulative sum
    for (int i = 1; i <= max; i++) {
     C[i] += C[i - 1];
    }


    // Find the index of each element of the original array in count array,
  // and place the elements in output array
  for (int i = n - 1; i >= 0; i--) {
    output[C[arr[i]] - 1] = arr[i];
    C[arr[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}
void cSort_radixSort(int arr[], int n, int place){
  const int max = 10;
  int output[n];
  int C[max];

  for (int i = 0; i < max; ++i)
    C[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < n; i++)
    C[(arr[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    C[i] += C[i - 1];

  // Place the elements in sorted order
  for (int i = n - 1; i >= 0; i--) {
    output[C[(arr[i] / place) % 10] - 1] = arr[i];
    C[(arr[i] / place) % 10]--;
  }

  for (int i = 0; i < n; i++)
    arr[i] = output[i];
  display(arr,n);
}
void radixSort(int arr[],int n)
{
    //Find max
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
          max = arr[i];
    }
    for (int i=1;max/i>0;i*=10){
        cSort_radixSort(arr,n,i);
        cout<<"Loop:"<<i<<endl;
    }
}
int main()
{
    int arr[100]; //Number inside brackets corresponds to number i is less than
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
    int t = rand() % 49;
    arr[i] = t;
    cout << arr[i] << endl;
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr,n);
    display(arr,n);

//

    counting_sort(arr, n);

    auto start = high_resolution_clock::now();

    radixSort(arr, n);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    //cout << "For an array of 1000 items:" << endl;
    //(change to cout << "For an array of " << x << " items:" << endl;)
    cout << "Time for counting: " << duration.count() << " microseconds" << endl;

//
    return 0;
}