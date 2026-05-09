#include <iostream>

using namespace std;

class ABC;

class XYZ
{
    private:
        int x;
    public:
        void setValue(int i)
        {
            x = i;
        }
        friend void swap(XYZ, ABC);
};

class ABC
{
    private:
        int a;
    public:
        void setValue(int i)
        {
            a = i;
        }
        friend void swap(XYZ, ABC);
};

void swap(XYZ m , ABC n)
{
    int temp;
    cout<<"Before swap ABC.a: "<<n.a<<endl;
    cout<<"Before swap XYZ.x: "<<m.x<<endl;
    temp = m.x;
    m.x = n.a;
    n.a = temp;
    cout<<"Before swap ABC.a: "<<n.a<<endl;
    cout<<"Before swap XYZ.x: "<<m.x;
}

int main() 
{
	ABC abc;
	XYZ xyz;
	abc.setValue(40);
	xyz.setValue(30);
	swap(xyz, abc);
	return 0;
}
