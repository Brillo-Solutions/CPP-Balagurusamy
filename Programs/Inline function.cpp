#include <iostream>
void displayData(int, float);
using namespace std;

int main() 
{
    displayData(20, 60.5);
    return 0;
}

void inline displayData(int a, float b)
{
    cout<<a<<", "<<b;
}