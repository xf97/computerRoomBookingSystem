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
#include <map>
#include <vector>
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

//初始化函数
/*
studentAccountInfo--学生账户信息
teacherAccountInfo--老师账户信息
adminAccountInfo--管理员账户信息
*/
void initSystem(map<int, vector<string>> & studentAccountInfo, 
                map<int, vector<string>> & teacherAccountInfo,
                map<string, string> & adminAccountInfo){
    getStuTeaAccountInfo(studentAccountInfo, STUDENT_FILE);
    getStuTeaAccountInfo(teacherAccountInfo, TEACHER_FILE);
    getAdminInfo(adminAccountInfo, ADMIN_FILE);
}

//获取文件信息
void getStuTeaAccountInfo(map<int, vector<string>> & infoMap, const string & fileName){
    //编号不会重复
    ifstream ifs(fileName, ios::in);    //读取文件
    if(!ifs.is_open()){
        //打开文件失败
        cerr<<"Open data file failed, please check.--"<<fileName<<endl;
        return;
    }
    //读取
    int id = 0;
    string accountName = "";
    string password = "";
    while(ifs>>id && ifs>>accountName && ifs>>password){
        infoMap.insert(make_pair(id, vector<string>{accountName, password}));
    }
} 

//获取文件信息
void getAdminInfo(map<string, string> & infoMap, const string & fileName){
    //编号不会重复
    ifstream ifs(fileName, ios::in);    //读取文件
    if(!ifs.is_open()){
        //打开文件失败
        cerr<<"Open data file failed, please check.--"<<fileName<<endl;
        return;
    }
    //读取
    string accountName = "";
    string password = "";
    while(ifs>>accountName && ifs>>password){
        infoMap.insert(make_pair(accountName, password));
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
    // 产生哈希值
    // hash<string> hashStr;
    // size_t hashPassword = hashStr(password);    //仿函数调用 
    //现在应该是要校验
    bool successFlag = false;   //登录成功标志
    if(_type == STUDENT_HEAD_BOY_TYPE){
        //学生登录校验
        //读取文件
        int realId = 0;
        string realAccountName = "", realPassword = "";
        //逐个读取，三个一组
        while(ifs>>realId && ifs>>realAccountName && ifs>>realPassword){
            //匹配
            if(realId == id && realAccountName == accountName && realPassword == password){
                successFlag = true;
                //初始化指针
                person = new StudentHeadBoy(id, accountName, password);
            }
        }
    }
    else if(_type == TEACHER_TYPE){
        //教师登录校验
        //读取文件
        int realId = 0;
        string realAccountName = "", realPassword = "";
        //逐个读取，三个一组
        while(ifs>>realId && ifs>>realAccountName && ifs>>realPassword){
            //匹配
            if(realId == id && realAccountName == accountName && realPassword == password){
                successFlag = true;
                //初始化指针
                person = new Teacher(id, accountName, password);
            }
        }
    }
    else if(_type == ADMINISTRATOR_TYPE){
        //管理员登录校验        
        //读取文件
        int realId = 0;
        string realAccountName = "", realPassword = "";
        //逐个读取，三个一组
        while(ifs>>realAccountName && ifs>>realPassword){
            //匹配
            if(realAccountName == accountName && realPassword == password){
                successFlag = true;
                //初始化指针
                person = new Administrator(accountName, password);
            }
        }
    }
    if(successFlag){
        cout<<"Successful login. Hello, "<<accountName<<endl;
        //转入person身份的子菜单
    }
    else{
        cout<<"Failed login, please check your account name and password, and re-input again.\n";
    }
    return;
}

#endif