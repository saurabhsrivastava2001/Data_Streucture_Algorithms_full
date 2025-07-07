#include <iostream>
using namespace std;

class node {
    public:
    int data ;
    node * next ;
    node * prev;

    // constructor-
    node (int d){
        this -> data =d;
        this -> prev=NULL;
        this -> next=NULL;
    }
      ~node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};
void insertathead(node * & head , int d){
    node * new_node =new node (d);
    new_node->next=head; 
    head->prev=new_node;
    head=new_node;
}

void insterAtTail(node * &tail,int d){
    node * newNode =new node(d);
    newNode->next=NULL;
    newNode->prev=tail;
    tail->next=newNode;
    tail=newNode;
}
void insertatposition(node * & head,node * & tail, int d, int pos){
    if(pos==1){
        insertathead(head, d);
        return ;
    }
    node * temp=head;
    int count=1;
    while ( count<pos-1){
        temp=temp->next;
        count++;
    }
    //adding at tail
    if (temp->next==NULL){
        insterAtTail(tail,d);
        return;
    }
    else {
        node * newNode=new node(d);
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next=newNode;
    }


}

void deleteNode(int position, node* & head) { 

    //deleting first or start node
    if(position == 1) {
        node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}

void print(node * head,node * tail){
    node * temp=head;
    while (temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"head="<<head->data <<" and tail="<<tail->data;
}
int main(){
    node * first =new node (10);
    node * head = first;
    node * tail = first;
    insertathead(head, 20);
    insterAtTail(tail,30);
    insertatposition(head,tail,40,2);
    insertatposition(head,tail,40,5);
    print(head,tail);
    deleteNode(3,head);
    print(head,tail);
}