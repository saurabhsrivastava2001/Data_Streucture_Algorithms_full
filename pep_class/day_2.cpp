#include <iostream>
using namespace std;

void reverse (int n){
    int rev=0;
    while (n>0)
    {
        rev=rev*10+n%10 ;
        n/=10;
    }
    cout<<rev;
}


int nextPrime(int n){
    cout<<"in prime function\n";
    while(n<INT32_MAX){
        n++;
        int isprime=1;
        for(int i=2;i<=n/2;i++){
        if(n%i==0){
            isprime=0;
            break;
        } 
    } if(isprime){
            cout<<"found the next prime number "<< n;
            return 0;
        }
    }
}
void summ(int n){
    int sum=0;
    while (n>0){
        sum+=n%10;
        n/=10;
    }
    if (sum>=10){
        summ(sum);
    }
    else cout<<sum;
}
void second_largest(int arr[],int size){
    int first=0;
    int second=0;
    for (int i=0;i<size;i++){
        if (arr[i]>=first){
            second=first;
            first=arr[i];
        }
        else if( arr[i]>second){
            second=arr[i];
        }
    }
    cout<<" max is : "<<first<<endl;
    cout<<"second max is : "<<second;
}
int main(){
    //int n;
    //cout<<" please enter the value you want to play with!\n";
    //cin>>n;
    //reverse(n);
    //summ(n);
    //nextPrime(n);

    int arr[5]={12,33,14,122,44};
    second_largest(arr,5);
}
