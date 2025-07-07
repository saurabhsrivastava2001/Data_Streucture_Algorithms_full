#include<iostream>
using namespace std;

int main(){
    for (int i=0;i<8 ;i++){
        
            for (int j=0;j<=8;j++){
                if (i=0){
                    if (j>=2 || j<=6){
                    cout<<"-";
                }
                else cout<<" ";
                }
                if (i=1){
                    if (j==1 ){
                        cout<<"/";
                    }
                    else if (j==7){
                        cout<<"\\";
                    }
                    else cout<<" ";
                }
                if (i==2){
                    if (j==0){
                        cout<<"/";
                    }
                    else if( j==7){
                        cout<<"\\";
                    }
                    else cout<<" ";
                }
                if (i==3 || i==4){
                    if (j==0 || j==7){
                        cout<<"|";
                    }
                    else cout<<" ";
                }
                else {
                    if (j==i-3){
                        cout<<"\\";
                    }
                    // else if ()
                }
                }
                
            cout<<endl;     
    }
}