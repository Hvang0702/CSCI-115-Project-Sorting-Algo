#include<iostream>
using namespace std;

//function for bubble sort
//takes an array and array size
void bubbleSort(int array[], int n)
{
    int j;
    for (int i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}

//function to print an array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    clock_t time;

    //array input:
    int array[] = { 0 };

    //to calculate run time
    time = clock();

    //finds array size
    int n = sizeof(array) / sizeof(array[0]);

    //calls bubble sort function
    bubbleSort(array, n);

    //prints sorted array
    cout << "Sorted array:  ";
    printArray(array, n);

    //prints run time
    time = clock() - time;
    cout << "Time:  " << (float)time / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}