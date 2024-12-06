#include <iostream>
#include <string>
#include <cmath>
#include <fstream>



int main() {
    using namespace std; // Simplify the code by eliminating repeated std::
    CityList cityList;   // Create a linked list to manage cities

    string command;
    while (true) {
        cout << "\nEnter command (add, delete, search, display, quit): ";
        cin >> command;

        if (command == "add") {
            cityList.addCity();
        } else if (command == "delete") {
            string name, country;
            cout << "Enter city name: ";
            cin >> name;
            cout << "Enter country: ";
            cin >> country;
            cityList.deleteCity(name, country);
        } else if (command == "search") {
            string name;
            cout << "Enter city name: ";
            cin >> name;
            cityList.searchCity(name);
        } else if (command == "display") {
            cityList.displayAllCities();
        } else if (command == "quit") {
            break;
        } else {
            cout << "Invalid command.\n";
        }
    }

    return 0;
}