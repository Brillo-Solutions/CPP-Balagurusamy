#include <iostream>

using namespace std;
void displayString(char *p);

int main() 
{
	displayString("Hello to the world of C++ programming!");
}

void displayString(char *p)
{
    while(*p != '\0')
	{
	    cout<<*p;
	    p++;
	}
}