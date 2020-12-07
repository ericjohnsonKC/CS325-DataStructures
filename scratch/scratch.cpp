#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

    ofstream theFile("players.txt");

    cout << "Enter players ID, Name, and Points" << endl;
    cout << "Ctl+Z to exit" << endl;

    int idNumber;
    string name;
    double points;

    while(cin >> idNumber >> name >> points){
        theFile << idNumber << ' ' << name << ' ' << points << endl;
    }

    return 0;

};