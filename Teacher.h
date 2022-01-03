#ifndef TEACHER_H
#define TEACHER_H 1

//老师身份实现类
/*
子身份菜单
查看预约
审核预约
*/

#include "identity.h"

class Teacher: public Identity{
public:
    Teacher();  //默认构造
    Teacher(int _id, const string & _accountName, const string & _password);    //有参构造
    ~Teacher(); //析构函数
    virtual void identitySubMenu(); //子身份菜单
    void showAllOrders() const; //显示所有的预约
    void examineOrder();    //审核预约
    //私有数据的公共接口
    //set
    void setId(const int _id);
    //get
    int getId() const;
private:
    int id;
};

#endif