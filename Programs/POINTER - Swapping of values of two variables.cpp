#include <iostream>

using namespace std;

int main() 
{
    int a = 1;
    int b = 0;
    int temp;
    cout<<"Value of (a) before swapping: "<<a<<endl;
    cout<<"Value of (b) before swapping: "<<b<<endl;
    int *p1, *p2;
    p1 = &b;
    p2 = &a;
    temp = *p2;
    *p2 = *p1;
    *p1 = temp;
    cout<<endl<<"Value of (a) after swapping: "<<a<<endl;
    cout<<"Value of (b) after swapping: "<<b<<endl;
}