//
// Created by Jordi Folland on 17/12/2024.
//

#ifndef MANAGECITIES_H
#define MANAGECITIES_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Structure to hold coordinates (latitude and longitude)
struct Coordinates {
    double latitude;
    double longitude;
};

// Structure for Mayor information
struct Mayor {
    string name;
    string address;
};

// CityNode: Represents a single city
class CityNode {
public:
    string name;
    string country;
    int population;
    int yearRecorded;
    Mayor mayor;
    string history;
    Coordinates coordinates;
    CityNode* next;  // Pointer to the next city in the list

    CityNode() : next(nullptr) {}
};

// CityList: Represents a list of cities
class CityList {
private:
    CityNode* head;  // Pointer to the first city in the list

public:
    CityList();
    ~CityList();

    // Add a city to the list
    void addCity();

    // Display all cities in the list
    void displayCities() const;

    // Modify an existing city's information
    void modifyCity(const string& cityName);

    // Resolve duplicate cities based on name and country
    void resolveDuplicates();

    // Calculate distance between two cities using the Haversine formula
    double calculateDistance(const Coordinates& coord1, const Coordinates& coord2) const;

    // Check if the list is empty
    bool isEmpty() const;
};

// ContinentNode: Represents a continent containing cities
class ContinentNode {
public:
    string continentName;
    CityList cityList;
    ContinentNode* next;

    ContinentNode(const string& name) : continentName(name), next(nullptr) {}
};

// ContinentList: Represents a list of continents
class ContinentList {
private:
    ContinentNode* head;

public:
    ContinentList();
    ~ContinentList();

    // Add a continent
    void addContinent(const string& continentName);

    // Add a city to a continent
    void addCityToContinent(const string& continentName);

    // Modify a city's information in a continent
    void modifyCityInContinent(const string& continentName, const string& cityName);

    // Resolve duplicate cities in a continent
    void resolveDuplicatesInContinent(const string& continentName);

    // Display all continents and their cities
    void displayAllContinents() const;

    // Check if a continent exists
    bool continentExists(const string& continentName) const;
};

#endif //MANAGECITIES_H