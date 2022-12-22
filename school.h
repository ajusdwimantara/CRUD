#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

#include "schoolAdmin.h"
#include "request.h"

using namespace std;

// This is class School for this code
class School
{
private:
    // Types and variables follow a given command
    string schoolName;
    string address;
    string city;
    int schoolId;
    int school_data = 0;

public:
    // make these public
    SchoolAdmin schoolAdmin_;
    vector<Request*> request_;

    // default constructor for School class
    School()
    {
    }

    // this code use to set the school name to the variable
    void setSchoolName(std::string name)
    {
        schoolName = name;
    }
    // this code use to set the address to the variable
    void setSchoolAddress(std::string newAddress)
    {
        address = newAddress;
    }
    // this code use to set the school city to the variable
    void setSchoolCity(std::string newCity)
    {
        city = newCity;
    }
    // this code use to set the school ID to the variable
    void setSchoolID(int newSchoolId)
    {
        schoolId = newSchoolId;
    }

    // this Code use to return school name
    string getSchoolName()
    {
        return schoolName;
    }
    // this Code use to return address
    string getSchoolAddress()
    {
        return address;
    }
    // this Code use to return city
    string getSchoolCity()
    {
        return city;
    }
    // this Code use to return school ID
    int getSchoolID()
    {
        return schoolId;
    }

    // to add new school admin to the school
    void addSchoolAdmin(SchoolAdmin *newSchoolAdmin)
    {
        schoolAdmin_ = *newSchoolAdmin;
    }
    // to add request 
    void addRequest(Request *newRequest)
    {
        request_.push_back(newRequest);
    }

    // get the whole vector of school admins
    SchoolAdmin getSchoolAdmins()
    {
        return schoolAdmin_;
    }
    // to get all request data
    void getRequest()
    {
        for(int i=0; i<request_.size(); i++)
        {
            if(!request_[i]->seen)
            {
                cout<<"Description: "<<request_[i]->getRequestDesc()<<"\n";
                cout<<"Status: "<<request_[i]->getRequestStatus()<<"\n";
                cout<<"Student level: "<<request_[i]->getStudentLevel()<<"\n";
                cout<<"Capacity: "<<request_[i]->getNumStudent()<<"\n";
                request_[i]->seen = true;
            }
            
        }
    }
    // to reset the value of seen so that we can print the offer again
    void reset()
    {
        for(int i=0;i<request_.size();i++)
        {
            request_[i]->seen = false;
        }
    }
};