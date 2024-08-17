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
    string purchaseDate;

public:
    Purchase()
    {
        this->id = ++idCounter;
        this->purchaseDate = "";
        this->studentId = 0;
        this->courseId = 0;
    }
    Purchase(int studentId, int courseId, Course *course, Student *student, string purchaseDate)
    {
        this->id = ++idCounter;
        this->setCourse(course);
        this->setCourseId(courseId);
        this->setStudent(student);
        this->setStudentId(studentId);
        this->setPurchaseDate(purchaseDate);
    }

    // getters
    int getId() { return this->id; }
    Student *getStudent() { return this->student; }
    int getStudentId() { return this->studentId; }
    Course *getCourse() { return this->course; }
    int getCourseId() { return this->courseId; }
    string getPurchaseDate() { return this->purchaseDate; }

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
    bool setPurchaseDate(string purchaseDate)
    {
        // TODO: validation
        this->purchaseDate = purchaseDate;
        return true;
    }
};