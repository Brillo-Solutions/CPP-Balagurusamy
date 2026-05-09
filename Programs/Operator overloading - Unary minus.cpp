#include <iostream>

using namespace std;

class space
{
    private:
        int x, y, z;
    public:
        void putData(int, int ,int);
        void display(void);
        void operator-(void);           // Overloading unary minus operator.
};

void space::putData(int a, int b, int c)
{
    x = a;
    y = b;
    z = c;
}

void space::display(void)
{
    cout<<"x: "<<x<<" y: "<<y<<" z: "<<z;
}

void space::operator-()
{
    x = -x;
    y = -y;
    z = -z;
}

int main() 
{
    space s;
    s.putData(20, -30, 40);
    s.display();
    -s;
    s.display();
    return 0;
}