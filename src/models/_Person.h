#pragma once
#include <string>
using namespace std;

class Person
{
private:
    int id;
    string name, email, password, phoneNumber;

public:
    Person()
    {
        this->name = "";
        this->email = "";
        this->password = "";
        this->phoneNumber = "";
    }
    Person(string name, string email, string password, string phoneNumber)
    {
        setName(name);
        setEmail(email);
        setPassword(password);
        setPhoneNumber(phoneNumber);
    }

    // getters
    int getId()
    {
        return this->id;
    }
    string getName()
    {
        return this->name;
    }
    string getEmail()
    {
        return this->email;
    }
    string getPassword()
    {
        return this->password;
    }
    string getPhoneNumber()
    {
        return this->phoneNumber;
    }

    // setters
    bool setId(int id)
    {
        this->id = id;
        return true;
    }
    bool setName(string name)
    {
        // TODO: validation
        this->name = name;
        return true;
    }
    bool setEmail(string email)
    {
        // TODO: validation
        this->email = email;
        return true;
    }
    bool setPassword(string password)
    {
        // TODO: validation
        this->password = password;
        return true;
    }
    bool setPhoneNumber(string phoneNumber)
    {
        // TODO: validation
        this->phoneNumber = phoneNumber;
        return true;
    }
};