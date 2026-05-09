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
            count++;                    // count is only one copy and is being shared by every object of class.
        }
        static void getCount(void)      // static function, it can access only static data members.
        {
            cout<<"Count: "<<count<<endl;
        }
};

int Item::count;                        // count is being initialized here automatically to zero when object of class is created 
                                        // (it has to be static member to do like that).

int main() 
{
    Item a, b, c;
    Item::getCount();                   // accessing static function of the class.
    Item::getCount();
    Item::getCount();
    
    a.getData(100);
    b.getData(200);
    c.getData(300);
    
    Item::getCount();
    Item::getCount();
    Item::getCount();
    return 0;
}