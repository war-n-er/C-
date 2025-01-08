#include <iostream>
#include <vector>

using namespace std;

// Function to perform bubble sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Early exit if no swaps were made (array already sorted)
        if (!swapped) break;
    }
}

// Function to display the array
void displayArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
// nnw 
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    displayArray(arr);

    bubbleSort(arr);

    cout << "Sorted Array: ";
    displayArray(arr);

    return 0;
}
