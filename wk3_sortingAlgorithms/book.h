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

#ifndef book_h
#define book_h

#include <string>

using namespace std;

class Book{
    public:
        void setAuthor(string &author);
            //Sets the author
        string getAuthor();
            //Returns the author
        void setTitle(string &title);
            //Sets the title
        string getTitle();
            //Returns the title
        void setPublisher(string &publisher);
            //Sets the publisher
        string getPublisher();
            //Returns the publisher
        void setDescription(string &description);
            //Sets the description
        string getDescription();
            //Returns the description
        void setIsbn(string &isbn);
            //Sets the isbn
        string getIsbn();
            //Gets the isbn
        void setYearPublished(string yearPublished);
            //Sets the year published
        string getYearPublished();
            //Gets the year published
        Book(const string &author = "", const string &title = "", const string &publisher = "", const string &description = "", const string &isbn = "", const string &yearPublished = "");
            //Constructor

    private:
        string author;
        string title;
        string publisher;
        string description;
        string isbn;
        string yearPublished;
};

void Book::setAuthor(string &author){
    this->author = author;
}

string Book::getAuthor(){
    return author;
}
void Book::setTitle(string &title){
    this->title = title;
}

string Book::getTitle(){
    return title;
}

void Book::setPublisher(string &publisher){
    this->publisher = publisher;
}
    
string Book::getPublisher(){
    return publisher;
}
  
void Book::setDescription(string &description){
    this->description = description;
}
   
string Book::getDescription(){
    return description;
}

void Book::setIsbn(string &isbn){
    this->isbn = isbn;
}
   
string Book::getIsbn(){
    return isbn;
}
  
void Book::setYearPublished(string yearPublished){
    this->yearPublished = yearPublished;
}

string Book::getYearPublished(){
    return yearPublished;
}

Book::Book(const string &author, const string &title, const string &publisher, const string &description, const string &isbn, const string &yearPublished){
    this->author = author;
    this->title = title;
    this->publisher = publisher;
    this->description = description;
    this->isbn = isbn;
    this->yearPublished = yearPublished;
}

#endif