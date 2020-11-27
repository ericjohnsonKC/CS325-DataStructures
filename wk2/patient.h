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
 *  This file will create a patient class as objects to store in a queue.
 * ***********************************/

#ifndef patient_h
#define patient_h

#include <string>

using namespace std;

class Patient{
    public:
        void setFirstName(string &patientFirstName);
            // Sets the patient's firstName

        string getFirstName();
            // Returns the patient's firstName

        void setLastName(string &patientLastName);
            // Sets the patient's lastName

        string getLastName();
            // Returns the patient's lastName

        void setTypeOfInsurance(string &patientTypeOfInsurance);
            // Sets the patient's typeOfInsurance

        string getTypeOfInsurance();
            // Returns the patient's typeOfInsurance

        void setSsn(int patientSsn);
            // Sets the patient's ssn

        int getSsn();
            // Returns the patient's ssn

        void setAddress(string patientAddress);
            // Sets the patient's address

        string getAddress();
            // Returns the patient's address

        void setDateOfVisit(string patientDateOfVisit);
            // Sets the patient's dateOfVisit

        string getDateOfVisit();
            // Returns the patient's dateOfVisit

    private:
        string firstName;
        string lastName;
        string typeOfInsurance;
        int ssn;
        string address;
        string dateOfVisit;

};

void Patient::setFirstName(string &patientFirstName){
    firstName = patientFirstName;
}
    
string Patient::getFirstName(){
    return firstName;
}

void Patient::setLastName(string &patientLastName){
    lastName = patientLastName;
}

string Patient::getLastName(){
    return lastName;
}

void Patient::setTypeOfInsurance(string &patientTypeOfInsurance){
    typeOfInsurance = patientTypeOfInsurance;
}

string Patient::getTypeOfInsurance(){
    return typeOfInsurance;
}

void Patient::setSsn(int patientSsn){
    ssn = patientSsn;
}

int Patient::getSsn(){
    return ssn;
}

void Patient::setAddress(string patientAddress){
    address = patientAddress;
}

string Patient::getAddress(){
    return address;
}

void Patient::setDateOfVisit(string patientDateOfVisit){
    dateOfVisit = patientDateOfVisit;
}

string Patient::getDateOfVisit(){
    return dateOfVisit;
}

#endif