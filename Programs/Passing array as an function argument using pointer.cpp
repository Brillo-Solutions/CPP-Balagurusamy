#include<iostream>
using namespace std;
/* function declaration */
double getAverage(int *, int);

int main ()
{
   /* an int array with 5 elements */
   int balance[5] = {10, 20, 30, 40, 50};

   /* pass pointer to the array as an argument */
   cout<<getAverage(balance, 5) ;
   /* output the returned value */
   return 0;
}

double getAverage(int *p, int size)
{
   int i;
   double sum = 0;
   for (i = 0; i < size; ++i)
   {
      sum += *(p + i);
   }
   return sum / size;
}