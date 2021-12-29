#ifndef IDENTITY_H
#define IDENTITY_H

#include <iostream>
#include <string>

using namespace std;

//学生、老师和管理员的身份共性基类-identity
class Identity{
public:
    virtual void identitySubMenu() = 0;     //子身份必须需要重写的子菜单，纯虚函数

    //提供对私有数据的公共访问接口
    //set
    void setAccountName(const string & _accountName);
    void setPassword(const string & _password);

    //get
    const string & getAccountName() const;
    const string & getPassword() const;

    //构造函数
    Identity(string _accountName = "None", string _password = "None");
    //析构函数
    //多态基类，虽未涉及堆区数据，但还是提供虚析构函数
    virtual ~Identity();
private:
    string accountName; //用户名
    string password;    //密码
};

#endif