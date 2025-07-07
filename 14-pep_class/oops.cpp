#include <iostream>
#include <String>
using namespace std;


class Student {
        private:
        int rollnum;
        string name;
        int marks ;


        public :
        Student(int roll,int marks,string name){
            this->marks=marks;
            this->name=name;
            this->rollnum=roll;
        }
        void view(){
            cout<<"the name of the student is "<<this->name<<" roll number : "<<this->rollnum<<" and the marks is << "<<this->marks<<" !"<<endl;
        }
}; 


int main(){
     Student a(1,88, "saurabh");
     Student b(2,8, "tushar");
     Student c(3,98, "suraj");

     a.view();
     b.view();


     return 0;
     
}