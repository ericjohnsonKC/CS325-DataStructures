/*********************************
*   Author: Eric Johnson
*   Date: 11/30/2020
*
*   Grantham University
*   CS325 Data Structures
*
*   Week 3: Sorting Algorithms
*   
*   This is a header file for a custom book object class.
**************************************/

#include "book.h"

#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void displayTime();
void checkIfFileExists();
void readFile();
void displayMenu();
int menuSelection;
int getMenuSelection();
void processMenuSelection(int menuSelection);
void addBook();
void removeBook();
void writeToFile();
void removeAllBooks();
void searchByAuthor();
void searchByIsbn();

vector<book> books;

//**************************MAIN PROGRAM**********************************************
int main(){
 
    displayTime();

    checkIfFileExists();
    
    displayMenu();

    menuSelection = getMenuSelection();

    processMenuSelection(menuSelection);

    cout << "Exiting the program..." << endl;
    

    return 0;
}
//********************END MAIN PROGRAM*****************************************

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
    txtFile.open("books.txt");
    
    string info;
    while(getline(txtFile, info, ',')){
        book book;
        book.author = info;
        getline(txtFile, info, ',');
        book.title = info;
        getline(txtFile, info, ',');
        book.publisher = info;
        getline(txtFile, info, ',');
        book.description = info;
        getline(txtFile, info, ',');
        book.isbn = info;
        getline(txtFile, info);
        book.yearPublished = info;

        books.push_back(book);
    }

    txtFile.close();
}

void displayMenu(){
    cout << endl;
    cout << "********MAIN MENU**********" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Remove a book" << endl;
    cout << "3. Remove all books" << endl;
    cout << "4. Search by author" << endl;
    cout << "5. Search by ISBN" << endl; 
    cout << "9. Exit the program" << endl << endl;
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
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                removeAllBooks();
                break;
            case 4:
                searchByAuthor();
                break;
            case 5: 
                searchByIsbn();
                break;
            default:
                cout << "Invalid menu selection." << endl;
                break;
        }
        displayMenu();
        menuSelection = getMenuSelection();
    }
}

void addBook(){
    cout << "Adding a new book to the list..." << endl;

    book book; //Create book object
    string input; //Temp variable to hold user input
    
    cout << "Enter author: ";
    getline(cin, input);
    book.author = input;
    cout << "Enter title: ";
    getline(cin, input);
    book.title = input;
    cout << "Enter publisher: ";
    getline(cin, input);
    book.publisher = input;
    cout << "Enter description: ";
    getline(cin, input);
    book.description = input;
    cout << "Enter ISBN: ";
    getline(cin, input);
    book.isbn = input;
    cout << "Enter year of publication: ";
    getline(cin, input);
    book.yearPublished = input;

    books.push_back(book);
    
    ofstream textFile("books.txt", ios::app);
    textFile    << book.author << ","
                << book.title << ","
                << book.publisher << ","
                << book.description << ","
                << book.isbn << ","
                << book.yearPublished << endl;
    textFile.close();
}

void removeBook(){
    cout << "Enter the title to remove from the list: ";
    string searchTitle;
    getline(cin, searchTitle);

    int location;
    bool found;

    location = 0;

    while(location < books.size() && !found)
        if(books[location].title == searchTitle)
            found = true;
        else
            location++;
    
    if(found){
        books.erase(books.begin() + location);
        writeToFile();
    }
    else
        cout << "Title not found in the collection." << endl;
        
}

void writeToFile(){
    ofstream txtFile;
    txtFile.open("books.txt");

    for(int i =0; i < books.size(); i++){
        txtFile << books[i].author << ","
                << books[i].title << ","
                << books[i].publisher << ","
                << books[i].description << ","
                << books[i].isbn << ","
                << books[i].yearPublished << endl;
    }
    txtFile.close();
}

void removeAllBooks(){
    cout << "Removing all books from the list..." << endl;

    books.clear(); 

    ofstream textFile;
    textFile.open("books.txt", ios::trunc);
    textFile.close();
}

void searchByAuthor(){
    cout << "Searching by author..." << endl;

    cout << "Enter the author to search for: ";
    string searchAuthor;
    getline(cin, searchAuthor);

    int location;
    bool found;

    location = 0;

    while(location < books.size() && !found)
        if(books[location].author == searchAuthor)
            found = true;
        else
            location++;
    
    if(found){
       cout << endl << "Author found.  Details: " << endl << endl;
       cout << "Author: " << books[location].author << endl;
       cout << "Title: " << books[location].title << endl;
       cout << "Publisher: " << books[location].publisher << endl;
       cout << "Description: " << books[location].description << endl;
       cout << "ISBN: " << books[location].isbn << endl;
       cout << "Year of publication: " << books[location].yearPublished << endl << endl;
    }
    else
        cout << "Title not found in the collection." << endl << endl;
}

void searchByIsbn(){
    cout << "Searching by ISBN..." << endl;

    cout << "Enter the ISBN to search for: ";
    string searchIsbn;
    getline(cin, searchIsbn);

    int location;
    bool found;

    location = 0;

    while(location < books.size() && !found)
        if(books[location].isbn == searchIsbn)
            found = true;
        else
            location++;
    
    if(found){
       cout << endl << "ISBN found.  Details: " << endl << endl;
       cout << "Author: " << books[location].author << endl;
       cout << "Title: " << books[location].title << endl;
       cout << "Publisher: " << books[location].publisher << endl;
       cout << "Description: " << books[location].description << endl;
       cout << "ISBN: " << books[location].isbn << endl;
       cout << "Year of publication: " << books[location].yearPublished << endl << endl;
    }
    else
        cout << "Title not found in the collection." << endl << endl;
}