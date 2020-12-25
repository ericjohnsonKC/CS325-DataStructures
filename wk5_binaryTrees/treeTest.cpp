/*************************************
*   Author: Eric Johnson
*   Date: 12/23/2020
*
*   Grantham University
*   CS325 Data Structures
* 
*   Week 5 Assignment
*   Binary Search Trees
*
*   This file is the test file for the 
*   week 5 assignement
*************************************/

#include "binarySearchTree.h"
#include "computer.h"

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

void displayTime();  // This displays the local date and time

bSearchTree<computer> computers;  //This structure will hold all the computers

void checkIfFileExists();   //This will check if the text file already exists
                            //and create it if it doesn't.  If the file does exist,
                            //it will read the contents into tree.
void readFile(); //This function will read the text file.

void displayMenu(); //This function displays the main menu
int menuSelection;  //This value holds the user entered menu selection
int getMenuSelection(); //This functions prompts user to enter selection and returns it.
void processMenuSelection(int menuSelection); //This function runs the code corresponding to the selected menu option.
void addNewComputer(); //This functin adds a new computer to stock.
void removeSoldComputer(); //This function removes a sold computer from stock.
void listAllComputers();  //This function lists all computers in stock.
void appendToTextFile(computer &computer);  //This function will append a computer to the text file.
void printToScreen(computer &computer);  //This functions prints a computer's info to the screen.

//***********************MAIN PROGRAM***************************************************
int main (){
    
    displayTime();

    checkIfFileExists();
    
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

void checkIfFileExists(){
    ifstream txtFile;
    txtFile.open("computers.txt");
    bool txtFileExists = false;
    if(txtFile){
        txtFileExists = true;
    }
    txtFile.close();    
    if(txtFileExists){
        readFile();        
       
    }else{
        ofstream textFile;
        textFile.open("computers.txt");
        textFile.close();
    }

}

void readFile(){
    ifstream txtFile;
    txtFile.open("computers.txt");
    
    string info;
    while(getline(txtFile, info, ',')){
        computer computer;
        computer.setStockCode(stoi(info));
        getline(txtFile, info, ',');
        computer.setName(info);
        getline(txtFile, info, ',');
        computer.setOperatingSystem(info);
        getline(txtFile, info, ',');
        computer.setHardDrive(info);
        getline(txtFile, info, ',');
        computer.setRam(info);
        getline(txtFile, info);
        computer.setPrice(stoi(info));

        computers.insert(computer);
    }

    txtFile.close();
}

void displayMenu(){
    cout << endl << endl;
    cout << "###### MAIN MENU ######" << endl;
    cout << "1. Add new computer" << endl;
    cout << "2. Remove a sold computer" << endl;
    cout << "3. List all computers in stock" << endl;
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
                addNewComputer();
                break;
            case 2:
                removeSoldComputer();
                break;
            case 3:
                listAllComputers();
                break;
            default:
                cout << "Invalid menu selection." << endl;
                break;
        }
        displayMenu();
        menuSelection = getMenuSelection();
    }
}

void addNewComputer(){
    cout << "Adding new computer..." << endl;
    string tempString;
    computer computer;

    cout << "Enter computer details:" << endl;
    cout << "Stock code: ";
    getline(cin, tempString);
    computer.setStockCode(stoi(tempString));
    cout << "Computer name: ";
    getline(cin, tempString);
    computer.setName(tempString);
    cout << "Operating system: ";
    getline(cin, tempString);
    computer.setOperatingSystem(tempString);
    cout << "Hard drive: ";
    getline(cin, tempString);
    computer.setHardDrive(tempString);
    cout << "RAM: ";
    getline(cin, tempString);
    computer.setRam(tempString);
    cout << "Price (Enter as an integer of cents): ";
    getline(cin, tempString);
    computer.setPrice(stoi(tempString));

    computers.insert(computer);

    ofstream textFile("computers.txt", ios::app);
    textFile    << computer.getStockCode() << ","
                << computer.getName() << ","
                << computer.getOperatingSystem() << ","
                << computer.getHardDrive() << ","
                << computer.getRam() << ","
                << computer.getPrice() << endl;
    textFile.close();
}

void removeSoldComputer(){
    cout << "Removing sold computer from stock..." << endl;
    string stockCode;
    computer computer;
    
    cout << "Enter stock code of computer to remove: ";
    getline(cin, stockCode);
    computer.setStockCode(stoi(stockCode));

    computers.deleteNode(computer);

    ofstream textFile;
    textFile.open("computers.txt", ios::trunc);
    textFile.close();
    
    ofstream txtFile;
    txtFile.open("computers.txt");

    computers.inorderTraversal(appendToTextFile);
}

void appendToTextFile(computer &computer){
    ofstream textFile("computers.txt", ios::app);
    textFile    << computer.getStockCode() << ","
                << computer.getName() << ","
                << computer.getOperatingSystem() << ","
                << computer.getHardDrive() << ","
                << computer.getRam() << ","
                << computer.getPrice() << endl;
    textFile.close();
}

void listAllComputers(){
    cout << "Listing all computers in stock..." << endl;

    computers.inorderTraversal(printToScreen);
}

void printToScreen(computer &computer){
    cout << endl;
    cout << "Stock code: " << computer.getStockCode() << endl;
    cout << "Computer name: " << computer.getName() << endl;
    cout << "Operating system: " << computer.getOperatingSystem() << endl;
    cout << "Hard drive: " << computer.getHardDrive() << endl;
    cout << "RAM: " << computer.getRam() << endl;
    cout << "Price (as an integer of cents): " << computer.getPrice() << endl;
}