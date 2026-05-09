#include <iostream>

using namespace std;

int main() 
{
    int x = 100;
    int &y = x; // y acts alias to x and points to same location of x.
    cout<<y;    
    y += 100;   // any change made to y will also be reflected in x.
    cout<<x;    // showing change in x due to y.
}
