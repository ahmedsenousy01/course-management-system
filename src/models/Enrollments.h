#pragma once

#include "Student.h"
#include "Course.h"

class Enrollment
{
private:
    static inline int idCounter = 0;
    int id;
    Student *student;
    Course *course;
    int studentId;
    int courseId;

public:
    Enrollment()
    {
        id = idCounter++;
        student = nullptr;
        course = nullptr;
        studentId = 0;
        courseId = 0;
    }
    Enrollment(int studentId, int courseId, Student *student, Course *course)
    {
        id = idCounter++;
        this->setStudent(student);
        this->setCourse(course);
        this->setStudentId(studentId);
        this->setCourseId(courseId);
    }

    // getters
    int getId() { return id; }
    Student *getStudent() { return student; }
    Course *getCourse() { return course; }
    int getStudentId() { return studentId; }
    int getCourseId() { return courseId; }

    // setters
    bool setStudent(Student *student)
    {
        this->student = student;
        return true;
    }
    bool setCourse(Course *course)
    {
        this->course = course;
        return true;
    }
    bool setStudentId(int studentId)
    {
        this->studentId = studentId;
        return true;
    }
    bool setCourseId(int courseId)
    {
        this->courseId = courseId;
        return true;
    }

    static inline vector<Enrollment *> allEnrollments = {};
};