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
        this->courseId = 0;
        this->assignmentScore = 0;
        this->deadline = "";
    }
    Assignment(string title, int courseId, Course *course, double assignmentScore = 0, string deadline = "")
    {
        this->id = ++idCounter;
        this->setTitle(title);
        this->setCourse(course);
        this->setCourseId(courseId);
        this->setAssignmentScore(assignmentScore);
        this->setDeadline(deadline);
    }

    // getters
    int getId() { return this->id; }
    string getTitle() { return this->title; }
    Course *getCourse() { return this->course; }
    int getCourseId() { return this->courseId; }
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
    bool setCourseId(int courseId)
    {
        // TODO: validation
        this->courseId = courseId;
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

    // others
    static vector<Assignment *> *getAssignmentsByCourseId(int courseId)
    {
        vector<Assignment *> *assignments = {};
        for (int i = 0; i < allAssignments.size(); i++)
        {
            if (allAssignments[i]->getCourseId() == courseId)
            {
                assignments->push_back(allAssignments[i]);
            }
        }
        return assignments;
    }

    static inline vector<Assignment *> allAssignments = {};
};