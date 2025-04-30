#include "Header.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
bool famine = false;
int faisal_vote = 0;
int Ehtasham_vote = 0;
bool election = true;
int row = 15;
int column = 35;
int randomPolitician = 0;
int politician = 2;
int randomPeople = 1;
int people = 10;


KingdomEngine::KingdomEngine() {
    ptr = new char* [row];
    for (int i = 0; i < row; i++) {
        ptr[i] = new char[column];
        for (int j = 0; j < column; j++) {
            ptr[i][j] = ' ';
        }
    }
}
KingdomEngine::~KingdomEngine() {
    for (int i = 0; i < row; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

void KingdomEngine::setVal() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 0 || i == row - 1) {
                ptr[i][j] = '+';
            }
            else if (j == 0 || j == column - 1) {
                ptr[i][j] = '+';
            }
            else {
                ptr[i][j] = ' ';
            }
        }
    }
}

void KingdomEngine::storeSpace() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
}

void population::initializePeople() {
    PointerToShowPeople = new char* [1];
    PointerToShowPeople[0] = new char[people];
    for (int j = 0; j < people; j++) {
        PointerToShowPeople[0][j] = 'L';
    }
}

void population::setPopulation() {
    int r, c;
    srand(time(0));
    int j = 0;
    if (people < 0)
    {
        people = 0;
    }
    while (j < people) {
        r = rand() % 15;
        c = rand() % 35;
        if (ptr[r][c] == ' ') {
            ptr[r][c] = PointerToShowPeople[0][j];
            j++;
        }
    }
}

void army::setArmy() {
    int armyGenerator = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 2 && j > 2 && j <= 6) {
                if (armyGenerator == 0) { ptr[i][j] = 'A'; }
                if (armyGenerator == 1) { ptr[i][j] = 'R'; }
                if (armyGenerator == 2) { ptr[i][j] = 'M'; }
                if (armyGenerator == 3) { ptr[i][j] = 'Y'; }
                armyGenerator++;
            }
        }
    }
}

void politics::setPolitics() {
    int politicsGenerator = 0;
    while (randomPolitician < politician) {
        int r, c;
        r = rand() % 15;
        c = rand() % 32;
        if (ptr[r][c] == ' ') {
            if (politicsGenerator == 0)
                ptr[r][c] = '1';
            else
                ptr[r][c] = '2';
            politicsGenerator++;
            randomPolitician++;
        }
    }
}

void resourceSystems::setResource() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 1 && j == 17) { ptr[i][j] = 'S'; }
            else if (i == 1 && j == 18) { ptr[i][j] = 'H'; }
            else if (i == 2 && j == 17) { ptr[i][j] = 'O'; }
            else if (i == 2 && j == 18) { ptr[i][j] = 'P'; }
            else if (i == 1 && j == 14) { ptr[i][j] = 'F'; }
            else if ((i == 1 && j == 15) || (i == 2 && j == 14)) { ptr[i][j] = 'O'; }
            else if (i == 2 && j == 15) { ptr[i][j] = 'D'; }
        }
    }
}

void bank::setBank() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 12 && j == 1) { ptr[i][j] = 'B'; }
            else if (i == 12 && j == 2) { ptr[i][j] = 'A'; }
            else if (i == 13 && j == 1) { ptr[i][j] = 'N'; }
            else if (i == 13 && j == 2) { ptr[i][j] = 'K'; }
        }
    }
}

void KingdomEngine::information() {
    cout << endl << "Bounded area by + is our region:";
    cout << endl << "P is showing population in the region:";
    cout << endl << "SH\nOP: is showing the shop";
    cout << endl << "FO\nOD: is showing the food that will be consumed by army and public:";
    cout << endl << "ARMY it is showing to army:";
    cout << endl << "BA\nNK: it is showing the bank in the region:";
}

void population::populationDetail() {
    cout << "The total number of people are: " << people << endl;
}

void KingdomEngine::displayKingdom() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << ptr[i][j];
        }
        cout << endl;
    }
}

void economy::showEconomy() {
    cout << "Economy of our region is now: " << money;

}

int politics::Election() {
    
    int choice;
    cout << "If you want to vote for Faisal press 1, for Ehtasham press 2: ";
    fstream file("Election.txt", ios::app);
    for (int i = 1; i <= people; i++) {
        cout << endl << "Enter vote (" << i << ") person: ";
        cin >> choice;
        if (choice == 1 || choice == 2) {
            if (choice == 1) {
                faisal_vote++;
            }
            if (choice == 2) {
                Ehtasham_vote++;
            }
        }
        else {
            cout << "Invalid input!";
            return 0;
        }
    }
    if (faisal_vote == Ehtasham_vote) {
        cout << "Tie! Enter the final vote (1 or 2): ";
        cin >> choice;
        if (choice == 1 || choice == 2) {
            if (choice == 1) {
                faisal_vote++;
            }
            if (choice == 2) {
                Ehtasham_vote++;
            }
        }
        else {
            cout << "Invalid input!";
            return 0;
        }
    }
    file << "Faisal:" << faisal_vote << "\t\t Ehtasham:" << Ehtasham_vote;
    if (faisal_vote > Ehtasham_vote) {
        system("cls");
        cout << "Winner is Faisal Khan!\n its votes are :" << faisal_vote << endl;
        return system("pause");

    }
    else if(faisal_vote < Ehtasham_vote){
        system("cls");
    cout << "Winner is Ehtasham!\n its votes are :" << Ehtasham_vote << endl;
    return system("pause");
    }
    else
    {
        system("cls");
        cout << "No one is winner!\n its votes are : " << faisal_vote<<":"<<Ehtasham_vote << endl;
        return system("pause");
    }
    return 0;
}

void politics::coruption(int x) {
    if (x == 1) {

        faisal_money = 2000;
        money -= 1000;
        revolt();
    }
    else {
        cout << "there is no revolt:";
    }
}
 
void politics::revolt() {
    if (faisal_vote>Ehtasham_vote) {
        cout << "There is corruption by Faisal Khan!\n";
        cout << "Revolt started!\n";
        cout << "Elections will be held again!\n";
        
        Election();
    }
    else if (faisal_vote < Ehtasham_vote) {
        cout << "There is corruption by Ehtasham!\n";
        cout << "Revolt started!\n";
        Election();

    }
    else
    {
        cout << "There is corruption by these both:";
        cout << "Revolt started!\n";
        Election();
    }
}

void population::disease() {
    srand(time(0));
    int num = rand() % 80 + 60;

    if (num <= 120 && num >= 80) {
        cout << "Person is healthy" << endl;
    }
    else if (num <= 70 || num >= 130) {
        if (people > 0) {
            people--;
            cout << "Remaining persons are: " << people << endl;
        }
    }
    else {
        cout << endl << "Person is ill!";
    }
}

void KingdomEngine::femine() {
    srand(time(0));
    int food = rand() % 100;
    if (food < 40 && food > 30) {
        cout << "Famine occurred!\n";
        people -= 4;
        cout << "Remaining persons are: " << people << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if ((i == 1 && j == 14) || (i == 1 && j == 15)) {
                    ptr[i][j] = ' ';
                }
            }
        }
        famine = true;
        money -= 400;
        amount -= 400;
        cout << "Food storage destroyed and money lost due to famine!\n";
        displayKingdom();
    }
    else {
        cout << "Famine does not occure:\n";
    }
}

void KingdomEngine::weather() {
    srand(time(0));
    int condition = rand() % 50;
    system("cls");
    if (condition == 22) {
        cout << endl << "It is raining in our kingdom!\n";
    }
    else if (condition > 15 && condition < 30) {
        cout << "The weather condition is normal!\n";
    }
    else if (condition < 15) {
        cout << "The weather condition is partially cloudy!\n";
    }
    else {
        cout << "The weather is too hot!\n";
    }
    system("pause");
    displayKingdom();
    return ;
}

int politics::war() {
    srand(time(0));
    int posibility = rand() % 50;
    system("cls");
    if (posibility == 25) {
        cout << "No one won the war!\n";
        cout << "War was tied!\n";
    }
    else if (posibility < 25 && posibility >= 0) {
        cout << "You lost the war!\n";
        cout << "There will be a large loss in kingdom!\n";
        money -= 200;
        people -= 4;
        destroyArmy();
    }
    else if (posibility > 25) {
        cout << "You won the war!\n";
        cout << "There will be a large advantage in everything!\n";
        money += 200;
        people += 4;
    }
    system("pause");
    return 0;
}

void politics::politicsDetail() {
    cout << endl << "There are two politicians:\n";
    cout << "1) Faisal\n";
    cout << "2) Ehtasham\n";
}

void bank::showBankDetails() {
    cout << endl << "In this bank the money is: " << amount;
}
void army::destroyArmy() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 2 && (j == 5 || j == 6)) {
                ptr[i][j] = ' ';
            }
        }
    }
}

int politics::moneyUpdate(int x) {
    money += x;
    return 0;
}
void bank::updateAmount(int x) {
    amount += x;
}

void army::restoreArmy() {
    int armyGenerator = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 2 && j > 2 && j <= 6) {
                if (armyGenerator == 0) { ptr[i][j] = 'A'; }
                if (armyGenerator == 1) { ptr[i][j] = 'R'; }
                if (armyGenerator == 2) { ptr[i][j] = 'M'; }
                if (armyGenerator == 3) { ptr[i][j] = 'Y'; }
                armyGenerator++;
            }
        }
    }
}
void population::addPeople() {
    people += 2;
}
void population::restorePeople() {
    people = 10;
}
void population::removePopulatoion()
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            if (ptr[i][j] == 'L')
            {
                ptr[i][j] = ' ';
            }
        }
    }
}
void population::cleanPopulation()
{
    delete[] PointerToShowPeople[0];
    delete[]  PointerToShowPeople;
}
void economy::foodComsume()
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            if (i == 1 && (j == 14 || j == 15))
            {
                ptr[i][j] = ' ';
            }
        }
    }
    cout << "Half food consumed by the army:" << endl;
    displayKingdom();
    system("pause");
    system("cls");
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            if (i == 2 && (j == 14 || j == 15))
            {
                ptr[i][j] = ' ';
            }
        }
    }
    cout << "Half food consumed by the public:" << endl;
    displayKingdom();
    system("pause");
    system("cls");
}
void economy::restoreFood()
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            if (i == 1 && j == 14) { ptr[i][j] = 'F'; }
            else if ((i == 1 && j == 15) || (i == 2 && j == 14)) { ptr[i][j] = 'O'; }
            else if (i == 2 && j == 15) { ptr[i][j] = 'D'; }
        }
    }
}