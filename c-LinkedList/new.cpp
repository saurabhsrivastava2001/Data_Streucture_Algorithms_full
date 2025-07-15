#include<iostream>
using namespace std;


class Node {
    public:
    int val;
    Node * next;
    Node (int data){
        this->val=data;
        this->next=NULL;
    }
};


int main(){
    Node *node=new Node (1);
    Node *head1=node;
    Node * interc;
    for (int i=1;i<5;i++){
        int a;
        cin>>a;
        Node * new_node = new Node (a);
        node->next=new_node;
        if (i==2){
            interc=new_node;
            cout<<"intersept point"<<interc->val;
        }
    }
    Node * node1=new Node (6);
    Node * head2= node1;
    Node * sec_end_p;
    cout<<"enter the data for the 2nd ll"<<endl;
    for (int i=0;i<2;i++){
        int  a;
        cin>>a;
        Node* new_node= new Node (a);
        node1->next=new_node;
        if (i==1){
            sec_end_p=new_node;
        }
        }
        cout<<"sec end"<<sec_end_p->val<<endl;
    sec_end_p->next=interc;
     
    while (head1)
    {
        /* code */
        cout<<head1->next<<endl;
        head1=head1->next;
    }
    while(head2){
        cout<<head2->next<<endl;
        head2=head2->next;
    }

    
}