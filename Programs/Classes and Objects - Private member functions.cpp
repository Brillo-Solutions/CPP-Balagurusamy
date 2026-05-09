#include <iostream>

using namespace std;

class Item
{
    private:
        int number;
        float cost;
        void putData(void);
    public:
        void getData(int, float);
};

void Item::getData(int a, float b)
{
    number = a;
    cost = b;
    putData();
}
    
void Item::putData(void)
{
    cout<<"Number: "<<number<<endl;
    cout<<"Cost: "<<cost;
}

int main() 
{
    Item item;
    item.getData(34, 78);
    return 0;
}