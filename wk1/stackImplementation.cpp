/*************************************************
*   Author: Eric Johnson
*   Date 7/13/2020
*
*   Grantham University
*   CS325 Data Structures
*   Week 1 Assignment: Stack Implementation
*
*   Description:
*   This is the main program file, created per the 
*   assignment instructions.
****************************************************/

#include "webPage.h"
#include "linkedStack.h"

#include <iostream>
#include <cassert>
#include <string>

using namespace std;


//  Declare functions needed for main program...
void displayMenu();  // This function will display the main menu

int getMenuSelection();  // This function will get user menu selection

int menuSelection;  // This will hold the user's menu selection

linkedStack<webPage> webPages_back;  // This is the linked list stack that will hold the webPages for going back

linkedStack<webPage> webPages_forward;  // This will hold the stack for webPages going forward.

void getNewWebPageUserInput(webPage & newWebPage); // This function will be used when adding a new page to get user input

void listAllPages(linkedStack<webPage> webPages_back, linkedStack<webPage> webPages_forward);  
    // This function will list all the webPages from the forward and back stacks. 

void resetTheStacks(linkedStack<webPage> & resultingStack, linkedStack<webPage> & stackToEmpty);  
    //  This function will put all the visited pages on the back stack to prep for adding a new page. 

int main()
{
    displayMenu();

    menuSelection = getMenuSelection();


    while (menuSelection != 9){
        switch(menuSelection){
            case 1: {
                if(webPages_back.size() < 2) {
                    // Check to see if going back is possible, note that the top of the back stack is the current page in the history.

                    cout << endl << "No previous page in the history" << endl;
                    break;
                } 
                else{                           
                    webPages_forward.push(webPages_back.peek());  // Put current page into forward stack
                    webPages_back.pop();  // Remove the page from the back stack
                    
                    // Now print the new current page location:
                    cout << endl;
                    cout << "Current page: " << webPages_back.peek().getTitle();
                    cout << endl;
                    break;
                }
            }

            case 2: {
                if(webPages_forward.isEmptyStack()) {
                    // Check to see if going forward is possible

                    cout << endl << "There are not forward pages in the history. " << endl;
                    break;
                }
                else {
                    webPages_back.push(webPages_forward.peek());  // Put next page from forward stack on the back stack
                    webPages_forward.pop(); // Remove the page from the forward stack

                    // Now print the new current page location:
                    cout << endl;
                    cout << "Current page: " << webPages_back.peek().getTitle();
                    cout << endl;
                    break;
                }
            }

            case 3: {
                    listAllPages(webPages_back, webPages_forward);
                    break;
            }

            case 4: {
                resetTheStacks(webPages_back, webPages_forward); // Put all the visited pages on the back stack to add new page to top
                webPage newWebPage; // Creates a new webPage
                getNewWebPageUserInput(newWebPage);  // Gets user input for webPage properties
                webPages_back.push(newWebPage);  // Pushes the new webPage onto the stack.
                cout << "Page added. " << endl;
                break;
            }

            case 5: {
                if(!webPages_back.isEmptyStack()) {  // Check if back stack is empty
                    webPages_back.pop();
                    cout << "Page deleted." << endl;
                    break;
                }
                else    
                    cout << endl << "Nothing in History to delete." << endl;
                    break;
            }

            default:
                cout << "Invalid selection" << endl;
                break;
        }

        displayMenu();
        menuSelection = getMenuSelection();
    }

    cout << "Exiting the program..." << endl;

    return 0;
}

void displayMenu(){
    cout << endl << endl;
    cout << "MAIN MENU:" << endl;
    cout << "1. Go back" << endl;
    cout << "2. Go forward" << endl;
    cout << "3. List all pages" << endl;
    cout << "4. Add page" << endl;
    cout << "5. Delete page" << endl;
    cout << endl;
    cout << "9. Exit the program" << endl << endl;
}

int getMenuSelection(){
    int menuSelection;
    
    cout << "Please enter a numeric option from the menu: ";
    cin >> menuSelection;
    cout << endl;

    return menuSelection;
}

void getNewWebPageUserInput(webPage & newWebPage) {
    string title, description, url, dateAccessed; // declare temp variables to hold input
    
    cout << endl << "Please enter web page title: ";
    cin >> title;
    cout << endl << "Please enter web page description: ";
    getline(cin >> ws, description);
    cout << endl << "Please enter web page url: ";
    cin >> url;
    cout << endl << "Please enter web page date accessed: ";
    cin >> dateAccessed;

    newWebPage.setTitle(title);
    newWebPage.setDescription(description);
    newWebPage.setUrl(url);
    newWebPage.setDateAccessed(dateAccessed);
}

void listAllPages(linkedStack<webPage> webPages_back, linkedStack<webPage> webPages_forward) {
    if(webPages_back.isEmptyStack())  // Because the current page is the top of the back stack
        cout << endl << "The history is empty." << endl;
    else {
        resetTheStacks(webPages_forward, webPages_back);
                // This will reset the local stack copies into one stack for ordered output
                // Notice I've passed the arguments in reverse order so I can 
                // Pull the oldest page off first and print chronologically.

        while(!webPages_forward.isEmptyStack()) {
            // Because of the above order of parameters to the resetTheStacks call,
            // now everything is in the forward stack, ready to print from oldest 
            // to newest.

            cout << endl;
            cout << endl << "Page Title: " << webPages_forward.peek().getTitle();
            cout << endl << "Page Description: " << webPages_forward.peek().getDescription();
            cout << endl << "Page URL: " << webPages_forward.peek().getUrl();
            cout << endl << "Date Accessed: " << webPages_forward.peek().getDateAccessed();
            cout << endl;

            webPages_forward.pop();
        }
    }  
}

void resetTheStacks(linkedStack<webPage> & resultingStack, linkedStack<webPage> & stackToEmpty) {
    while(!stackToEmpty.isEmptyStack()) {
        resultingStack.push(stackToEmpty.peek());  // Copy top element of stackToEmpty to top of resultingStack
        stackToEmpty.pop();  // Delete the top element of the stackToEmpty
    }
}