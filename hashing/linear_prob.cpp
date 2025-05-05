//linear probling
//managing a pet registration number system with a hash table using linear probing t resolve the collision 
//operation :
//insert a new tag id( check for collision)
//resolve the collision by linear probing

#include <iostream>
using namespace std;

int main(){
    int size = 10; // size of the hash table
    int hashTable[size]; // hash table array
    for(int i = 0; i < size; i++){
        hashTable[i] = -1; // initialize the hash table with -1 (indicating empty slots)
    }
    int tagId; // variable to store the tag id to be inserted
    cout << "Enter the tag id to be inserted: ";
    cin >> tagId; // take input from the user
    int index = tagId % size;//get the has index 
    if(hashTable[index] == -1){ // if the slot is empty
        hashTable[index] = tagId;
        cout << "Tag id " << tagId << " inserted at index " << index << endl;
    }else{ // if the slot is occupied (collision occurs)
        cout << "Collision occurred at index " << index << endl;
        int i = (index + 1) % size; // start probing from the next index
        while(i != index){ // loop until we find an empty slot or come back to the original index
            if(hashTable[i] == -1){ // if the slot is empty
                hashTable[i] = tagId; // insert the tag id into the hash table
                cout << "Tag id " << tagId << " inserted at index " << i << endl;
                break; // exit the loop after inserting
            }
            i = (i + 1) % size; // move to the next index
        }
        if(i == index){
            cout << "Hash table is full, cannot insert tag id " << tagId << endl;
        }
    }
}