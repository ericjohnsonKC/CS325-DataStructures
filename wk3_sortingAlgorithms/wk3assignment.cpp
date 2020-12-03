/*********************************
*   Author: Eric Johnson
*   Date: 11/30/2020
*
*   Grantham University
*   CS325 Data Structures
*
*   Week 3: Sorting Algorithms
*   
*   This is file will test implementation of 
*   insertion sort on a linked list.
**************************************/

#include "queueUsingArray.h"
#include "book.h"

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>


using namespace std;

void displayTime();  // This displays the local date and time

queueUsingArray<Book> books;  //This  will hold the books
int bookListSize = 0;

void checkIfFileExists();   //This will check if the text file already exists
                            //and create it if it doesn't.  If the file does exist,
                            //it will read the contents into the linked list.

int displayMenu(); // This will display the main menu and return selection

int menuSelection;

void addBook();
void removeBook(queueUsingArray<Book> &books);
void removeAllBooks();
void sortBooks();

int main(){   

    displayTime();

    checkIfFileExists();

    menuSelection = displayMenu(); 

    while(menuSelection != 9){
        switch(menuSelection){
                case 1 : 
                    addBook();
                    break;
                case 2 : 
                    removeBook(books);
                    break;
                case 3 : 
                    removeAllBooks();
                    break;
                case 4 : 
                    sortBooks();
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

void displayTime(){
    time_t now = time(0);

    char *dt = ctime(&now);

    cout << "The local date and time is: " << dt << endl;
}

void checkIfFileExists(){
    ifstream txtFile;
    txtFile.open("books.txt");
    bool txtFileExists = false;
    if(txtFile){
        txtFileExists = true;
    }
    txtFile.close();    
    if(txtFileExists){
        ifstream txtFile;
        txtFile.open("booksl.txt");
        while(txtFile.good()){
            Book book;
            string info;
            getline(txtFile, info, ',');
            book.setAuthor(info);
            getline(txtFile, info, ',');
            book.setTitle(info);
            getline(txtFile, info, ',');
            book.setPublisher(info);
            getline(txtFile, info, ',');
            book.setDescription(info);
            getline(txtFile, info, ',');
            book.setIsbn(info);
            getline(txtFile, info, ',');
            book.setYearPublished(info);

            books.enQueue(book);
            bookListSize++;
        }

    }else{
        ofstream textFile;
        textFile.open("books.txt");
        textFile.close();
    }

}

int displayMenu(){

    cout << endl << endl;
    cout << "Main Menu:" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Remove a book" << endl;
    cout << "3. Remove all books" << endl;
    cout << "4. Sort the books" << endl;
    cout << "9. Exit the program" << endl << endl;

    string tempStr;  // Will temporarily hold string input before converting to type int
    int menuSelection;
    
    cout << "Please enter a numeric option from the menu: ";
    getline(cin, tempStr);
    menuSelection = stoi(tempStr);  // Convert user input to type int
    cout << endl;

    return menuSelection;
}

void addBook(){
    cout << "Adding a new book to the list:" << endl;

    Book book; //Create book object
    string input; //Temp variable to hold user input
    
    cout << "Enter author: ";
    getline(cin, input);
    book.setAuthor(input);
    cout << "Enter title: ";
    getline(cin, input);
    book.setTitle(input);
    cout << "Enter publisher: ";
    getline(cin, input);
    book.setPublisher(input);
    cout << "Enter description: ";
    getline(cin, input);
    book.setDescription(input);
    cout << "Enter ISBN: ";
    getline(cin, input);
    book.setIsbn(input);
    cout << "Enter year of publication: ";
    getline(cin, input);
    book.setYearPublished(input);

    books.enQueue(book);
    bookListSize++;

    ofstream textFile("books.txt", ios::app);
    textFile    << book.getAuthor() << ","
                << book.getTitle() << ","
                << book.getPublisher() << ","
                << book.getDescription() << ","
                << book.getIsbn() << ","
                << book.getYearPublished() << endl;
    textFile.close();
}

void removeBook(queueUsingArray<Book> &books){
    cout << "Removing book from the list...";

    books.deQueue();
    bookListSize--;

    queueUsingArray<Book> booksCopy(books);

    ofstream txtFile;
    txtFile.open("books.txt");

    for(int i = bookListSize; i > 0; i--){
        txtFile << booksCopy.peek().getAuthor() << ","
                << booksCopy.peek().getTitle() << ","
                << booksCopy.peek().getPublisher() << ","
                << booksCopy.peek().getDescription() << ","
                << booksCopy.peek().getIsbn() << ","
                << booksCopy.peek().getYearPublished() << endl;

        booksCopy.deQueue();
    }

}

void removeAllBooks(){
    cout << "removing all books";
}

void sortBooks(){
    cout << "sorting books";
}