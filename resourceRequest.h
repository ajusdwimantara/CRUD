#include <iostream>
#include <vector>
#include "request.h"
using namespace std;

// this is derived class from Request class
class ResourceRequest : public Request
{
    private:
    // Types and variables follow a given command
    string resourceType;
    int numRequired;

    public:
    // default constructor for ResourceRequest class
    ResourceRequest()
    {
        resourceType = "";
		numRequired = 0;
    }
    // this code use to set the resource type to the variable
	void setResourceType(string newResourceType) 
    {
		resourceType = newResourceType;
	}
    // this Code use to return resource type
    string getResourceType() 
    {
		return resourceType;
	}
    // this code use to set the number required to the variable
	void setNumRequired(int newNumRequired) 
    {
		numRequired = newNumRequired;
    }
    // this Code use to return number required
	int getNumRequired() 
    {
		return numRequired;
	}

};