#pragma once

#include "Student.h"
#include "Assignment.h"

class Submission
{
private:
    static inline int idCounter = 0;
    int id;
    Student *student;
    int studentId;
    Assignment *assignment;
    int assignmentId;
    double grade;
    string timeOfSubmission;

public:
    Submission()
    {
        this->id = ++idCounter;
        this->grade = 0;
    }
    Submission(Student *student, Assignment *assignment, double grade = 0, string timeOfSubmission = "")
    {
        this->id = ++idCounter;
        this->setStudent(student);
        this->setAssignment(assignment);
        this->setGrade(grade);
        this->setTimeOfSubmission(timeOfSubmission);
    }

    // getters
    int getId() { return this->id; }
    Student *getStudent() { return this->student; }
    int getStudentId() { return this->studentId; }
    Assignment *getAssignment() { return this->assignment; }
    int getAssignmentId() { return this->assignmentId; }
    double getGrade() { return this->grade; }
    string getTimeOfSubmission() { return this->timeOfSubmission; }

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
    bool setAssignment(Assignment *assignment)
    {
        // TODO: validation
        this->assignment = assignment;
        return true;
    }
    bool setAssignmentId(int assignmentId)
    {
        // TODO: validation
        this->assignmentId = assignmentId;
        return true;
    }
    bool setGrade(double grade)
    {
        // TODO: validation
        this->grade = grade;
        return true;
    }
    bool setTimeOfSubmission(string timeOfSubmission)
    {
        // TODO: validation
        this->timeOfSubmission = timeOfSubmission;
        return true;
    }

    // other
    static vector<Submission *> getSubmissionsByStudentId(int studentId)
    {
        vector<Submission *> submissions;
        for (int i = 0; i < allSubmissions.size(); i++)
        {
            if (allSubmissions[i]->getStudentId() == studentId)
            {
                submissions.push_back(allSubmissions[i]);
            }
        }
        return submissions;
    }

    static inline vector<Submission *> allSubmissions = {};
};