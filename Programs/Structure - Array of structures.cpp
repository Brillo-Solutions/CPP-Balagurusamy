#include <iostream>

using namespace std;

struct Books 
{
   const char *title;
   int id;
}; 
int main( )
{
    struct Books b[3];
    b[0].id = 1;
    b[0].title = "PIC";
    b[1].id = 2;
    b[1].title = "AVR";
    b[2].id = 3;
    b[2].title = "8051";
    for(int i = 0; i <= 2; i++)
    {
        cout<<b[i].id<<": ";
        cout<<b[i].title<<endl;
    }
}