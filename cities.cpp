#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

class CityList {
private
:
CityNode *head;

public
:
CityList() : head(nullptr) {
}

~CityList() {
    while (head) {
        CityNode *temp = head;
        head = head->next;
        delete temp;
    }
}

void addCity() {
    CityNode *newCity = new CityNode();
    cout << "Enter city name: ";
    cin << newCity->name;
    cout << "Enter country: ";
    cin << newCity->country;
    cout << "Enter population: ";
    cin << newCity->population;
    cout << "Enter year recorded: ";
    cin << newCity->year;
    cout << "Enter mayor's name: ";
    cin << newCity->mayor.name;
    cout << "Enter mayor's address: ";
    cin << newCity->mayor.address;
    cout << "Enter city history: ";
    cin.ignore();
    getline(std::cin, newCity->history);
    cout << "Enter latitude: ";
    cin >> newCity->coordinates.latitude;
    cout << "Enter longitude: ";
    cin >> newCity->coordinates.longitude;

    //insert at the beginning of the list
    newCity->next = head;
    head = newCity;
    cout << "City added successfully.\n";
}

// Created by 19237285 on 02/12/2024.
//
