#include<iostream>
using namespace std;

int main (){
    bool arr[100]={false};
    for (int i=0;i<100;i++){
        int val=i+1;
        for (int j=val;j<=100;j++){
            if (j%val==0){
                arr[j-1]=!arr[j-1];
            }
        }
    } int open=0; int close =0;
    for (int i=0;i<100;i++){
        arr[i]?open++:close++;    
    }cout<<"open doors are :"<<open;
}