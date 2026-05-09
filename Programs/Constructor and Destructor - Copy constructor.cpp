#include <iostream>

using namespace std;

class M
{
    private:
        int x;
    public:
        M(){}
        M(int a)
        {
            x = a;
        }
        M(M & m)        // Copy constructor
        {
            x = m.x;
        }
        void showVal()
        {
            cout<<x<<endl;
        }
};

int main() 
{
    M m1(100);
    M m2(m1);
    M m3 = m1;
    M m4;
    m4 = m1;
    m1.showVal();
    m2.showVal();
    m3.showVal();
    m4.showVal();
    return 0;
}