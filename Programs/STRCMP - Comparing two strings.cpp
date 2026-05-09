#include <iostream>
using namespace std;

int main() 
{
	char a[] = "hello";
	char b[] = "world";
	cout<<strcmp(b,a); // Returns difference in positive number if a > b else in negative number if b > a.
}
