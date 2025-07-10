#include <bits/stdc++.h>
using namespace std;
    bool wordPattern(string pattern, string s) {
        vector <string > str;
        int i=0;
        string curr="";
        while(i<s.length()){
            if (s[i]!=' '){
                curr+=s[i];
            }
            else if (s[i]==' ' && curr!=""){
                
                str.push_back(curr);
                curr="";
            }
            i++;
        }
        str.push_back(curr);
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        if (pattern.length() != str.size()) return false;
        for (int i=0; i<pattern.length(); i++){
            if (mp.find(pattern[i]) == mp.end() && mp2.find(str[i]) == mp2.end()){
                mp[pattern[i]] = str[i];
                mp2[str[i]] = pattern[i];
            }
            else if (mp.find(pattern[i]) != mp.end() && mp2.find(str[i]) != mp2.end()){
                if (mp[pattern[i]] != str[i] || mp2[str[i]] != pattern[i]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    int main(){
        string s= "dog cat cat dog";
        cout<<wordPattern("abba", s);

    }