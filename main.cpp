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

int main(){
    int choose = -1;    //用户选择
    while(choose != 0){
        showMenu();
        input(choose, "Please give your choose: ");
        switch (choose)
        {
        case 1:
            //学生身份
            LoginIn(STUDENT_FILE, STUDENT_HEAD_BOY_TYPE);
            break;
        case 2:
            //老师身份
            LoginIn(TEACHER_FILE, TEACHER_TYPE);
            break;
        case 3:
            //管理员身份
            LoginIn(ADMIN_FILE, ADMINISTRATOR_TYPE);
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
        system("pause");
        system("cls");
    }
    cout<<"Already quit this system.\n";
    return 0;
}