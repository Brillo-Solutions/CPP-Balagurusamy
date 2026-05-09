#include <iostream>

using namespace std;

int main() 
{
const char *str[2] = {"Hello", " World"};
    for(int i = 0; i <= 1; i++)
    {
        cout<<*(str + i);
    }
}