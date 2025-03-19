
#include <iostream>
using namespace std;

class Heap_leaderboard {
public:
    int arr_score[100];
    int size;
    
    Heap_leaderboard() {
        size = 0;
    }
    
    
    void insert(int a) {
        if (size >= 100) {
            cout << "Heap_leaderboard overflow" << endl;
            return;
        }
        
        size++;
        int index = size;
        arr_score[index] = a;

        while (index > 1) {
            int parent = index / 2;
            if (arr_score[parent] < arr_score[index]) {
                swap(arr_score[parent], arr_score[index]);
                index = parent;
            } else {
                break;  // Use break instead of return for clarity
            }
        }
    }
    
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr_score[i] << " ";
        }
        cout << endl;
    }
};




int main(){
    Heap_leaderboard h;
    h.insert(60);
    h.insert(79);
    h.insert(23);
    h.insert(232);
    h.insert(25);;
    h.insert(22);


    h.print();
}