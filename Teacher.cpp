#include "Teacher.h"


//老师身份实现类

Teacher::Teacher(): Identity(){
    id = 0;
}

Teacher::Teacher(int _id, const string & _accountName, const string & _password):
        Identity(_accountName, _password), id(_id){

}

Teacher::~Teacher(){

}

void Teacher::identitySubMenu(){
    cout<<"Welcome teacher -- "<<getAccountName()<<endl;
    cout<<"----------------------------------------- \n";
    cout<<"| 1. show all orders \n";
    cout<<"| 2. examine orders \n";
    cout<<"| 0. log out \n";
    cout<<"----------------------------------------- \n";
    return;
}

void Teacher::showAllOrders() const{
    //类似学生的功能实现
    Orders orders;  //初始化预约单
    if(orders.getSize() == 0){
        cout<<"No orders apply.\n";
        return;
    }
    else{
        for(int i = 1; i <= orders.getSize(); ++ i){
            //0-取消的预约，1-审核中，2-预约成功，3-预约失败
            cout<<"#"<<i<<", ";
            cout<<"Apply student account name: "<<orders.getValue(i, "studentName");
            cout<<", Apply date: "<<vector<string>{"Monday", "Tuesday", "Wendesday", "Thusday", "Friday"}[atoi(orders.getValue(i, "date").c_str())];
            cout<<", Interval: "<<(orders.getValue(i, "interval") == "1" ? "Morning" : "Afternoon");
            cout<<", Computer room: "<<orders.getValue(i, "computerRoomId");
            cout<<", Apply status: " + vector<string>{"Canceled", "Applying", "Successed", "Failed"}[atoi(orders.getValue(i, "applyStatus").c_str())]<<endl;
            cout<<"**************************\n";
        }
    }
}

void Teacher::examineOrder(){

}

void Teacher::setId(const int _id){
    id = _id;
}

int Teacher::getId() const{
    return id;
}