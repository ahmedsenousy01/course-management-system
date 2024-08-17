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

    vector<Course *> courses;
    vector<Purchase *> purchases;
    vector<Progress *> progress;
    vector<Submission *> submissions;

public:
    Student()
    {
        numberOfStudents++;
        this->setId(numberOfStudents);
    }
    Student(string name, string email, string password, string phoneNumber, vector<Course *> courses = {}, vector<Purchase *> purchases = {}, vector<Progress *> progress = {}, vector<Submission *> submissions = {}) : Person(name, email, password, phoneNumber)
    {
        numberOfStudents++;
        this->setId(numberOfStudents);
        setCourses(courses);
        setPurchases(purchases);
        setProgresses(progress);
        setSubmissions(submissions);
    }

    // getters
    vector<Course *> getCourses() { return this->courses; }
    vector<Purchase *> getPurchases() { return this->purchases; }
    vector<Progress *> getProgress() { return this->progress; }
    vector<Submission *> getSubmissions() { return this->submissions; }

    // setters
    bool setCourses(vector<Course *> courses)
    {
        // TODO: validation
        this->courses = courses;
        return true;
    }
    bool setPurchases(vector<Purchase *> purchases)
    {
        // TODO: validation
        this->purchases = purchases;
        return true;
    }
    bool setProgresses(vector<Progress *> progress)
    {
        // TODO: validation
        this->progress = progress;
        return true;
    }
    bool setSubmissions(vector<Submission *> submissions)
    {
        // TODO: validation
        this->submissions = submissions;
        return true;
    }

    // other
    static vector<Student *> getStudentsByCourseId(int courseId)
    {
        vector<Student *> students;
        for (int i = 0; i < allStudents.size(); i++)
        {
            if (allStudents[i]->getCourses().size() > 0)
            {
                for (int j = 0; j < allStudents[i]->getCourses().size(); j++)
                {
                    if (allStudents[i]->getCourses()[j]->getId() == courseId)
                    {
                        students.push_back(allStudents[i]);
                    }
                }
            }
        }
        return students;
    }

    static Student *getStudentsBySubmissionId(int submissionId)
    {
        for (int i = 0; i < allStudents.size(); i++)
        {
            if (allStudents[i]->getSubmissions().size() > 0)
            {
                for (int j = 0; j < allStudents[i]->getSubmissions().size(); j++)
                {
                    if (allStudents[i]->getSubmissions()[j]->getId() == submissionId)
                    {
                        return allStudents[i];
                    }
                }
            }
        }
        return nullptr;
    }

    static Student *getStudentByPurchaseId(int purchaseId)
    {
        for (int i = 0; i < allStudents.size(); i++)
        {
            if (allStudents[i]->getPurchases().size() > 0)
            {
                for (int j = 0; j < allStudents[i]->getPurchases().size(); j++)
                {
                    if (allStudents[i]->getPurchases()[j]->getId() == purchaseId)
                    {
                        return allStudents[i];
                    }
                }
            }
        }
        return nullptr;
    }

    static Student *getStudentByProgressId(int progressId)
    {
        for (int i = 0; i < allStudents.size(); i++)
        {
            if (allStudents[i]->getProgress().size() > 0)
            {
                for (int j = 0; j < allStudents[i]->getProgress().size(); j++)
                {
                    if (allStudents[i]->getProgress()[j]->getId() == progressId)
                    {
                        return allStudents[i];
                    }
                }
            }
        }
        return nullptr;
    }

    static inline vector<Student *> allStudents = {};
};