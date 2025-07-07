#include<iostream>
#include<unordered_map>
using namespace std;

    string getHint(string secret, string guess) {
        string ans="";
        unordered_map<char,int> mp;
        for (int i =0;i<secret.length();i++){
            if( secret[i]==guess[i]){
                mp['A']++;
            }
            else mp['B']++;
        }
       
        ans+=(char)mp['A'];
        return ans;
    }

    int main(){
        
    string a= "1233";
    string a= "3233";


        return 0;
    }
