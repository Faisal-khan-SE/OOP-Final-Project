
#pragma once
#include<iostream>
using namespace std;
static int amount=1000;
static int money=1000;
class KingdomEngine {
protected:
    char** ptr;
public:
   
    KingdomEngine();
    virtual ~KingdomEngine();  // Added destructor
    void information();
    void displayKingdom();
    void setVal();
    void storeSpace();
    void femine();
    void weather();
};

class population : public KingdomEngine {
public:
    char** PointerToShowPeople;
    population() {};
   void cleanPopulation();  
    void initializePeople();
    void setPopulation();
    void removePopulatoion();
    void populationDetail();
    void disease();
    void addPeople();
    void restorePeople();
};

class economy : public population {
public:
    economy(){}
    void showEconomy();
    void foodComsume();
    void restoreFood();
};

class army : public economy {
public:
    army(){}
    void setArmy();
    void destroyArmy();
    void restoreArmy();
};

class resourceSystems : public army {
public:
    void setResource();
};

class bank : public resourceSystems {

public:
   
    bank() { amount = 1000;
    money = 1000;
    }
    void updateAmount(int);
    void setBank();
    void showBankDetails();
};

class politics : public bank {
public:
    int faisal_money = 1000;
    int ehtasham_money = 1000;
    void setPolitics();
    void politicsDetail();
    int Election();
    void coruption(int);
    void revolt();
    int war();
    int moneyUpdate(int);

};