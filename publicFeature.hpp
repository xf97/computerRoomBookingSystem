#ifndef PUBLICFEATURE_H
#define PUBLICFEATURE_H

#include <string>
#include <iostream>

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

#endif