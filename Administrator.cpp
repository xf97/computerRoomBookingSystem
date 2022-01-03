#include "Administrator.h"



//导入于其他头文件中定义的函数
extern void LogIn(const string & _fileName, const int _type);
template<typename inputType> extern  void input(inputType & content,  const string & tips);
extern void pauseLinuxShell();

//管理员身份实现文件

//默认构造
Administrator::Administrator(): Identity(){

}

//有参构造
Administrator::Administrator(const string & _accountName, const string & _password):
               Identity(_accountName, _password){
    initIdSet();
}

//析构函数
Administrator::~Administrator(){

}

//初始化已有的id集合
void Administrator::initIdSet(){
    //读文件
    //先读学生的
    studentIds.clear();
    ifstream ifs(STUDENT_FILE, ios::in);
    //判断是否打开
    if(!ifs.is_open()){
        cerr<<"Open data file failed --- "<<STUDENT_FILE<<", please check.\n";
        return;
    }
    int id = -1;    
    string cache = "";  //缓存
    while(ifs>>id && ifs>>cache && ifs>>cache){
        //压入已有id
        studentIds.insert(id);
    }
    ifs.close();    //关闭
    teacherIds.clear();
    ifs.open(TEACHER_FILE, ios::in);
    //判断是否打开
    if(!ifs.is_open()){
        cerr<<"Open data file failed --- "<<TEACHER_FILE<<", please check.\n";
        return;
    }
    id = -1;    
    cache = "";  //缓存
    while(ifs>>id && ifs>>cache && ifs>>cache){
        //压入已有id
        teacherIds.insert(id);
    }
    ifs.close();    //关闭
    cout<<"Init ids records ... Successed.\n";\
    //cout<<studentIds.size()<<" "<<teacherIds.size()<<endl;
    return;
}

//添加账号
void Administrator::addPerson(){
    int accountType = 1;    //添加的账号类型
    do{
        input(accountType, "Please select the new account your creat (" + to_string(STUDENT_HEAD_BOY_TYPE)
                     + "-Student, " + to_string(TEACHER_TYPE) +"-Teacher): ");
    } while(accountType != STUDENT_HEAD_BOY_TYPE && accountType != TEACHER_TYPE);
    string filename = "";   //要写入数据的文件名
    string tips = "";   //用于提示输入的语句
    if(accountType == STUDENT_HEAD_BOY_TYPE){
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
    //要判断重复
    bool reduntantFlag = false; //id存在标志
    do
    {
        string reduntantStr = tips;
        if(reduntantFlag){
            //存在重复
            reduntantStr = "The id you input exists, please reinput another one. " + tips;
        }
        input(id, reduntantStr);  
        if(accountType == STUDENT_HEAD_BOY_TYPE){
            if(studentIds.find(id) != studentIds.end()){
                //找到
                reduntantFlag = true;
            }
            else{
                //如果不存在，要置回来
                reduntantFlag = false;
            }
        }
        else{
            if(teacherIds.find(id) != teacherIds.end()){
                //找到
                reduntantFlag = true;
            }
            else{
                //如果不存在，要置回来
                reduntantFlag = false;
            }
        }
    } while (reduntantFlag);
    string accountName;
    input(accountName, "Please input the new account name: "); 
    string _1stPassword = "";
    input(_1stPassword, "Please set " + accountName + "'s password (first time): ");    //重复验证
    string _2ndPassword = "";
    input(_2ndPassword, "Please set " + accountName + "'s password (second time): ");
    while(_1stPassword != _2ndPassword){
        cerr<<"Twice input passwords are different, please reset the password!\n";
        input(_1stPassword, "Please set " + accountName + "'s password (first time): ");
        input(_2ndPassword, "Please set " + accountName + "'s password (second time): "); 
    }
    //密码加密
    hash<string> hashString;
    //仿函数产生
    auto hashPassword = hashString(_1stPassword);
    //写文件
    ofs<<to_string(id)<<" "<<accountName<<" "<<to_string(hashPassword)<<endl;
    //写入id
    if(accountType == STUDENT_HEAD_BOY_TYPE){
        //学生
        studentIds.insert(id);
    }
    else{
        teacherIds.insert(id);
    }
    cout<<"Add new account "<<accountName<<" ... Successed.\n";
    //关闭文件
    ofs.close();
    return;
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