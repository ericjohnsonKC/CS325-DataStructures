/*********************************
*   Author: Eric Johnson
*   Date: 7/13/2020
*
*   Grantham University
*   CS325 Data Structures
*   
**************************************/

#ifndef webpage_h
#define webpage_h

#include <string>

using namespace std;


class webPage
{
    public:
        string getTitle() const;
            // Returns title.
        
        string getDescription() const;
            // Returns description.

        string getUrl() const;
            // Returns url.

        string getDateAccessed() const;
            // Returns dateAccessed.

        void setTitle(const string & title);
            // Sets title.
        
        void setDescription(const string & description);
            // Sets description.

        void setUrl(const string & url);
            // Set url.

        void setDateAccessed(const string & dateAccessed);
            // Set dateAccessed.
        
        webPage(const string & title = "", const string & description = "", const string & url = "", const string & dateAccessed = "");
            // Default constructor.


    private:
        string title;
        string description;
        string url;
        string dateAccessed;
};

/*****************************************
*   The class function definitions follow.
******************************************/

string webPage::getTitle() const {
    return title;
}

string webPage::getDescription() const {
    return description;
}

string webPage::getUrl() const {
    return url;
}

string webPage::getDateAccessed() const {
    return dateAccessed;
}

void webPage::setTitle(const string & title) {
    this->title = title;
}
        
void webPage::setDescription(const string & description) {
    this->description = description;
}

void webPage::setUrl(const string & url) {
    this->url = url;
}

void webPage::setDateAccessed(const string & dateAccessed) {
    this->dateAccessed = dateAccessed;
}

webPage::webPage(const string & title, const string & description, const string & url, const string & dateAccessed) {
    this->title = title;
    this->description = description;
    this->url = url;
    this->dateAccessed = dateAccessed;
}

#endif