#include <iostream>
#include <string.h>

using namespace std;

struct Books 
{
   char title[50];
   int id;
}; 
int main( )
{
    struct Books b1 = {"Microchip's PIC", 1}; // Initialize structure members.
    struct Books b2 = {"Atmel's AVR", 2};
    cout<<b1.id<<": "<<b1.title<<endl;
    cout<<b2.id<<": "<<b2.title<<endl;
}