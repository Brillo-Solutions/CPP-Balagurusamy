#include <iostream>
using namespace std;

struct stores
{
    int num ;
    const char *name;
};

int main() 
{
    struct stores *p, s = {1, ". Flipkart"};
    p = &s;
    cout<<(*p).num; // or p->num
    cout<<p->name;  // or (*p).name
}