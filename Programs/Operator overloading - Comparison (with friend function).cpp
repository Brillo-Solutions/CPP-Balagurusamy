#include <iostream>

using namespace std;

class compare
{
    private:
        int x;
    public:
        friend bool operator==(compare, compare);
        void setData(int a)
        {
            x = a;
        }
};

bool operator==(compare c1, compare c2)
{
    if(c1.x == c2.x)
        return true;
    else
        return false;
}

int main() 
{
    compare comp1, comp2;
    comp1.setData(200);
    comp2.setData(200);
    cout<<(comp1 == comp2);
    return 0;
}