#include <iostream>
#include <vector>
using namespace std;

class Shape
{
private:
    /* data */
public:
        // pure virtual functions
        virtual void draw()=0;
        virtual double area()=0;

};

class Circle : public Shape
{
private:
    /* data */
    int radius;
public:
    Circle(int a){
        this->radius=a;
    }
    void draw() override{
        cout<<"\n this is circle\n";
    }
    double area() override{
        return 3.14*radius*radius;
    }
};

class Rectangle : public Shape
{
private:
    /* data */
    int length;
    int width;
public:
    Rectangle(int a,int b){
        this->length=a;
        this->width=b;
    }
    void draw() override{
        cout<<"\n this is rectangle\n";
    }
    double area () override{
        return this->length*this->width;
    }
};

int main(){
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Circle(10));
    shapes.push_back(new Circle(9));
    shapes.push_back(new Rectangle(4, 7));
    shapes.push_back(new Rectangle(7,2 ));


for (auto* s : shapes){
    s->draw();
    cout<<"area of the shape is "<<s->area();
}
    
}