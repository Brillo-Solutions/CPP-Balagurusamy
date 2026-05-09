#include <iostream>

using namespace std;

class Item
{
    private:
        int number;
        float cost;
    public:
        void getData(int, float);
        void putData(void);
};

void Item::getData(int a, float b)
{
    number = a;
    cost = b;
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
    item.putData();
    return 0;
}