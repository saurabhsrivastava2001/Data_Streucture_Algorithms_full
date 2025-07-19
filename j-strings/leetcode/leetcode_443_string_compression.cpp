#include <bits/stdc++.h>
using namespace std;

 int compress(vector<char>& chars) {
        int index=0; // for assigning
        int i=0; // for traversal
        int n=chars.size();
        while(i<n ){ 
            char curr_char=chars[i];
            int count=0;

            while(i<n && chars[i]==curr_char){
                i++;
                count++;
            }
            //assigning the current char at the index 
            chars[index]=curr_char;
            index++;
//now we'll assign the occurence if greater than 1
            if(count>1){

                //if greater than 10 then split into multiple char--
                string count_str=to_string(count);
                for (char ch : count_str){
                    chars[index]=ch;
                    index++;
                }
            }

        }      
        return index; //now the index will point 1 after the last assigned occ (occ+1) so return it 
    }
int main() {
    string word= "aabbbccc";
    
    vector<char> s;
    for (char c:word){
        s.push_back(c);
    }
    int lenght=compress(s);
    for (auto c : s){
        cout<<c;
    }
    return 0;
}