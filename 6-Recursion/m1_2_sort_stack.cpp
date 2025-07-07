#include <iostream>
#include <stack>

using namespace std;


void insert(stack<int> &s,int temp){
    if (s.size()==0 || s.top()<temp){
        s.push(temp);
        return ;
    }

    int val=s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
}

void sort(stack<int> & s){
    if (s.size()==1){
        return;
    }
    int temp=s.top();
    s.pop();
    sort(s);
    insert(s,temp);
}


void print(stack<int> s){
    int n=s.size();
     for (int i=0;i<n;i++){
        cout<<s.top()<< " ";
        s.pop();
     }
     cout<<endl;
}

int main() {
    stack <int >s;
    s.push(9);
    s.push(6);
    s.push(4);
    s.push(8);
    s.push(10);
    s.push(3);
    print (s);
    sort(s);
    print(s);
    return 0;
}