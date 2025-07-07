// Dog Food Delivery – VIP Orders First
// Problem (Array-based):
// Use an array to create a Max Heap representing delivery priorities. 
//Allow dynamic insertion of new customer priority values and always serve the highest priority (maximum value in heap)

#include <iostream>
using namespace std;

class delivery_priorities{
    public:
        int customers[100];
        int size=0;
        void insert(int val){
            
            int index=size;
            customers[index]=val;
            size+=1;
            while (index>0){
                int parent=index/2;
                if(customers[parent]<customers[index]){
                    swap(customers[parent], customers[index]);

                    index=parent;
                }
                else {
                    break;
                }
            }
        }

        void print(){
            for (int i=0;i<size;i++){
                cout<<customers[i]<<" ";
            }
        }

};
int main (){
    delivery_priorities dp;


    while (true)
    {
        cout << "press 1 to enter the customer \n 2 to print the top priority \n  any other key to exit the program \n";
        int n;
        cin>>n;
        switch (n){
            case 1: 
                cout<<"enter the priorty ";
                int x;
                cin >>x;
                dp.insert(x);
                break;
            case 2:
                cout<<dp.customers[0];
            default:
            cout<<"exiting the program ! thanks  for using ";
            return 0;
        }
    }


     return 0;
}
