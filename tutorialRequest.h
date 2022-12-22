#include <iostream>
#include "request.h"
using namespace std;

// this is derived class from Request class
class TutorialRequest : public Request
{
    private:
    // Types and variables follow a given command
    string propDate,propTime,studentLevel;
    int numStudent;

    public:
    // default constructor for TutorialRequest class
    TutorialRequest()
    {
        propDate = "";
        propTime = "";
        studentLevel = "";
        numStudent = 0;
    }
    // this code use to set the proposed date to the variable
    void setPropDate(string newPropDate)
    {
        propDate = newPropDate;
    }
    // this code use to set the proposed time to the variable
    void setPropTime(string newPropTime)
    {
        propTime = newPropTime;
    }
    // this code use to set the student level to the variable
    void setRequestStatus(string newStudentLevel)
    {
        studentLevel = newStudentLevel;
    }
    // this code use to set the number student to the variable
    void setNumStudent(int newNumStudents)
    {
        numStudent = newNumStudents;
    }

    // this Code use to return proposed date
    string getPropDate()
	{
		return propDate;
	}
    // this Code use to return proposed time
	string getPropTime()
	{
		return propTime;
	}
    // this Code use to return student level
	string getstudentlevel()
	{
		return studentLevel;
	}
    // this Code use to return number student
	int getnumstudent()
	{
		return numStudent;
	}
};