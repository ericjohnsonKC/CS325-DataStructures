/*************************************************
*   Author: Eric Johnson
*   Date 7/13/2020
*
*   Grantham University
*   CS325 Data Structures
*   Week 1 Assignment: Stack Implementation
*
*   Description:
*   This is the main program file, created per the 
*   assignment instructions.
****************************************************/

#include "webPage.h"

#include <iostream>

using namespace std;


//  Declare functions needed for main program...
void displayMenu();

int getMenuSelection();

int menuSelection;

int main()
{
    displayMenu();

    menuSelection = getMenuSelection();


    while (menuSelection != 9){
        switch(menuSelection){
            case 1:
                cout << "Going back" << endl;
                break;
            case 2:
                cout << "Going forward" << endl;
                break;
            case 3:
                cout << "Listing all pages" << endl;
                break;
            case 4:
                cout << "Adding page" << endl;
                break;
            case 5:
                cout << "Deleting page" << endl;
                break;
            default:
                cout << "Invalid selection" << endl;
                break;
        }

        displayMenu();
        menuSelection = getMenuSelection();
    }

    cout << "Exiting the program..." << endl;

    return 0;
}

void displayMenu(){
    cout << endl << endl;
    cout << "MAIN MENU:" << endl;
    cout << "1. Go back" << endl;
    cout << "2. Go forward" << endl;
    cout << "3. List all pages" << endl;
    cout << "4. Add page" << endl;
    cout << "5. Delete page" << endl;
    cout << endl;
    cout << "9. Exit the program" << endl << endl;
}

int getMenuSelection(){
    int menuSelection;
    
    cout << "Please enter a numeric option from the menu: ";
    cin >> menuSelection;
    cout << endl;

    return menuSelection;
}