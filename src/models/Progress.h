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
    double progress;

public:
    Progress()
    {
        this->id = ++idCounter;
        this->studentId = 0;
        this->courseId = 0;
        this->progress = 0;
    }
    Progress(int studentId, int courseId, Student *student, Course *course, double progress = 0)
    {
        this->id = ++idCounter;
        this->setStudent(student);
        this->setStudentId(studentId);
        this->setCourse(course);
        this->setCourseId(courseId);
        this->setProgress(progress);
    }

    // getters
    int getId() { return this->id; }
    Student *getStudent() { return this->student; }
    int getStudentId() { return this->studentId; }
    Course *getCourse() { return this->course; }
    int getCourseId() { return this->courseId; }
    double getProgress() { return this->progress; }

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
    bool setProgress(double progress)
    {
        // TODO: validation
        this->progress = progress;
        return true;
    }

    // others
    static vector<Progress *> *getProgressesByCourseId(int courseId)
    {
        vector<Progress *> *progresses = {};
        for (int i = 0; i < allProgresses.size(); i++)
        {
            if (allProgresses[i]->getCourseId() == courseId)
            {
                progresses->push_back(allProgresses[i]);
            }
        }
        return progresses;
    }

    static vector<Progress *> *getProgressesByStudentId(int studentId)
    {
        vector<Progress *> *progresses = {};
        for (int i = 0; i < allProgresses.size(); i++)
        {
            if (allProgresses[i]->getStudentId() == studentId)
            {
                progresses->push_back(allProgresses[i]);
            }
        }
        return progresses;
    }

    static inline vector<Progress *> allProgresses = {};
};