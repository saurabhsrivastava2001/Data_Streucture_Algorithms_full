#include <bits/stdc++.h>
using namespace std;

void func(string &s,int k){
    map<int,int > mp;
    string res="";
    string temp=s;
    for (int i=0;i<temp.length();i++){
        temp.erase(i, 1); 
        int a = stoi(temp);
        mp[a]=i;
        temp=s;
    }
    
}

int main() {
    string a= "1432219";
    int k=3;
    
    func(a,k);
    cout<<a;
    return 0;
}