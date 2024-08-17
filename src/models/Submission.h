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
        this->studentId = 0;
        this->assignmentId = 0;
        this->submissionDate = "";
    }
    Submission(int studentId, int assignmentId, Assignment *assignment, Student *student, double grade = 0, string submissionDate = "")
    {
        this->id = ++idCounter;
        this->setStudent(student);
        this->setStudentId(studentId);
        this->setAssignment(assignment);
        this->setAssignmentId(assignmentId);
        this->setGrade(grade);
        this->setSubmissionDate(submissionDate);
    }

    // getters
    int getId() { return this->id; }
    Student *getStudent() { return this->student; }
    int getStudentId() { return this->studentId; }
    Assignment *getAssignment() { return this->assignment; }
    int getAssignmentId() { return this->assignmentId; }
    double getGrade() { return this->grade; }
    string getSubmissionDate() { return this->submissionDate; }

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
    bool setSubmissionDate(string submissionDate)
    {
        // TODO: validation
        this->submissionDate = submissionDate;
        return true;
    }

    // others
    static vector<Submission *> *getSubmissionsByStudentId(int studentId)
    {
        vector<Submission *> *submissions = {};
        for (int i = 0; i < allSubmissions.size(); i++)
        {
            if (allSubmissions[i]->getStudentId() == studentId)
            {
                submissions->push_back(allSubmissions[i]);
            }
        }
        return submissions;
    }

    static inline vector<Submission *> allSubmissions = {};
};