#include <iostream>

using namespace std;

struct stores getName(struct stores);

struct stores
{
    const char *name;
};

int main() 
{
    struct stores s;
    s = getName(s);
    cout<<s.name;
}

struct stores getName(struct stores s)
{
    s.name = "Flipkart";
    return s;
}