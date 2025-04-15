#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int target) { 
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return index of the element
        } else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right subarray
        } else {
            right = mid - 1; // Target is in the left subarray
        }
    }

    return -1; // Element not found
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter element to search: ";
    cin >> x;

    int result = binary_search(arr, n, x);
    if (result == -1) {
        cout << "Element is not present in array.\n";
    } else {
        cout << "Element is present at index: " << result << endl;
    }

    return 0;
}

