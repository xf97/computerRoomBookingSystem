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
            cout<<", Apply status: " + vector<string>{"Canceled", "Applying", "Successed", "Rejected"}[atoi(orders.getValue(i, "applyStatus").c_str())]<<endl;
            cout<<"**************************\n";
        }
    }
}

void Teacher::examineOrder(){
   Orders orders;  //当前所有的预约记录
    if(orders.getSize() == 0){
        cerr<<"No orders your applied have  been saved.\n";
        return;
    }
    cout<<"The orders that can be canceled are shown below:\n";
    vector<int> indexVec;
    int index = 1;
    for(int i = 1; i <= orders.getSize(); ++ i){
        if(orders.getValue(i, "applyStatus") == "1"){
                indexVec.push_back(i);  //这里存储的是符合条件的key值
                cout<<"#"<<index<<", ";
                cout<<"Apply date: "<<vector<string>{"Monday", "Tuesday", "Wendesday", "Thusday", "Friday"}[atoi(orders.getValue(i, "date").c_str())];
                cout<<" Interval: "<<(orders.getValue(i, "interval") == "1" ? "Morning" : "Afternoon");
                cout<<" Computer room: "<<orders.getValue(i, "computerRoomId");
                cout<<" Apply status: " + vector<string>{"Canceled", "Applying", "Successed", "Rejected"}[atoi(orders.getValue(i, "applyStatus").c_str())]<<endl;
                cout<<"**************************\n";
                ++ index;
            }
    }
    int select = -1;    //选择
    do{
        input(select, "Please choose a order you want to change (0-back to upperr menu): ");
        if(select == 0){
            break;
        }
    } while(select > indexVec.size());
    if(select > 0 && select <= indexVec.size()){
        //orders.setValue(indexVec[select - 1], "applyStatus", "0");
        //cout<<indexVec[select - 1]<<" "<<orders.getValue(indexVec[select - 1], "applyStatus")<<endl;
        int result = -1;
        do{
            input(result, "For order #" + to_string(select) + ", Please give your eaxmine decesion (1 - Accept, 2 - Reject): ");
        } while(result != 1 && result != 2);
        if(result == 1){
            orders.setValue(indexVec[select - 1], "applyStatus", "2");
        }
        else{
            orders.setValue(indexVec[select - 1], "applyStatus", "3");
        }
        orders.updateOrder();   //写文件保存
        cout<<"Examine order ... Successed\n";
    }
    else{
        cout<<"Examine order ... Roll back\n";
    }
    return;
}

void Teacher::setId(const int _id){
    id = _id;
}

int Teacher::getId() const{
    return id;
}