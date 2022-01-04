#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H 1

//管理员身份实现类
#include "identity.h"
#include <functional> //为使用哈希函数
#include <iostream>
//#include "publicFeature.hpp"    //使用一些公共函数，注意此处容易存在循环包含的问题
#include <string>
#include <fstream>
#include "Constant.h"
#include <set>  //为了使账号去重
#include <vector>
#include <map>

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
private:
    void init();
    set<int> studentIds;    //学生id集合
    set<int> teacherIds ;   //老师id集合
    map<int, string> studentAccounts;   //学生账号集合
    map<int, string> teacherAccounts;   //老师账号集合
};

#endif