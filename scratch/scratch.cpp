#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream myFile;
    myFile.open("example.txt");
    myFile << "Writing this to a file.\n";
    myFile << "Line number two.\n";
    myFile << "Line number three.\n";
    myFile.close();

    fstream myFile2;
    myFile2.open("example2.txt");
    myFile2 << "test test\n";
    myFile2.close();
    
    return 0;
}





