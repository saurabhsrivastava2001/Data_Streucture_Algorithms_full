#include<iostream>
using namespace std;

class Node{
    public:
    int data ;
    Node * next;
    Node( int data ){
        this->data=data;
        this->next=NULL;
    }
    ~Node() {
            int value = this -> data;
            //memory free
            if(this->next != NULL) {
                delete next;
                this->next = NULL;
            }
            cout << " memory is free for node with data " << value << endl;
        }    
};

void insertAtTail( Node * &tail, int d){

    // new node create
    Node* temp =new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void insertAtHead(Node* &head,int d){
    //inserting at head
    Node * temp=new Node(d);
    temp->next=head;
    head=temp;
}
void print(Node * &head){
    if(head == NULL){
        cout<<"list is empty"<<endl;
        return ;
    }
    Node * temp =head;
    while  (temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}
void deleteNode(int position, Node* & head,Node * &tail) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr->next==NULL){
            prev->next=NULL;
            tail=prev;
            delete curr;
            return;
        }
        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;
    }
}

Node* reverseList(Node* head) {
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursive case: reverse the rest
    Node* newHead = reverseList(head->next);

    // Reverse the pointers
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

int main(){
    Node * first = new Node(10);
    Node * head=first;
    Node * tail=first;
    insertAtHead(head,20);
    insertAtTail(tail,30);
    print(head);

    insertAtPosition(tail,head,2,39);
    print(head);

    deleteNode(4,head,tail);
    print(head);
    cout<<"tail is -- "<<tail->data;
}


