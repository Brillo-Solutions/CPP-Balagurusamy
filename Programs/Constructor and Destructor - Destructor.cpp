#include <iostream>

using namespace std;

class M
{
    public:
        M()
        {
            cout<<"Object created"<<endl;
        }
        ~M()
        {
            cout<<"Object destroyed"<<endl;
        }
};

int main() 
{
    cout<<"Enter main."<<endl;
    M m1, m2, m3, m4;
    {
        cout<<"Entered block 1st."<<endl;
        M m5;
    }
    {
        cout<<"Entered block 2nd."<<endl;
        M m6;
    }
    cout<<"Re-enter main."<<endl;
    return 0;
}