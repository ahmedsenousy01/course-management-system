#pragma once

#include "Student.h"
#include "Course.h"

class Progress
{
private:
    static inline int idCounter = 0;
    int id;
    Student *student;
    Course *course;
    double progress;

public:
    Progress()
    {
        this->id = ++idCounter;
        this->progress = 0;
    }
    Progress(Student *student, Course *course, double progress = 0)
    {
        this->id = ++idCounter;
        this->setStudent(student);
        this->setCourse(course);
        this->setProgress(progress);
    }

    // getters
    int getId() { return this->id; }
    Student *getStudent() { return this->student; }
    Course *getCourse() { return this->course; }
    double getProgress() { return this->progress; }

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
    bool setProgress(double progress)
    {
        // TODO: validation
        this->progress = progress;
        return true;
    }
};