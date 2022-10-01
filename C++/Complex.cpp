//to create a class of complex numbers
//create a member function to add, substract, multiply two complex numbers

#include <iostream>
using namespace std;

class complex
{
    int real;
    int img;
    public:
    void getdata()
    {
        cout<<"Enter the complex number in real and imaginary parts: ";
        cin>>real>>img;
    }
    void add(complex c1, complex c2)
    {
        real = c1.real + c2.real;
        img = c1.img + c2.img;
    }
    void sub(complex c1, complex c2)
    {
        real = c1.real - c2.real;
        img = c1.img - c2.img;
    }
    void mul(complex c1, complex c2)
    {
        real = c1.real*c2.real - c1.img*c2.img;
        img = c1.real*c2.img + c1.img*c2.real;
    }
    void display()
    {
        cout<<"The complex number is: "<<real<<" + "<<img<<"i"<<endl;
    }
};

//main funtion with switch case to add, substract or multiply two complex numbers
int main()
{
    complex c1, c2, c3;
    int choice;
    c1.getdata();
    c2.getdata();
    do
    {
        cout<<"MENU \n 1. To add the two complex numbers \n 2. To substract the two complex numbers \n 3. To multiply the two complex numbers \n 0. To exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                c3.add(c1, c2);
                c3.display();
                break;
            case 2:
                c3.sub(c1, c2);
                c3.display();
                break;
            case 3:
                c3.mul(c1, c2);
                c3.display();
                break;
            case 0:
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(choice!=0);
    return 0;
}
