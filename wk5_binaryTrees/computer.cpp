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
*   This file is the implementation file for the 
*   computer class
*************************************/

#include "computer.h"

#include <string>

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