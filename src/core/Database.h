#pragma once

#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "../models/Student.h"
#include "../models/Course.h"
#include "../models/Teacher.h"
#include "../models/Assignment.h"
#include "../models/Submission.h"
#include "../models/Purchase.h"
#include "../models/Progress.h"
#include "../models/Enrollment.h"

#include "../utils/Parser.h"

class Database
{
public:
    static void addStudent(Student *s)
    {
        fstream file("data/students.txt", ios::app);

        file << s->getName() << "&" << s->getEmail() << "&" << s->getPassword() << "&" << s->getPhoneNumber() << endl;

        file.close();
    }

    static void addTeacher(Teacher *t)
    {
        fstream file("data/teachers.txt", ios::app);

        file << t->getName() << "&" << t->getEmail() << "&" << t->getPassword() << "&" << t->getPhoneNumber() << "&" << t->getSalary() << endl;

        file.close();
    }

    static void addCourse(Course *c)
    {
        fstream file("data/courses.txt", ios::app);

        file << c->getTitle() << "&" << c->getDescription() << "&" << c->getPrice() << "&" << c->getTeacherId() << endl;

        file.close();
    }

    static void addEnrollment(Enrollment *e)
    {
        fstream file("data/enrollments.txt", ios::app);

        file << e->getStudentId() << "&" << e->getCourseId() << endl;

        file.close();
    }

    static void addAssignment(Assignment *a)
    {
        fstream file("data/assignments.txt", ios::app);

        file << a->getTitle() << "&" << a->getCourseId() << "&" << a->getDeadline() << "&" << a->getAssignmentScore() << endl;

        file.close();
    }

    static void addSubmission(Submission *s)
    {
        fstream file("data/submissions.txt", ios::app);

        file << s->getStudentId() << "&" << s->getAssignmentId() << "&" << s->getGrade() << "&" << s->getSubmissionDate() << endl;

        file.close();
    }

    static void addPurchase(Purchase *p)
    {
        fstream file("data/purchases.txt", ios::app);

        file << p->getStudentId() << "&" << p->getCourseId() << "&" << p->getPurchaseDate() << endl;

        file.close();
    }

    static void addProgress(Progress *p)
    {
        fstream file("data/progresses.txt", ios::app);

        file << p->getStudentId() << "&" << p->getCourseId() << "&" << p->getProgress() << endl;

        file.close();
    }

    static void getStudents()
    {
        fstream file("data/students.txt", ios::in);
        string line;

        while (getline(file, line))
        {
            Student *s = Parser::parseStudent(line);
            Student::allStudents.push_back(s);
        }

        file.close();
    }

    static void getTeachers()
    {
        fstream file("data/teachers.txt", ios::in);
        string line;

        while (getline(file, line))
        {
            Teacher *t = Parser::parseTeacher(line);
            Teacher::allTeachers.push_back(t);
        }

        file.close();
    }

    static void getCourses()
    {
        fstream file("data/courses.txt", ios::in);
        string line;

        while (getline(file, line))
        {
            Course *c = Parser::parseCourse(line);
            Course::allCourses.push_back(c);
        }

        file.close();
    }

    static void getEnrollments()
    {
        fstream file("data/enrollments.txt", ios::in);
        string line;

        while (getline(file, line))
        {
            Enrollment *e = Parser::parseEnrollment(line);
            Enrollment::allEnrollments.push_back(e);
        }

        file.close();
    }

    static void getAssignments()
    {
        fstream file("data/assignments.txt", ios::in);
        string line;

        while (getline(file, line))
        {
            Assignment *a = Parser::parseAssignment(line);
            Assignment::allAssignments.push_back(a);
        }

        file.close();
    }

    static void getSubmissions()
    {
        fstream file("data/submissions.txt", ios::in);
        string line;

        while (getline(file, line))
        {
            Submission *s = Parser::parseSubmission(line);
            Submission::allSubmissions.push_back(s);
        }

        file.close();
    }

    static void getPurchases()
    {
        fstream file("data/purchases.txt", ios::in);
        string line;

        while (getline(file, line))
        {
            Purchase *p = Parser::parsePurchase(line);
            Purchase::allPurchases.push_back(p);
        }

        file.close();
    }

    static void getProgresses()
    {
        fstream file("data/progresses.txt", ios::in);
        string line;

        while (getline(file, line))
        {
            Progress *p = Parser::parseProgress(line);
            Progress::allProgresses.push_back(p);
        }

        file.close();
    }

    static void getAllData()
    {
        getStudents();
        getTeachers();
        getCourses();
        getEnrollments();
        getAssignments();
        getSubmissions();
        getPurchases();
        getProgresses();
    }

    static void saveAllStudents()
    {
        for (int i = 0; i < Student::allStudents.size(); i++)
        {
            Student *s = Student::allStudents[i];
            addStudent(s);
        }
    }

    static void saveAllTeachers()
    {
        for (int i = 0; i < Teacher::allTeachers.size(); i++)
        {
            Teacher *t = Teacher::allTeachers[i];
            addTeacher(t);
        }
    }

    static void saveAllCourses()
    {
        for (int i = 0; i < Course::allCourses.size(); i++)
        {
            Course *c = Course::allCourses[i];
            addCourse(c);
        }
    }

    static void saveAllEnrollments()
    {
        for (int i = 0; i < Enrollment::allEnrollments.size(); i++)
        {
            Enrollment *e = Enrollment::allEnrollments[i];
            addEnrollment(e);
        }
    }

    static void saveAllAssignments()
    {
        for (int i = 0; i < Assignment::allAssignments.size(); i++)
        {
            Assignment *a = Assignment::allAssignments[i];
            addAssignment(a);
        }
    }

    static void saveAllSubmissions()
    {
        for (int i = 0; i < Submission::allSubmissions.size(); i++)
        {
            Submission *s = Submission::allSubmissions[i];
            addSubmission(s);
        }
    }

    static void saveAllPurchases()
    {
        for (int i = 0; i < Purchase::allPurchases.size(); i++)
        {
            Purchase *p = Purchase::allPurchases[i];
            addPurchase(p);
        }
    }

    static void saveAllProgresses()
    {
        for (int i = 0; i < Progress::allProgresses.size(); i++)
        {
            Progress *p = Progress::allProgresses[i];
            addProgress(p);
        }
    }

    static void saveAllData()
    {
        saveAllStudents();
        saveAllTeachers();
        saveAllCourses();
        saveAllEnrollments();
        saveAllAssignments();
        saveAllSubmissions();
        saveAllPurchases();
        saveAllProgresses();
    }

    static void buildModelsRelationships()
    {
        // course relationships
        for (int i = 0; i < Course::allCourses.size(); i++)
        {
            // teacher relationship
            Course::allCourses[i]->setTeacher(Teacher::getTeacherById(Course::allCourses[i]->getTeacherId()));

            // student relationship
            vector<Enrollment *> *enrollments = Enrollment::getEnrollmentsByCourseId(Course::allCourses[i]->getId());

            for (int j = 0; j < enrollments->size(); j++)
            {
                Student *student = Student::getStudentById(enrollments->at(j)->getStudentId());
                Course::allCourses[i]->addStudent(student);
            }

            // assignment relationship
            vector<Assignment *> *assignments = Assignment::getAssignmentsByCourseId(Course::allCourses[i]->getId());
            Course::allCourses[i]->setAssignments(assignments);

            // purchase relationship
            vector<Purchase *> *purchases = Purchase::getPurchasesByCourseId(Course::allCourses[i]->getId());
            Course::allCourses[i]->setPurchases(purchases);

            // progress relationship
            vector<Progress *> *progresses = Progress::getProgressesByCourseId(Course::allCourses[i]->getId());
            Course::allCourses[i]->setProgresses(progresses);
        }

        // student relationships
        for (int i = 0; i < Student::allStudents.size(); i++)
        {
            // enrollment relationship
            vector<Enrollment *> *enrollments = Enrollment::getEnrollmentsByStudentId(Student::allStudents[i]->getId());

            for (int j = 0; j < enrollments->size(); j++)
            {
                Course *course = Course::getCourseById(enrollments->at(j)->getCourseId());
                Student::allStudents[i]->addCourse(course);
            }

            // purchase relationship
            vector<Purchase *> *purchases = Purchase::getPurchasesByStudentId(Student::allStudents[i]->getId());
            Student::allStudents[i]->setPurchases(purchases);

            // progress relationship
            vector<Progress *> *progresses = Progress::getProgressesByStudentId(Student::allStudents[i]->getId());
            Student::allStudents[i]->setProgress(progresses);

            // submission relationship
            vector<Submission *> *submissions = Submission::getSubmissionsByStudentId(Student::allStudents[i]->getId());
            Student::allStudents[i]->setSubmissions(submissions);
        }

        // teacher relationships
        for (int i = 0; i < Teacher::allTeachers.size(); i++)
        {
            //   course relationship
            vector<Course *> *courses = Course::getCoursesByTeacherId(Teacher::allTeachers[i]->getId());
            Teacher::allTeachers[i]->setCourses(courses);
        }

        // assignment relationships
        for (int i = 0; i < Assignment::allAssignments.size(); i++)
        {
            //   course relationship
            Course *course = Course::getCourseById(Assignment::allAssignments[i]->getCourseId());
            Assignment::allAssignments[i]->setCourse(course);

            // submission relationship
            vector<Submission *> *submissions = Submission::getSubmissionsByAssignmentId(Assignment::allAssignments[i]->getId());
            Assignment::allAssignments[i]->setSubmissions(submissions);
        }

        // submission relationships
        for (int i = 0; i < Submission::allSubmissions.size(); i++)
        {
            // student relationship
            Student *student = Student::getStudentById(Submission::allSubmissions[i]->getStudentId());
            Submission::allSubmissions[i]->setStudent(student);

            // assignment relationship
            Assignment *assignment = Assignment::getAssignmentById(Submission::allSubmissions[i]->getAssignmentId());
            Submission::allSubmissions[i]->setAssignment(assignment);
        }

        // progress relationships
        for (int i = 0; i < Progress::allProgresses.size(); i++)
        {
            // student relationship
            Student *student = Student::getStudentById(Progress::allProgresses[i]->getStudentId());
            Progress::allProgresses[i]->setStudent(student);

            // course relationship
            Course *course = Course::getCourseById(Progress::allProgresses[i]->getCourseId());
            Progress::allProgresses[i]->setCourse(course);
        }

        // purchase relationships
        for (int i = 0; i < Purchase::allPurchases.size(); i++)
        {
            // student relationship
            Student *student = Student::getStudentById(Purchase::allPurchases[i]->getStudentId());
            Purchase::allPurchases[i]->setStudent(student);

            // course relationship
            Course *course = Course::getCourseById(Purchase::allPurchases[i]->getCourseId());
            Purchase::allPurchases[i]->setCourse(course);
        }
    }

    static void getAllDataWithRelationships()
    {
        getAllData();
        buildModelsRelationships();
    }
};