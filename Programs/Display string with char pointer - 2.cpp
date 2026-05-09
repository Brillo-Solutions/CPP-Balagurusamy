#include <iostream>

using namespace std;

int main() 
{
	char a[] = "Hello World of C++ programming!";
	char *p;
	p = a;
	while(*p != NULL)
	{
	    cout<<*p;
	    p++;
	}
}
