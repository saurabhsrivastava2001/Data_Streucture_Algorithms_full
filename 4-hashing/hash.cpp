#include<iostream>
using namespace std;
int main(){
    int arr[8]={10,10,10,13,6,4,4,5};
    int arr2[14]={0};
    for(int i=0;i<8;i++){
        arr2[arr[i]]++;
    }
}