#include <iostream>
using namespace std;

class A
{
private:
    /* data */
    int a ,b;
public:
    A(int ,int);
    ~A();

    int sum(){
        cout<<"sum funct of class a \n";
        return a +b;
    }
};

A::A(/* args */
    int a ,int b
)
{
    this->a=a;
    this->b=a;
}

A::~A()
{
    cout<<"\nthe object memory is freed";
}

class B 
{
private:
    int a ,b;
public:
    B(/* args */ int ,int );
    ~B();
    int sum(int a ,int b){
        cout<<"this is the func of the b class\n";
        return a+b;
    }
};

B::B(/* args */int a,int b)
{
    this->a=a;
    this->b=b;
}

B::~B()
{
}

class C
{
private:
    /* data */
public:
    C(/* args */);
    ~C();
};

C::C(/* args */)
{
}

C::~C()
{
}
