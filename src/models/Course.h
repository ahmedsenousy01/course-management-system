#pragma once

#include <string>
#include <vector>
using namespace std;

#include "Teacher.h"
#include "Student.h"
#include "Assignment.h"
#include "Purchase.h"

class Course
{
private:
    static inline int idCounter = 0;
    int id;
    string title, description;
    double price;

    Teacher *teacher;
    int teacherId;
    vector<Student *> students;
    vector<Assignment *> assignments;
    vector<Purchase *> purchases;
    vector<Progress *> progresses;

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
        this->purchases = vector<Purchase *>();
        this->progresses = vector<Progress *>();
    }

    Course(string title, string description, double price, Teacher *teacher, vector<Student *> students = {}, vector<Assignment *> assignments = {}, vector<Purchase *> purchases = {}, vector<Progress *> progresses = {})
    {
        this->id = ++idCounter;
        setTitle(title);
        setDescription(description);
        setPrice(price);
        setTeacher(teacher);
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
    vector<Student *> getStudents() { return this->students; }
    vector<Assignment *> getAssignments() { return this->assignments; }
    vector<Purchase *> getPurchases() { return this->purchases; }
    vector<Progress *> getProgresses() { return this->progresses; }

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
    bool setPurchases(vector<Purchase *> purchases)
    {
        // TODO: validation
        this->purchases = purchases;
        return true;
    }
    bool setProgresses(vector<Progress *> progresses)
    {
        // TODO: validation
        this->progresses = progresses;
        return true;
    }

    // other
    static vector<Course *> getCoursesByStudentId(int studentId)
    {
        vector<Course *> courses;
        for (int i = 0; i < allCourses.size(); i++)
        {
            if (allCourses[i]->getStudents().size() > 0)
            {
                for (int j = 0; j < allCourses[i]->getStudents().size(); j++)
                {
                    if (allCourses[i]->getStudents()[j]->getId() == studentId)
                    {
                        courses.push_back(allCourses[i]);
                    }
                }
            }
        }
        return courses;
    }

    static vector<Course *> getCoursesByTeacherId(int teacherId)
    {
        vector<Course *> courses = {};
        for (int i = 0; i < allCourses.size(); i++)
        {
            if (allCourses[i]->getTeacherId() == teacherId)
            {
                courses.push_back(allCourses[i]);
            }
        }
        return courses;
    }

    static Course *getCourseByAssignmentId(int assignmentId)
    {
        for (int i = 0; i < allCourses.size(); i++)
        {
            if (allCourses[i]->getAssignments().size() > 0)
            {
                for (int j = 0; j < allCourses[i]->getAssignments().size(); j++)
                {
                    if (allCourses[i]->getAssignments()[j]->getId() == assignmentId)
                    {
                        return allCourses[i];
                    }
                }
            }
        }
        return nullptr;
    }

    static Course *getCourseByPurchaseId(int purchaseId)
    {
        for (int i = 0; i < allCourses.size(); i++)
        {
            if (allCourses[i]->getPurchases().size() > 0)
            {
                for (int j = 0; j < allCourses[i]->getPurchases().size(); j++)
                {
                    if (allCourses[i]->getPurchases()[j]->getId() == purchaseId)
                    {
                        return allCourses[i];
                    }
                }
            }
        }
        return nullptr;
    }

    static Course *getCourseByProgressId(int progressId)
    {
        for (int i = 0; i < allCourses.size(); i++)
        {
            if (allCourses[i]->getProgresses().size() > 0)
            {
                for (int j = 0; j < allCourses[i]->getProgresses().size(); j++)
                {
                    if (allCourses[i]->getProgresses()[j]->getId() == progressId)
                    {
                        return allCourses[i];
                    }
                }
            }
        }
        return nullptr;
    }

    static inline vector<Course *> allCourses = {};
};