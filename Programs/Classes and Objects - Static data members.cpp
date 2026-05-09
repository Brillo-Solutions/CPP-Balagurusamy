#include <iostream>

using namespace std;

class Item
{
    private:
        static int count;
        int number;
    public:
        void getData(int a)
        {
            number = a;
            count++;            // count is being shared by every object of class.
        }
        void getCount(void)
        {
            cout<<"Count: "<<count<<endl;
        }
};

int Item::count;                // count is being initialized here automatically to zero when object of class is created 
                                // (it has to be static member to do like that).

int main() 
{
    Item a, b, c;
    a.getCount();
    b.getCount();
    c.getCount();
    
    a.getData(100);
    b.getData(200);
    c.getData(300);
    
    a.getCount();
    b.getCount();
    c.getCount();
    return 0;
}