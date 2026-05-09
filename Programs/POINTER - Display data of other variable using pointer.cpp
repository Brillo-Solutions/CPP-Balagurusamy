#include <iostream>

using namespace std;

int main() 
{
    int a = 1;
    int *p = &a;
    cout<<"Data of (a): "<<*p<<endl;
    cout<<"Address of (a): "<<p;
}