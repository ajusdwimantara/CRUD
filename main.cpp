// I Gusti Bagus Vendizeta Dharma Hira
// E2100301

#include <iostream>
#include <string>
#include <time.h>

// call all header files
#include "school.h"
#include "user.h"
#include "schoolAdmin.h"
#include "volunteer.h"
#include "request.h"
#include "resourceRequest.h"
#include "tutorialRequest.h"
#include "offer.h"

using namespace std;

int main()
{   
    // variable use to admin, administrator, and volunteer
    string username, password;
    string fullname, phone, position, email, occupation, dob;
    int staf_id;
    // variable use to all request
    string req_date, req_stats, req_desc, req_time;
    string res_type; 
    int num_required; 
    string student_level;
    int n_student;
    string prop_date, prop_time;
    // variable use to all offer
    string offer_date,offer_status,remarks_;
    int id;

    // variable current admin and volunteer
    SchoolAdmin currentAdmin = SchoolAdmin();
    Volunteer currentVolunteer = Volunteer();

    // init a new vector to store all the Class in the system
    vector<School *> allSchools;
    vector<Volunteer *> allVolunteers;
    vector<Request *> allRequest;
    vector<TutorialRequest*> allTutorialRequest;
    vector<ResourceRequest*> allResourceRequest;
    vector<Offer*> allOffer;

    // variable to make an option what you choose
    int option;
    // variables to know can login or not
    bool administrator_login = false;
    bool volunteer_login = false;
    bool id_correct = false;
    // variables index to track the vector
    int index = 0;
    int index_v = 0;
     // If you input -1 it will exit the loop
    while (option != -1)
    {
    // mainmenu display
    mainmenu:
        cout << "\n==========WELCOME==========" << endl;
        cout << "1. Admin" << endl;
        cout << "2. School Administrator" << endl;
        cout << "3. Volunteer" << endl;
        cout << "4. Quit" << endl;
        cout << "Input Your Option: ";
        cin >> option;
        cout << endl;

        // if you choose no 1, automatically login by input a free username & password  
        if (option == 1)
        {   
            // input a free username & password
            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;
            // notification
            cout << "Login Successful" << endl;

            // If you input -1 it will exit the loop
            while (option != -1)
            {   
                // if you already login, u can register school include administrator account
                cout << "\n=====Welcome Admin HELP School=====" << endl;
                cout << "1. Register School" << endl;
                cout << "2. Back" << endl;
                cout << "Input Your Option: ";
                cin >> option;
                cout << endl;

                // choose 1 to register school include administrator account
                if (option == 1)
                {
                    // init a new school object to add to
                    School* newSchool = new School();
                    // new school registration process
                    string schoolName, schoolAddress, schoolCity;
                    cout << "\n=====Register School=====" << endl;
                    cout << "School Name : ";
                    cin >> schoolName;
                    newSchool->setSchoolName(schoolName);
                    cout << "School Address : ";
                    cin >> schoolAddress;
                    newSchool->setSchoolAddress(schoolAddress);
                    cout << "School City : ";
                    cin >> schoolCity;
                    newSchool->setSchoolCity(schoolCity);
                    // randomized schoolID
                    srand(time(NULL));
                    int schoolId = rand() % 1000;
                    newSchool->setSchoolID(schoolId);
                    // notification your register school successfull
                    cout << "Register School Successfull" << endl;

                    // school admin registration process
                    cout << "\n=====Register Administrator Account=====" << endl;
                    // init a new schoolAdmin object to add to
                    SchoolAdmin* newSchoolAdmin = new SchoolAdmin();

                    // input all data to register administrator account
                    cout << "Username : ";
                    cin >> username;
                    cout << "Password : ";
                    cin >> password;
                    cout << "Full name : ";
                    cin.ignore();
                    getline(cin, fullname);
                    cout<< "Email : ";
                    cin >> email;
                    cout << "Phone : ";
                    cin >> phone;
                    cout << "Position : ";
                    cin.ignore();
                    getline(cin, position);
                    cout << "Staff ID : ";
                    cin >> staf_id;

                    // set all data for register administrator account
                    newSchoolAdmin->setUsername(username);
                    newSchoolAdmin->setPassword(password);
                    newSchoolAdmin->setFullname(fullname);
                    newSchoolAdmin->setEmail(email);
                    newSchoolAdmin->setPhone(phone);
                    newSchoolAdmin->setPosition(position);
                    newSchoolAdmin->setStaffID(staf_id);

                    // notification after register successful
                    cout << "Register Administrator Account Successful\n";

                    // now we push this newly created schoolAdmin object into the schoolAdmin vector
                    newSchool->addSchoolAdmin(newSchoolAdmin);

                    // add this school to the vector in main
                    allSchools.push_back(newSchool);

                    // at this point, you can now check if the schooladmin exists by checking this vector everytime you log in
                    goto mainmenu;
                }
                else if (option == 2)
                {
                    // go back to main menu display
                    goto mainmenu;
                }
                else
                {
                    // notification if you enter wrong choice in options
                    cout << "Invalid input" << endl;
                }
            }
        }
        // Logging in as School Admin
        else if (option == 2)
        {   
            // variable to use admin login
            string username, password;
            vector<SchoolAdmin> schoolAdmins;
            for (int i = 0; i < allSchools.size(); i++)
            {
                // get the schoolAdmin vector from the school
                schoolAdmins.push_back(allSchools[i]->getSchoolAdmins());
            }

            // input username and password
            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;


            // check if there are any schools yet
            if (allSchools.size() == 0)
            {   
                // notification if you haven't registered for school yet
                cout << "No schools registered" << endl;
                // back to main menu display
                goto mainmenu;
            }
            // iterate through the vector of schools and check if the username and password matches

            // check if there are any school admins
            if (schoolAdmins.size() == 0)
            {
                // notification if you haven't registered for school admin yet
                cout << "No school admins registered" << endl;
                // back to main menu display
                goto mainmenu;
            }

            // iterate through the schoolAdmin vector
            for (int j = 0; j < schoolAdmins.size(); j++)
            {
                // check if the username and password matches
                if (schoolAdmins[j].getUsername() == username && schoolAdmins[j].getPassword() == password)
                {
                    administrator_login = true;
                    index = j;
                    break;
                }
            }
            // check if the login was successful
            if (administrator_login)
            {
                // notification after login successful
                cout << "Login Successful\n\n========WELCOME========" << endl;
                administrator_login = false;
                // set the current user to the school admin
                SchoolAdmin* currentAdmin = new SchoolAdmin();
                *currentAdmin = schoolAdmins[index];

                // set the currentAdmin's school
                currentAdmin->setSchool(*allSchools[index]);

                // all data you need to input
                cout << "Administrator: " << schoolAdmins[index].getFullname()<<'\n';
                cout << "Position: "<< schoolAdmins[index].getPosition()<<'\n';
                cout << "School Name: " << allSchools[index]->getSchoolName()<<'\n';
                cout << "School ID: " << allSchools[index]->getSchoolID()<<'\n';
                cout<< "==============================\n\n";

                // move on to the happy path
                while (option != -1)
                {
                    // menu after already login as administrator
                    cout << "\n1. Submit Request" << endl;
                    cout << "2. Review Offer" << endl;
                    cout << "3. Edit Profile" << endl;
                    cout << "4. Back" << endl;
                    cout << "Input Your Option: ";
                    cin >> option;
                    // if you choose no 1 you can submit your request
                    if (option == 1)
                    {   
                        // init a new request object to add to
                        Request* newRequest = new Request();
                        // init a new tutorial request object to add to
                        TutorialRequest* newTutorialRequest = new TutorialRequest();
                        cin.ignore();
                        // set the request id
                        newRequest->setRequestID();
                        // set the request status
                        newRequest->setRequestStatus(" NEW ");
                        // get the request status has been set
                        cout << "Request Status\t:" << newRequest->getRequestStatus() << endl;
                        // get the request id has been set by using random generate number
						cout << "Request ID\t: " << newRequest->getRequestID() << endl;
                        // all data you need to input for submit request
                        cout << "Proposed Date\t: ";
                        getline(cin, prop_date);
                        cout << "Proposed Time\t: ";
                        getline(cin, prop_time);
                        cout << "Request Description: ";
                        getline(cin, req_desc);
                        cout<<"Student Level\t: ";
                        getline(cin, student_level);
                        cout<<"Capacity\t: ";
                        cin>>n_student;
                        // notification after everything you input has been done
                        cout <<"Your Request Has Been Sent\n"<<endl;

                        // set all data for submit request
                        newTutorialRequest->setPropDate(prop_date);
                        newTutorialRequest->setPropTime(prop_time);
                        newRequest->setRequestDate("req1");
                        newRequest->setRequestDesc(req_desc);
                        newRequest->setStudentLevel(student_level);
                        newRequest->setNumStudent(n_student);

                        // add this request to the vector in main
                        allTutorialRequest.push_back(newTutorialRequest);
                        // add this tutorial request to the vector in main
                        allRequest.push_back(newRequest);
                        // 
                        allSchools[index]->addRequest(newRequest);

                        // init a new resource request object to add to
                        ResourceRequest* newResourceRequest = new ResourceRequest();
                        // choose an option to add any resource request
                        char options;
						cout << "\nDo You Want Add Any Resource Request?(y/n)\t:";
						cin >> options;'\n';
                        // if you choose y, you can add any resource request
						if (options == 'y')
						{
                            // input all data to add any resource request
							cout << "Resource Type\t\t: ";
							cin.ignore();
							getline(cin, res_type);
							cout << "Number Of Resource\t: ";
							cin >> num_required;'\n';

                            // set the resource type
							newResourceRequest->setResourceType(res_type);
                            // set the number required
							newResourceRequest->setNumRequired(num_required);
                            //
							allResourceRequest.push_back(newResourceRequest);
                            // notification after everything you input has been done
                            cout << "Resource Request Has Been Added\n";
						}
						else
						{
                            // nothing is input or blank 
							newResourceRequest->setResourceType("");
							newResourceRequest->setNumRequired(0);
							allResourceRequest.push_back(newResourceRequest);
						}
                    }
                    else if (option == 2)
                    {
                        // You can choose the offer by whom 
                            cout << "\n1. Offer by Status" << endl;
                            cout << "2. Offer by Date" << endl;
                            cout << "Input Your Option: ";
                            cin >> option;

                            // choose no 1 if you want see offer by status
                            if(option == 1)
                            {  
                                for(int status_s = 0; status_s<3;status_s++)
                                {
                                    // show the new status 
                                    if(status_s == 0)
                                    {
                                        cout<<"\nStatus: NEW\n";
                                        for(int i=0; i<allOffer.size();i++)
                                        {
                                            if(allOffer[i]->getOfferStatus() == "NEW")
                                            {
                                                cout<<allOffer[i]->getRemarks()<<'\n';
                                            }
                                        }
                                    }
                                    // show the pending status
                                    if(status_s == 1)
                                    {
                                        cout<<"\nStatus: PENDING\n";
                                        for(int i=0; i<allOffer.size();i++)
                                        {   
                                            // we can directly accept the pending offer
                                            if(allOffer[i]->getOfferStatus() == "PENDING")
                                            {
                                                char choose;
                                                cout<<allOffer[i]->getRemarks()<<'\n';
                                                cout<<"\nDo you want to accept this? (y/n): ";
                                                cin>>choose;
                                                if(choose == 'y')
                                                {
                                                    allOffer[i]->setOfferStatus("ACCEPTED");
                                                }
                                            }
                                        }
                                    }
                                    // show the accepted status
                                    if(status_s == 2)
                                    {
                                        cout<<"\nStatus: ACCEPTED\n";
                                        for(int i=0; i<allOffer.size();i++)
                                        {
                                            if(allOffer[i]->getOfferStatus() == "ACCEPTED")
                                            {
                                                cout<<allOffer[i]->getRemarks()<<'\n';
                                            }
                                        }
                                    }
                                }
                                
                            }
                            // choose no 2 if you want see offer by date
                            else if(option == 2)
                            {
                                for(int i=0; i<allOffer.size();i++)
                                {   
                                    // if the offer is not printed yet, print the offer by date
                                    if(allOffer[i]->seen == false)
                                    {
                                        cout<<"\nDate and time: "<<allOffer[i]->getOfferDate()<<'\n';
                                        cout<<allOffer[i]->getRemarks()<<'\n';
                                        allOffer[i]->seen = true;
                                        for(int j=i; j< allOffer.size(); j++)
                                        {
                                            if(allOffer[j]->getOfferDate() == allOffer[i]->getOfferDate() && allOffer[j]->seen == false)
                                            {
                                                cout<<allOffer[j]->getRemarks()<<'\n';
                                                allOffer[j]->seen = true;
                                            }
                                        }
                                    }
                                }
                                // reset the value of seen so that we can print the offer again
                                for(int i=0; i<allOffer.size();i++)
                                {
                                    allOffer[i]->seen == false;
                                }
                                    
                            }
                    }
                    // you can edit your profile has been registered
                    else if (option == 3)
                    {
                        while(option != -2)
                        {
                            // you can choose the one you want to edit
                            cout << "1. Edit Password" << endl;
                            cout << "2. Edit Fullname" << endl;
                            cout << "3. Edit Email" << endl;
                            cout << "4. Edit Phone" << endl;
                            cout << "5. Edit Position" << endl;
                            cout << "6. Edit Staff ID" << endl;
                            cout << "7. Back" << endl;
                            cout << "Input Your Option: ";
                            cin >> option;

                            // you can edit your password
                            if(option == 1)
                            {
                                cout << "Password : ";
                                cin >> password;
                                currentAdmin->setPassword(password);
                            }
                            // you can edit your full name
                            else if(option == 2)
                            {
                                cout << "Full name : ";
                                cin.ignore();
                                getline(cin, fullname);
                                currentAdmin->setFullname(fullname);

                                allSchools[index]->addSchoolAdmin(currentAdmin);
                                
                            }
                            // you can edit your email
                            else if(option == 3)
                            {
                                cout<< "Email : ";
                                cin >> email;
                                currentAdmin->setEmail(email);

                                allSchools[index]->addSchoolAdmin(currentAdmin);
                            }
                            // you can edit your phone
                            else if(option == 4)
                            {
                                cout << "Phone : ";
                                cin >> phone;
                                currentAdmin->setPhone(phone);

                                allSchools[index]->addSchoolAdmin(currentAdmin);
                            }
                            // you can edit your position
                            else if(option == 5)
                            {
                                cout << "Position : ";
                                cin.ignore();
                                getline(cin, position);
                                currentAdmin->setPosition(position);

                                allSchools[index]->addSchoolAdmin(currentAdmin);
                            }
                            // you can edit your staff id
                            else if(option == 6)
                            {
                                cout << "Staff ID : ";
                                cin >> staf_id;
                                currentAdmin->setStaffID(staf_id);

                                allSchools[index]->addSchoolAdmin(currentAdmin);
                            }
                            // go back to main menu
                            else if(option == 7)
                            {
                                goto mainmenu;
                            }
                        }
                            
                        }
                        // go back to main menu
                        else if (option == 4)
                        {
                            goto mainmenu;
                        }
                        //notification if you enter wrong choice in options
                        else
                        {
                            cout << "Invalid input" << endl;
                        }
                    }
                }
                else
                {
                    // notification if you fail input username or password 
                    cout << "Login Failed, Admin User not found." << endl;
                    // just go back to the main menu
                    goto mainmenu;
                }
        }
        // Logging in as Volunteer
        else if (option == 3)
        {
            while (option != -1)
            {
                // menu as volunteer
                cout << "\n=====CHOOSE=====\n";
                cout << "1. LOGIN" << endl;
                cout << "2. REGISTER" << endl;
                cout << "3. Back" << endl;
                cout << "Input Your Option: ";
                cin >> option;
                // Can't log in if you haven't registered yet
                // but, if you have been registered you can go next menu
                if (option == 1)
                {
                    // data to login as volunteer
                    string username, password;
                    cout << "Username : ";
                    cin >> username;
                    cout << "Password : ";
                    cin >> password;

                    // check if there are any volunteer yet
                    if (allVolunteers.size() == 0)
                    {
                        // notification if you haven't registered for volunteer yet
                        cout << "No volunteer registered" << endl;

                        // just go back to main menu
                        goto mainmenu;
                    }

                    // iterate through the schoolAdmin vector
                    for (int j = 0; j < allVolunteers.size(); j++)
                    {
                        // check if the username and password matches
                        if (allVolunteers[j]->getUsername() == username && allVolunteers[j]->getPassword() == password)
                        {
                            // check can login or not as volunteer
                            volunteer_login = true;
                            index_v = j;
                            break;
                        }
                    }

                    // check if the login was successful
                    if(volunteer_login)
                    {
                        cout << "Login Successful\n\n========WELCOME========" << endl;
                        volunteer_login = false;
                        // init a new volunteer object to add to
                        Volunteer* currentVolunteer = new Volunteer();
                        currentVolunteer = allVolunteers[index];

                        // get or display the name and occupation of volunteer has been registered
                        cout << "Volunteer: " << currentVolunteer->getFullname()<<"\n";
                        cout << "Occupation: "<< currentVolunteer->getOccupation()<<"\n";
                        cout<< "==============================\n\n";
                    }
                    else
                    {
                        // notification if you wrong input your username or password
                        cout << "Login Failed, Volunteer User not found." << endl;
                        // just go back to the main menu
                        goto mainmenu;
                    }
                    while (option != -1)
                    {
                        // menu after already login as volunteer
                        cout << "\n1. Review Request" << endl;
                        cout << "2. Submit Offer" << endl;
                        cout << "3. Back" << endl;
                        cout << "Input Your Option: ";
                        cin >> option;
                        // you can see all request has been submitted if you choose no 1
                        if (option == 1)
                        {
                            // You can choose the request by whom 
                            cout << "\n1. Request by school" << endl;
                            cout << "2. Request by city" << endl;
                            cout << "3. Request by date" << endl;
                            cout << "Input Your Option: ";
                            cin >> option;

                            // choose no 1 if you want see request by school
                            if(option == 1)
                            {  
                                // for looping to display all request detail
                                // to know the school size
                                for(int i =0; i<allSchools.size(); i++)
                                {   
                                    // detailed display
                                    cout<<"\n=====Details=====\n";
                                    // show the school name has been registered
                                    cout<<"School: "<<allSchools[i]->getSchoolName();
                                    cout<<"\n";
                                    // show all request has been submitted
                                    allSchools[i]->getRequest();
                                    // show a tutorial date from the proposed date you have been input before
                                    cout << "Tutorial Date\t:" << allTutorialRequest[i]->getPropDate() << endl;
                                    // show a tutorial time from the proposed time you have been input before
									cout << "Tutorial Time\t:" << allTutorialRequest[i]->getPropTime() << endl;
                                    for (int j = 0; j < allResourceRequest.size(); j++)
									{
                                        // show resource type you have been added
									    cout << "Resource Type\t\t:" << allResourceRequest[j]->getResourceType() << endl;
                                        // show number required you have been added
									    cout << "Number Required\t\t:" << allResourceRequest[j]->getNumRequired() << endl;
									}
                                    cout<<"\n\n";
                                }
                            }
                            else if(option == 2)
                            {
                                int j = 0;
                                // for looping to display all request detail
                                // to know the school size
                                for(int i=0; i<allSchools.size();i++)
                                {
                                    // detailed display
                                    cout<<"\n=====Details=====\n";
                                    // show the school city has been registered
                                    cout<<"City: "<<allSchools[i]->getSchoolCity()<<"\n";
                                    // show all request has been submitted
                                    allSchools[i]->getRequest();
                                    for(int j=i; j< allSchools.size();j++)
                                    {
                                        if(allSchools[i]->getSchoolCity() == allSchools[j]->getSchoolCity())
                                        {
                                            allSchools[j]->getRequest();
                                        }
                                        // show a tutorial date from the proposed date you have been input before
                                        cout << "Tutorial Date\t:" << allTutorialRequest[i]->getPropDate() << endl;
                                        // show a tutorial time from the proposed time you have been input before
									    cout << "Tutorial Time\t:" << allTutorialRequest[i]->getPropTime() << endl;
                                        for (int l = 0; l < allResourceRequest.size(); l++)
									    {
                                            // show resource type you have been added
									        cout << "Resource Type\t\t:" << allResourceRequest[l]->getResourceType() << endl;
                                            // show number required you have been added
									        cout << "Number Required\t\t:" << allResourceRequest[l]->getNumRequired() << endl;
									    }
                                        cout<<"\n\n";
                                    }
                                }
                                // reset the value of seen so that we can print the request again
                                for(int i=0; i<allSchools.size();i++)
                                {
                                    allSchools[i]->reset();
                                }
                                    
                            }
                            else if(option == 3)
                            {
                                int j = 0;
                                for(int i=0; i<allRequest.size();i++)
                                {
                                    // detailed display
                                    cout<<"\n=====Details=====\n";
                                    // show the auto generate date and time when you run the program
                                    cout<<"Date: "<<allRequest[i]->getRequestDate();
                                    cout<<"Description: "<<allRequest[i]->getRequestDesc()<<"\n";
                                    cout<<"Status: "<<allRequest[i]->getRequestStatus()<<"\n";
                                    cout<<"Student level: "<<allRequest[i]->getStudentLevel()<<"\n";
                                    cout<<"Capacity: "<<allRequest[i]->getNumStudent()<<"\n";
                                    for(int j=i; j< allRequest.size();j++)
                                    {
                                        if(allRequest[i]->getRequestDate() == allRequest[j]->getRequestDate() && allRequest[j]->seen == false)
                                        {
                                            // show a tutorial date from the proposed date you have been input before
                                            cout << "Tutorial Date\t:" << allTutorialRequest[i]->getPropDate() << endl;
                                            // show a tutorial time from the proposed time you have been input before
									        cout << "Tutorial Time\t:" << allTutorialRequest[i]->getPropTime() << endl;
                                            for (int l = 0; l < allResourceRequest.size(); l++)
									        {
                                                // show resource type you have been added
									            cout << "Resource Type\t\t:" << allResourceRequest[l]->getResourceType() << endl;
                                                // show number required you have been added
									            cout << "Number Required\t\t:" << allResourceRequest[l]->getNumRequired() << endl;
									        }
                                        }
                                        cout<<"\n\n";
                                    }
                                }
                                // reset the value of seen so that we can print the request again
                                for(int i=0; i<allRequest.size();i++)
                                {
                                    allRequest[i]->seen = false;
                                }
                            }
                        }
                        // input your request Id from your submit request and you can write a remarks
                        else if (option == 2)
                        {
                            cout<<"\nEnter Request ID: ";
                            cin>>id;
                            // to check your request ID valid or not
                            for(int i = 0; i<allRequest.size(); i++)
                            {
                                if(id == allRequest[i]->getRequestID())
                                {
                                    id_correct = true;
                                    break;
                                }
                            }
                            // if your request ID is correct, you can enter the remarks 
                            if(id_correct)
                            {
                                // init a new offer object to add to
                                Offer* newOffer = new Offer();
                                cout<<"Enter Remarks: ";
                                cin.ignore();
                                getline(cin, remarks_);
                                cout<<"Remarks Has Been Submitted\n";

                                offer_status = "PENDING";
                                newOffer->setRemarks(remarks_);
                                newOffer->setOfferStatus(offer_status);
                                newOffer->setOfferDate();
                                // a method to insert the value to the vector
                                allOffer.push_back(newOffer);
                            }
                            else if(!id_correct)
                            {
                                cout<<"No such request ID!\n";
                            }
                        }
                        else if (option == 3)
                        {
                            // back to main menu
                            goto mainmenu;
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                        }
                    }
                }
                else if (option == 2)
                {
                    // school admin registration process
                    cout << "\n=====Register Volunteer Account=====" << endl;
                    // init a new volunteer object to add to
                    Volunteer* newVolunteer = new Volunteer();

                    // input all data to register volunteer account
                    cout << "Username : ";
                    cin >> username;
                    cout << "Password : ";
                    cin >> password;
                    cout << "Full name : ";
                    cin.ignore();
                    getline(cin, fullname);
                    cout<< "Email : ";
                    cin >> email;
                    cout << "Phone : ";
                    cin >> phone;
                    cout << "Occupation : ";
                    cin.ignore();
                    getline(cin, occupation);
                    cout << "Date of Birth(DD/MM/YY) : ";
                    cin >> dob;

                    // set all data for register vlounteer account
                    newVolunteer->setUsername(username);
                    newVolunteer->setPassword(password);
                    newVolunteer->setFullname(fullname);
                    newVolunteer->setEmail(email);
                    newVolunteer->setPhone(phone);
                    newVolunteer->setOccupation(occupation);
                    newVolunteer->setDOB(dob);

                    // notification after finish input all data to register the volunteer account
                    cout << "Register Administrator Account Successful\n";
                    // a method to insert the value to the vector
                    allVolunteers.push_back(newVolunteer);


                }
                else if (option == 3)
                {
                    // back to main menu
                    goto mainmenu;
                }
                else
                {
                    //notification if you enter wrong choice in options
                    cout << "Invalid input" << endl;
                }
            }
        }
        // Exit the program
        else if (option == 4)
        {
        }
        return 0;
    }
}