#include <iostream>
using namespace std;

int main() 
{
	char a[] = "Hello";
	char b[] = "World";
	strncpy(a, b, 2); 
	cout<<a;
}
