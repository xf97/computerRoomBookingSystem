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

}

void Teacher::showAllOrders() const{

}

void Teacher::examineOrder(){

}

void Teacher::setId(const int _id){
    id = _id;
}

int Teacher::getId() const{
    return id;
}