#include <iostream>
#include <string>
#include <vector>

using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swaped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaped = true;
            }
        }
        if (!swaped)
        {
            break;
        }
    }
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_pos])
            {
                min_pos = j;
            }
        }
        swap(arr[min_pos], arr[i]);
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
class mergeSort
{
public:
    void merge(int arr[], int low, int high, int mid)
    {
        int n = high - low + 1; // Number of elements between low and high
        int temp[n];            // Temporary array
        int index = 0;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] < arr[right])
            {
                temp[index++] = arr[left++];
            }
            else
            {
                temp[index++] = arr[right++];
            }
        }

        // Copy any remaining elements from the left subarray
        while (left <= mid)
        {
            temp[index++] = arr[left++];
        }

        // Copy any remaining elements from the right subarray
        while (right <= high)
        {
            temp[index++] = arr[right++];
        }

        // Copy sorted elements back into original array
        for (int i = 0; i < n; i++)
        {
            arr[low + i] = temp[i];
        }
    }

    void partition(int arr[], int low, int high)
    {
        if (low >= high)
        { // corrected (== changed to >= to prevent infinite recursion)
            return;
        }
        int mid = (low + high) / 2;
        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }

    void merge_sort(int arr[], int n)
    {
        partition(arr, 0, n - 1);
    }
};

class quick
{
public:
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j)
        {
            while (arr[i] <= pivot && i <= high - 1)
            {
                i++;
            }

            while (arr[j] > pivot && j >= low + 1)
            {
                j--;
            }
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }

    void qs(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int pIndex = partition(arr, low, high);
            qs(arr, low, pIndex - 1);
            qs(arr, pIndex + 1, high);
        }
    }

    vector<int> quickSort(vector<int> arr)
    {
        qs(arr, 0, arr.size() - 1);
        return arr;
    }
};

void print(string text, int arr[], int n)
{
    cout << text;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void print_vec(string text, vector<int > arr)
{
    cout << text;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    mergeSort m;
    quick q;
    int arr[7] = {43, 55, 2, 44, 1, 23, 22};
    vector <int> arr1={43, 55, 2, 44, 1, 23, 22};
    int n = 7;
    print("the unsorted array is \n", arr, n);
    
    print_vec("the sorted array by merge sort \n", q.quickSort(arr1));
}