#include <iostream>
#include <stdio.h>

using namespace std;

int main() 
{
    char city[5][15] = {"Patiala", "Ambala", "Rajpura", "Chandigarh", "Amritsar"};
    for(int j=0; j<=4; j++)
    {
        for(int k=0; city[j][k]!=NULL; k++)
        {
            cout<<city[j][k];
        }
        cout<<endl;
    }
}