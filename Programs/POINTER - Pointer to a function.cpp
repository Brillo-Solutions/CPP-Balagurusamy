#include <iostream>
using namespace std;

void bubbleSort(int*a, int size, bool(*comp)(int, int))
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if((*comp)(a[j],a[j+1]))
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                
            }
        }
    }
}

void print(int*a, int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
bool comp1(int x, int y)
{
    return(x<y);
}
bool comp2(int x,int y)
{
    return(x>y);
}
int main()
{
    int arr[10] = {3,1,8,11,21,89,32,4,65,2};
    bubbleSort(arr,10,comp1);
    print(arr,10);
    int arr1[10] = {3,1,8,11,21,89,32,4,65,2};
    bubbleSort(arr1,10,comp2);
    print(arr1,10);
    
}