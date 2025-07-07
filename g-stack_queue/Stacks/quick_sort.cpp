#include <iostream>
#include <stack>

using namespace std;

// Partition function (same as in recursive QuickSort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Iterative QuickSort
void quickSortIterative(int arr[], int low, int high) {
    stack<pair<int, int>> st;

    st.push({low, high});

    while (!st.empty()) {
        auto range = st.top();
        st.pop();
        int l = range.first, h = range.second;

        if (l < h) {
            int pi = partition(arr, l, h);

            // Push left and right subarrays onto the stack
            if (pi - 1 > l) st.push({l, pi - 1});
            if (pi + 1 < h) st.push({pi + 1, h});
        }
    }
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSortIterative(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}
