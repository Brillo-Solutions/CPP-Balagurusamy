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
        void display(void)
        {
            cout<<x<<endl;
        }
        friend void swap(XYZ &, ABC &);
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
        void display(void)
        {
            cout<<a<<endl;
        }
        friend void swap(XYZ &, ABC &);
};

void swap(XYZ & m , ABC & n)
{
    int temp;
    temp = m.x;
    m.x = n.a;
    n.a = temp;
}

int main() 
{
	ABC abc;
	XYZ xyz;
	abc.setValue(40);
	xyz.setValue(30);
	cout<<"Before swapping: "<<endl;
	xyz.display();
	abc.display();
	swap(xyz, abc);
	cout<<"After swapping: "<<endl;
 	xyz.display();
 	abc.display();
	return 0;
}
