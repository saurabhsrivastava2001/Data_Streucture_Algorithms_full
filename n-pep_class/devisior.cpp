#include <iostream>
using namespace std;

bool func(int even, int odd) {
    int i = 1;
    while (i < 1000) {
        int count_even = 0;
        int count_odd = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                j % 2 == 0 ? ++count_even : ++count_odd;
            }
        }
        if (count_even == even && count_odd == odd) {
            cout<<i;
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    int odd = 2;
    int even = 3;
    if (func(odd, even)) {
        cout << "yes";
    }
    else cout<<"no";
}
