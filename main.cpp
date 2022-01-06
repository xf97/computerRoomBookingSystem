#include "headFiles.h"

/*
学校有几个不同规格的机房，需要开发预约系统
身份：
学生代表-申请使用机房
教师-审核预约申请
管理员-给学生和老师创建账号
机房：
1号机房-20人
2号-50人
3号-100人
申请简介：
1. 申请订单每周由管理员负责清空
2. 学生可以预约未来一周的机房，日期为周一到周五，预约需要选择时段-上午、下午
3. 教师审核，给予通过或不通过
系统具体要求：
进入登录界面，可选登录身份：
    学生代表、老师、管理员、退出
每个身份都需要进行验证：
    学生-学号，姓名和登录密码
    老师-职工号，姓名和登录密码
    管理员-姓名和密码
学生具体功能：
    申请预约
    查看自身的预约
    查看所有预约
    取消预约
    退出登录
教师具体功能：
    查看所有的预约
    审核预约
    退出登录
管理员具体功能：
    添加账号，需要检测账号重复
    查看账号，选择查看学生或老师的账号信息
    查看所有机房的信息
*/

//进入管理员子菜单页面
//此处传入的是指针的引用
void administratorMenu(Identity * &admin){
    int choose = -1;
    while(choose != 0){
        //以指针形式传入基类指针，通过动态多态转成派生类指针后行使子类功能
        admin->identitySubMenu();   //由于此函数基类纯虚，因此此处调用的是admin子类的
        //转换指针
        Administrator * realAdmin =  (Administrator *)admin;
        input(choose, "Please give your choose: ");
        switch (choose)
        {
            case 1:
                //添加新人
                realAdmin->addPerson();
                break;
            case 2:
                //查看当前所有账号
                realAdmin->showPersons();
                break;
            case 3:
                //查看当前的机房
                realAdmin->showComputerRooms();
                break;
            case 4:
                //取消当前所有预约
                realAdmin->cleanData();
                break;
            case 0:
                //退出菜单，可能面临数据的写入
                break;
            default:
                cout<<"You have entered a wrong input, please check your input and reinput again.\n";
                break;
            }
        }
    cout<<"Already back to upper menu, press any key to continue.\n";
    //要注意回收指针空间，两个指针指向了同一个内存
    delete admin;
    admin = nullptr;
    return;
}
        
//进入教师子菜单页面
void teacherMenu(Identity * & teacher){
    int choose = -1;
    while(choose != 0){
        //以指针形式传入基类指针，通过动态多态转成派生类指针后行使子类功能
        teacher->identitySubMenu();   //由于此函数基类纯虚，因此此处调用的是student子类的
        //转换指针
        Teacher * realTeacher = (Teacher *) teacher;
        //Administrator * realAdmin =  (Administrator *)admin;
        input(choose, "Please give your choose: ");
        switch (choose)
        {
            case 1:
                //查看预约
                realTeacher->showAllOrders();
                break;
            case 2:
                //审核预约
                realTeacher->examineOrder();
                break;
            case 0:
                //退出菜单，可能面临数据的写入
                break;
            default:
                cout<<"You have entered a wrong input, please check your input and reinput again.\n";
                break;
            }
        }
    cout<<"Already back to upper menu, press any key to continue.\n";
    //要注意回收指针空间，两个指针指向了同一个内存
    delete teacher; //因为传入引用，因此在此处delete，可以作用到指针，如果传入的指针不改变，二维指针相当于指针引用
    teacher = nullptr;
    return;
}

//进入学生代表子菜单页面
//此处传入的是指针的引用
void studentMenu(Identity * &student){
    int choose = -1;
    while(choose != 0){
        //以指针形式传入基类指针，通过动态多态转成派生类指针后行使子类功能
        student->identitySubMenu();   //由于此函数基类纯虚，因此此处调用的是student子类的
        //转换指针
        StudentHeadBoy * realStudent = (StudentHeadBoy *) student;
        //Administrator * realAdmin =  (Administrator *)admin;
        input(choose, "Please give your choose: ");
        switch (choose)
        {
            case 1:
                //申请预约
                realStudent->applyOrder();
                break;
            case 2:
                //查看我的预约
                realStudent->showMyOrders();
                break;
            case 3:
                //查看当前所有的预约
                realStudent->showAllOrders();
                break;
            case 4:
                //取消我的预约
                realStudent->cancelOrder();
                break;
            case 0:
                //退出菜单，可能面临数据的写入
                break;
            default:
                cout<<"You have entered a wrong input, please check your input and reinput again.\n";
                break;
            }
        }
    cout<<"Already back to upper menu, press any key to continue.\n";
    //要注意回收指针空间，两个指针指向了同一个内存
    delete student; //因为传入引用，因此在此处delete，可以作用到指针，如果传入的指针不改变，二维指针相当于指针引用
    student = nullptr;
    return;
}


void showMenu(){
    cout<<"Welcome to xiaofeng's computer room booking system.\n";
    cout<<"Please choose your identity:\n";
    cout<<"--------------------\n";
    cout<<"1. Student head boy\n";
    cout<<"2. Teacher\n";
    cout<<"3. Administrator\n";
    cout<<"0. Quit\n";
    cout<<"--------------------\n";
}

//登录函数
//_fileName, 操作的文件名
//_type, 登录的身份，1-学生，2-老师，3-管理员
void LogIn(const string & _fileName, const int _type){
    //工厂模式，动态多态
    Identity * person = nullptr;
    //要读取文件
    ifstream ifs(_fileName, ios::in);
    //判断是否打开
    if(!ifs.is_open()){
        cerr<<"Data file open failed, please check it -- "<<_fileName<<endl;
        return;
    }
    //现在准备校对
    int id = 0; //编号
    string accountName = "";    //账户名
    string password = "";   //密码
    //判断类型
    if(_type == STUDENT_HEAD_BOY_TYPE){
        input(id, "Please input your student id: ");
    }
    else if(_type == TEACHER_TYPE){
        input(id, "Please input your employee id: ");
    }
    else if(_type == ADMINISTRATOR_TYPE){
        //nothing to do, just zhanwei
    }
    else{
        cerr<<"Wrong identity type you given, please chec it.\n";
        return;
    }
    //给定用户名和密码
    input(accountName, "Please input your account name: ");
    input(password, "Please input your password: ");
    // 产生哈希值
    hash<string> hashStr;
    string hashPassword = to_string(hashStr(password));    //仿函数调用 
    //现在应该是要校验
    bool successFlag = false;   //登录成功标志
    if(_type == STUDENT_HEAD_BOY_TYPE){
        //学生登录校验
        //读取文件
        int realId = 0;
        string realAccountName = "", realPassword = "";
        //逐个读取，三个一组
        while(ifs>>realId && ifs>>realAccountName && ifs>>realPassword){
            //匹配
            if(realId == id && realAccountName == accountName && realPassword == hashPassword){
                //初始化指针
                //cout<<"Successful login.\n";zicaidan
                //进入子菜单
                successFlag = true;
                person = new StudentHeadBoy(id, accountName, password);
                studentMenu(person);
            }
        }
    }
    else if(_type == TEACHER_TYPE){
        //教师登录校验
        //读取文件
        int realId = 0;
        string realAccountName = "", realPassword = "";
        while(ifs>>realId && ifs>>realAccountName && ifs>>realPassword){
            //匹配
            if(realId == id && realAccountName == accountName && realPassword == hashPassword){
                //初始化指针
                successFlag = true;
                //cout<<"Successful login.\n";
                person = new Teacher(id, accountName, password);
                //进入教师身份子菜单
                teacherMenu(person);
            }
        }
    }
    else if(_type == ADMINISTRATOR_TYPE){
        //管理员登录校验        
        //读取文件
        int realId = 0;
        string realAccountName = "", realPassword = "";
        //逐个读取，三个一组
        while(ifs>>realAccountName && ifs>>realPassword){
            //匹配
            if(realAccountName == accountName && realPassword == hashPassword){
                //初始化指针
                successFlag = true;
                person = new Administrator(accountName, password);
                //进入管理员身份的子菜单
                administratorMenu(person);
            }
        }
    }
    if(!successFlag){
        cerr<<"Failed login, please check your account name and password, and re-input again, press any key to continue.\n";
    }
    //     cout<<"Successful login. Hello, "<<accountName<<endl;
    //     //转入person身份的子菜单
    //     person->identitySubMenu();  //展示菜单
    // }
    // else{
    //     cout<<"Failed login, please check your account name and password, and re-input again.\n";
    // }
    return;
}



//用于在linux上暂停终端
void pauseLinuxShell(){
    cin.get();
    cin.get();
}


int main(){
    int choose = -1;    //用户选择
    while(choose != 0){
        showMenu();
        input(choose, "Please give your choose: ");
        switch (choose)
        {
        case 1:
            //学生身份
            LogIn(STUDENT_FILE, STUDENT_HEAD_BOY_TYPE);
            break;
        case 2:
            //老师身份
            LogIn(TEACHER_FILE, TEACHER_TYPE);
            break;
        case 3:
            //管理员身份
            LogIn(ADMIN_FILE, ADMINISTRATOR_TYPE);
            break;
        case 0:
            //退出系统，可能面临数据的写入
            /* code */
            cout<<"Welcome your next accessment.\n";
            break;
        default:
            cout<<"You have entered a wrong input, please check your input and reinput again.\n";
            break;
        }
        //system("pause");  //此句话forwindows
        pauseLinuxShell();
        system("clear");
    }
    cout<<"Already quit this system.\n";
    return 0;
}