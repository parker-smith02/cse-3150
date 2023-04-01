//
//  ECSimHuman.h
//
//
//  Created by Yufeng Wu on 2/21/23.
//  Human related definitions in campus simulation

#ifndef ECSimHuman_h
#define ECSimHuman_h
class ECOrganization;
class ECSimBursar;
#include "ECSimOrganization.h"
#include <string>

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

    void Serve(ECSimHR *hr);
    virtual void Serve(ECSimBursar *bursar) { throw std::string("BAD REQUEST"); }
    virtual void Serve(ECSimRecCenter *recCenter) { throw std::string("BAD REQUEST"); }
    virtual void Serve(ECSimDiningHall *diningHall) { throw std::string("BAD REQUEST"); }

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
    void Serve(ECSimHR *hr) { throw std::string("BAD REQUEST"); }
    void Serve(ECSimRecCenter *recCenter) { throw std::string("BAD REQUEST"); }
    void Serve(ECSimDiningHall *diningHall) { throw std::string("BAD REQUEST"); }
};

#endif /* ECSimHuman_h */