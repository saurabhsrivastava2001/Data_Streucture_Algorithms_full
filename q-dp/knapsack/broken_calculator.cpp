#include <iostream>
using namespace std;


int rec(int val, int target) {
    if (val == target) return 0;
    if (val <= 0 || val > 2 * target) return 1e9;

    if (val > target) {
        return 1 + rec(val - 1, target);
    } else {
        return 1 + min(
            rec(val * 2, target),
            rec(val - 1, target)
        );
    }
}

int main() {
    cout << rec(2, 3);
    return 0;
}
