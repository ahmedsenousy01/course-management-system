#pragma once

#include "../models/Course.h"
#include "../models/Teacher.h"

using namespace std;

class CourseRepository
{
public:
    static Course *create(string title, string description, double price, int teacherId, Teacher *teacher)
    {
        Course *course = new Course();
        if (course->setTitle(title) && course->setDescription(description) && course->setPrice(price) && course->setTeacherId(teacherId) && course->setTeacher(teacher))
        {
            Course::allCourses.push_back(course);
            return course;
        }

        return nullptr;
    }
};