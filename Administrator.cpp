#include "Administrator.h"


//导入于其他头文件中定义的函数
extern void LoginIn(const string & _fileName, const int _type);
template<typename inputType> extern  void input(inputType & content,  const string & tips);
extern void pauseLinuxShell();

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

//重写子菜单函数
void Administrator::identitySubMenu(){
    //动态多态在运行时才初始化
    cout<<"Welcome adminstrator -- "<<getAccountName()<<endl;
    cout<<"----------------------------------------- \n";
    cout<<"| 1. add new person \n";
    cout<<"| 2. check all persons \n";
    cout<<"| 3. check all computer rooms \n";
    cout<<"| 4. delete all orders \n";
    cout<<"| 0. log out \n";
    cout<<"----------------------------------------- \n";
    return;
}