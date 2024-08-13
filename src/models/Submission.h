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
    string submissionDate;

public:
    Submission()
    {
        this->id = ++idCounter;
        this->grade = 0;
    }
    Submission(Student *student, Assignment *assignment, double grade = 0, string submissionDate = "")
    {
        this->id = ++idCounter;
        this->setStudent(student);
        this->setAssignment(assignment);
        this->setGrade(grade);
        this->setSubmissionDate(submissionDate);
    }

    // getters
    int getId() { return this->id; }
    Student *getStudent() { return this->student; }
    Assignment *getAssignment() { return this->assignment; }
    double getGrade() { return this->grade; }
    string getSubmissionDate() { return this->submissionDate; }

    // setters
    bool setStudent(Student *student)
    {
        // TODO: validation
        this->student = student;
        return true;
    }
    bool setAssignment(Assignment *assignment)
    {
        // TODO: validation
        this->assignment = assignment;
        return true;
    }
    bool setGrade(double grade)
    {
        // TODO: validation
        this->grade = grade;
        return true;
    }
    bool setSubmissionDate(string submissionDate)
    {
        // TODO: validation
        this->submissionDate = submissionDate;
        return true;
    }
};