// using keyword
#include<iostream>
using namespace std;
class Base{
    public:
    void print(){
        cout<<"Base"<<endl;
    }

    void greet(){
        cout<<"Greetings"<<endl;
    }
};
class Derived1:protected Base{
    public:
    // when we only need to inherit one function from base class publically but not all, then we can use using keyword.
    using Base::print;

};

class Derived2:public Base{
    public:
    // when we need overloaded functionality of functions
    using Base::greet;

    void greet(string Name){
        cout<<"Greetings "<<Name<<endl;
    }

};

int main(){
    cout<<"Print"<<endl;
    Derived1 b;
    b.print(); // if we will not have the function of print by using keyword in the class, it will give error


    Derived2 c;
    c.greet("Priya");
    c.greet(); // it will give error, if we will not have the function of greet function without any parameters by using keyword.
}