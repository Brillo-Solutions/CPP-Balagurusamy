#include <iostream>

using namespace std;

class M
{
    private:
        int x;
        int y;
    public:
        void set_xy(int a, int b)
        {
            x = a;
            y = b;
        }
        friend int sumVal(M);
};

int sumVal(M m)
{
    int M::*px = &M::x;
    int M::*py = &M::y;
    M *pm = &m;
    int s = m.*px + pm->*py;
    return s;
}

int main() 
{
    M m;
    void (M::*p)(int, int) = &M::set_xy;
    (m.*p)(10, 20);
    cout<<sumVal(m);
    return 0;
}
