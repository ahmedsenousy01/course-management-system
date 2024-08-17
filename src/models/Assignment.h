#pragma once
#include <vector>

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
    vector<Submission *> submissions;
    double maxGrade;
    string deadline;

public:
    Assignment()
    {
        this->id = ++idCounter;
        this->title = "";
        this->course = nullptr;
        this->maxGrade = 0;
        this->deadline = "";
        this->submissions = vector<Submission *>();
    }
    Assignment(string title, Course *course, double maxGrade = 0, string deadline = "", vector<Submission *> submissions = {})
    {
        this->id = ++idCounter;
        this->setTitle(title);
        this->setCourse(course);
        this->setMaxGrade(maxGrade);
        this->setDeadline(deadline);
        this->setSubmissions(submissions);
    }

    // getters
    int getId() { return this->id; }
    string getTitle() { return this->title; }
    Course *getCourse() { return this->course; }
    int getCourseId() { return this->courseId; }
    vector<Submission *> getSubmissions() { return this->submissions; }
    double getMaxGrade() { return this->maxGrade; }
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
    bool setSubmissions(vector<Submission *> submissions)
    {
        // TODO: validation
        this->submissions = submissions;
        return true;
    }
    bool setMaxGrade(double maxGrade)
    {
        // TODO: validation
        this->maxGrade = maxGrade;
        return true;
    }
    bool setDeadline(string deadline)
    {
        // TODO: validation
        this->deadline = deadline;
        return true;
    }

    // other
    static vector<Assignment *> getAssignmentsByCourseId(int courseId)
    {
        vector<Assignment *> assignments;
        for (int i = 0; i < allAssignments.size(); i++)
        {
            if (allAssignments[i]->getCourseId() == courseId)
            {
                assignments.push_back(allAssignments[i]);
            }
        }
        return assignments;
    }

    static Assignment *getAssignmentBySubmissionId(int submissionId)
    {
        for (int i = 0; i < allAssignments.size(); i++)
        {
            if (allAssignments[i]->getSubmissions().size() > 0)
            {
                for (int j = 0; j < allAssignments[i]->getSubmissions().size(); j++)
                {
                    if (allAssignments[i]->getSubmissions()[j]->getId() == submissionId)
                    {
                        return allAssignments[i];
                    }
                }
            }
        }
        return nullptr;
    }

    static inline vector<Assignment *> allAssignments = {};
};