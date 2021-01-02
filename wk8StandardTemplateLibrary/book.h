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

struct book{
    std::string author;
    std::string title;
    std::string publisher;
    std::string description;
    std::string isbn;
    std::string yearPublished;
};

#endif