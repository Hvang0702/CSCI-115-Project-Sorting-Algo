#include<iostream>
using namespace std;

//function for insertion sort
//takes an array and array size
void insertionSort(int array[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

//function to print an array
//takes an array and array size
void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
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

    //calls insertion sort
    insertionSort(array, n);

    //prints sorted array
    cout << "Sorted array: ";
    printArray(array, n);

    //prints run time
    time = clock() - time;
    cout << "Time:  " << (float)time / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}