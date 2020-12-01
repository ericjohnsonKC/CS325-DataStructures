/************************************
 *  Author: Eric Johnson
 *  Date:   11/17/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 *  Week 2: Queues
 * 
 *  This assignment is to create a queue data structure
 *  given the instructions.
 * 
 *  This file is a test file to implement the queue class using the custom patient objects.
 * ***********************************/

#include "queueUsingArray.h"
#include "patient.h"

#include <iostream>
#include <string>

using namespace std;

// Declare functions needed for main program:

queueUsingArray<Patient> waitingQueue;  // This is the queue that will hold patients

Patient currentPatient;

Patient prevPatient;

int displayMenu();  // This will display the main menu and return selection

int menuSelection;

void addPatient(); // Adds a pateint to the queue

void nextPatient(); // Outputs the next patient to the console

void previousPatient(); // Outputs the previous patient to the console

void deletePatient(); // Deletes the next patient from the queue

void viewCurrentPatient(); // Outputs the current patient to the console


int main(){

   menuSelection = displayMenu(); 

   while(menuSelection != 9){
       switch(menuSelection){
            case 1 : 
                addPatient();
                break;
            case 2 : 
                nextPatient();
                break;
            case 3 : 
                previousPatient();
                break;
            case 4 : 
                deletePatient();
                break;
            case 5 : 
                viewCurrentPatient();
                break;
            default:
                cout << "Invalid selection" << endl;
                break;
       }

       menuSelection = displayMenu();
    }

    cout << "Exiting the program..." << endl << endl;

    return 0;
}

int displayMenu(){

    cout << endl << endl;
    cout << "Main Menu:" << endl;
    cout << "1. Add patient" << endl;
    cout << "2. Next patient" << endl;
    cout << "3. Previous patient" << endl;
    cout << "4. Delete patient" << endl;
    cout << "5. View current patient" << endl;
    cout << "9. Exit the program" << endl << endl;

    string tempStr;  // Will temporarily hold string input before converting to type int
    int menuSelection;
    
    cout << "Please enter a numeric option from the menu: ";
    getline(cin, tempStr);
    menuSelection = stoi(tempStr);  // Convert user input to type int
    cout << endl;

    return menuSelection;
}

void addPatient(){
    string firstName, lastName, typeOfInsurance, ssnString, address, dateOfVisit;
    int ssn;  // Declare variables to hold patient info

    cout << "Enter patient's first name: ";
    getline(cin, firstName);
    cout << endl;
    cout << "Enter patient's last name: ";
    getline(cin, lastName);
    cout << endl;
    cout << "Enter patient's type of insurance: ";
    getline(cin, typeOfInsurance);
    cout << endl;
    cout << "Enter patient's SSN: ";
    getline(cin, ssnString);
    ssn = stoi(ssnString);
    cout << endl;
    cout << "Enter patient's address: ";
    getline(cin, address);
    cout << endl;
    cout << "Enter date of visit: ";
    getline(cin, dateOfVisit);
    cout << endl;

    Patient patient(firstName, lastName, typeOfInsurance, ssn, address, dateOfVisit);  
        //creates a patient object

    waitingQueue.enQueue(patient);
        // Adds the patient to the queue

    cout << "Patient added to the waiting list." << endl << endl;
    
}

void nextPatient(){
    prevPatient = currentPatient;
    currentPatient = waitingQueue.peek();
    waitingQueue.deQueue();

    cout << "The next patient is now being seen." << endl << endl;
}

void previousPatient(){
    cout << "Previous patient: " << endl;
    cout << "First name: " << prevPatient.getFirstName() << endl;
    cout << "Last name: " << prevPatient.getLastName() << endl;
    cout << "Type of insurance: " << prevPatient.getTypeOfInsurance() << endl;
    cout << "SSN: " << prevPatient.getSsn() << endl;
    cout << "Address: " << prevPatient.getAddress() << endl;
    cout << "Date of visit: " << prevPatient.getDateOfVisit() << endl << endl;
}

void deletePatient(){
    waitingQueue.deQueue();

    cout << "The next patient has been removed from the waiting list." << endl << endl;
}

void viewCurrentPatient(){
    cout << "Current patient: " << endl;
    cout << "First name: " << currentPatient.getFirstName() << endl;
    cout << "Last name: " << currentPatient.getLastName() << endl;
    cout << "Type of insurance: " << currentPatient.getTypeOfInsurance() << endl;
    cout << "SSN: " << currentPatient.getSsn() << endl;
    cout << "Address: " << currentPatient.getAddress() << endl;
    cout << "Date of visit: " << currentPatient.getDateOfVisit() << endl << endl;
}