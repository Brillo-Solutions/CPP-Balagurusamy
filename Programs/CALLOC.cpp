#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() 
{
    int size;
    cout<<"Enter size of array"<<endl;
    cin>>size;
     int *arr = (int *) calloc (size, sizeof(int));
     for(int i = 0; i <= size - 1; i++)
     {
         cin >> arr[i];
     }
     for(int i = 0; i <= size - 1; i++)
     {
         cout << arr[i];
     }
}
