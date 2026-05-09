#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() 
{
    int size;
    cout<<"Enter the size of array for dynamic allocation!"<<endl;
    cin>>size;
    int *arr;
    void *ptr = (void *) malloc (size *sizeof(int));
//    int *arr = (int *) malloc (size *sizeof(int)); // Activate this line and deactivate line 13, 14 and 16.
    arr = (int *)ptr;
    for(int i=0; i<=size-1;i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<=size-1;i++)
    {
        cout<<arr[i];
    }
}