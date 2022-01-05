#ifndef ORDER_H
#define ORDER_H 1

//order预约类的定义

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include "Constant.h"
#include <vector>

using namespace std;

//此类中存储所有的预约
class Orders{
public:
    Orders();   //构造函数
    ~Orders(){
        //析构
    };
    void updateOrder(); //更新预约记录
    //get
    string getValue(int key1, string key2);
    int getSize(){
        return size;
    };
    //set
    void setValue(int key1, string key2, string value);
    void setSize(int  _size){
        size = _size;
    };
private:
    map<int, map<string, string>> orders;   //key-条数，value-每条预约记录
    int size;   //记录条数
};

#endif