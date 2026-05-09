#include <iostream>

using namespace std;

class Sample
{
    private:
        int a, b;
    public:
        void setValue(void)
        {
            a = 25;
            b = 40;
        }
        friend float meanValue(Sample);
};

float meanValue(Sample sample)
{
    return (sample.a + sample.b) / 2.0;
}

int main() 
{
    Sample sample;
    sample.setValue();
    cout<<"Mean value: "<<meanValue(sample)<<endl;
    return 0;
}


Language Version:  GCC 7.2.0