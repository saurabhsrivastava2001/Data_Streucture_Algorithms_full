#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;
    
    Heap() {
        size = 0;
    }
    void insert(int a) {
        if (size >= 100) {
            cout << "Heap overflow" << endl;
            return;
        }
        
        size++;
        int index = size;
        arr[index] = a;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;  // Use break instead of return for clarity
            }
        }
    }
    
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    Heap h;
    h.insert(60);
    h.insert(79);
    h.insert(23);
    h.insert(232);
    h.insert(25);;
    h.insert(22);


    h.print();
}