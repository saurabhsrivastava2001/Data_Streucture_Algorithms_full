#include <iostream>

using namespace std;

void solve( int source , int dest, int helper, int n){
    if (n==1){
        cout<<" moving disk "<<n<<" from "<<source <<" to "<<dest<<endl;
        return;
    }
    solve (source, helper,dest,n-1);
    cout<<" moving disk "<<n<< " from "<<source<< " to "<<dest<<endl;
    solve(helper,dest,source,n-1);
    cout<<" program completed";
    return ;
}

int main(){
    int n=3;
    solve(1,3,2,n);
}