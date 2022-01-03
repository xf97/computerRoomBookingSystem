#ifndef STUDENTHEADBOY_H
#define STUDENTHEADBOY_H 1

//定义学生代表类
#include "identity.h"


class StudentHeadBoy: public Identity{
public:
    StudentHeadBoy();   //默认构造
    StudentHeadBoy(int _id, const string & _accountName, const string & _password); //有参构造
    virtual void identitySubMenu();  //子身份菜单
    void applyOrder();  //申请预约
    void showMyOrders() const;  //查看自身的预约
    void showAllOrders() const; //查看所有人的预约
    void cancelOrder(); //取消预约
    ~StudentHeadBoy();
    //私有数据的公共接口
    //set
    void setId(const int _id);
    //get
    int getId() const;
private:
    int id; //学生学号
};

#endif