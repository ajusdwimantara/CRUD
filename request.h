// to call the other headers you have created
// and ends with #endif
#ifndef request_HEADER
#define request_HEADER

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

// This is class Request for this code
class Request
{
    // protected is used to make it accessible to derived classes.
    protected:
    // Types and variables follow a given command
    int requestID;
	string requestDate,requestStatus,requestDesc, requestTime;
    int request_data = 0;
    string student_level;
    int n_student;
    
    public:
    bool seen = false;
    // default constructor for Request class
    Request()
    {
        requestID = 0;
        requestDate = "";
        requestStatus = "";
        requestDesc = "";

    }
    // this code use to set the request date to the variable
    void setRequestDate(string newDate)
    {
        // this code use to auto generate date and time
        time_t Today = time(0);
		string Date = ctime(&Today);
		requestDate = Date;
    }
    // this code use to set the request time to the variable
    void setRequestTime(string newTime)
    {
        requestTime = newTime;
    }
    // this code use to set the request status to the variable
    void setRequestStatus(string newStatus)
    {
        requestStatus = newStatus;
    }
    // this code use to set the request description to the variable
    void setRequestDesc(string newDesc)
    {
        requestDesc = newDesc;
    }
    // this code use to set the student level to the variable
    void setStudentLevel(string newStudentLevel)
    {
        student_level = newStudentLevel;
    }
    // this code use to set the number student to the variable
    void setNumStudent(int newNumStudents)
    {
        n_student = newNumStudents;
    }
    // this code use to set the request ID to the variable
    void setRequestID()
	{
        // this code is to generate random number
		srand(time(0));
		requestID = rand();
	}

    // this Code use to return request date
    string getRequestDate()
    {
        return requestDate;
    }
    // this Code use to return request time
    string getRequestTime()
    {
        return requestTime;
    }
    // this Code use to return request status
    string getRequestStatus()
    {
        return requestStatus;
    }
    // this Code use to return request description
    string getRequestDesc()
    {
        return requestDesc;
    }
    // this Code use to return student level
    string getStudentLevel()
    {
        return student_level;
    }
    // this Code use to return number student
    int getNumStudent()
    {
        return n_student;
    }
    // this Code use to return request ID
    int getRequestID()
    {
        return requestID;
    }
};
#endif