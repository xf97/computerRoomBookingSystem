#include "studentHeadBoy.h"


//学生代表身份实现文件
//默认构造
StudentHeadBoy::StudentHeadBoy(): Identity(){
    id = 0;
    init();
}

//有参构造
StudentHeadBoy::StudentHeadBoy(int _id, const string & _accountName, const string & _password):
                Identity(_accountName, _password), id(_id){
    init();
}


//析构函数
StudentHeadBoy::~StudentHeadBoy(){
    
}

void StudentHeadBoy::init(){
    //机房信息
    ifstream ifs(COMPUTER_FILE, ios::in);
    if(!ifs.is_open()){
        cerr<<"Open data file failed --- "<<COMPUTER_FILE<<", please check.\n";
        return;
    }
    ComputerRoom temp;
    //开始读
    while(ifs>>temp.id && ifs>>temp.capacity){
        computerRoomsVec.push_back(temp);   //值拷贝构造？
    }
    ifs.close();
    cout<<"Init data ... Successed.\n";
    return;
}


//重写纯虚函数
void StudentHeadBoy::identitySubMenu(){
    cout<<"Welcome student -- "<<getAccountName()<<endl;
    cout<<"----------------------------------------- \n";
    cout<<"| 1. creat a new booking order \n";
    cout<<"| 2. check my all orders \n";
    cout<<"| 3. check all orders at present \n";
    cout<<"| 4. cancel my order \n";
    cout<<"| 0. log out \n";
    cout<<"----------------------------------------- \n";
    return;
}

//申请预约
void StudentHeadBoy::applyOrder(){
    //选时间
    cout<<"Creat a new order:\n";
    //星期一到星期五
    int date = -1;
    vector<int> candidates{1, 2, 3, 4, 5};
    do{
        input(date, string("Please select the date you want to apply\n") + 
                                  "(1 - Monday \n" +
                                  "2 - Tuesday\n" +
                                  "3 - Wednesday\n" + 
                                  "4 - Thursday \n" + 
                                  "5 - Friday): ");
    } while(find(candidates.begin(), candidates.end(), date) == candidates.end());
    int interval = -1;  //上午下午
    candidates = {1, 2};
    do{
        input(interval, string("Please select the interval you want to apply\n") + 
                                  "(1 - Morning \n" +
                                  "2 - Afternoon): ");
    } while(find(candidates.begin(), candidates.end(), interval) == candidates.end());
    int room = -1;  //
    candidates.clear();
    string tips = "(";
    //填充
    for(auto it = computerRoomsVec.begin(); it != computerRoomsVec.end(); ++ it){
        candidates.push_back(it->id);
        tips += ("Computer room id :" + to_string(it->id) + ", Computer room capacity: " + to_string(it->capacity) + ",\n");
    }
    tips = (tips.size() >= 2) ? tips.substr(0, tips.size() - 2) : tips;
    tips += "): ";
    do{
        input(room, "Please select the computer room you want to apply\n" + tips);
    } while(find(candidates.begin(), candidates.end(), room) == candidates.end());
    //写入订单
    ofstream ofs(ORDER_FILE, ios::out | ios::app);  //追加写入
    if(!ofs.is_open()){
        cerr<<"The data file open failed --- "<<ORDER_FILE<<endl;
        ofs.close();
        return;
    }
    //往里面写
    ofs<<"date: "<<date<<" ";
    ofs<<"interval (1-morning, 2-afternoon): "<<internal<<" ";
    ofs<<"computer room id: "<<room<<" ";
    ofs<<"student id: "<<getId()<<" ";
    ofs<<"student name: "<<getAccountName()<<" ";
    ofs<<"apply status (1-examining): "<<1<<endl;

    ofs.close();
    cout<<"Create new booking order ... Successed.\n";
    return;
}

//查看自身的预约
void StudentHeadBoy::showMyOrders() const{

}

//查看所有人的预约
void StudentHeadBoy::showAllOrders() const{

}
   
//取消预约
void StudentHeadBoy::cancelOrder(){
    
}

//set方法
void StudentHeadBoy::setId(const int _id){
    id = _id;
}

//get方法
int StudentHeadBoy::getId() const{
    return id;
}