#include <iostream>

using namespace std;
void stat(void);

int main()                  
{
    extern int y;   // extern will still access a variable even if variable is declared later (as y).
    cout<<y<<endl;
    stat();
}
int y = 8;
void stat()
{
    y = y + 1;
    cout<<y;
}