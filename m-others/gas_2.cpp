#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    int maxdiff=0;
    int prev=0;
    int last_diff;
    int dest;
    cin>>dest;
    for (int i=0;i<n;i++){
        int a ;
        cin>>a ;
        maxdiff= max(maxdiff,abs(a-prev));
        
        if(i==n-1){
            last_diff=abs(dest-a);
        }
        prev=a;
    }

    cout<<max(2*last_diff , maxdiff);
}