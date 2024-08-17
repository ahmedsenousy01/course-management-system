#pragma once

#include <string>
#include <vector>
using namespace std;

#include "Teacher.h"
#include "Student.h"
#include "Assignment.h"
#include "Purchase.h"
#include "Progress.h"
#include "Enrollment.h"

class Course
{
private:
    static inline int idCounter = 0;
    int id;
    string title, description;
    double price;

    Teacher *teacher;
    int teacherId;
    vector<Student *> *students;
    vector<Assignment *> *assignments;
    vector<Purchase *> *purchases;
    vector<Progress *> *progresses;

public:
    Course()
    {
        this->id = ++idCounter;
        this->title = "";
        this->description = "";
        this->price = 0;
        this->teacher = nullptr;
        this->teacherId = 0;
        this->students = new vector<Student *>();
        this->assignments = new vector<Assignment *>();
        this->purchases = new vector<Purchase *>();
        this->progresses = new vector<Progress *>();
    }

    Course(string title, string description, double price, int teacherId, Teacher *teacher, vector<Student *> *students = {}, vector<Assignment *> *assignments = {}, vector<Purchase *> *purchases = {}, vector<Progress *> *progresses = {})
    {
        this->id = ++idCounter;
        setTitle(title);
        setDescription(description);
        setPrice(price);
        setTeacher(teacher);
        setTeacherId(teacherId);
        setStudents(students);
        setAssignments(assignments);
        setPurchases(purchases);
        setProgresses(progresses);
    }

    // getters
    int getId() { return this->id; }
    string getTitle() { return this->title; }
    string getDescription() { return this->description; }
    double getPrice() { return this->price; }
    Teacher *getTeacher() { return this->teacher; }
    int getTeacherId() { return this->teacherId; }
    vector<Student *> *getStudents() { return this->students; }
    vector<Assignment *> *getAssignments() { return this->assignments; }
    vector<Purchase *> *getPurchases() { return this->purchases; }
    vector<Progress *> *getProgresses() { return this->progresses; }

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
    bool setTeacherId(int teacherId)
    {
        // TODO: validation
        this->teacherId = teacherId;
        return true;
    }
    bool setStudents(vector<Student *> *students)
    {
        // TODO: validation
        this->students = students;
        return true;
    }
    bool addStudent(Student *student)
    {
        // TODO: validation
        this->students->push_back(student);
        return true;
    }
    bool setAssignments(vector<Assignment *> *assignments)
    {
        // TODO: validation
        this->assignments = assignments;
        return true;
    }
    bool addAssignment(Assignment *assignment)
    {
        // TODO: validation
        this->assignments->push_back(assignment);
        return true;
    }
    bool setPurchases(vector<Purchase *> *purchases)
    {
        // TODO: validation
        this->purchases = purchases;
        return true;
    }
    bool setProgresses(vector<Progress *> *progresses)
    {
        // TODO: validation
        this->progresses = progresses;
        return true;
    }

    // others
    static Course *getCourseById(int courseId)
    {
        for (int i = 0; i < allCourses.size(); i++)
        {
            if (allCourses[i]->getId() == courseId)
            {
                return allCourses[i];
            }
        }
        return nullptr;
    }

    static inline vector<Course *> allCourses = {};
};