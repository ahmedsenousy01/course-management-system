#pragma once

#include <iostream>
using namespace std;

class TeacherViews
{
public:
    static int printTeacherMenu()
    {
        cout << "1. view my courses\n";
        cout << "2. create a course\n";
        cout << "3. view course details\n";
        cout << "4. logout\n";

        int choice;
        cin >> choice;

        if (choice < 1 || choice > 4)
            return -1;

        return choice;
    }
};