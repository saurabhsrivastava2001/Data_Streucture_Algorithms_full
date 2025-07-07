//using min heap
#include<iostream>
#include <queue>

using namespace std;


void kth_largest_ele(int arr[],int size,int k){
    priority_queue<int ,vector<int > , greater<int>> min_heap;

    for (int i=0;i<size;i++){
        min_heap.push(arr[i]);

        if (min_heap.size()> k){
            min_heap.pop();
        }
    }
    for (int i=0;i<k;i++){
        printf("the %dth biggest number is %d\n",k-i,min_heap.top());
        min_heap.pop();
    }

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
    cout<<" how much laegest numbers you want ? enter a value less than "<< n<<endl;
    int k;
    cin>>k;
    kth_largest_ele(arr,n,k);
}
