#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string brand;
    string model;
    int year;

public:
    Vehicle(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }
    virtual string GetInfo() {
        cout<< "Brand: "  << brand  <<  ", Model: "   <<  model  <<  ", Year: "  <<  to_string(year);
    }
};
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(string b, string m, int y, int doors) 
        : Vehicle(b, m, y) {
        numDoors = doors;
    }
    string GetInfo() override {
        cout<< Vehicle::GetInfo() << ", Doors: " <<  to_string(numDoors);
    }
};
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(string b, string m, int y, bool sidecar) 
        : Vehicle(b, m, y) {
        hasSidecar = sidecar;
    }
    string GetInfo() override {
        string sidecarInfo = hasSidecar ? "Yes" : "No";
        cout << Vehicle::GetInfo()  <<  ", Has Sidecar: " <<  sidecarInfo;
    }
};
int main() {
    Car car1("Toyota", "Corolla", 2020, 4);
    Motorcycle bike1("Yamaha", "MT-07", 2021, false);
    cout << car1.GetInfo() << endl;
    cout << bike1.GetInfo() << endl;

    return 0;
}