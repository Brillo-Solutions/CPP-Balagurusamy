#include <iostream>

using namespace std;

class Employee
{
    private:
        char name[30];
        float age;
    public:
        void getData(void);
        void putData(void);
};

void Employee::getData(void)
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
}

void Employee::putData(void)
{
    cout << "Name: " << name << endl;
    cout << "Age :" << age << endl;
}

const int size = 3;
int main() 
{
    Employee manager[size];
    for(int i = 0; i < size; i++)
    {
        cout << "Detials of manager: " << i + 1 << endl;
        manager[i].getData();
    }
    cout << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Manager: " << i + 1 << endl;
        manager[i].putData();
    }
    return 0;
}