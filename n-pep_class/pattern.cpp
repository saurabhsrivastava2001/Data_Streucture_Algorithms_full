#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    n*=2;
    for (int i=1;i<=n;i++){
        if (i<=n/2){
            for(int j=1;j<=n;j++){
            if (j<=i){
                cout<<"*";
            }
            else if (j>n-i){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<endl;
        } 
         else{
            for(int j=1;j<=n;j++){
            if (j<=n-i+1){
                cout<<"*";
            }
            else if (j>i-1){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<endl;
         }
    }
   
}