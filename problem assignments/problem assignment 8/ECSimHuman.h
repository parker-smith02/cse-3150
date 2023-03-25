//
//  ECSimHuman.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//  Human related definitions in campus simulation

#ifndef ECSimHuman_h
#define ECSimHuman_h
#include "ECSimOrganization.h"

//  Place all human related definitions here: ECSimStudent, ECSimEmployee, etc


// ***********************************************************
// Employee

class ECSimEmployee : public ECSimEntity
{
public:
    ECSimEmployee(int idEmployee);
    
    // payrate: amount paid per day. If not set, not getting paid
    void SetPayrate(int rate);  
    int Getpayrate() const;  
    
    // Your code goes here...
    void Request(ECSimEntity *reciever); 

    void Serve(ECSimBursar *bursar);


private:
    int payRate;

};

// ***********************************************************
// Student

class ECSimStudent : public ECSimEntity
{
public:
    // each student must have a distinct id
    ECSimStudent(int idStudent);
    
    // Your code goes here...

    void Request(ECSimEntity *reciever);

    void Serve(ECSimBursar *bursar);
};

#endif /* ECSimHuman_h */