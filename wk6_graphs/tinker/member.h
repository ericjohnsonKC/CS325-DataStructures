/*****************************************
 *  Author: Eric Johnson
 *  Date: 12/26/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 * 
 *  Week 6: Graphs
 * 
 *  This file is a struct header for a member object
 *  as required by the assignment instructions.
 * ******************************************/

#ifndef member_H
#define member_H
#include <string>

class member{
        public:
                int memberID;
                std::string name;
                std::string gender;
                std::string status;
                const member & operator = (const member &);
                bool operator==(const member &otherMember) const;
                bool operator>(const member &otherMember) const;
};

const member &member::operator = (const member & otherMember){
        if(this != &otherMember){
                memberID = otherMember.memberID;
                name = otherMember.name;
                gender = otherMember.gender;
                status = otherMember.status;
        }
        return *this;
}

bool member::operator == (const member &otherMember) const {
        return (memberID == otherMember.memberID);
}

bool member::operator > (const member &otherMember) const {
        return (memberID > otherMember.memberID);
}

#endif