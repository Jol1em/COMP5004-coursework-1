//
// Created by Jordi Folland on 17/12/2024.
//
#include "manageCities.h"

// ---------------- CityList Methods ----------------

// Constructor
CityList::CityList() : head(nullptr) {}

//Destructor
CityList::~CityList() {
    while (head) {
        CityNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Check if the list is empty
bool CityList::isEmpty() const {
    return head == nullptr;
}

// Add new city to the list
void CityList::addCity() {
    CityNode* newCity = new CityNode();

    // Collect city data from user
    cout << "Enter city name: ";
    cin >> newCity->name;
    cout << "Enter country: ";
    cin >> newCity->country;
    cout << "Enter population: ";
    cin >> newCity->population;
    cout << "Enter year recorded: ";
    cin >> newCity->yearRecorded;
    cout << "Enter mayor's name: ";
    cin >> newCity->mayor.name;
    cout << "Enter mayor's address: ";
    cin >> newCity->mayor.address;
    cout << "Enter city history: ";
    cin.ignore(); // To clear the input buffer
    getline(cin, newCity->history);
    cout << "Enter latitude: ";
    cin >> newCity->coordinates.latitude;
    cout << "Enter longitude: ";
    cin >> newCity->coordinates.longitude;

    // Insert at the begining of the list
    newCity->next = head;
    head = newCity;

    cout << "City added successfully!\n";
}

// Display all cities in the list
void CityList::displayCities() const {
    if (!head) {
        cout << "No cities in this continent.\n";
        return;
    }

    CityNode* current = head;
    while (current) {
        cout << "City: " << current->name << ", Country: " << current->country
             << ", Population: " << current->population
             << ", Year Recorded: " << current->yearRecorded
             << "\nMayor: " << current->mayor.name << ", Address: " << current->mayor.address
             << "\nCoordinates: (" << current->coordinates.latitude
             << ", " << current->coordinates.longitude << ")\n";
        cout << "History: " << current->history << "\n\n";
        current = current->next;
    }
}

// Search for a city by name and display its information
void CityList::searchCity(const string& cityName) const {
    CityNode* current = head;

    while (current) {
        if (current->name == cityName) {
            cout << "City Found!\n";
            cout << "City: " << current->name << ", Country: " << current->country
                 << ", Population: " << current->population
                 << ", Year Recorded: " << current->yearRecorded << "\n";
            cout << "Mayor: " << current->mayor.name << ", Address: " << current->mayor.address << "\n";
            cout << "Coordinates: (" << current->coordinates.latitude << ", " << current->coordinates.longitude << ")\n";
            cout << "History: " << current->history << "\n";
            return;
        }
        current = current->next;
    }

    cout << "City '" << cityName << "' not found.\n";
}

//modify an existing city's information
void CityList::modifyCity(const string& cityName) {
    CityNode* current = head;

    while (current) {
        if (current->name == cityName) {
            cout << "Updating city: " << current->name << "\n";
            cout << "Enter new country: ";
            cin >> current->country;
            cout << "Enter new population: ";
            cin >> current->population;
            cout << "Enter new year recorded: ";
            cin >> current->yearRecorded;
            cout << "Enter new latitude: ";
            cin >> current->coordinates.latitude;
            cout << "Enter new longitude: ";
            cin >> current->coordinates.longitude;

            cout << "City updated successfully!\n";
            return;
        }
        current = current->next;
    }

    cout << "City not found.\n";
}

// Resolve duplicates cities based on name and country
void CityList::resolveDuplicates() {
    CityNode* current = head;

    while (current) {
        CityNode* prev = current;
        CityNode* check = current->next;

        while (check) {
            if (check->name == current->name && check->country == current->country) {
                // Remove duplicate node
                prev->next = check->next;
                delete check;
                check = prev->next;
                cout << "Duplicate city '" << current->name << "' removed.\n";
            } else {
                prev = check;
                check = check->next;
            }
        }
        current = current->next;
    }
}

// Calculate the distance between two cities
double CityList::calculateDistance(const Coordinates& coord1, const Coordinates& coord2) const {
    const double R = 6371; // Earth radius in kilometers
    double lat1 = coord1.latitude * M_PI / 180.0;  // Convert to radians
    double lon1 = coord1.longitude * M_PI / 180.0;
    double lat2 = coord2.latitude * M_PI / 180.0;
    double lon2 = coord2.longitude * M_PI / 180.0;

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c;  // Distance in kilometers
}

// ContinentList functions

//Constructor
ContinentList::ContinentList() : head(nullptr) {}

// Destructor
ContinentList::~ContinentList() {
    while (head) {
        ContinentNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Add continent
void ContinentList::addContinent(const string& continentName) {
    if (continentExists(continentName)) {
        cout << "Continent already exists.\n";
        return;
    }

    ContinentNode* newContinent = new ContinentNode(continentName);
    newContinent->next = head;
    head = newContinent;

    cout << "Continent '" << continentName << "' added successfully.\n";
}

// Add city to a continent
void ContinentList::addCityToContinent(const string& continentName) {
    ContinentNode* current = head;
    while (current) {
        if (current->continentName == continentName) {
            current->cityList.addCity();
            return;
        }
        current = current->next;
    }
    cout << "Continent not found.\n";
}

// Search for a city within a specific continent by name
void ContinentList::searchCityInContinent(const string& continentName, const string& cityName) const {
    ContinentNode* current = head;

    while (current) {
        if (current->continentName == continentName) {
            current->cityList.searchCity(cityName);
            return;
        }
        current = current->next;
    }

    cout << "Continent '" << continentName << "' not found.\n";
}

// Serch for a city across all continents by name
void ContinentList::searchCityInAllContinents(const string& cityName) const {
    ContinentNode* current = head;
    bool found = false;

    while (current) {
        cout << "Searching in continent: " << current->continentName << "\n";
        current->cityList.searchCity(cityName);
        current = current->next;
    }

    if (!found) {
        cout << "City '" << cityName << "' not found in any continent.\n";
    }
}

// Modify a citys information in a continent
void ContinentList::modifyCityInContinent(const string& continentName, const string& cityName) {
    ContinentNode* current = head;
    while (current) {
        if (current->continentName == continentName) {
            current->cityList.modifyCity(cityName);
            return;
        }
        current = current->next;
    }
    cout << "Continent not found.\n";
}

// Resolve duplicate cities in a continent
void ContinentList::resolveDuplicatesInContinent(const string& continentName) {
    ContinentNode* current = head;
    while (current) {
        if (current->continentName == continentName) {
            current->cityList.resolveDuplicates();
            return;
        }
        current = current->next;
    }
    cout << "Continent not found.\n";
}

// Display all continents and their cities
void ContinentList::displayAllContinents() const {
    ContinentNode* current = head;
    while (current) {
        cout << "\nContinent: " << current->continentName << "\n";
        current->cityList.displayCities();
        current = current->next;
    }
}

//Check if a continent exists
bool ContinentList::continentExists(const string& continentName) const {
    ContinentNode* current = head;
    while (current) {
        if (current->continentName == continentName) return true;
        current = current->next;
    }
    return false;
}