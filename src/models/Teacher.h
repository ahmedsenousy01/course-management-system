#pragma once
#include <string>
#include <vector>
using namespace std;

#include "_Person.h"
#include "Course.h"

class Teacher : public Person
{
private:
    static inline int numberOfTeachers = 22000;

    double salary;
    vector<Course *> courses;

public:
    Teacher()
    {
        numberOfTeachers++;
        this->setId(numberOfTeachers);
    }
    Teacher(string name, string email, string password, string phoneNumber, string banKAccountNumber, double salary, vector<Course *> courses = {}) : Person(name, email, password, phoneNumber)
    {
        numberOfTeachers++;
        this->setId(numberOfTeachers);
        setName(name);
        setEmail(email);
        setPhoneNumber(phoneNumber);
        setSalary(salary);
        setCourses(courses);
    }

    // Getters
    double getSalary() { return salary; }
    vector<Course *> getCourses() { return this->courses; }

    // Setters
    bool setSalary(double salary)
    {
        // TODO: validation
        this->salary = salary;
        return true;
    }
    bool setCourses(vector<Course *> courses)
    {
        // TODO: validation
        this->courses = courses;
        return true;
    }

    // other
    static Teacher *getTeacherByCourseId(int courseId)
    {
        for (int i = 0; i < allTeachers.size(); i++)
        {
            if (allTeachers[i]->getCourses().size() > 0)
            {
                for (int j = 0; j < allTeachers[i]->getCourses().size(); j++)
                {
                    if (allTeachers[i]->getCourses()[j]->getId() == courseId)
                    {
                        return allTeachers[i];
                    }
                }
            }
        }
        return nullptr;
    }

    static inline vector<Teacher *> allTeachers = {};
};