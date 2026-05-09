#include <iostream>
#define NUMBER 10                   // Declaring name to a constant.
#define SQUARE(x) (x*x)             // Declaring function using macro.
#define CUBE(x) (SQUARE(x)*x)       // Nesting of function in macro.
#define MAX(a,b) (a>b)?a:b          // Writing if comparator using macro.
using namespace std;

int main() 
{
    cout<<SQUARE(NUMBER)<<endl;     // Calling square.
    cout<<CUBE(NUMBER)<<endl;       // Calling cube which in turn calling square.
    #ifdef MAX                      // If MAX macro is defined above then code in #ifdef and #endif will be executed else false.
    //#undef MAX                    // #undef will undefine MAX macro (make this line active to see result).
    cout<<MAX(55,45);               // Returns 1 if a > b else returns 0. 
    #endif
    return 0;
}
