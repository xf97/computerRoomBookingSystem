#ifndef CONSTANT_H
#define CONSTANT_H

//常量信息定义于此
#include <string>

using namespace std;

//常量定义
const string ADMIN_FILE = "./dataFile/admin.txt";  //管理员记录文件
const string STUDENT_FILE = "./dataFile/student.txt";  //学生信息记录文件
const string TEACHER_FILE = "./dataFile/teacher.txt";  //教师信息记录文件
const string COMPUTER_FILE = "./dataFile/computerRooms.txt";   //机房信息记录文件
const string ORDER_FILE = "./dataFile/orders.txt"; //预定信息记录文件

//身份类型
const int STUDENT_HEAD_BOY_TYPE = 1;
const int TEACHER_TYPE = 2;
const int ADMINISTRATOR_TYPE = 3;

#endif