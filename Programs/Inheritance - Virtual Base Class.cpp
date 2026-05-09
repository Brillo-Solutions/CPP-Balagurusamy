#include <iostream>

using namespace std;

class A
{
    private:
        int a = 1;
    public:
        int showContentOfA()
        {
            return a;
        }
};
class B: virtual public A
{
    private:
        int b = 2;
    public:
        int showContentOfB()
        {
            return b;
        }
};
class C: virtual public A
{
     private:
        int c = 3;
    public:
        int showContentOfC()
        {
            return c;
        }
};
class D: public B, public C
{
    private:
        int d = 4;
    public:
        int showContentOfD()
        {
            return d;
        }
};

int main() 
{
    D d;
    //cout<<d.showContentOfA(); //error: request for member 'showContentOfA' is ambiguous if keyword 'virtual' is not added public A
    cout<<d.showContentOfA(); 
}
