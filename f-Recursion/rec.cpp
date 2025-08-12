# include <iostream>



using namespace std;
int rem=0;
int rec (int n){
    if ( n<10)return n;
    int digit = n%10;
    int rem += rec(n/10);
    return ;
}

int main(){
    cout<< rec(112);
}