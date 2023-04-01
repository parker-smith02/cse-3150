//
//  ECSimHuman.cpp
//
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECSimHuman.h"
#include "ECSimOrganization.h"

// Your code goes here

// EMPLOYEE
ECSimEmployee::ECSimEmployee(int idEmployee) : ECSimEntity(idEmployee) {}

void ECSimEmployee::SetPayrate(int rate) { payRate = rate; }

int ECSimEmployee::Getpayrate() const { return payRate; }

void ECSimEmployee::Request(ECSimEntity *reciever)
{
    reciever->Serve(this);
}

void ECSimEmployee::Serve(ECSimHR *hr)
{
    hr->Charged(2000);
    this->Paid(2000);
}

// STUDENT
ECSimStudent::ECSimStudent(int idStudent) : ECSimEntity(idStudent) {}

void ECSimStudent::Request(ECSimEntity *reciever)
{
    reciever->Serve(this);
};

void ECSimStudent::Serve(ECSimBursar *bursar)
{
    bursar->Charged(1000);
    this->Paid(1000);
}