//
//  ECCampusSimulator.h
//
//
//  Created by Yufeng Wu on 2/21/23.
//
#ifndef ECCampusSimulator_h
#define ECCampusSimulator_h
#include <iostream>
#include <string>
#include <vector>
#include <map>
class ECSimHuman;
class ECOrganization;
class ECSimStudent;
class ECSimDiningHall;
class ECSimBursar;
class ECSimEmployee;
class ECSimLibrary;
class ECSimRecCenter;
class ECSimHR;

class ECSimEntity
{
public:
    ECSimEntity(int idIn) : id(idIn), balance(0) {}

    virtual void Paid(int amt) { balance += amt; }

    virtual void Charged(int amt)
    {
        if (balance - amt < 0)
        {
            throw std::string("BANKRUPT");
            std::cout << "BANKRUPT" << std::endl;
            return;
        }
        balance -= amt;
    }

    virtual int GetBalance() const { return balance; }

    virtual int GetId() const { return id; }

    virtual void Request(ECSimEntity *reciever) = 0;
    virtual void Serve(ECSimEntity *sender)
    {
        std::cout << "BAD REQUEST" << std::endl;
        throw std::string("BAD REQUEST");
    }
    virtual void Serve(ECSimBursar *bursar) {}
    virtual void Serve(ECSimStudent *student) {}
    virtual void Serve(ECOrganization *org) {}
    virtual void Serve(ECSimDiningHall *diningHall) {}
    virtual void Serve(ECSimRecCenter *recCenter) {}
    virtual void Serve(ECSimHR *hr) {}
    virtual void Serve(ECSimLibrary *library) {}
    virtual void Serve(ECSimEmployee *employee) {}

private:
    int id;
    int balance;
};

// ***********************************************************
// Simulation script: a sequence of events to simulate

class ECCampusSimScript
{
public:
    ECCampusSimScript(){};
    // Mark the end of a day; unitl calling it again, any events before are the current day
    void EndofDay();
    // Add a simulation event. An event is from a sender (with type and id) to a receiver (with type and id). Also evtCode is the code of the type of event between these two kinds of entities. For example, a student (sender) enrolls (event code 0) in univerisity (receiver)
    void AddSimEvt(int idSender, int idReceiver);

    // Your code here...

    std::vector<std::pair<int, int>> GetSimEvents() const { return vecSimEvents; }

private:
    std::vector<std::pair<int, int>> vecSimEvents;
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
    std::map<int, ECSimEntity *> GetSimItems() { return mapSimItems; }

private:
    std::map<int, ECSimEntity *> mapSimItems;
};

#endif /* ECCampusSimulator_h */
