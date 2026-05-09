#include <iostream>
int change(int *p);
using namespace std;

int main() 
{
    int x = 20;
    cout<<change(&x);       //Calling function by reference or address.
    
}
int change (int *p)
{
    *p = *p + 10;
    return *p;
}