#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class String
{
    private:
        char *p;
        int len;
    public:
        String()
        {
            len = 0;
            p = 0;
        }
        String(const char *);
        String(const String &);
        friend String operator+(const String &, const String &);
        friend bool operator<=(const String &, const String &);
        friend bool operator==(const String &, const String &);
        friend bool operator<(const String &, const String &);
        friend void show(const String);
        String toLowerCase(void);
        String toUpperCase(void);
        int compareTo(const String &);
        int indexOf(const String);
        String concat(const String &);
        bool contains(const String);
        bool equals(const String &);
        String substring(int);
        String substring(int, int);
        bool startsWith(const String);
        bool endsWith(const String);
        int lastIndexOf(char);
        bool isEmpty(void);
        String replace(char, char);
        String reverse(void);
        char charAt(int);
        int length(void);
        static char *toString(int numToConvert)
        {
            static char tempBuffer[3];
            sprintf(tempBuffer, "%d", numToConvert);
            return tempBuffer;
        }
};

String::String(const char *s)
{
    len = strlen(s);
    p = (char *) calloc (len + 1, sizeof(char));
    strcpy(p, s);
}

String::String(const String & s)
{
    len = s.len;
    p = (char *) calloc (len + 1, sizeof(char));
    strcpy(p, s.p);
}

String operator+(const String & s1, const String & s2)
{
    String s3;
    s3.len = s1.len + s2.len;
    s3.p = (char *) calloc (s3.len + 1, sizeof(char));
    strcpy(s3.p, s1.p);
    strcat(s3.p, s2.p);
    return s3;
}

bool operator<=(const String & s1, const String & s2)
{
    int m = strlen(s1.p);
    int n = strlen(s2.p);
    if(m <= n)
        return true;
    else
        return false;
}

bool operator<(const String & s1, const String & s2)
{
    int m = strlen(s1.p);
    int n = strlen(s2.p);
    if(m < n)
        return true;
    else
        return false;
}

bool operator==(const String & s1, const String & s2)
{
    int r = strcmp(s1.p, s2.p);
    if(r == 0)
        return true;
    else
        return false;
}

bool String::equals(const String & s)
{
    int r = strcmp(p, s.p);
    if(r == 0)
        return true;
    else
        return false;
}

char String::charAt(int k)
{
    return *(p + k);
}

int String::length(void)
{
    return strlen(p);
}

bool String::contains(const String s)
{
    if(strstr(p, s.p))
        return true;
    else
        return false;
}

String String::toLowerCase(void)
{
    String s;
    s.len = len + 1;
    s.p = (char *) calloc (s.len + 1, sizeof(char));
    strcpy(s.p, p);
    for(int i = 0; i <= len - 1; i++)
        *(s.p + i) = tolower(*(s.p + i));
    return s;
}

String String::toUpperCase(void)
{
    String s;
    s.len = len + 1;
    s.p = (char *) calloc (s.len + 1, sizeof(char));
    strcpy(s.p, p);
    for(int i = 0; i <= len - 1; i++)
        *(s.p + i) = toupper(*(s.p + i));
    return s;
}

String String::concat(const String & s1)
{
    String s2;
    s2.len = len + s1.len;
    s2.p = (char *) calloc (s2.len + 1, sizeof(char));
    strcpy(s2.p, p);
    strcat(s2.p, s1.p);
    return s2;
}

int String::compareTo(const String & s1)
{
    int k = strcmp(p, s1.p);
    return k;
}

int String::indexOf(const String s)
{
    int i, j = 0, k;
    for(i = 0; i <= len - 1; i++)
    {
        if(*(p + i) == *(s.p + j))
        {
            j++;
            if(j == strlen(s.p))
            {
                k = i - j + 1;
                break;
            }
        }
        else
        {
            k = -1;
            j = 0;
        }
    }
    return k;
}

String String::substring(int n)
{
    String s;
    s.len = len - n;
    s.p = (char *) calloc (s.len + 1, sizeof(char));
    for(int i = n, j = 0; i <= len - 1; i++, j++)
        *(s.p + j) = *(p + i);
    return s;
}

String String::substring(int m, int n)
{
    String s;
    s.len = n - m;
    s.p = (char *) calloc (s.len + 1, sizeof(char));
    for(int i = m, j = 0; i < n; i++, j++)
        *(s.p + j) = *(p + i);
    return s;
}

bool String::startsWith(const String s)
{
    bool k;
    for(int i = 0; i <= s.len - 1; i++)
    {
        if(*(p + i) == *(s.p + i))
            k = true;
        else
        {
            k = false;
            break;
        }
    }
    return k;
}

bool String::endsWith(const String s)
{
    bool k;
    for(int i = len - 1, j = s.len - 1; i >= (len - s.len); i--, j--)
    {
        if(*(p + i) == *(s.p + j))
            k = true;
        else
        {
            k = false;
            break;
        }
    }
    return k;
}

bool String::isEmpty(void)
{
    int k = strlen(p);
    if(k > 0)
        return false;
    else
        return true;
}

int String::lastIndexOf(char j)
{
    int k = -1;
    for(int i = 0; i <= len - 1; i++)
    {
        if(*(p + i) == j)
            k = i;
    }
    return k;
}

String String::replace(char j, char k)
{
    String s;
    s.len = len + 1;
    s.p = (char *) calloc (s.len + 1, sizeof(char));
    strcpy(s.p, p);
    for(int i = 0; i <= len - 1; i++)
        if(*(s.p + i) == j)
            *(s.p + i) = k;
    return s;
}

String String::reverse(void)
{
    String s;
    s.len = len + 1;
    s.p = (char *) calloc (s.len + 1, sizeof(char));
    strcpy(s.p, p);
    char temp;
    int k = strlen(s.p) / 2;
    for(int i = strlen(s.p) - 1, j = 0; j < k; i--, j++)
    {
        temp = *(s.p + i);
        *(s.p + i) = *(s.p + j);
        *(s.p + j) = temp;
    }
    return s;
}

void show(const String s)
{
    cout<<s.p<<endl;
}

int main() 
{
    String s1 = "AT+CIPSEND=";
    String s2 = String::toString(107);
	show(s1 + s2);
}