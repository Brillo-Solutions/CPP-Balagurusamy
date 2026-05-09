#include <iostream>

using namespace std;
void stat(void);
int main() 
{
    for(int i = 1; i <= 3; i++)
    {
        stat();
    }
}
void stat()
{
    static int x = 0; // static will keep current value of x alive even if function terminates.
    x++;
    cout<<"x = "<<x<<endl;
}