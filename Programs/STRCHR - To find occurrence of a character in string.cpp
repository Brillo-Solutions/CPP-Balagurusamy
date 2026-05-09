#include <iostream>
using namespace std;

int main() 
{
	char a[] = "Hello";
	if(strchr(a, 'e') == NULL)
	{
	    cout<<"Target not found!";
	}
	else
	{
	    cout<<"Target found there.";
	}
}
