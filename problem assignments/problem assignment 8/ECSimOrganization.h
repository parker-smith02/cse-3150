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

//  Place simulation organization related code here...
//  Consider adding base class here...

// ***********************************************************
// University bursar office: handling enrollment related matters

class ECOrganization: public ECSimEntity
{
    public:
        ECOrganization(int idIn) : ECSimEntity(idIn), dailyBudget(0) {}
        void SetBudgetForDay(int amt) { dailyBudget = amt; }
        int getBudgetForDay() const { return dailyBudget; }

        void Serve(ECSimBursar *bursar);

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
    void Serve(ECSimStudent *student);

    void Serve(ECOrganization *org);

private:
    int tuition;
    
};

// ***********************************************************
// Human resource (HR)

class ECSimHR : public ECOrganization
{
public:
    // each organization has an unique ID
    ECSimHR( int tid );

    void Serve(ECSimEmployee *employee);
    
    // your code goes here
};

// ***********************************************************
// Dining hall

class ECSimDiningHall : public ECOrganization
{
public:
    // each organization has an unique ID
    ECSimDiningHall( int tid );
    
    // your code goes here

    void Serve(ECSimStudent *student);
    void Serve(ECSimEmployee *employee);
};

// ***********************************************************
// Rec center

class ECSimRecCenter : public ECOrganization
{
public:
    // each organization has an unique ID
    ECSimRecCenter( int tid );
    
    // your code goes here

    void Serve(ECSimStudent *student);
    void Serve(ECSimEmployee *employee);
};

// ***********************************************************
// Library

class ECSimLibrary : public ECOrganization
{
public:
    // each organization has an unique ID
    ECSimLibrary(int bid);
    
    // your code goes here
    void Serve(ECSimStudent *student);
    void Serve(ECSimEmployee *employee);
};

#endif /* ECSimOrganization_h */
