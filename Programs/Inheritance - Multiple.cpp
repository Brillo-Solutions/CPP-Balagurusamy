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

class B
{
    private:
        int c = 10;
    public:
        int x = 70;
        int getData(void)
        {
            return (c * x);
        }
};

class C:public B, public A          // Multiple inheritance.
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
    C c;                    // Constructor is being called on creating object and member of class A, B and C are accessed.
    c.putData(30);
    cout<<c.getData();
    return 0;
}