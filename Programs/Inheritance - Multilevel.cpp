#include <iostream>

using namespace std;

class A
{
    private:
        int a = 5;
    public:
        int b = 40;
        void putData(int x)
        {
            b = a * x;
        }
};

class B:public A
{
    private:
        int c = 10;
    public:
        int x = 70;
        int getData(void)
        {
            return (c * b);
        }
};

class C:public B
{
    private:
        int d = 20;
    public:
        C(void)
        {
            cout<<"d: "<<d<<endl;   // Member of class C (local).
            cout<<"x: "<<x<<endl;   // Member of class B (base).
            cout<<"b: "<<b<<endl;   // Member of class A (base of class B).
        }
};

int main() 
{
    B b;
    C c;                    // Constructor is being called on creating object.
    b.putData(30);          // putData is property of class A and is inheritable by class B due to public access specifier.
    cout<<b.getData()<<endl;
    return 0;
}