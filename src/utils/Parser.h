#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "../models/Student.h"
#include "../models/Teacher.h"
#include "../models/Course.h"
#include "../models/Assignment.h"
#include "../models/Submission.h"
#include "../models/Purchase.h"
#include "../models/Progress.h"

using namespace std;

class Parser
{
public:
    static vector<string> split(string line)
    {
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, '&'))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    static Student *parseStudent(string line)
    {
        vector<string> tokens = split(line);
        Student *s = new Student();
        s->setName(tokens[0]);
        s->setEmail(tokens[1]);
        s->setPassword(tokens[2]);
        s->setPhoneNumber(tokens[3]);
        return s;
    }

    static Teacher *parseTeacher(string line)
    {
        vector<string> tokens = split(line);
        Teacher *t = new Teacher();
        t->setName(tokens[0]);
        t->setEmail(tokens[1]);
        t->setPassword(tokens[2]);
        t->setPhoneNumber(tokens[3]);
        t->setSalary(stod(tokens[4]));
        return t;
    }

    static Course *parseCourse(string line)
    {
        vector<string> tokens = split(line);
        Course *c = new Course();
        c->setTitle(tokens[0]);
        c->setDescription(tokens[1]);
        c->setPrice(stod(tokens[2]));
        c->setTeacherId(stoi(tokens[3]));
        return c;
    }

    static Assignment *parseAssignment(string line)
    {
        vector<string> tokens = split(line);
        Assignment *a = new Assignment();
        a->setTitle(tokens[0]);
        a->setCourseId(stoi(tokens[1]));
        a->setMaxGrade(stod(tokens[2]));
        a->setDeadline(tokens[3]);
        return a;
    }

    static Submission *parseSubmission(string line)
    {
        vector<string> tokens = split(line);
        Submission *s = new Submission();
        s->setStudentId(stoi(tokens[0]));
        s->setAssignmentId(stoi(tokens[1]));
        s->setGrade(stod(tokens[2]));
        s->setTimeOfSubmission(tokens[3]);
        return s;
    }

    static Purchase *parsePurchase(string line)
    {
        vector<string> tokens = split(line);
        Purchase *p = new Purchase();
        p->setStudentId(stoi(tokens[0]));
        p->setCourseId(stoi(tokens[1]));
        p->setTimeOfPurchase(tokens[2]);
        return p;
    }

    static Progress *parseProgress(string line)
    {
        vector<string> tokens = split(line);
        Progress *p = new Progress();
        p->setStudentId(stoi(tokens[0]));
        p->setCourseId(stoi(tokens[1]));
        p->setPercentage(stod(tokens[2]));
        return p;
    }
};