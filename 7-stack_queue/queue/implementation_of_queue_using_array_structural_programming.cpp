// this is the implementation of the queue using array , structural programming

#include <iostream>
using namespace std;

void push(int* & arr,int & rear,int d){
    arr[rear]=d;
    rear++;
}
void pop(int * & arr, int &front,int &rear){
    if (front==rear){
        cout<<"empty queue"; 
    }
    else {
        arr[front]=-1;
        front++;
    }
}
void print(int * arr,int front,int rear){

    if (rear!=0){
        for(int i=front;i<rear;i++){
            cout<<arr[i]<<endl;
        }
    }
    
}

int main(){
    int size;
    cin>>size;
    int * arr=new int (size);
    int front=0;
    int rear=0;
    cout<<"before pop"<<endl;
    push(arr,rear,10);
    push(arr,rear,20);
    push(arr,rear,30);
    push(arr,rear,40);
    print(arr,front,rear);

    cout<<"after popping"<<endl;
    
    pop(arr,front,rear);
    print(arr,front,rear);
    
}