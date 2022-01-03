#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H 1

//管理员身份实现类
#include "identity.h"
#include <functional> //为使用哈希函数
#include <iostream>
#include "publicFeature.hpp"    //使用一些公共函数
#include <string>
#include <fstream>
#include "Constant.h"


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