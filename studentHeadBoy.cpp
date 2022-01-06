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
    ofs<<"date:"<<date<<" ";
    ofs<<"interval:"<<interval<<" ";
    ofs<<"computerRoomId:"<<room<<" ";
    ofs<<"studentId:"<<getId()<<" ";
    ofs<<"studentName:"<<getAccountName()<<" ";
    ofs<<"applyStatus:"<<1<<endl;

    ofs.close();
    cout<<"Create new booking order ... Successed.\n";
    return;
}

//查看自身的预约
void StudentHeadBoy::showMyOrders() const{
    Orders orders;  //初始化预约单
    if(orders.getSize() == 0){
        cout<<"No orders apply.\n";
        return;
    }
    else{
        //读取，以学号来判断
        for(int i = 1; i <= orders.getSize(); ++ i){
            if(orders.getValue(i, "studentId") == to_string(getId())){
                //学号匹配，那么打印
                //0-取消的预约，1-审核中，2-预约成功，3-预约失败
                cout<<"Apply date: "<<vector<string>{"Monday", "Tuesday", "Wendesday", "Thusday", "Friday"}[atoi(orders.getValue(i, "date").c_str())];
                cout<<" Interval: "<<(orders.getValue(i, "interval") == "1" ? "Morning" : "Afternoon");
                cout<<" Computer room: "<<orders.getValue(i, "computerRoomId");
                cout<<" Apply status: " + vector<string>{"Canceled", "Applying", "Successed", "Rejected"}[atoi(orders.getValue(i, "applyStatus").c_str())]<<endl;
                cout<<"**************************\n";
            }
        }
    }
}

//查看所有人的预约
void StudentHeadBoy::showAllOrders() const{
    Orders orders;  //初始化预约单
    if(orders.getSize() == 0){
        cout<<"No orders apply.\n";
        return;
    }
    else{
        for(int i = 1; i <= orders.getSize(); ++ i){
            //0-取消的预约，1-审核中，2-预约成功，3-预约失败
            cout<<"Apply student account name: "<<orders.getValue(i, "studentName");
            cout<<" Apply date: "<<vector<string>{"Monday", "Tuesday", "Wendesday", "Thusday", "Friday"}[atoi(orders.getValue(i, "date").c_str())];
            cout<<" Interval: "<<(orders.getValue(i, "interval") == "1" ? "Morning" : "Afternoon");
            cout<<" Computer room: "<<orders.getValue(i, "computerRoomId");
            cout<<" Apply status: " + vector<string>{"Canceled", "Applying", "Successed", "Rejected"}[atoi(orders.getValue(i, "applyStatus").c_str())]<<endl;
            cout<<"**************************\n";
        }
    }
}
   
//取消预约
void StudentHeadBoy::cancelOrder(){
    Orders orders;  //当前所有的预约记录
    if(orders.getSize() == 0){
        cerr<<"No orders your applied have  been saved.\n";
        return;
    }
    cout<<"The orders that can be canceled are shown below:\n";
    vector<int> indexVec;
    int index = 1;
    for(int i = 1; i <= orders.getSize(); ++ i){
        if(to_string(getId()) == orders.getValue(i, "studentId") &&
            (orders.getValue(i, "applyStatus") == "1" || orders.getValue(i, "applyStatus") == "2")){
                indexVec.push_back(i);  //这里存储的是符合条件的key值
                cout<<"#"<<index<<", ";
                cout<<"Apply date: "<<vector<string>{"Monday", "Tuesday", "Wendesday", "Thusday", "Friday"}[atoi(orders.getValue(i, "date").c_str())];
                cout<<" Interval: "<<(orders.getValue(i, "interval") == "1" ? "Morning" : "Afternoon");
                cout<<" Computer room: "<<orders.getValue(i, "computerRoomId");
                cout<<" Apply status: " + vector<string>{"Canceled", "Applying", "Successed", "Rejected"}[atoi(orders.getValue(i, "applyStatus").c_str())]<<endl;
                cout<<"**************************\n";
                ++ index;
            }
    }
    int select = -1;    //选择
    do{
        input(select, "Please choose a order you want to cancel (0-back to upperr menu): ");
        if(select == 0){
            break;
        }
    } while(select > indexVec.size());
    if(select > 0 && select <= indexVec.size()){
        orders.setValue(indexVec[select - 1], "applyStatus", "0");
        //cout<<indexVec[select - 1]<<" "<<orders.getValue(indexVec[select - 1], "applyStatus")<<endl;
        orders.updateOrder();   //写文件保存
        cout<<"Cancel order ... Successed\n";
    }
    else{
        cout<<"Cancel order ... Roll back\n";
    }
    return;
}

//set方法
void StudentHeadBoy::setId(const int _id){
    id = _id;
}

//get方法
int StudentHeadBoy::getId() const{
    return id;
}