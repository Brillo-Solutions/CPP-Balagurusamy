#include <iostream>

using namespace std;

class M
{
    private:
        int x, y;
    public:
        M(void)
        {
            x = 220;
            y = 223;
        }
        M(int a, int b)
        {
            x = a;
            y = b;
        }
        M(int *a, int *b)
        {
            x = *a;
            y = *b;
        }
        void showVal()
        {
            cout<<x<<endl;
            cout<<y<<endl;
        }
};

int main() 
{
    M m1;
    int m = 23;
    int n = 44;
    m1.showVal();
    M m2(10, 20);
    m2.showVal();
    M m3(&m, &n);
    m3.showVal();
    return 0;
}
