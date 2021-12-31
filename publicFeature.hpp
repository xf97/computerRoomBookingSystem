#ifndef PUBLICFEATURE_H
#define PUBLICFEATURE_H

#include <string>
#include <iostream>
#include "identity.h"
#include "studentHeadBoy.h"
#include "Teacher.h"
#include "Administrator.h"
#include "Constant.h"
#include <functional>   //为使用哈希函数
#include <fstream>
using namespace std;

//定义于此的功能是一些公共函数，或者模板函数

void showMenu(){
    cout<<"Welcome to xiaofeng's computer room booking system.\n";
    cout<<"Please choose your identity:\n";
    cout<<"--------------------\n";
    cout<<"1. Student head boy\n";
    cout<<"2. Teacher\n";
    cout<<"3. Administrators\n";
    cout<<"0. Quit\n";
    cout<<"--------------------\n";
}

//抽象为模板函数
template<typename inputType>
void input(inputType & content, //接收输入的参数
            const string & tips){   //给出的提示语
    cout<<tips;
    while(true){
        cin>>content;
        if(cin.fail()){
            //先clear再sync
            cin.clear();
            cin.sync();
            cout<<"Input is wrong type, please check your input and reinput agian: ";
            continue;
        }
        break;
    }
}

//登录函数
//_fileName, 操作的文件名
//_type, 登录的身份，1-学生，2-老师，3-管理员
void LoginIn(const string & _fileName, const int _type){
    //工厂模式，动态多态
    Identity * person = nullptr;
    //要读取文件
    ifstream ifs(_fileName, ios::in);
    //判断是否打开
    if(!ifs.is_open()){
        cerr<<"Data file open failed, please check it -- "<<_fileName<<endl;
        return;
    }
    //现在准备校对
    int id = 0; //编号
    string accountName = "";    //账户名
    string password = "";   //密码
    //判断类型
    if(_type == STUDENT_HEAD_BOY_TYPE){
        input(id, "Please input your student id: ");
    }
    else if(_type == TEACHER_TYPE){
        input(id, "Please input your employee id: ");
    }
    else if(_type == ADMINISTRATOR_TYPE){
        //nothing to do, just zhanwei
    }
    else{
        cerr<<"Wrong identity type you given, please chec it.\n";
        return;
    }
    //给定用户名和密码
    input(accountName, "Please input your account name: ");
    input(password, "Please input your password: ");
    //产生哈希值
    hash<string> hashStr;
    size_t hashPassword = hashStr(password);    //仿函数调用 
    //现在应该是要校验
    bool successFlag = false;   //登录成功标志
    if(_type == STUDENT_HEAD_BOY_TYPE){
        //学生登录校验
    }
    else if(_type == TEACHER_TYPE){
        //教师登录校验
    }
    else if(_type == ADMINISTRATOR_TYPE){
        //管理员登录校验
    }
    if(successFlag){
        cout<<"Successful login. Hello, "<<accountName<<endl;
    }
    else{
        cout<<"Failed login, please check your account name and password, and re-input again.\n";
    }
    return;
}

#endif