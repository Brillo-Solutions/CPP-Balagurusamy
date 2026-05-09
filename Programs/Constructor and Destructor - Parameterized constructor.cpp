#include <iostream>

using namespace std;

class M
{
    private:
        int x, y;
    public:
        M(int a, int b)
        {
            x = a;
            y = b;
        }
        void showVal()
        {
            cout<<x<<endl;
            cout<<y;
        }
};

int main() 
{
    M m(10, 20);
    m.showVal();
    return 0;
}
