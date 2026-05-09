#include <iostream>

using namespace std;

class Complex
{
    private:
        float x, y;
    public:
        Complex(){}
        Complex(float real, float imag)
        {
            x = real;
            y = imag;
        }
       friend Complex operator+(Complex, Complex);			// Binary operator is member function here so it needs only one argument.
                                                            // in case of friend it will become like: C3 = operator+(C1, C2).
                                                            // return can be  like: return Complex((c1.x+c2.x), (c1.y+c2.y));
        void display(void);
};

Complex operator+(Complex c1, Complex c2)
{
    Complex temp;
    temp.x = c1.x + c2.x;           			            // x belongs to C1 and c.x belongs to C2.
    temp.y = c1.y + c2.y;           			            // y belongs to C1 and c.y belongs to C2.
    return(temp);               			                // temp will be returned to C3.
    
            //OR
    //return Complex((x+c.x), (y+c.y));
}

void Complex::display(void)
{
    cout<<x<<" + j"<<y<<endl;
}

int main() 
{
    Complex C1, C2, C3;         			                // Invokes constructor - 1.
    C1 = Complex(2.5, 3.5);     		                	// Invokes constructor - 2.    
    C2 = Complex(1.6, 2.7);     			                // Invokes constructor - 2.
    C3 = C1 + C2;               			                // Invokes operator+() function and send C2 as an argument whereas C1 invokes operator+() function.
        //OR
    //C3 = C1.operator+(C2);
    C1.display();
    C2.display();
    C3.display();
    return 0;
}