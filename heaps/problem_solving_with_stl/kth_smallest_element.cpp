//  here we have to implement the mac heap bcz its asking for the smallest element 


#include <iostream>
#include <queue>

using namespace std;

int kth_smallest(int arr[],int size,int k){
    priority_queue<int> max_heap;
    for (int i=0;i<size;i++){
        max_heap.push(arr[i]);
        if (max_heap.size()>k){
            max_heap.pop();
        }
    }
    return max_heap.top();
}



int main(){
    int n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cout<<"enter the "<<i+1 << "th elements of array then (press enter) "<<n-i<<" more to enter "<<endl;
        cin>>arr[i];
    }
    cout<<" we want which smallest number ? enter a value less than  "<< n<<endl;
    int k;
    cin>>k;
    printf("the %dth smallest number is %d",k,kth_smallest(arr,n,k));
}