// Problem Statement: "The Tower of Magic Scrolls"
// The Grand Librarian stores magic scrolls in a stack using a linked list. However, after a teleportation mishap, some scrolls have been lost! To restore the collection, students must retrieve only the essential spells.
// Level 1: "Stacking the Arcane Scrolls" (Basic Stack Operations)
// Task:
// •	The Librarian gathers five important scrolls in the following order:
// "Summon", "Shield", "Heal", "Fireball", "Invisibility"
// •	Push them onto a stack (linked list implementation).
// •	Pop and display the order to verify stacking.
// ✅ Completion Condition:
// •	When popping from the stack, the order should be:
// Invisibility → Fireball → Heal → Shield → Summon....for odd roll numbers

#include <iostream>
using namespace std;

class Node{
public:
    string spell;
    Node* next;

    Node(string val){
        spell = val;
        next = NULL;
    }
};


int main(){
    Node* top = NULL; // Initialize the stack

    // Pushing scrolls onto the stack
    string scrolls[] = {"Summon", "Shield", "Heal", "Fireball", "Invisibility"};
    for(int i = 0; i < 5; i++){
        Node* newNode = new Node(scrolls[i]);
        newNode->next = top;
        top = newNode;
    }

    // Popping and displaying the order
    cout << "Popped scrolls in order: ";
    while(top != NULL){
        cout << top->spell << " ";
        Node* temp = top;
        top = top->next;
        delete temp; // Free memory
    }
    cout << endl;

    return 0;
}