//
//  ECCampusSimulator.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//
#ifndef ECCampusSimulator_h
#define ECCampusSimulator_h
#include <string>
#include <vector>
#include <map>
#include "ECSimHuman.h"
#include "ECSimOrganization.h"

class ECSimEntity
{
    public:
        ECSimEntity(int idIn) : id(idIn) {}

        virtual void Paid(int amt) { balance += amt; }

        virtual void Charged(int amt) {
            if (amt - balance < 0) {
                throw std::string("BANKRUPT");
                return;
            }
            balance -= amt;
        }

        virtual int GetBalance() { return this->balance; }

        int GetId() const { return id; }
        virtual void Request(ECSimEntity *reciever) { reciever->Serve(this); };

        virtual void Serve(ECSimEntity *sender) {throw std::string("BAD REQUEST");}

    private:
        int id;
        int balance;
};


// ***********************************************************
// Simulation script: a sequence of events to simulate

class ECCampusSimScript
{
public:
    ECCampusSimScript() {};
    // Mark the end of a day; unitl calling it again, any events before are the current day
    void EndofDay();
    // Add a simulation event. An event is from a sender (with type and id) to a receiver (with type and id). Also evtCode is the code of the type of event between these two kinds of entities. For example, a student (sender) enrolls (event code 0) in univerisity (receiver)
    void AddSimEvt(int idSender, int idReceiver);
    
    // Your code here...

    std::vector<std::pair<int, int> > GetSimEvents() const { return vecSimEvents; }

private:
    std::vector<std::pair<int, int> > vecSimEvents;
};

// ***********************************************************
// Simulator

class ECCampusSimulator
{
public:
    ECCampusSimulator() {}
    ~ECCampusSimulator() {}
    void Simulate(const ECCampusSimScript &script);
    
    // Add a new sim item
    void AddSimItem(ECSimEntity *pe);

    // Your code goes here..
    std::map<int, ECSimEntity*> GetSimItems() { return mapSimItems; }

private:
    std::map<int, ECSimEntity*> mapSimItems;
};

#endif /* ECCampusSimulator_h */
