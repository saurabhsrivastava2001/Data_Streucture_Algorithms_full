#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    int a = 10;
    int *b = new int(20);
    {
        int c = 10;
        b = &c;
    }
    cout << a * (*b) << endl;
    b = nullptr;
    int *ptr = (int *)malloc(5 * sizeof(int));
    cout << "enter the value " << endl;

    cin >> *ptr;
    cout << *ptr;

    return 0;
}