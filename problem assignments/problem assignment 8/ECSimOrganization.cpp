//
//  ECSimOrganization.cpp
//
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECSimOrganization.h"

// Your code goes here

// ORGANIZATION

void ECOrganization::Serve(ECSimDiningHall *diningHall)
{
    std::cout << "DINGIN HALL" << std::endl;
}

void ECOrganization::Request(ECSimEntity *reciever)
{
    reciever->Serve(this);
}

// BURSAR
ECSimBursar::ECSimBursar(int bid) : ECOrganization(bid) {}

void ECSimBursar::Request(ECSimEntity *reciever)
{
    reciever->Serve(this);
}

void ECSimBursar::SetTuition(int tuitionIn)
{
    tuition = tuitionIn;
}

void ECSimBursar::Serve(ECSimStudent *student)
{
    student->Charged(tuition);
    this->Paid(tuition);
}

void ECSimBursar::Serve(ECOrganization *org)
{
    org->Paid(org->getBudgetForDay());
    this->Charged(org->getBudgetForDay());
}
void ECSimBursar::Serve(ECSimDiningHall *org)
{
    org->Paid(org->getBudgetForDay());
    this->Charged(org->getBudgetForDay());
}

void ECSimBursar::Serve(ECSimRecCenter *org)
{
    org->Paid(org->getBudgetForDay());
    this->Charged(org->getBudgetForDay());
}

void ECSimBursar::Serve(ECSimHR *org)
{
    org->Paid(org->getBudgetForDay());
    this->Charged(org->getBudgetForDay());
}

void ECSimBursar::Serve(ECSimLibrary *org)
{
    org->Paid(org->getBudgetForDay());
    this->Charged(org->getBudgetForDay());
}

// HR
ECSimHR::ECSimHR(int tid) : ECOrganization(tid) {}

void ECSimHR::Request(ECSimEntity *reciever)
{
    reciever->Serve(this);
}

void ECSimHR::Serve(ECSimEmployee *employee)
{
    int payRate = employee->Getpayrate();
    employee->Paid(payRate);
    this->Charged(payRate);
}

void ECSimHR::Serve(ECSimBursar *bursar)
{
    bursar->Paid(this->GetBalance());
    this->Charged(this->GetBalance());
}

// DINING HALL
ECSimDiningHall::ECSimDiningHall(int tid) : ECOrganization(tid) {}

void ECSimDiningHall::Request(ECSimEntity *reciever)
{
    reciever->Serve(this);
}

void ECSimDiningHall::Serve(ECSimBursar *bursar)
{
    std::cout << "TRANSFERING MONEY" << std::endl;
    bursar->Paid(this->GetBalance());
    this->Charged(this->GetBalance());
}

void ECSimDiningHall::Serve(ECSimStudent *student)
{
    std::cout << student->GetId() << std::endl;
    student->Charged(5);
    this->Paid(5);
}

void ECSimDiningHall::Serve(ECSimEmployee *employee)
{
    employee->Charged(10);
    this->Paid(10);
}

// REC CENTER
ECSimRecCenter::ECSimRecCenter(int tid) : ECOrganization(tid) {}

void ECSimRecCenter::Request(ECSimEntity *reciever)
{
    reciever->Serve(this);
}

void ECSimRecCenter::Serve(ECSimStudent *student)
{
    student->Charged(10);
    this->Paid(10);
}

void ECSimRecCenter::Serve(ECSimEmployee *employee)
{
    employee->Charged(20);
    this->Paid(20);
}

void ECSimRecCenter::Serve(ECSimBursar *bursar)
{
    bursar->Paid(this->GetBalance());
    this->Charged(this->GetBalance());
}

// LIBRARY
ECSimLibrary::ECSimLibrary(int bid) : ECOrganization(bid) {}

void ECSimLibrary::Request(ECSimEntity *reciever)
{
    reciever->Serve(this);
}

void ECSimLibrary::Serve(ECSimStudent *student) { return; }

void ECSimLibrary::Serve(ECSimEmployee *employee) { return; }
