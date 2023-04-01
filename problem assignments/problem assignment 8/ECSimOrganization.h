//
//  ECSimOrganization.h
//
//
//  Created by Yufeng Wu on 2/21/23.
//

#ifndef ECSimOrganization_h
#define ECSimOrganization_h
#include "ECCampusSimulator.h"
#include "ECSimHuman.h"
class ECSimHuman;
class ECOrganization;
class ECSimStudent;
class ECSimDiningHall;
class ECSimBursar;
class ECSimEmployee;
class ECSimLibrary;
class ECSimRecCenter;
class ECSimHR;

//  Place simulation organization related code here...
//  Consider adding base class here...

// ***********************************************************
// University bursar office: handling enrollment related matters

class ECOrganization : public ECSimEntity
{
public:
    ECOrganization(int idIn) : ECSimEntity(idIn), dailyBudget(0) {}
    void SetBudgetForDay(int amt) { dailyBudget = amt; }
    int getBudgetForDay() const { return dailyBudget; }

    virtual void Serve(ECSimBursar *bursar) {}
    virtual void Serve(ECSimDiningHall *dininghall);
    virtual void Serve(ECSimRecCenter *recCenter) {}
    virtual void Serve(ECSimHR *hr) {}
    virtual void Serve(ECSimEmployee *employee) {}
    virtual void Serve(ECSimStudent *student) {}
    virtual void Serve(ECSimLibrary *library) {}
    virtual void Request(ECSimEntity *reciever) override;

private:
    int dailyBudget;
};

class ECSimBursar : public ECOrganization
{
public:
    // each organization has an unique ID
    ECSimBursar(int bid);

    // set tuition rate; same tuition for everyone; tuition is form the entire simulation period (say semester)
    void SetTuition(int tuitionIn);
    // your code goes here
    void Request(ECSimEntity *reciever) override;
    void Serve(ECSimStudent *student);
    void Serve(ECSimDiningHall *dininghall);
    void Serve(ECSimRecCenter *recCenter);
    void Serve(ECOrganization *org);
    void Serve(ECSimHR *hr);
    void Serve(ECSimLibrary *library);

private:
    int tuition;
};

// ***********************************************************
// Human resource (HR)

class ECSimHR : public ECOrganization // bursar -> hr = bad request
{
public:
    // each organization has an unique ID
    ECSimHR(int tid);

    void Serve(ECSimEmployee *employee);
    void Serve(ECSimBursar *bursar);
    void Serve(ECSimHR *hr) { throw std::string("BAD REQUEST"); }
    void Serve(ECSimRecCenter *recCenter) { throw std::string("BAD REQUEST"); }
    void Serve(ECSimDiningHall *dininghall) { throw std::string("BAD REQUEST"); }
    void Request(ECSimEntity *reciever) override;
    // your code goes here
};

// ***********************************************************
// Dining hall

class ECSimDiningHall : public ECOrganization
{
public:
    // each organization has an unique ID
    ECSimDiningHall(int tid);

    // your code goes here

    void Serve(ECSimStudent *student);
    void Serve(ECSimEmployee *employee);
    void Serve(ECSimBursar *bursar);
    void Serve(ECSimDiningHall *dininghall) { throw std::string("BAD REQUEST"); }
    void Serve(ECSimRecCenter *recCenter) { throw std::string("BAD REQUEST"); }
    void Serve(ECSimHR *hr) { throw std::string("BAD REQUEST"); }
    void Request(ECSimEntity *reciever) override;
};

// ***********************************************************
// Rec center

class ECSimRecCenter : public ECOrganization
{
public:
    // each organization has an unique ID
    ECSimRecCenter(int tid);

    // your code goes here
    void Request(ECSimEntity *reciever) override;

    void Serve(ECSimStudent *student);
    void Serve(ECSimEmployee *employee);
    void Serve(ECSimBursar *bursar);
    void Serve(ECSimHR *hr) { throw std::string("BAD REQUEST"); }
    void Serve(ECSimRecCenter *recCenter) { throw std::string("BAD REQUEST"); }
    void Serve(ECSimDiningHall *dininghall) { throw std::string("BAD REQUEST"); }
};

// ***********************************************************
// Library

class ECSimLibrary : public ECOrganization
{
public:
    // each organization has an unique ID
    ECSimLibrary(int bid);

    // your code goes here
    void Request(ECSimEntity *reciever) override;
    void Serve(ECSimStudent *student);
    void Serve(ECSimEmployee *employee);
};

#endif /* ECSimOrganization_h */
