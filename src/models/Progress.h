#pragma once

#include "Student.h"
#include "Course.h"

class Progress
{
private:
    static inline int idCounter = 0;
    int id;
    Student *student;
    int studentId;
    Course *course;
    int courseId;
    double percentage;

public:
    Progress()
    {
        this->id = ++idCounter;
        this->percentage = 0;
    }
    Progress(Student *student, Course *course, double percentage = 0)
    {
        this->id = ++idCounter;
        this->setStudent(student);
        this->setCourse(course);
        this->setPercentage(percentage);
    }

    // getters
    int getId() { return this->id; }
    Student *getStudent() { return this->student; }
    int getStudentId() { return this->studentId; }
    Course *getCourse() { return this->course; }
    int getCourseId() { return this->courseId; }
    double getPercentage() { return this->percentage; }

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
    bool setPercentage(double percentage)
    {
        // TODO: validation
        this->percentage = percentage;
        return true;
    }

    // other
    static vector<Progress *> getProgressesByStudentId(int studentId)
    {
        vector<Progress *> progresses;
        for (int i = 0; i < allProgresses.size(); i++)
        {
            if (allProgresses[i]->getStudentId() == studentId)
            {
                progresses.push_back(allProgresses[i]);
            }
        }
        return progresses;
    }

    static vector<Progress *> getProgressesByStudentId(int studentId)
    {
        vector<Progress *> progresses;
        for (int i = 0; i < allProgresses.size(); i++)
        {
            if (allProgresses[i]->getStudentId() == studentId)
            {
                progresses.push_back(allProgresses[i]);
            }
        }
        return progresses;
    }

    static inline vector<Progress *> allProgresses = {};
};