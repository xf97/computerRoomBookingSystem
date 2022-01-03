#include "Administrator.h"



//导入于其他头文件中定义的函数
// extern void LogIn(const string & _fileName, const int _type);
// template<typename inputType> extern  void input(inputType & content,  const string & tips);
// extern void pauseLinuxShell();

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
    int accountType = 1;    //添加的账号类型
    do{
        input(accountType, "Please select the new account your creat (1-Student, 2-Teacher): ");
    } while(accountType != 1 && accountType != 2);
    string filename = "";   //要写入数据的文件名
    string tips = "";   //用于提示输入的语句
    if(accountType == 1){
        filename = STUDENT_FILE;
        tips = "Please input this student's id: ";
    }
    else{
        filename = TEACHER_FILE;
        tips = "Please input this employee's id: ";
    }
    //打开文件
    ofstream ofs(filename, ios::out | ios::app);    //追加写入
    //接收数据
    int id;
    input(id, tips);
    string accountName;
    input(accountName, "Please input the new account name: ");  //此处未判断重复
    string _1stPassword;
    input(_1stpassword, "Please set " + accountName + "'s password (first time): ");    //重复验证
    string _2ndPassword;
    while(_1stPassword != _2ndPassword){
        cerr<"Twice input passwords are different, please reset the password!\n";
        input(_1stpassword, "Please set " + accountName + "'s password (first time): ");
        input(_2ndpassword, "Please set " + accountName + "'s password (second time): "); 
    }
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