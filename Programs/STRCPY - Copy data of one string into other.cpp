#include <iostream>
#include <stdio.h>
using namespace std;

int main() 
{
	char a[] = "Hello";
	char b[] = " World";
	strcpy(a, b);
	cout<<a;
}
