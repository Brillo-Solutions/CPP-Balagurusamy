#include <iostream>

using namespace std;

class A
{
    public:
    A()
    {
        cout<<"Constructor of A";
    }
};

class B
{
    public:
    B()
    {
        cout<<"Constructor of B";
    }
};

class C: public B, public A
{
    public:
    C()
    {
        cout<<"Constructor of C";
    }
};

int main() 
{
	C c;
}
