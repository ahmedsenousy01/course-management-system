#pragma once

#include <string>
using namespace std;

#include "../models/Student.h"
#include "../models/Teacher.h"

class StudentRepository
{
public:
    static Student *getById(int id)
    {
        for (auto s : Student::allStudents)
        {
            if (s->getId() == id)
                return s;
        }
        return nullptr;
    }

    static Student *getByEmail(string email)
    {
        for (auto s : Student::allStudents)
        {
            if (s->getEmail() == email)
                return s;
        }
        return nullptr;
    }

    static Student *create(string name, string email, string password, string phoneNumber)
    {
        Student *s = new Student();
        if (s->setName(name) && s->setEmail(email) && s->setPassword(password) && s->setPhoneNumber(phoneNumber))
        {
            Student::allStudents.push_back(s);
            return s;
        }
        return nullptr;
    }

    static Student *update(int id, string name, string email, string password, string phoneNumber)
    {
        Student *s = getById(id);
        if (s && s->setName(name) && s->setEmail(email) && s->setPassword(password) && s->setPhoneNumber(phoneNumber))
        {
            return s;
        }
        return nullptr;
    }

    static bool remove(int id)
    {
        for (int i = 0; i < Student::allStudents.size(); i++)
        {
            if (Student::allStudents[i]->getId() == id)
                Student::allStudents.erase(Student::allStudents.begin() + i);
        }
    }
};