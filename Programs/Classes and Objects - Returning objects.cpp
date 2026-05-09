#include <iostream>

using namespace std;

class Complex
{
    private:
        float x;
        float y;
    public:
        void inputVal(float real, float imag)
        {
            x = real;
            y = imag;
        }
        friend Complex sumVal(Complex, Complex);
        void showVal(Complex);
};

Complex sumVal(Complex c1, Complex c2)
{
    Complex c3;
    c3.x = c1.x + c2.x;
    c3.y = c1.y + c2.y;
    return (c3);
}

void Complex::showVal(Complex c)
{
    cout<<c.x<<" + j"<<c.y<<endl;
}

int main() 
{
    Complex A, B, C;
    A.inputVal(3.1, 5.65);
    B.inputVal(2.75, 1.2);
    
    C = sumVal(A, B);
    
    cout<<"A: ";
    A.showVal(A);
    cout<<"B: ";
    B.showVal(B);
    cout<<"C: ";
    C.showVal(C);
}
