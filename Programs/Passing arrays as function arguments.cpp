#include <stdio.h>
/* function declaration */
double getAverage(int arr[], int size);

int main () 
{
   /* an int array with 5 elements */
   int *p,balance[5] = {1000, 2, 3, 17, 50};
    p = balance;
   double avg;
   /* pass pointer to the array as an argument */
   avg = getAverage(p, 5);
   /* output the returned value */
   cout<<avg;
   return 0;
}

double getAverage(int arr[], int size) 
{
   int i;
   double avg;
   double sum = 0;
   for (i = 0; i < size; ++i) 
   {
      sum += arr[i];
   }
   avg = sum / size;
   return avg;
}