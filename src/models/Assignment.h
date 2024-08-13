#pragma once

#include "Student.h"
#include "Course.h"

class Assignment
{
private:
    static inline int idCounter = 0;
    int id;
    string title;
    Course *course;
    int courseId;
    double assignmentScore;
    string deadline;

public:
    Assignment()
    {
        this->id = ++idCounter;
        this->title = "";
        this->course = nullptr;
        this->assignmentScore = 0;
        this->deadline = "";
    }
    Assignment(string title, Course *course, double assignmentScore = 0, string deadline = "")
    {
        this->id = ++idCounter;
        this->setTitle(title);
        this->setCourse(course);
        this->setAssignmentScore(assignmentScore);
        this->setDeadline(deadline);
    }

    // getters
    int getId() { return this->id; }
    string getTitle() { return this->title; }
    Course *getCourse() { return this->course; }
    double getAssignmentScore() { return this->assignmentScore; }
    string getDeadline() { return this->deadline; }

    // setters
    bool setTitle(string title)
    {
        // TODO: validation
        this->title = title;
        return true;
    }
    bool setCourse(Course *course)
    {
        // TODO: validation
        this->course = course;
        return true;
    }
    bool setAssignmentScore(double assignmentScore)
    {
        // TODO: validation
        this->assignmentScore = assignmentScore;
        return true;
    }
    bool setDeadline(string deadline)
    {
        // TODO: validation
        this->deadline = deadline;
        return true;
    }
};