#pragma once

#include <string>
#include <vector>
using namespace std;

#include "Teacher.h"
#include "Student.h"
#include "Assignment.h"

class Course
{
private:
    static inline int idCounter = 0;
    int id;
    string title, description;
    double price;

    Teacher *teacher;
    vector<Student *> students;
    vector<Assignment *> assignments;

public:
    Course()
    {
        this->id = ++idCounter;
        this->title = "";
        this->description = "";
        this->price = 0;
        this->teacher = nullptr;
        this->students = vector<Student *>();
        this->assignments = vector<Assignment *>();
    }

    Course(string title, string description, double price, Teacher *teacher, vector<Student *> students = {}, vector<Assignment *> assignments = {})
    {
        this->id = ++idCounter;
        setTitle(title);
        setDescription(description);
        setPrice(price);
        setTeacher(teacher);
        setStudents(students);
        setAssignments(assignments);
    }

    // getters
    int getId() { return this->id; }
    string getTitle() { return this->title; }
    string getDescription() { return this->description; }
    double getPrice() { return this->price; }
    Teacher *getTeacher() { return this->teacher; }
    vector<Student *> getStudents() { return this->students; }
    vector<Assignment *> getAssignments() { return this->assignments; }

    // setters
    bool setTitle(string title)
    {
        // TODO: validation
        this->title = title;
        return true;
    }
    bool setDescription(string description)
    {
        // TODO: validation
        this->description = description;
        return true;
    }
    bool setPrice(double price)
    {
        // TODO: validation
        this->price = price;
        return true;
    }
    bool setTeacher(Teacher *teacher)
    {
        // TODO: validation
        this->teacher = teacher;
        return true;
    }
    bool setStudents(vector<Student *> students)
    {
        // TODO: validation
        this->students = students;
        return true;
    }
    bool setAssignments(vector<Assignment *> assignments)
    {
        // TODO: validation
        this->assignments = assignments;
        return true;
    }
};