#include <iostream>
using namespace std;
int *getData();
int main () 
{
   int *p;
   int i;
   p = getData();
   for (i = 0; i <=3; i++)
   {
      cout<<*(p + i);
   }
   return 0;
}

int *getData() 
{
    static int r[4] = {1,2,3,4};
    return r;
}