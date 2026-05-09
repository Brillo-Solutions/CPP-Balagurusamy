#include <iostream>
using namespace std;

union test
{
   int x;
   int y;
   char z;
};

int main() 
{
    union test t;
    t.x = 2;
    t.y = 10;
    t.z = '6'; // 54 as decimal
    cout<<t.x;
}