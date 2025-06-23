#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int > ans(5);
    ans[0]=v[0];
    for (int i=1;i<v.size();i++){
        ans[i]=ans [i-1]+v[i];
    }

    for (int i=0;i<5;i++){
        cout<<ans[i]<<" ";
    }
    cout << endl;
    return 0;
}
