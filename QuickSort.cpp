#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pI = partition(arr, low, high);
        qs(arr, low, pI - 1);
        qs(arr, pI + 1, high);
    }
}

vector<int> QuickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    vector<int> arr = {4, 3, 2, 5, 7, 9, 1, 6};
    arr = QuickSort(arr); // capture the sorted array

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}


// THEORY
// QuickSort is a divide-and-conquer algorithm that sorts an array by selecting a 'pivot' element and partitioning the other elements into two sub-arrays,
//STEPS:
/*
1.Choose a pivot element from the array, can be any element, commonly the first or last element
2. here it is the first element 
3.place it at its correct position in the sorted array with the help of partition function.
Partition the array into two halves:
   - Elements less than or equal to the pivot go to the left
   - Elements greater than the pivot go to the right
5. Recursively apply the same steps to the left and right sub-arrays until the base case is reached (sub-array size is 1 or 0).



*/
/*

     TIME AND SPACE COMPLEXITIES:
     TC:0(n log n) on average, O(n^2) in the worst case (when the smallest or largest element is always chosen as the pivot)
     SC:O(log n) for the recursive stack space in the average case, O(n) in the worst case due to stack space.

*/











