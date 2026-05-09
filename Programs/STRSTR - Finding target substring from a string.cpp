#include <iostream>
using namespace std;

int main() 
{
	char a[] = "Hello";
	if(strstr(a, "llo") == NULL)
	{
	    cout<<"Target not found!";
	}
	else
	{
	    cout<<"Target found there.";
	}
}
