#include<iostream>
using namespace std;

pair<int,int> two_sum(int arr[],int n,int target){
    int i=0,j=n-1; 
    while(i<j){
        if (arr[i]+arr[j]==target){
            pair <int ,int > p;
            p.first=arr[i];
            p.second=arr[j];
            return p;
        }
        else if (arr[i]+arr[j]>target){
            j--;
        }
        else i++;
    }
}

int main(){
    int arr[6]={1,2,5,6,7,8};
    int k;
    cin>>k;
    pair<int ,int > ans=two_sum(arr,6,k);
    cout<<ans.first<<" "<<ans.second;
}