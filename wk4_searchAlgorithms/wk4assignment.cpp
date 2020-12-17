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

int menuSelection;  //This will hold user's menu selection

void addBook();  //Adds a book to the list and to the books.txt file
void removeBook();  //Removes a book from the list and the books.txt file
void removeAllBooks();  //Removes all books from the list and the books.text file
void sortBooks();  //Sorts books in alphabetical order by author
template <class T>
    void insertionSort(T list[], int length);  //This will perform the insertion sort algorithm
void readFile(); //This function will read the text file.
void searchByAuthor();
template <class T>
int searchAuthor(T list[], int length, string &item);
void searchByTitle();
template <class T>
int searchTitle(T list[], int length, string &item);
void searchByIsbn();
template <class T>
int searchIsbn(T list[], int length, string &item);

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
                    removeBook();
                    break;
                case 3 : 
                    removeAllBooks();
                    break;
                case 4 : 
                    sortBooks();
                    break;
                case 5 : 
                    searchByAuthor();
                    break;
                case 6 :
                    searchByTitle();
                    break;
                case 7 : 
                    searchByIsbn();
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
        readFile();        
       
    }else{
        ofstream textFile;
        textFile.open("books.txt");
        textFile.close();
    }

}

void readFile(){
    ifstream txtFile;
    txtFile.open("books.txt");
    
    string info;
    while(getline(txtFile, info, ',')){
        Book book;
        book.setAuthor(info);
        getline(txtFile, info, ',');
        book.setTitle(info);
        getline(txtFile, info, ',');
        book.setPublisher(info);
        getline(txtFile, info, ',');
        book.setDescription(info);
        getline(txtFile, info, ',');
        book.setIsbn(info);
        getline(txtFile, info);
        book.setYearPublished(info);

        books.enQueue(book);
        bookListSize++;
    }

    txtFile.close();
}

int displayMenu(){

    cout << endl << endl;
    cout << "Main Menu:" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Remove a book" << endl;
    cout << "3. Remove all books" << endl;
    cout << "4. Sort the books" << endl;
    cout << "5. Search by author" << endl;
    cout << "6. Search by title" << endl;
    cout << "7. Search by ISBN" << endl;
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

void removeBook(){
    cout << "Removing book from the list...";

    books.deQueue();
    bookListSize--;

    queueUsingArray<Book> booksCopy;

    ofstream txtFile;
    txtFile.open("books.txt");

    for(int i = bookListSize; i > 0; i--){
        txtFile << books.peek().getAuthor() << ","
                << books.peek().getTitle() << ","
                << books.peek().getPublisher() << ","
                << books.peek().getDescription() << ","
                << books.peek().getIsbn() << ","
                << books.peek().getYearPublished() << endl;

        booksCopy.enQueue(books.peek());
        books.deQueue();
    }
    txtFile.close();

    for(int i = bookListSize; i > 0; i--){
        books.enQueue(booksCopy.peek());
        booksCopy.deQueue();
    }    
}

void removeAllBooks(){
    cout << "Removing all books: ";

    for(int i = bookListSize; i > 0; i--){
        books.deQueue();
        bookListSize--;
    }  

    ofstream textFile;
    textFile.open("books.txt", ios::trunc);
    textFile.close();
}

void sortBooks(){
    cout << "Sorting books...";

    Book *tempArray;
    tempArray = new Book[bookListSize];

    for(int i = 0; i < bookListSize; i++){  //This will put books in an array of exact size of the list
        tempArray[i] = books.peek();        //for sorting.
        books.deQueue();
    }

    insertionSort(tempArray, bookListSize);

    for(int i = 0; i < bookListSize; i++){
        books.enQueue(tempArray[i]);
    }

    queueUsingArray<Book> booksCopy;

    ofstream txtFile;
    txtFile.open("books.txt");

    for(int i = bookListSize; i > 0; i--){
        txtFile << books.peek().getAuthor() << ","
                << books.peek().getTitle() << ","
                << books.peek().getPublisher() << ","
                << books.peek().getDescription() << ","
                << books.peek().getIsbn() << ","
                << books.peek().getYearPublished() << endl;

        booksCopy.enQueue(books.peek());
        books.deQueue();
    }
    txtFile.close();

    for(int i = bookListSize; i > 0; i--){
        books.enQueue(booksCopy.peek());
        booksCopy.deQueue();
    }
}

template <class T>
void insertionSort(T list[], int length){
    for(int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
        if(list[firstOutOfOrder].getAuthor() < list[firstOutOfOrder - 1].getAuthor()){
            T temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;

            do{
                list[location] = list[location - 1];
                location--;
            }
            while(location > 0 && list[location - 1].getAuthor() > temp.getAuthor());

            list[location] = temp;
        }
}

void searchByAuthor(){
    string key;
    int result;

    cout << "Enter the author you want to search for: ";
    getline(cin, key);
    cout << endl;

    cout << "Searching books..." << endl << endl;

    Book *tempArray;
    tempArray = new Book[bookListSize];

    for(int i = 0; i < bookListSize; i++){  //This will put books in an array of exact size of the list
        tempArray[i] = books.peek();        //for searching.
        books.deQueue();
    }

    result = searchAuthor(tempArray, bookListSize, key);

    for(int i = 0; i < bookListSize; i++){
        books.enQueue(tempArray[i]);
    }

    if(result == -1){
        cout << "The author was not found." << endl;
    }else{
        cout << "Author: " << tempArray[result].getAuthor() << endl;
        cout << "Title: " << tempArray[result].getTitle() << endl;
        cout << "Publisher: " << tempArray[result].getPublisher() << endl;
        cout << "Description: " << tempArray[result].getDescription() << endl;
        cout << "ISBN: " << tempArray[result].getIsbn() << endl;
        cout << "Year published: " << tempArray[result].getYearPublished() << endl << endl;
    }
}

template <class T>
int searchAuthor(T list[], int length, string &item){

    int loc;
    bool found = false;

    loc = 0;

    while(loc < length && !found)
        if(list[loc].getAuthor() == item)
            found = true;
        else
        {
            loc++;
        }
    if(found)
        return loc;
    else 
        return -1;      
}
        
void searchByTitle(){
    string key;
    int result;

    cout << "Enter the title you want to search for: ";
    getline(cin, key);
    cout << endl;

    cout << "Searching books..." << endl << endl;

    Book *tempArray;
    tempArray = new Book[bookListSize];

    for(int i = 0; i < bookListSize; i++){  //This will put books in an array of exact size of the list
        tempArray[i] = books.peek();        //for searching.
        books.deQueue();
    }

    result = searchTitle(tempArray, bookListSize, key);

    for(int i = 0; i < bookListSize; i++){
        books.enQueue(tempArray[i]);
    }

    if(result == -1){
        cout << "The title was not found." << endl;
    }else{
        cout << "Author: " << tempArray[result].getAuthor() << endl;
        cout << "Title: " << tempArray[result].getTitle() << endl;
        cout << "Publisher: " << tempArray[result].getPublisher() << endl;
        cout << "Description: " << tempArray[result].getDescription() << endl;
        cout << "ISBN: " << tempArray[result].getIsbn() << endl;
        cout << "Year published: " << tempArray[result].getYearPublished() << endl << endl;
    }
}

template <class T>
int searchTitle(T list[], int length, string &item){
 
    int loc;
    bool found = false;

    loc = 0;

    while(loc < length && !found)
        if(list[loc].getTitle() == item)
            found = true;
        else
        {
            loc++;
        }
    if(found)
        return loc;
    else 
        return -1;      
}

void searchByIsbn(){
   
    string key;
    int result;

    cout << "Enter the ISBN you want to search for: ";
    getline(cin, key);
    cout << endl;

    cout << "Searching books..." << endl << endl;

    Book *tempArray;
    tempArray = new Book[bookListSize];

    for(int i = 0; i < bookListSize; i++){  //This will put books in an array of exact size of the list
        tempArray[i] = books.peek();        //for searching.
        books.deQueue();
    }

    result = searchIsbn(tempArray, bookListSize, key);

    for(int i = 0; i < bookListSize; i++){
        books.enQueue(tempArray[i]);
    }

    if(result == -1){
        cout << "The ISBN was not found." << endl;
    }else{
        cout << "Author: " << tempArray[result].getAuthor() << endl;
        cout << "Title: " << tempArray[result].getTitle() << endl;
        cout << "Publisher: " << tempArray[result].getPublisher() << endl;
        cout << "Description: " << tempArray[result].getDescription() << endl;
        cout << "ISBN: " << tempArray[result].getIsbn() << endl;
        cout << "Year published: " << tempArray[result].getYearPublished() << endl << endl;
    }
}

template <class T>
int searchIsbn(T list[], int length, string &item){
 
    int loc;
    bool found = false;

    loc = 0;

    while(loc < length && !found)
        if(list[loc].getIsbn() == item)
            found = true;
        else
        {
            loc++;
        }
    if(found)
        return loc;
    else 
        return -1;      
}