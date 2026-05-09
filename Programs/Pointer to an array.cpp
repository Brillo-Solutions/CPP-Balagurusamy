#include <iostream>
using namespace std;
#include <stdio.h>

int main () 
{
   /* an array with 5 elements */
   double balance[5] = {1,2,3,4,5};
   double *p;
   p = balance;
  
    for (int i=0;i<5;i++) 
    {
        cout<<*(p + i);
    }
    cout<<endl;
    for (int i=0;i<5;i++) 
    {
        cout<<*(balance + i);
    }
   return 0;
}