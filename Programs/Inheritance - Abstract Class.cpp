#include <iostream>

using namespace std;

class AbstractClass
{
    protected:
        int j, k;
    public:
        virtual int getData() = 0;
        void setData(int x, int y)
        {
            j = x;
            k = y;
        }
};

class Addition: public AbstractClass
{
    private:
        int n;
    public:
        int getData()
        {
            n = j + k;
            return n;
        }
};

class Multiply: public AbstractClass
{
    private:
        int m;
    public:
        int getData()
        {
            m = j * k;
            return m;
        }
};

int main() 
{
    Multiply mply;
    Addition add;
    //AbstractClass ac; // Cannot declare variable 'ac' to be of abstract type 'AbstractClass'
    mply.setData(10, 10);
    add.setData(10, 10);
    cout<<mply.getData()<<endl;
    cout<<add.getData();
}
