#include <iostream>
#include <vector>
using namespace std;


void print(vector <int > & arr){
    int n=arr.size();
    

    int temp=arr[n-1];
    arr.pop_back();
    print(arr)
    


}



int main() {
   
    return 0;
}