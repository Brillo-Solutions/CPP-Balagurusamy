#include <iostream>

using namespace std;

class A
{
    private:
        int a = 5;
    public:
        int b;
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
        int getData(void)
        {
            return (c * b);
        }
};

int main() 
{
    B b;
    b.putData(30);          // putData is property of class A and is inheritable by class B due to public access specifier.
    cout<<b.getData();
    return 0;
}