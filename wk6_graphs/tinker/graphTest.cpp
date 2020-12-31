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

#include "myGraphType.h"
#include "member.h"
#include "binarySearchTree.h"

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

graphType graph; //this graph will hold all of the member ID's
bSearchTree<member> memberSet; //This will hold all member objects

void displayTime();  // This displays the local date and time
void displayMenu(); //This function displays the main menu
int menuSelection;  //This value holds the user entered menu selection
int getMenuSelection(); //This functions prompts user to enter selection and returns it.
void processMenuSelection(int menuSelection); //This function runs the code corresponding to the selected menu option.

void addMember();
void deleteMember();
void addFriend();
void listFriends();

void findFriends(int &memberID);
void printFriend(member &currentMember);

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

    member newMember;
    string tempString;

    cout << "Member ID: ";
    getline(cin, tempString);
    newMember.memberID = stoi(tempString);
    cout << "Name: ";
    getline(cin, tempString);
    newMember.name = tempString;
    cout << "Gender: ";
    getline(cin, tempString);
    newMember.gender = tempString;
    cout << "Status: ";
    getline(cin, tempString);
    newMember.status = tempString;

    graph.addVertex();
    memberSet.insert(newMember);
}

void deleteMember(){
    cout << "Deleting member..." << endl;
    string tempString;

    cout << "Enter member ID to delete: ";
    getline(cin, tempString);

    graph.removeVertex();
    member newMember;
    newMember.memberID = graph.numOfVertices;
    memberSet.deleteNode(newMember);
}

void addFriend(){
    cout << "Adding friend..." << endl;
    int member1, member2;
    string tempString;

    cout << "Enter member ID for which to add friend: ";
    getline(cin, tempString);
    member1 = stoi(tempString);
    cout << "Enter member ID of friend to add: ";
    getline(cin, tempString);
    member2 = stoi(tempString);
    graph.addEdge(member1 -1, member2 - 1);
}

void listFriends(){
    cout << "Listing friends..." << endl;
    string tempString;
    int memberID;

    cout << "Enter member ID to list friends of: ";
    getline(cin, tempString);
    memberID = stoi(tempString);
    graph.traverseAdjacencyList(memberID - 1, findFriends);

}

void findFriends(int &memberID){
    member newMember;
    newMember.memberID = memberID + 1;
    memberSet.inorderTraversal(printFriend, newMember);
}

void printFriend(member &currentMember){
    cout << endl;
    cout << "Friend member ID: " << currentMember.memberID << endl;
    cout << "Friend name: " << currentMember.name << endl;
    cout << "Friend gender: " << currentMember.gender << endl;
    cout << "Friend status: " << currentMember.gender << endl;
}