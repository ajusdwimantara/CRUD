#include <iostream>
#include <vector>
#include "user.h"
using namespace std;

// this is derived class from Request class
class Volunteer : public User
{
private:
    // Types and variables follow a given command
    string date_of_birth, occupation;
    int volunteer_data = 0;
    string username;
    string password;
    string fullname, email, phone;

public:
    // default constructor so we can init an empty object in main.cpp
    Volunteer()
    {
        User("", "", "", "", "");
        date_of_birth = "";
        occupation = "";
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

    // this code use to set the occupation to the variable
    void setOccupation(string newOccupation)
    {
        occupation = newOccupation;
    }

    // this code use to set the date of birth to the variable
    void setDOB(string newDOB)
    {
        date_of_birth = newDOB;
    }

    // this Code use to return occupation
    string getOccupation()
    {
        return occupation;
    }

    // this Code use to return date of birth
    string getDOB()
    {
        return date_of_birth;
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
};