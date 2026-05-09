#include <iostream>

using namespace std;
int m = 10;
int main() 
{
 int m = 20;
 cout<<m;   // points to local variable i.e. int m = 20
 cout<<::m; // points to m declared outide function or scope i.e. int m = 10 using scope resolution operator.
}
