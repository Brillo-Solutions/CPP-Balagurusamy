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
        float meanValue(Sample);
};

float Sample::meanValue(Sample sample)
{
    cout<<"Mean Value: "<<(sample.a + sample.b) / 2.0;
}

int main() 
{
    Sample sample;
    sample.setValue();
    sample.meanValue(sample);
    return 0;
}