#include <iostream>

using namespace std;

int main() 
{
    int a = 1;
    int b = 0;
    cout<<b<<endl;    // No value of (a) here.
    int *p = &b;
    *p = a;
    cout<<b;    // Value of (a) is now in (b).
}
