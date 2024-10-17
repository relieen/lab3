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
        Car customCar("Toyota", "��������", 2.5, 150);
        cout << customCar << endl;

        Car customCar1("BMW", "������", 2.5, 150);
        cout << customCar1 << endl;

        // increasing the power
        customCar += 50;
        cout << "ϳ��� ��������� ���������:\n" << customCar << endl;

        // input of a new car
        Car newCar;
        cin >> newCar;
        cout << newCar << std::endl;

        // search for a car by brand
        if (newCar.search("Toyota")) {
            cout << "�������� ��������� ����� Toyota!" << endl;
        }

        if (newCar.search("BMW")) {
            cout << "�������� ��������� ����� BMW!" << endl;
        }

        // search for a car by power
        if (newCar.search(200)) {
            cout << "�������� ��������� � ��������� 200 �.�.!" << endl;
        }

        if (newCar.search(150)) {
            cout << "�������� ��������� � ��������� 150 �.�.!" << endl;
        }

        // search for a car by volume
        if (customCar.search(2.5)) {
            cout << "�������� ��������� � ��'���� ������� 2.5 �!" << endl;
        }

    }
    catch (const invalid_argument& e) {
        cerr << "�������: " << e.what() << endl;
    }

    return 0;
}

