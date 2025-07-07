#include <iostream>
#include <vector>
using namespace std;

void func(vector<int> arr, int k)
{
    int n= arr.size();
    int i=0,j=0;
    int sum=0;
    int maxi=0;
    while(j<n){
        sum+=arr[j];
        if(j-i+1<k){
            j++;
            continue;
        }
        maxi=  max(maxi,sum);
        sum-=arr[i];
        i++;
        j++;
    }
    cout<<maxi;
}

int main(){
    vector <int> arr= {1,2,3,4,12,4,12,7};
    func(arr,3);
}