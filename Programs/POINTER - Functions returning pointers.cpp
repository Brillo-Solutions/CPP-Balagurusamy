#include <iostream>

using namespace std;
int *larger(int *, int *);

int main() 
{
	int a = 10;
	int b = 20;
	int *p;
	p = larger(&a, &b);
	cout<<*larger(&a, &b)<<endl;    // Without *p.
	cout<<*p;   // With *p.
}
int *larger(int *x, int *y)
{
    if(*x > *y)
    {
        return (x);
    }
    else
    {
        return (y);
    }
}