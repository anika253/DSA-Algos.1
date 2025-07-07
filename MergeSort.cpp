#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Merge both halves into temp
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back into original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void ms(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    ms(arr, low, mid);
    ms(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int>& arr) {
    ms(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {3, 2, 4, 1, 3};
    mergeSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
/*


MergeSort is a divide-and-conquer algorithm that sorts an array by recursively dividing it into halves, sorting each half, and then merging the sorted halves back together.
keep on dividing the array into halves until each half has one element, then merge the sorted halves back together.
TC: O(n log n) in all cases (best, average, worst)
SC: O(n) due to the temporary array used for merging.














*/