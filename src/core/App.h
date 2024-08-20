#pragma once

#include <iostream>
using namespace std;

#include "Database.h"

#include "../controllers/student.controller.h"
#include "../controllers/teacher.controller.h"

#include "../views/generic.views.h"

#include "../models/Student.h"
#include "../models/Teacher.h"

class App
{
public:
    static bool init()
    {
        Database::init();
        // print login menu (student or teacher)
        while (true)
        {

            int choice = GenericViews::printLoginMenu();
            // call the suitable controller::router(currentUser)
            switch (choice)
            {
            case 1:
            {
                string email, password;
                cout << "enter email: \n";
                cin >> email;
                cout << "enter password: \n";
                cin >> password;
                Teacher *currentUser = TeacherController::login(email, password);
                if (currentUser)
                {
                    if (TeacherController::router(currentUser))
                    {
                        continue;
                    }
                }
                else
                {
                    cout << "invalid email or password\n";
                }
                break;
            }
            case 2:
            {
                string email, password;
                cout << "enter email: \n";
                cin >> email;
                cout << "enter password: \n";
                cin >> password;
                Student *currentUser = StudentController::login(email, password);
                if (currentUser)
                {
                    if (StudentController::router(currentUser))
                    {
                        continue;
                    }
                }
                else
                {
                    cout << "invalid email or password\n";
                }
                break;
            }
            case 3:
            {
                int choice = GenericViews::printRegisterMenu();
                switch (choice)
                {
                case 1:
                {
                    string name, email, password, phoneNumber;
                    cout << "enter name: \n";
                    cin >> name;
                    cout << "enter email: \n";
                    cin >> email;
                    cout << "enter password: \n";
                    cin >> password;
                    cout << "enter phone number: \n";
                    cin >> phoneNumber;
                    Teacher *currentUser = TeacherController::registerTeacher(name, email, password, phoneNumber);
                    if (currentUser)
                    {
                        if (TeacherController::router(currentUser))
                        {
                            continue;
                        }
                    }
                    else
                    {
                        cout << "invalid email or password\n";
                    }
                    break;
                }
                case 2:
                {
                    string name, email, password, phoneNumber;
                    cout << "enter name: \n";
                    cin >> name;
                    cout << "enter email: \n";
                    cin >> email;
                    cout << "enter password: \n";
                    cin >> password;
                    cout << "enter phone number: \n";
                    cin >> phoneNumber;
                    Student *currentUser = StudentController::registerStudent(name, email, password, phoneNumber);
                    if (currentUser)
                    {
                        if (StudentController::router(currentUser))
                        {
                            continue;
                        }
                    }
                    else
                    {
                        cout << "invalid email or password\n";
                    }
                    break;
                }
                case 3:
                {
                    break;
                }
                }
            case 4:
            {
                Database::saveAllData();
                return true;
            }
            default:
            {
                Database::saveAllData();
            }
            }
            }
        }
    }
};