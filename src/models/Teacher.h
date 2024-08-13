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

    string banKAccountNumber;
    double salary;
    vector<Course *> courses;

public:
    Teacher()
    {
        numberOfTeachers++;
        this->setId(numberOfTeachers);
    }
    Teacher(string name, string email, string phoneNumber, string banKAccountNumber, double salary, vector<Course *> courses = {})
    {
        numberOfTeachers++;
        this->setId(numberOfTeachers);
        setName(name);
        setEmail(email);
        setPhoneNumber(phoneNumber);
        setBanKAccountNumber(banKAccountNumber);
        setSalary(salary);
        setCourses(courses);
    }

    // Getters
    string getBanKAccountNumber() { return banKAccountNumber; }
    double getSalary() { return salary; }
    vector<Course *> getCourses() { return this->courses; }

    // Setters
    bool setBanKAccountNumber(string banKAccountNumber)
    {
        // TODO: validation
        this->banKAccountNumber = banKAccountNumber;
        return true;
    }
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
};