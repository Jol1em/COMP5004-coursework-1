#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

struct Coordinates {
    double latitude;
    double longitude;
};

struct Mayor {
    std::string name;
    std::string address;
};

class City {
    std::string name;
    std::string country;
    int population;
    int year;
    Mayor mayor;
    std::string history;
    Coordinates coordinates;
    CityNode* next; //pointer to the next code in the list

    CityNode() : next(nullptr) {}
};

class CityList {
private:
    CityNode* head;

public:
    CityList() : head(nullptr) {}

    ~CityList() {
        while (head) {
            CityNode* temp = head;
            head = head -> next;
            delete temp;
        }
}

    void addCity() {
        CityNode* newCity = new CityNode();
        std::cout << "Enter city name: ";
        std::cin << newCity->name;
        std::cout << "Enter country: ";
        std::cin << newCity->country;
        std::cout << "Enter population: ";
        std::cin << newCity->population;
        std::cout << "Enter year recorded: ";
        std::cin << newCity->year;
        std::cout << "Enter mayor's name: ";
        std::cin << newCity->mayor.name;
        std::cout << "Enter mayor's address: ";
        std::cin << newCity->mayor.address;
        std::cout << "Enter city history: ";
        std::cin.ignore();
        std::getline(std::cin, newCity->history);
        std::cout << "Enter latitude: ";
        std::cin >> newCity->coordinates.latitude;
        std::cout << "Enter longitude: ";
        std::cin >> newCity->coordinates.longitude;

        //insert at the beginning of the list
        newCity ->next = head;
        head = newCity;
        std::cout << "City added successfully.\n";
    }


int main() {

    }
