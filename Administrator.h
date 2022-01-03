#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H 1

//管理员身份实现类
#include "identity.h"

class Administrator: public Identity{
public:
    Administrator();
    Administrator(const string & _accountName, const string & _password);
    ~Administrator();
    void addPerson();
    void showPersons() const;
    void showComputerRooms() const;
    void cleanData();   
    virtual void identitySubMenu();
};

#endif