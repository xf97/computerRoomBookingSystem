#include "identity.h"
#include <random>
#include <ctime>

//身份基类的实现文件

//构造函数
Identity::Identity(string _accountName, string _password){
    accountName = _accountName;
    password = _password;
    //要避免空账号重复
    if(_accountName == "None"){
        srand((unsigned int)time(NULL));
        accountName += to_string(rand() % 10000);
    }
}

//析构函数
Identity::~Identity(){
    accountName.clear();
    password.clear();
}

//set方法
void Identity::setAccountName(const string & _accountName){
    accountName = _accountName;
}

void Identity::setPassword(const string & _password){
    password = _password;
}

//get
const string & Identity::getAccountName() const{
    return accountName;
}

const string & Identity::getPassword() const{
    return password;
}
