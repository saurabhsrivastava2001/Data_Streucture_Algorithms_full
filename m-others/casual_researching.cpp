
#include <iostream>
using namespace std;


int main(){
    int n=123452314;
    int arr[9]={0};
    int pos[9]={0};
    int copy=n;
    int possi=0;
    while(copy>0){
        int digit =copy%10;
        arr[digit]++;
        //cout<<"arr :"<<digit<<"is : "<<arr[digit]<<endl;
        if (arr[digit]>1){
            pos[possi]=digit;
            //cout<<"updating posi position : "<<possi<<" value : "<<pos[possi]<<endl;
            possi++;
        }
        
        possi++;
        copy=copy/10;
    }
   
    for (int i=9;i>=0;i--){
        if(pos[i]>0){
            cout<<"the final ans is : "<<pos[i];
            break;
        }
        cout<<"not found";
        break;
    }
    
}