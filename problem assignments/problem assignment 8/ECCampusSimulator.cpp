//
//  ECCampusSimulator.cpp
//
//
//  Created by Yufeng Wu on 2/21/23.
//
#include "ECCampusSimulator.h"
#include "ECSimOrganization.h"
#include "ECSimHuman.h"
#include <iostream>
// Your code here
class ECOrganization;

// SIMULATION SCRIPT

void ECCampusSimScript::EndofDay()
{
    AddSimEvt(-1, -1);
}

void ECCampusSimScript::AddSimEvt(int idSender, int idReciever)
{
    vecSimEvents.push_back(std::make_pair(idSender, idReciever));
}

// SIMULATOR

void ECCampusSimulator::Simulate(const ECCampusSimScript &script)
{
    for (auto evt : script.GetSimEvents())
    {
        std::cout << "Event: " << evt.first << " -> " << evt.second << std::endl;
        if (evt.first == -1 && evt.second == -1)
        {
            for (auto item : mapSimItems)
            {
                if (dynamic_cast<ECOrganization *>(item.second) != NULL)
                {
                    ECOrganization *org = dynamic_cast<ECOrganization *>(item.second);
                    org->Charged(org->getBudgetForDay());
                }
            }
            continue;
        }
        ECSimEntity *sender = mapSimItems[evt.first];
        ECSimEntity *reciever = mapSimItems[evt.second];
        sender->Request(reciever);
    }
}

void ECCampusSimulator::AddSimItem(ECSimEntity *pe)
{
    std::cout << "Add item: " << pe->GetId() << " " << typeid(*pe).name() << std::endl;
    mapSimItems.insert(std::make_pair(pe->GetId(), pe));
}