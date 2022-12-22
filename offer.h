#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Offer
{
    private:
	string offerDate,offerStatus,remarks;

    public:
    // to check whether the offer is printed or not
    bool seen = false;
    Offer()
    {

    }
    void setOfferDate()
    {
        time_t now = time(0);
   
        // convert now to string form
        char* dt = ctime(&now);
        offerDate = dt;
    }
    void setOfferStatus(string newOfferStatus)
    {
        offerStatus = newOfferStatus;
    }
    void setRemarks(string newRemarks)
    {
        remarks = newRemarks;
    }
    string getOfferStatus()
    {
        return offerStatus;
    }
    string getOfferDate()
    {
        return offerDate;
    }
    string getRemarks()
    {
        return remarks;
    }
};