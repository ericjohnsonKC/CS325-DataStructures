#include "binarySearchTree.h"
#include "computer.h"

#include <iostream>

using namespace std;

bSearchTree<computer> computers;

int main(){
    
    computer comp1(3, "name1", "os1", "hd1", "ram1", 101);
    computer comp2(2, "name2", "os2", "hd2", "ram2", 102);

    computers.insert(comp1);
    computers.insert(comp2);

    cout << "comp1 name: " << comp1.getName() << endl;

    if(comp1 == comp2)
        cout << "They have equal stockCodes" << endl;
    else
        cout << "They don't have equal stockCodes" << endl;
    
    if(comp1 > comp2)
        cout << "comp1 is greater than comp2" << endl;
    else
    {
        cout << "comp1 is not greater than comp2" << endl;
    }
    

    computer comp3;
    comp3 = comp1;
    cout << "comp3: " << endl;
    cout << comp3.getStockCode() << endl
         << comp3.getName() << endl;
    
    
    return 0;
}