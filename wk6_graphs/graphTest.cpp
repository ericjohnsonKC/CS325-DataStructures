/*****************************************
 *  Author: Eric Johnson
 *  Date: 12/26/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 * 
 *  Week 6: Graphs
 * 
 *  This file is a test file for the graph assighment.
 * ******************************************/

#include "graph.h"
#include "member.h"

#include <iostream>
#include <ctime>
#include <string>

graphType graph; //this graph will hold all of the member ID's

void displayTime();  // This displays the local date and time
void displayMenu(); //This function displays the main menu
int menuSelection;  //This value holds the user entered menu selection
int getMenuSelection(); //This functions prompts user to enter selection and returns it.
void processMenuSelection(int menuSelection); //This function runs the code corresponding to the selected menu option.

void addMember();
void deleteMember();
void addFriend();
void listFriends();

//***********************MAIN PROGRAM***************************************************
int main (){
    
    displayTime();

    displayMenu();

    menuSelection = getMenuSelection();

    processMenuSelection(menuSelection);

    cout << "Exiting the program..." << endl;
    
    return 0;
}
//*******************END MAIN PROGRAM***********************************************


void displayTime(){
    time_t now = time(0);

    char *dt = ctime(&now);

    cout << "The local date and time is: " << dt << endl;
}

void displayMenu(){
    cout << endl << endl;
    cout << "###### MAIN MENU ######" << endl;
    cout << "1. Add member" << endl;
    cout << "2. Delete member" << endl;
    cout << "3. Add friend" << endl;
    cout << "4. List friends" << endl;
    cout << "9. Exit the program" << endl;
    cout << endl;
}

int getMenuSelection(){
    string menuSelection;

    cout << "Please enter an number corresponding to a menu option: ";
    getline(cin, menuSelection);
    cout << endl;

    return stoi(menuSelection);
}

void processMenuSelection(int menuSelection){
    while(menuSelection != 9){
        switch(menuSelection){
            case 1:
                addMember();
                break;
            case 2:
                deleteMember();
                break;
            case 3:
                addFriend();
                break;
            case 4:
                listFriends();
                break;
            default:
                cout << "Invalid menu selection." << endl;
                break;
        }
        displayMenu();
        menuSelection = getMenuSelection();
    }
}

void addMember(){
    cout << "Adding member..." << endl;
}

void deleteMember(){
    cout << "Deleting member..." << endl;
}

void addFriend(){
    cout << "Adding friend..." << endl;
}

void listFriends(){
    cout << "Listing friends..." << endl;
}