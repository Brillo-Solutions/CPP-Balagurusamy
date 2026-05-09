#include <iostream>

using namespace std;

class A
{
    private:
        int a = 5;
    public:
        int b;
        void putData(int x);
};

class B:private A
{
    private:
        int c = 10;
    public:
        int getData(void)
        {
            putData(30);    // putData() can be used here as a nested function.
            return (c * b);
        }
};

void A::putData(int x)
{
    b = a * x;
}

int main() 
{
    B b;
    //b.putData(30);          // use of putData() will not work here directly because private access specifier is used for A. 
    cout<<b.getData();
    return 0;
}