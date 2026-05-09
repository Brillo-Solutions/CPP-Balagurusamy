#include <iostream>

using namespace std;

class Item
{
    private:
        int *p;   
    public:
        void setVal(int *, int);
        void getVal(int);
};

void Item::setVal(int arr[], int size)
{
    for(int i = 0; i <= size - 1; i++)
    {
        arr[i] = arr[i] + i;
    }
    p = arr;
}

void Item::getVal(int size)
{
    for(int i = 0; i <= size - 1; i++)
    {
        cout << *(p + i)<<" ";
    }
}

int main() 
{
    Item item;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    item.setVal(arr, 10);
    item.getVal(10);
    return 0;
}