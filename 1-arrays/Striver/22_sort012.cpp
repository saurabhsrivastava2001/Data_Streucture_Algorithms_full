#include <iostream>
#include <vector>
using namespace std;

void move(vector<int>& arr, int n){
    int left=0,mid=0,high=n-1;
    for (int i=0;i<n;i++){
        if (arr[mid]==0){
            swap(arr[mid],arr[left]);
            left++;
            mid++;
        }
        else if (arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
void print(vector<int> arr){
    for (auto it : arr){
        cout<<it<<" ";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    move(arr,n);
    print(arr);
    return 0;
}