#include <iostream>
#include "Car.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        // create a default car
        Car defaultCar;
        cout << defaultCar << endl;

        // create a car with parameters
        Car customCar("Toyota", "Червоний", 2.5, 150);
        cout << customCar << endl;

        Car customCar1("BMW", "Чорний", 2.5, 150);
        cout << customCar1 << endl;

        // increasing the power
        customCar += 50;
        cout << "Після збільшення потужності:\n" << customCar << endl;

        // input of a new car
        Car newCar;
        cin >> newCar;
        cout << newCar << std::endl;

        // search for a car by brand
        if (newCar.search("Toyota")) {
            cout << "Знайдено автомобіль марки Toyota!" << endl;
        }

        if (newCar.search("BMW")) {
            cout << "Знайдено автомобіль марки BMW!" << endl;
        }

        // search for a car by power
        if (newCar.search(200)) {
            cout << "Знайдено автомобіль з потужністю 200 к.с.!" << endl;
        }

        if (newCar.search(150)) {
            cout << "Знайдено автомобіль з потужністю 150 к.с.!" << endl;
        }

        // search for a car by volume
        if (customCar.search(2.5)) {
            cout << "Знайдено автомобіль з об'ємом двигуна 2.5 л!" << endl;
        }

    }
    catch (const invalid_argument& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}

