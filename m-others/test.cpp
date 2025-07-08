#include<iostream>
using namespace std;

int main(){
    int a= 5;
    int b= 3;
    int c= (a|b);
    cout<<c<<endl;;
    int x=(c & ~b);
    cout<<x;
}