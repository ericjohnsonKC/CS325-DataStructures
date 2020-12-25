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
*   This file is a header file that defines a class for 
*   computer objects.
*************************************/

#ifndef computer_h  
#define computer_h

#include <string>

class computer {
    public:
        void setStockCode(int stockCode);
            //Sets the stockCode of the computer
        int getStockCode() const;
            //Returns the stockCode of the computer
        void setName(std::string name);
            //Sets the name of the computer
        std::string getName() const;
            //Returns the name of the computer
        void setOperatingSystem(std::string operatingSystem);
            //Sets the operatingSystem of the computer
        std::string getOperatingSystem() const;
            //Returns the operatingSystem of the computer
        void setHardDrive(std::string hardDrive);
            //Sets the hardDrive of the computer
        std::string getHardDrive() const;
            //Returns the hardDrive of the computer
        void setRam(std::string ram);
            //Sets the ram of the computer
        std::string getRam() const;
            //Returns the ram of the computer
        void setPrice(int price);
            //Sets the price of the computer
        int getPrice() const;
            //Returns the price of the computer
        computer();
            //Default constructor
        computer(int stockCode, std::string name, std::string operatingSystem,
                        std::string hardDrive, std::string ram, int price);
            //Constructor with parameters
        const computer &operator=(const computer&);
            //Overloads the assignment operator
        bool operator==(const computer &computer) const;
            //Overloads the comparison operator   
        bool operator>(const computer &computer) const;
            //Overloads the comparison operator

    private:
        int stockCode;
        std::string name;
        std::string operatingSystem;
        std::string hardDrive;
        std::string ram;
        int price;  //Price is stored as an integer of cents.
};

void computer::setStockCode(int stockCode){
    this->stockCode = stockCode;
}

int computer::getStockCode() const{
    return this->stockCode;
}

void computer::setName(std::string name) {
    this->name = name;
}

std::string computer::getName() const{
    return this->name;
}

void computer::setOperatingSystem(std::string operatingSystem){
    this->operatingSystem = operatingSystem;
}

std::string computer::getOperatingSystem() const {
    return this->operatingSystem;
}

void computer::setHardDrive(std::string hardDrive) {
    this->hardDrive = hardDrive;
}

std::string computer::getHardDrive() const {
    return this->hardDrive;
}

void computer::setRam(std::string ram) {
    this->ram = ram;
}

std::string computer::getRam() const {
    return this->ram;
}

void computer::setPrice(int price) {
    this->price = price;
}

int computer::getPrice() const {
    return this->price;
}

computer::computer(){
    this->stockCode = 0;
    this->name = "";
    this->operatingSystem = "";
    this->hardDrive = "";
    this->ram = "";
    this->price = 0;
}

computer::computer(int stockCode, std::string name, std::string operatingSystem,
                        std::string hardDrive, std::string ram, int price){
    this->stockCode = stockCode;
    this->name = name;
    this->operatingSystem = operatingSystem;
    this->hardDrive = hardDrive;
    this->ram = ram;
    this->price = price;
}

const computer &computer::operator=(const computer &otherComputer){
    if(this != &otherComputer){ //Avoid a self copy
        stockCode = otherComputer.stockCode;
        name = otherComputer.name;
        operatingSystem = otherComputer.operatingSystem;
        hardDrive = otherComputer.hardDrive;
        ram = otherComputer.ram;
        price = otherComputer.price;
    }
    return *this;
}

bool computer::operator==(const computer &otherComputer) const {
    return (stockCode == otherComputer.stockCode);
}

bool computer::operator>(const computer &otherComputer) const {
    return (stockCode > otherComputer.stockCode);
}
#endif 