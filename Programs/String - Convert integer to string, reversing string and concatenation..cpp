#include<iostream>
#include<string.h>
using namespace std;

void revString(char *stringToReverse)
{
    char temp;
    int j = 0;
    int k = strlen(stringToReverse) / 2;
    for(int i = strlen(stringToReverse) - 1; j < k; i--, j++)
    {
        temp = *(stringToReverse + i);
        *(stringToReverse + i) = *(stringToReverse + j);
        *(stringToReverse + j) = temp;
    }
}

char *toString(int numToConvert)
{
    static char tempBuffer[3];
    int incLoc = 0;
    while(numToConvert)
    {
        int splitNumber = numToConvert % 10;
        numToConvert = numToConvert / 10;

        char formedCharacter = splitNumber + 48;
        tempBuffer[incLoc] = formedCharacter;
        incLoc++;
    }
    revString(tempBuffer);
    return tempBuffer;
}

int main()
{
    char myString[] = "AT+CIPSEND=";
    int targetNumber = 98;
    strcat(myString, toString(targetNumber));
    cout<<myString;
}