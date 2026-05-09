#include <iostream>

using namespace std;

class space
{
    private:
        int x, y, z;
    public:
        void putData(int, int ,int);
        void display(void);
        friend void operator-(space &s);           // Overloading unary minus operator.
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

void operator-(space &s)
{
    s.x = -s.x;
    s.y = -s.y;
    s.z = -s.z;
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