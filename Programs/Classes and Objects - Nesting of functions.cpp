#include <iostream>

using namespace std;

class Compare
{
    private:
        int a, b;
    public:
        void putData(int, int);
        int compVar(void);
        void getResult(void);
};

void Compare::putData(int x, int y)
{
   a = x;
   b = y;
}
    
int Compare::compVar(void)
{
    if(a>b)
        return a;
    else
        return b;
}

void Compare::getResult(void)
{
    cout<<"Largest of two is: "<<compVar();
}

int main() 
{
    Compare c;
    c.putData(12, 24);
    c.getResult();
    return 0;
}