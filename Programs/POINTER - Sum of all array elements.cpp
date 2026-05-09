#include <iostream>

using namespace std;

int main() 
{
	int v[] = {100,200,300,400,500};
	int *p;
	int sum = 0;
	p = v;
	for(int i=0; i<=4; i++)
	{
	    sum = sum + *(p + i);
	}
	cout<<sum;
}