#pragma once

#include <iostream>
using namespace std;

class GenericViews
{
public:
    static int printLoginMenu()
    {
        cout << "\n\n\t\t\t\t\t\t" << endl;
        cout << "Login As:" << endl;
        cout << "\t\t\t\t\t\t" << endl;
        cout << "1. Teacher" << endl;
        cout << "2. Student" << endl;
        cout << "3. Register" << endl;
        cout << "4. Quit" << endl;
        cout << "\t\t\t\t\t\t" << endl;

        int choice;
        cin >> choice;

        if (choice < 1 || choice > 4)
            return -1;

        return choice;
    }

    static int printRegisterMenu()
    {
        cout << "\n\n\t\t\t\t\t\t" << endl;
        cout << "Register As:" << endl;
        cout << "\t\t\t\t\t\t" << endl;
        cout << "1. Teacher" << endl;
        cout << "2. Student" << endl;
        cout << "3. Login" << endl;
        cout << "4. Quit" << endl;
        cout << "\t\t\t\t\t\t" << endl;

        int choice;
        cin >> choice;

        if (choice < 1 || choice > 4)
            return -1;

        return choice;
    }
};