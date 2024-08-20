#pragma once

#include "../models/Teacher.h"
#include "../views/teacher.views.h"
#include "../repositories/teacher.repository.h"
#include "../repositories/course.repository.h"

class TeacherController
{
public:
    static Teacher *login(string email, string password)
    {
        Teacher *t = Teacher::getTeacherByEmail(email);
        if (t && t->getPassword() == password)
            return t;

        return nullptr;
    }

    static Teacher *registerTeacher(string name, string email, string password, string phoneNumber)
    {
        return TeacherRepository::create(name, email, password, phoneNumber);
    }

    static bool router(Teacher *currentUser)
    {
        while (true)
        {

            // print student menu
            // take input from user
            int choice = TeacherViews::printTeacherMenu();
            // switch case to match input to function
            // PS. logout == return true
            switch (choice)
            {
            case 1:
            {
                int id = currentUser->getId();
                vector<Course *> *courses = Course::getCoursesByTeacherId(id);
                for (int i = 0; i < courses->size(); i++)
                {
                    courses->at(i)->display();
                }
                break;
            }
            case 2:
            {
                string title, description;
                double price;

                cout << "enter course title: ";
                cin >> title;
                cout << "enter course description: ";
                cin >> description;
                cout << "enter course price: ";
                cin >> price;

                Course *course = CourseRepository::create(title, description, price, currentUser->getId(), currentUser);
                course->display();
                break;
            }
            case 3:
            {
                int id = currentUser->getId();
                vector<Course *> *courses = Course::getCoursesByTeacherId(id);
                for (int i = 0; i < courses->size(); i++)
                {
                    courses->at(i)->display();
                }

                int choice;
                cout << "enter course id: \n";
                cin >> choice;

                Course *course = Course::getCourseById(choice);
                if (course)
                    course->viewDetails();
                else
                    cout << "course not found\n";
                break;
            }
            case 4:
            {
                return true;
            }
            default:
            {
                cout << "invalid input\n";
            }
            }
        }
    }
};