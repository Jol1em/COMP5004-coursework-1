#include "manageCities.h"

int main() {
    ContinentList continentList;
    string command;

    while (true) {
        cout << "\nEnter command (addContinent, addCity, modifyCity, resolveDuplicates, display, quit): ";
        cin >> command;

        if (command == "addContinent") {
            string continentName;
            cout << "Enter continent name: ";
            cin >> continentName;
            continentList.addContinent(continentName);
        } else if (command == "addCity") {
            string continentName;
            cout << "Enter continent name to add a city: ";
            cin >> continentName;
            continentList.addCityToContinent(continentName);
        } else if (command == "modifyCity") {
            string continentName, cityName;
            cout << "Enter continent name: ";
            cin >> continentName;
            cout << "Enter city name to modify: ";
            cin >> cityName;
            continentList.modifyCityInContinent(continentName, cityName);
        } else if (command == "resolveDuplicates") {
            string continentName;
            cout << "Enter continent name to resolve duplicates: ";
            cin >> continentName;
            continentList.resolveDuplicatesInContinent(continentName);
        } else if (command == "display") {
            continentList.displayAllContinents();
        } else if (command == "quit") {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid command. Try again.\n";
        }
    }

    return 0;
}