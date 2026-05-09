#include <iostream>

using namespace std;

class compare
{
    private:
        int x;
    public:
        bool operator==(compare);
        void setData(int a)
        {
            x = a;
        }
};

bool compare::operator==(compare c)
{
    if(x == c.x)
        return true;
    else
        return false;
}

int main() 
{
    compare comp1, comp2, comp3;
    comp1.setData(200);
    comp2.setData(200);
    cout<<(comp1 == comp2);
    return 0;
}