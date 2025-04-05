#include <iostream>

using namespace std;


class leaderboard{
    public:
        int arr [100];
        int size=0;
        void insert(int val){
            
            int index=size;
            arr[index]=val;
            size+=1;
            while (index>0){
                int parent=index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent], arr[index]);

                    index=parent;
                }
                else {
                    break;
                }
            }
        }

        void print(){
            for (int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
        }

};
int main (){
    leaderboard l;

     l.insert(10);
     l.insert(100);
     l.insert(120);
     l.insert(130);
     l.insert(102);
     l.insert(103);

     l.print();
}
