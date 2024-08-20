#pragma once
#include <string>
#include <vector>
using namespace std;

#include "_Person.h"
#include "Course.h"
#include "Purchase.h"
#include "Progress.h"
#include "Submission.h"

class Student : public Person
{
private:
    static inline int numberOfStudents = 11000;

    vector<Course *> *courses;
    vector<Purchase *> *purchases;
    vector<Progress *> *progress;
    vector<Submission *> *submissions;

public:
    Student()
    {
        numberOfStudents++;
        this->setId(numberOfStudents);
    }
    Student(string name, string email, string phoneNumber, vector<Course *> *courses = {}, vector<Purchase *> *purchases = {}, vector<Progress *> *progress = {}, vector<Submission *> *submissions = {})
    {
        numberOfStudents++;
        this->setId(numberOfStudents);
        setName(name);
        setEmail(email);
        setPhoneNumber(phoneNumber);
        setCourses(courses);
        setPurchases(purchases);
        setProgress(progress);
        setSubmissions(submissions);
    }

    // getters
    vector<Course *> *getCourses() { return this->courses; }
    vector<Purchase *> *getPurchases() { return this->purchases; }
    vector<Progress *> *getProgress() { return this->progress; }
    vector<Submission *> *getSubmissions() { return this->submissions; }

    // setters
    bool setCourses(vector<Course *> *courses)
    {
        // TODO: validation
        this->courses = courses;
        return true;
    }
    bool addCourse(Course *course)
    {
        // TODO: validation
        this->courses->push_back(course);
        return true;
    }
    bool setPurchases(vector<Purchase *> *purchases)
    {
        // TODO: validation
        this->purchases = purchases;
        return true;
    }
    bool setProgress(vector<Progress *> *progress)
    {
        // TODO: validation
        this->progress = progress;
        return true;
    }
    bool setSubmissions(vector<Submission *> *submissions)
    {
        // TODO: validation
        this->submissions = submissions;
        return true;
    }

    // others
    static Student *getStudentById(int studentId)
    {
        for (int i = 0; i < allStudents.size(); i++)
        {
            if (allStudents[i]->getId() == studentId)
            {
                return allStudents[i];
            }
        }
        return nullptr;
    }

    static Student *getStudentByEmail(string email)
    {
        for (int i = 0; i < allStudents.size(); i++)
        {
            if (allStudents[i]->getEmail() == email)
            {
                return allStudents[i];
            }
        }
        return nullptr;
    }
    static inline vector<Student *> allStudents = {};
};