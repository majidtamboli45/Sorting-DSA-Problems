#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    // Merge the two sorted halves
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Remaining elements from left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Remaining elements from right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mS(vector<int> &arr, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    mS(arr, low, mid);        // Left half
    mS(arr, mid + 1, high);   // Right half
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n) {
    mS(arr, 0, n - 1);
}

int main() {
    vector<int> arr = {10, 5, 30, 15, 7, 20};

    cout << "Original Array: ";
    for (int x : arr)
        cout << x << " ";

    mergeSort(arr, arr.size());

    cout << "\nSorted Array: ";
    for (int x : arr)
        cout << x << " ";

    return 0;
}