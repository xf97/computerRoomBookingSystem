#include "Administrator.h"

//管理员身份实现文件

//默认构造
Administrator::Administrator(): Identity(){

}

//有参构造
Administrator::Administrator(const string & _accountName, const string & _password):
               Identity(_accountName, _password){

}

//析构函数
Administrator::~Administrator(){

}

//添加账号
void Administrator::addPerson(){

}

//查看账号
void Administrator::showPersons() const{

}

//查看机房状态
void Administrator::showComputerRooms() const{

}

//清空数据
void Administrator::cleanData(){
    
}