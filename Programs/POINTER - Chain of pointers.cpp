#include <iostream>

using namespace std;

int main() 
{
	int *p1, **p2;
	int x = 100;
	p1 = &x;
	p2 = &p1;
	cout<<x<<endl;  //x holds 100 originally.
	cout<<*p1<<endl;    //p1 hold address of x *p1 will show value of x.
	cout<<**p2<<endl;   //p2 hold address of p1 and **p2 will show value of x.
}
