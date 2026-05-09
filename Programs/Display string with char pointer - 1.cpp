#include <iostream>

using namespace std;

int main() 
{
   char *p, arr[] = "Hello world";
   int i;
   p = arr;
	for(i = 0; *(p + i)!='\0' ; i++)
	{
                cout<<*(p + i);
	}
}
