#include <iostream>
using namespace std;

class base
{
private:
    /* data */
    int money;
public:
    base(/* args */int);
    ~base();
    void credit (int amount){
        this->money+=amount;
        cout<<"credit successful for money %d current bank balance : %d \n",amount,this->money;
    }
    void debit(int amount){
        if (amount>this->money){
            cout<<"invalid transaction\n";
        }
        else {
            this->money-=amount;
        }
    }
};

base::base(int initial)
{
 this->money=initial;
}

base::~base()
{
}


class Ind : public base
{
private:
    /* data */
   
public:
    Ind(/* args */int );
    ~Ind();

    void upi(int money){

    }
};

Ind::Ind(/* args */int initial)
{
    this->money=initial;
}

Ind::~Ind()
{
}

class USA
{
private:
    /* data */
public:
    USA(/* args */);
    ~USA();
};

USA::USA(/* args */)
{
}

USA::~USA()
{
}
class UK
{
private:
    /* data */
public:
    UK(/* args */);
    ~UK();
};

UK::UK(/* args */)
{
}

UK::~UK()
{
}

