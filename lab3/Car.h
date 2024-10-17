#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

class Car {
private:
    char* brand;
    char* color;
    double engineVolume;
    int enginePower;

public:
    // Default constructor
    Car() {
        brand = new char[8];
        strcpy_s(brand, 8, "Unknown");
        color = new char[8];
        strcpy_s(color, 8, "Unknown");
        engineVolume = 0;
        enginePower = 0;
    }

    // Constructor with parameters
    Car(const char* br, const char* col, double vol, int pow) {
        brand = new char[strlen(br) + 1];
        strcpy_s(brand, strlen(br) + 1, br);
        color = new char[strlen(col) + 1];
        strcpy_s(color, strlen(col) + 1, col);

        setEngineVolume(vol);
        setEnginePower(pow);
    }

    // Destructor
    ~Car() {
        delete[] brand;
        delete[] color;
    }

    // Getters and setters
    double getEngineVolume() const {
        return engineVolume;
    }

    void setEngineVolume(double vol) {
        if (vol <= 0) throw std::invalid_argument("Об'єм двигуна має бути більшим за нуль.");
        engineVolume = vol;
    }

    int getEnginePower() const {
        return enginePower;
    }

    void setEnginePower(int pow) {
        if (pow <= 0) throw std::invalid_argument("Потужність двигуна має бути більшою за нуль.");
        enginePower = pow;
    }

    // Overloaded operators
    Car& operator+=(int extraPower) {
        if (extraPower <= 0) throw std::invalid_argument("Нарощення потужності має бути додатнім.");
        enginePower += extraPower;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Car& car) {
        out << "Автомобіль: Марка - " << car.brand
            << ", Колір - " << car.color
            << ", Об'єм двигуна - " << car.engineVolume << " л"
            << ", Потужність - " << car.enginePower << " к.с.";
        return out;
    }

    friend istream& operator>>(istream& in, Car& car) {
        char tempBrand[50];
        char tempColor[50];

        cout << "Введіть марку автомобіля: ";
        in >> tempBrand;
        delete[] car.brand;
        car.brand = new char[strlen(tempBrand) + 1];
        strcpy_s(car.brand, strlen(tempBrand) + 1, tempBrand);

        cout << "Введіть колір автомобіля: ";
        in >> tempColor;
        delete[] car.color;
        car.color = new char[strlen(tempColor) + 1];
        strcpy_s(car.color, strlen(tempColor) + 1, tempColor);

        cout << "Введіть об'єм двигуна: ";
        in >> car.engineVolume;
        if (car.engineVolume <= 0) throw invalid_argument("Об'єм двигуна має бути більшим за нуль.");

        cout << "Введіть потужність двигуна: ";
        in >> car.enginePower;
        if (car.enginePower <= 0) throw invalid_argument("Потужність має бути більшою за нуль.");

        return in;
    }

    // method overloading for search function
    bool search(const char* searchBrand) const {
        return strcmp(brand, searchBrand) == 0;
    }

    bool search(int searchPower) const {
        return enginePower == searchPower;
    }

    bool search(double searchVolume) const {
        return engineVolume == searchVolume;
    }
};

#endif
