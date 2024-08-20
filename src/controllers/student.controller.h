#pragma once

#include "../models/Student.h"
#include "../views/student.views.h"
#include "../repositories/student.repository.h"

class StudentController
{
public:
    static Student *login(string email, string password)
    {
        Student *s = Student::getStudentByEmail(email);
        if (s && s->getPassword() == password)
            return s;

        return nullptr;
    }

    static Student *registerStudent(string name, string email, string password, string phoneNumber)
    {
        return StudentRepository::create(name, email, password, phoneNumber);
    }

    static bool router(Student *currentUser)
    {
        // print student menu
        // take input from user
        int choice = StudentViews::printStudentMenu();
        // switch case to match input to function
        // PS. logout == return true
        switch (choice)
        {
        case 1:
        {
        }
        case 5:
        {
            return true;
        }
        default:
        {
        }
        }
    }
};