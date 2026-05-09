#include <iostream>

using namespace std;

struct marks
{
    int number;
    float sub[3];
};

int main() 
{
    struct marks student[2];
    student[0].sub[0] = 12;
    student[0].sub[1] = 56;
    student[0].sub[2] = 48;
    
    student[1].sub[0] = 78.5;
    student[1].sub[1] = 18.5;
    student[1].sub[2] = 58.5;
    
    for(int i = 0; i <= 1; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            cout<<student[i].sub[j]<<endl;
        }
    }
}