#include <iostream>
#include <vector>
#include<stack>
using namespace std;

vector<int> stock_span(int arr[], int size){
    vector <int> v;
    stack <pair<int,int> >s;
    for (int i =0;i<size;i++){
        if (s.size()==0){
            v.push_back(i+1);
            //directly
        }
        else if(s.top().first>arr[i]){
            v.push_back(i-s.top().second);
        }
        else if (s.top().first<arr[i]){
            while(s.size()>0 && s.top().first<arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(i+1);
            }
            else if (s.top().first>arr[i]){
                v.push_back(i-s.top().second);
            }
        }
        s.push({arr[i],i});
    }
    return v;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    vector <int> ans;
    // arr={100,80,60,70,60,75,85}
    //v=(-1,0,1,1,3,1,0)
    //ans[i]=i-v[i]
    // ans=(1,1,1,2,1,4,6)
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    ans=stock_span(arr,n);
    for (int i=0; i<n; i++){
        cout<<ans[i]<<"  ";
    }
}