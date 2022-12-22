// to call the other headers you have created
// and ends with #endif
#ifndef schoolAdmin_HEADER
#define schoolAdmin_HEADER

#include <iostream>
#include "user.h"

using namespace std;

// forward declaration of type class School
class School;

// this is derived class from User class
class SchoolAdmin : public User
{
protected:
    // Administraror data
    string position;
    int staff_id;

    string username;
    string password;
    string fullname, email, phone;

    // as each schooladmin has their own school, we need to store a reference to the school
    School *thisSchool;

public:
    // SchoolAdmin default constructor so we can init an empty object for main.cpp
    SchoolAdmin()
    {
        User(username, password, "", "", "");
        position = "";
        staff_id = 0;
    }

    // this code use to set the school name to the variable
    void setSchool(School &school)
    {
        thisSchool = &school;
    }

    // getter for the school reference
    School &getSchool()
    {
        return *thisSchool;
    }

    // this code use to set the username to the variable
    void setUsername(string newUsername)
    {
        username = newUsername;
    }

    // this code use to set the password to the variable
    void setPassword(string newPassword)
    {
        password = newPassword;
    }

    // this code use to set the full name to the variable
    void setFullname(string newFullname)
    {
        fullname = newFullname;
    }

    // this code use to set the email to the variable
    void setEmail(string newEmail)
    {
        email = newEmail;
    }

    // this code use to set the phone to the variable
    void setPhone(string newPhone)
    {
        phone = newPhone;
    }

    // this code use to set the position to the variable
    void setPosition(string newPosition)
    {
        position = newPosition;
    }

    // this code use to set the staff ID to the variable
    void setStaffID(int newId)
    {
        staff_id = newId;
    }

    // this Code use to return position
    string getPosition()
    {
        return position;
    }

    // this Code use to return staff ID
    int getStaffID()
    {
        return staff_id;
    }

    // this Code use to return username
    string getUsername()
    {
        return username;
    }

    // this Code use to return password
    string getPassword()
    {
        return password;
    }

    // this Code use to return full name
    string getFullname()
    {
        return fullname;
    }

    // function to add data school admin
    void addSCHadmin()
    {
        cout << "Enter Staff ID\t: ";
        cin >> staff_id;

        cout << "Enter Position\t: ";
        cin >> position;
    }
};
#endif