//This is our OOP Project main file that contains the main game implimentation
#include<iostream>
#include "Header.h"
#include <conio.h>
#include <cstdlib>


int main() {
    politics game;
    int choice;
    bool running = true;

    game.setVal();
    game.initializePeople();
    game.setPopulation();
    game.setArmy();
    game.setResource();
    game.setBank();
    game.setPolitics();

    while (running) {
        system("cls");
        game.removePopulatoion();
        game.initializePeople();
        game.setPopulation();
        game.displayKingdom();
        game.information();
        game.showEconomy();
        game.showBankDetails();

        cout << "\n\n=== KINGDOM MANAGEMENT ===";
        cout << "\n1. Check Weather";
        cout << "\n2. Check Population";
        cout << "\n3.Consume Food";
        cout << "\n4. Hold Election";
        cout << "\n5. Check for Corruption";
        cout << "\n6. Check for Disease";
        cout << "\n7. Check for Famine";
        cout << "\n8. Check for War";
        cout << "\n9. Restore Army (Cost: 200)";
        cout << "\n10. Add People (Cost: 100)";
        cout << "\n11. Restore People (Cost: 300)";
        cout << "\n12.Restore Food (Cost:300)";
        cout << "\n00. Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;// no need to write limit 
 

        system("cls");
        switch (choice) {
        case 1: {
            game.weather(); 
            game.moneyUpdate(100);
            game.updateAmount(100);
            break;

        }
        case 2: {
            game.populationDetail();
            game.moneyUpdate(100);
            game.updateAmount(100);
            break;
        }
        case 3:
        {
            game.foodComsume();
            game.moneyUpdate(100);
            game.updateAmount(100);
            break;
        }
        case 4: {
            game.Election(); 
            game.moneyUpdate(100);
            game.updateAmount(100);
            break;
        }
        case 5:
        {
            int corup;
            cout << "\n If u want corruption then press 1 otherwise press any key:";
            cin >> corup;
             game.coruption(corup);
        }
        case 6: {
            game.disease(); 
            game.moneyUpdate(100);
            game.updateAmount(100);
            break;
        }

        case 7: {
            game.femine();
            game.moneyUpdate(100);
            game.updateAmount(100);
            break;
        }

        case 8: { game.war();
            game.moneyUpdate(100);
            game.updateAmount(100);
            break; 
        }
        case 9: {
            if (money >= 200) {
                 game.moneyUpdate(-200);
                 game.updateAmount(-200);
                game.restoreArmy();
                cout << "Army restored!";
            }
            else {
                cout << "Not enough money!";
            }
            break;
        }
        case 10: {
            if (money >= 100) {
                game.moneyUpdate(-100);
                game.updateAmount(-100);
                game.addPeople();
                cout << "People added!";
            }
            else {
                cout << "Not enough money!";
            }
            break;
        }
        case 11:
        {
            if (money >= 300) {
                game.moneyUpdate(-300);
                game.updateAmount(-300);
                cout << "Population restored!";
                game.restorePeople();
            }
            else {
                cout << "Not enough money!";
            }
            break;
        }
        case 12:
        {
            if (money >= 300 && amount >= 300)
            {
                game.restoreFood();
                game.moneyUpdate(-300);
                game.updateAmount(-300);
            }
            else {
                cout << "\n balance shortage:";
            }
            break;
        }
        case 00: running = false; break;
        default: cout << "Invalid choice!";
            system("pause");
        }
        game.cleanPopulation();
        if (amount <= 0) { amount = 0; }
        if (money <= 0) { money = 0; }
        cout << "\nPress enter to continue...";
        cin.get();
    }
    return 0;
}