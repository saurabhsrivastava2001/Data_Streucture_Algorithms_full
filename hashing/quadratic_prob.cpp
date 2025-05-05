#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

void insert(int arr[], int key) {
    int hash = key % TABLE_SIZE;
    int i = 0;
    
    // Quadratic probing
    while (arr[(hash + i * i) % TABLE_SIZE] != -1 && i < TABLE_SIZE) {
        i++;
    }

    if (i < TABLE_SIZE) {
        arr[(hash + i * i) % TABLE_SIZE] = key;
    } else {
        cout << "Hash table is full! Could not insert " << key << endl;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " -> " << arr[i] << endl;
    }
}

int main() {
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) table[i] = -1;

    int keys[] = {12, 13, 23, 43, 22, 55, 26};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        insert(table, keys[i]);
    }

    display(table, TABLE_SIZE);
    return 0;
}
