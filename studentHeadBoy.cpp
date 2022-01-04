#include "studentHeadBoy.h"
#include <random>
#include <ctime>

//学生代表身份实现文件
//默认构造
StudentHeadBoy::StudentHeadBoy(): Identity(){
    id = 0;
}

//有参构造
StudentHeadBoy::StudentHeadBoy(int _id, const string & _accountName, const string & _password):
                Identity(_accountName, _password), id(_id){

}


//析构函数
StudentHeadBoy::~StudentHeadBoy(){
    
}


//重写纯虚函数
void StudentHeadBoy::identitySubMenu(){
    cout<<"Welcome student -- "<<getAccountName()<<endl;
    cout<<"----------------------------------------- \n";
    cout<<"| 1. creat a new booking order \n";
    cout<<"| 2. check my all orders \n";
    cout<<"| 3. check all orders at present \n";
    cout<<"| 4. cancel my order \n";
    cout<<"| 0. log out \n";
    cout<<"----------------------------------------- \n";
    return;
}

//申请预约
void StudentHeadBoy::applyOrder(){

}

//查看自身的预约
void StudentHeadBoy::showMyOrders() const{

}

//查看所有人的预约
void StudentHeadBoy::showAllOrders() const{

}
   
//取消预约
void StudentHeadBoy::cancelOrder(){
    
}

//set方法
void StudentHeadBoy::setId(const int _id){
    id = _id;
}

//get方法
int StudentHeadBoy::getId() const{
    return id;
}