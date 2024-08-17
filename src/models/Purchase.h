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
    int studentId;
    Course *course;
    int courseId;
    string timeOfPurchase;

public:
    Purchase()
    {
        this->id = ++idCounter;
        this->timeOfPurchase = "";
    }
    Purchase(Student *student, Course *course, string timeOfPurchase)
    {
        this->id = ++idCounter;
        this->setCourse(course);
        this->setStudent(student);
        this->setTimeOfPurchase(timeOfPurchase);
    }

    // getters
    int getId() { return this->id; }
    Student *getStudent() { return this->student; }
    int getStudentId() { return this->studentId; }
    Course *getCourse() { return this->course; }
    int getCourseId() { return this->courseId; }
    string getTimeOfPurchase() { return this->timeOfPurchase; }

    // setters
    bool setStudent(Student *student)
    {
        // TODO: validation
        this->student = student;
        return true;
    }
    bool setStudentId(int studentId)
    {
        // TODO: validation
        this->studentId = studentId;
        return true;
    }
    bool setCourse(Course *course)
    {
        // TODO: validation
        this->course = course;
        return true;
    }
    bool setCourseId(int courseId)
    {
        // TODO: validation
        this->courseId = courseId;
        return true;
    }
    bool setTimeOfPurchase(string timeOfPurchase)
    {
        // TODO: validation
        this->timeOfPurchase = timeOfPurchase;
        return true;
    }

    // other
    static vector<Purchase *> getPurchasesByStudentId(int studentId)
    {
        vector<Purchase *> purchases;
        for (int i = 0; i < allPurchases.size(); i++)
        {
            if (allPurchases[i]->getStudentId() == studentId)
            {
                purchases.push_back(allPurchases[i]);
            }
        }
        return purchases;
    }

    static inline vector<Purchase *> allPurchases = {};
};