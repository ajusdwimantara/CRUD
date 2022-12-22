// to call the other headers you have created
// and ends with #endif
#ifndef user_HEADER
#define user_HEADER
#include <iostream>
#include <vector>
using namespace std;

// This is class User for this code
class User
{
protected:
    // Administraror data
    string username, password, fullname, email, phone;
    int userdata = 0;
    vector<User> user[10];

public:
    // Constructor with arguments for Class User
    User(string username, string password, string fullname, string email, string phone)
    {
        username = username;
        password = password;
        fullname = fullname;
        email = email;
        phone = phone;
    }

    // default constructor
    User()
    {
        username = "";
        password = "";
        fullname = "";
        email = "";
        phone = "";
    }

    // Setter code
    void setUsername(string username)
    {
        username = username;
    }
    void setPassword(string password)
    {
        password = password;
    }
    void setFullname(string fullname)
    {
        fullname = fullname;
    }
    void setEmail(string email)
    {
        email = email;
    }
    void setPhone(string phone)
    {
        phone = phone;
    }

    // This function use to input all user needs
    void addUser()
    {
        User *temp = new User();

        cout << "Enter Username\t: ";
        cin >> temp->username;

        cout << "Enter Password\t: ";
        cin >> temp->password;

        cout << "Enter Full Name\t: ";
        cin >> fullname;
        getline(cin, temp->fullname);

        cout << "Enter Email\t: ";
        cin >> temp->email;

        cout << "Enter Phone\t: ";
        cin >> temp->phone;

        user[userdata].push_back(*temp);

        userdata += 1;
        delete temp;
    }
};
#endif