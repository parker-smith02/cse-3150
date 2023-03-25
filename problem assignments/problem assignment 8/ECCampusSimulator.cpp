//
//  ECCampusSimulator.cpp
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECCampusSimulator.h"
#include "ECSimOrganization.h"
#include "ECSimHuman.h"

// Your code here

//SIMULATION SCRIPT

void ECCampusSimScript::EndofDay() {

}

void ECCampusSimScript::AddSimEvt(int idSender, int idReciever) {
    vecSimEvents.push_back(std::make_pair(idSender, idReciever));
}


//SIMULATOR

void ECCampusSimulator::Simulate(const ECCampusSimScript &script) {
    for (auto evt : script.GetSimEvents()) {
        ECSimEntity *sender = mapSimItems[evt.first];
        ECSimEntity *reciever = mapSimItems[evt.second];
        sender->Request(reciever);
    }
}

void ECCampusSimulator::AddSimItem(ECSimEntity *pe) {
    mapSimItems.insert(std::make_pair(pe->GetId(), pe));
}