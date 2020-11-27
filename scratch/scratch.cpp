#include <string>
#include <iostream>

using namespace std;

class Thing
{
    public:
        // int getLength()
        // {
        //     return (list.size);
        // }

    //private:
        int list[5];
};

Thing thg1;

double a[6];

int main() {
    
    cout << sizeof(thg1.list) << endl;

    return 0;
}




