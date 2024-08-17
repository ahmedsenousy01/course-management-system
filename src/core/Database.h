#pragma once
#include <fstream>
using namespace std;

#include "../models/Student.h"
#include "../models/Teacher.h"
#include "../models/Course.h"
#include "../models/Assignment.h"
#include "../models/Submission.h"
#include "../models/Purchase.h"
#include "../models/Progress.h"

#include "Parser.h"

class Database
{
public:
    static void addStudent(Student *s)
    {
        ofstream file;
        file.open("data/students.txt", ios::app);
        file << s->getName() << "&" << s->getEmail() << "&" << s->getPassword() << "&" << s->getPhoneNumber() << endl;
        file.close();
    }

    static void addTeacher(Teacher *t)
    {
        ofstream file;
        file.open("data/teachers.txt", ios::app);
        file << t->getName() << "&" << t->getEmail() << "&" << t->getPassword() << "&" << t->getPhoneNumber() << endl;
        file.close();
    }

    static void addCourse(Course *c)
    {
        ofstream file;
        file.open("data/courses.txt", ios::app);
        file << c->getTitle() << "&" << c->getDescription() << "&" << c->getPrice() << "&" << c->getTeacherId() << endl;
        file.close();
    }

    static void addAssignment(Assignment *a)
    {
        ofstream file;
        file.open("data/assignments.txt", ios::app);
        file << a->getTitle() << "&" << a->getCourseId() << "&" << a->getMaxGrade() << "&" << a->getDeadline() << endl;
        file.close();
    }

    static void addSubmission(Submission *s)
    {
        ofstream file;
        file.open("data/submissions.txt", ios::app);
        file << s->getAssignmentId() << "&" << s->getStudentId() << "&" << s->getGrade() << "&" << s->getTimeOfSubmission() << endl;
        file.close();
    }

    static void addPurchase(Purchase *p)
    {
        ofstream file;
        file.open("data/purchases.txt", ios::app);
        file << p->getCourseId() << "&" << p->getStudentId() << "&" << p->getTimeOfPurchase() << endl;
        file.close();
    }

    static void addProgress(Progress *p)
    {
        ofstream file;
        file.open("data/progress.txt", ios::app);
        file << p->getCourseId() << "&" << p->getStudentId() << "&" << p->getPercentage() << endl;
        file.close();
    }

    static void getStudents()
    {
        ifstream file;
        file.open("data/students.txt");
        string line;
        while (getline(file, line))
        {
            Student::allStudents.push_back(Parser::parseStudent(line));
        }
        file.close();
    }

    static void getTeachers()
    {
        ifstream file;
        file.open("data/teachers.txt");
        string line;
        while (getline(file, line))
        {
            Teacher::allTeachers.push_back(Parser::parseTeacher(line));
        }
        file.close();
    }

    static void getCourses()
    {
        ifstream file;
        file.open("data/courses.txt");
        string line;
        while (getline(file, line))
        {
            Course::allCourses.push_back(Parser::parseCourse(line));
        }
        file.close();
    }

    static void getAssignments()
    {
        ifstream file;
        file.open("data/assignments.txt");
        string line;
        while (getline(file, line))
        {
            Assignment::allAssignments.push_back(Parser::parseAssignment(line));
        }
        file.close();
    }

    static void getSubmissions()
    {
        ifstream file;
        file.open("data/submissions.txt");
        string line;
        while (getline(file, line))
        {
            Submission::allSubmissions.push_back(Parser::parseSubmission(line));
        }
        file.close();
    }

    static void getPurchases()
    {
        ifstream file;
        file.open("data/purchases.txt");
        string line;
        while (getline(file, line))
        {
            Purchase::allPurchases.push_back(Parser::parsePurchase(line));
        }
        file.close();
    }

    static void getProgress()
    {
        ifstream file;
        file.open("data/progress.txt");
        string line;
        while (getline(file, line))
        {
            Progress::allProgresses.push_back(Parser::parseProgress(line));
        }
        file.close();
    }

    static void buildModelRelations()
    {
        for (int i = 0; i < Student::allStudents.size(); i++)
        {
            Student::allStudents[i]->setCourses(Course::getCoursesByStudentId(Student::allStudents[i]->getId()));

            Student::allStudents[i]->setSubmissions(Submission::getSubmissionsByStudentId(Student::allStudents[i]->getId()));

            Student::allStudents[i]->setPurchases(Purchase::getPurchasesByStudentId(Student::allStudents[i]->getId()));

            Student::allStudents[i]->setProgresses(Progress::getProgressesByStudentId(Student::allStudents[i]->getId()));
        }
        for (int i = 0; i < Teacher::allTeachers.size(); i++)
        {
            Teacher::allTeachers[i]->setCourses(Course::getCoursesByTeacherId(Teacher::allTeachers[i]->getId()));
        }
        for (int i = 0; i < Course::allCourses.size(); i++)
        {
            Course::allCourses[i]->setStudents(Student::getStudentsByCourseId(Course::allCourses[i]->getId()));

            Course::allCourses[i]->setTeacher(Teacher::getTeacherByCourseId(Course::allCourses[i]->getId()));

            Course::allCourses[i]->setAssignments(Assignment::getAssignmentsByCourseId(Course::allCourses[i]->getId()));
        }
        for (int i = 0; i < Assignment::allAssignments.size(); i++)
        {
            Assignment::allAssignments[i]->setCourse(Course::getCourseByAssignmentId(Assignment::allAssignments[i]->getId()));
        }
        for (int i = 0; i < Submission::allSubmissions.size(); i++)
        {
            Submission::allSubmissions[i]->setAssignment(Assignment::getAssignmentBySubmissionId(Submission::allSubmissions[i]->getId()));

            Submission::allSubmissions[i]->setStudent(Student::getStudentsBySubmissionId(Submission::allSubmissions[i]->getId()));
        }
        for (int i = 0; i < Purchase::allPurchases.size(); i++)
        {
            Purchase::allPurchases[i]->setCourse(Course::getCourseByPurchaseId(Purchase::allPurchases[i]->getId()));

            Purchase::allPurchases[i]->setStudent(Student::getStudentByPurchaseId(Purchase::allPurchases[i]->getId()));
        }
        for (int i = 0; i < Progress::allProgresses.size(); i++)
        {
            Progress::allProgresses[i]->setStudent(Student::getStudentByProgressId(Progress::allProgresses[i]->getId()));

            Progress::allProgresses[i]->setCourse(Course::getCourseByProgressId(Progress::allProgresses[i]->getId()));
        }
    }
};

/*
    student
    // name&email&password&phoneNumber
    teacher
    // name&email&password&phoneNumber&salary
    course
    // title&description&price&teacherId
    assignment
    // title&courseId&maxGrade&deadline
    submission
    // assignmentId&studentId&grade&timeOfSubmission
    purchase
    // courseId&studentId&timeOfPurchase
    progress
    // courseId&studentId&percentage
*/