#include <iostream>

using namespace std;

class M
{
    private:
        int x, y;
    public:
        M(void)
        {
            x = 20;
            y = 25;
        }
        void showVal()
        {
            cout<<x<<endl;
            cout<<y;
        }
};

int main() 
{
    M m;
    m.showVal();
    return 0;
}