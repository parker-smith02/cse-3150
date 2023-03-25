//
//  ECSimOrganization.cpp
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECSimOrganization.h"

// Your code goes here

//ORGANIZATION

void ECOrganization::Serve(ECSimBursar *bursar) {
    bursar->Paid(this->GetBalance());
    this->Charged(this->GetBalance());
}

//BURSAR
ECSimBursar::ECSimBursar(int bid) : ECOrganization(bid) {}

void ECSimBursar::SetTuition(int tuitionIn) {
    tuition = tuitionIn;
}


void ECSimBursar::Serve(ECSimStudent *student) {
    student->Charged(tuition);
    this->Paid(tuition);
}

void ECSimBursar::Serve(ECOrganization *org) {
    org->Paid(org->getBudgetForDay());
    this->Charged(org->getBudgetForDay());
}

//HR
ECSimHR::ECSimHR(int tid) : ECOrganization(tid) {}

void ECSimHR::Serve(ECSimEmployee *employee) {
    int payRate = employee->Getpayrate();
    employee->Paid(payRate);
    this->Charged(payRate);
}


//DINING HALL
ECSimDiningHall::ECSimDiningHall(int tid) : ECOrganization(tid) {}


void ECSimDiningHall::Serve(ECSimStudent *student) {
    student->Charged(5);
    this->Paid(5);
}

void ECSimDiningHall::Serve(ECSimEmployee *employee) {
    employee->Charged(10);
    this->Paid(10);
}

//REC CENTER
ECSimRecCenter::ECSimRecCenter(int tid) : ECOrganization(tid) {}


void ECSimRecCenter::Serve(ECSimStudent *student) {
    student->Charged(10);
    this->Paid(10);
}

void ECSimRecCenter::Serve(ECSimEmployee *employee) {
    employee->Charged(20);
    this->Paid(20);
}

//LIBRARY
ECSimLibrary::ECSimLibrary(int bid) : ECOrganization(bid) {}


void ECSimLibrary::Serve(ECSimStudent *student) {return;}

void ECSimLibrary::Serve(ECSimEmployee *employee) {return;}
