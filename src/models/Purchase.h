#pragma once
#include <string>
using namespace std;

#include "Student.h"
#include "Course.h"

class Purchase
{
private:
    static inline int idCounter = 0;
    int id;
    Student *student;
    Course *course;
    string purchaseDate;

public:
    Purchase()
    {
        this->id = ++idCounter;
        this->purchaseDate = "";
    }
    Purchase(Student *student, Course *course, string purchaseDate)
    {
        this->id = ++idCounter;
        this->setCourse(course);
        this->setStudent(student);
        this->setPurchaseDate(purchaseDate);
    }

    // getters
    int getId() { return this->id; }
    Student *getStudent() { return this->student; }
    Course *getCourse() { return this->course; }
    string getPurchaseDate() { return this->purchaseDate; }

    // setters
    bool setStudent(Student *student)
    {
        // TODO: validation
        this->student = student;
        return true;
    }
    bool setCourse(Course *course)
    {
        // TODO: validation
        this->course = course;
        return true;
    }
    bool setPurchaseDate(string purchaseDate)
    {
        // TODO: validation
        this->purchaseDate = purchaseDate;
        return true;
    }
};