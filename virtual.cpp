#include <iostream>
using namespace std;

class a {
    public:
    virtual void funca () {
        cout << "funca" << endl;
    }
};
class b : public a{
    public:
    void funca () {
        cout << "funcb" << endl;
    }
};
class c : public a{
    public:
    void funca () {
        cout << "funcc" << endl;
    }
};
int main() {
    a * ptr;
    b objb;
    c objc;
    ptr = &objb;
    ptr->funca();
    ptr = &objc;
    ptr->funca();
    return 0;
}
