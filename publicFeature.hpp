#ifndef PUBLICFEATURE_H
#define PUBLICFEATURE_H 1

#include <string>
#include <iostream>
#include <functional>   //为使用哈希函数
#include <fstream>
#include <map>
#include <vector>
#include <numeric>
using namespace std;


//此文件中定义的应该是“算法”函数，并不与特定类的市县相关
//定义于此的功能是一些公共函数，或者模板函数


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
            //cin.sync(); ubuntu上无法清空
            cin.ignore(INT64_MAX, '\n');    //清空缓冲区直到清空到换行，ubuntu上换行是lf
            //要清空输入缓冲区
            //cin.get();
            cout<<"Input is wrong type, please check your input and reinput agian: ";
            continue;
        }
        break;
    }
}

//再次抽象出模板函数，输入必须为指定类型的指定值
template<typename inputType>
void inputSpecificValue(inputType & content, 
                                                  const string & tips, 
                                                  const vector<inputType> & candidateValues){
    do{
        input(content, tips);
    }while(find(candidateValues.begin(), candidateValues.end(), content) == candidateValues.end());
    //在未输入指定值时继续执行
}


// //获取文件信息
// void getStuTeaAccountInfo(map<int, vector<string>> & infoMap, const string & fileName){
//     //编号不会重复
//     ifstream ifs(fileName, ios::in);    //读取文件
//     if(!ifs.is_open()){
//         //打开文件失败
//         cerr<<"Open data file failed, please check.--"<<fileName<<endl;
//         return;
//     }
//     //读取
//     int id = 0;
//     string accountName = "";
//     string password = "";
//     while(ifs>>id && ifs>>accountName && ifs>>password){
//         infoMap.insert(make_pair(id, vector<string>{accountName, password}));
//     }
// } 

// //获取文件信息
// void getAdminInfo(map<string, string> & infoMap, const string & fileName){
//     //编号不会重复
//     ifstream ifs(fileName, ios::in);    //读取文件
//     if(!ifs.is_open()){
//         //打开文件失败
//         cerr<<"Open data file failed, please check.--"<<fileName<<endl;
//         return;
//     }
//     //读取
//     string accountName = "";
//     string password = "";
//     while(ifs>>accountName && ifs>>password){
//         infoMap.insert(make_pair(accountName, password));
//     }
// } 

//初始化函数
/*
studentAccountInfo--学生账户信息
teacherAccountInfo--老师账户信息
adminAccountInfo--管理员账户信息
*/
// void initSystem(map<int, vector<string>> & studentAccountInfo, 
//                 map<int, vector<string>> & teacherAccountInfo,
//                 map<string, string> & adminAccountInfo){
//     getStuTeaAccountInfo(studentAccountInfo, STUDENT_FILE);
//     getStuTeaAccountInfo(teacherAccountInfo, TEACHER_FILE);
//     getAdminInfo(adminAccountInfo, ADMIN_FILE);
// }


#endif