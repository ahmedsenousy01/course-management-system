#pragma once

#include <iostream>
using namespace std;

class StudentViews
{
public:
    static int printStudentMenu()
    {
        cout << "1. view available courses\n";
        cout << "2. view student courses\n";
        cout << "3. enroll in a course\n";
        cout << "4. view course details\n";
        cout << "5. logout\n";

        int choice;
        cin >> choice;

        if (choice < 1 || choice > 5)
            return -1;

        return choice;
    }
};