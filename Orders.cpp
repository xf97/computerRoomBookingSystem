#include "Order.h"

//预约类实现文件

//字符串分割函数
vector<string> split(string str, string pattern){
    string::size_type pos;
    vector<string> result;
    str += pattern;
    int size = str.size();
    for(int i = 0; i < size; ++ i){
        pos = str.find(pattern, i); //i指的是起始搜索位置
        if(pos < size){
            string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;   //跃进
        }
    }
    return result;
}

//构造函数
Orders::Orders(){
    ifstream ifs(ORDER_FILE, ios::in);
    if(!ifs.is_open()){
        cerr<<"Open data file failed --- "<<ORDER_FILE<<endl;
        ifs.close();
        return;
    }
    //准备数据
    string content = "";
    string key = "", value = "";
    bool valueFlag = false, keyFlag = false;
    size = 0;
    //ifs自动以空格为分割
    while(getline(ifs, content)){
        if(content.empty()){
            //跳过空行
            continue;
        }
        //截取
        int index = 0;
        map<string, string> temp;
        vector<string> result = split(content, " ");
        //逐个切分组合，压入
        for(auto str : result){
           if(str.find(':') >= str.size()){
               continue;
           }
            string key = str.substr(0, str.find(':'));
            string value = str.substr(str.find(':') + 1);
            temp.insert(make_pair(key, value));
        }
        ++ size;
        orders.insert(make_pair(size, temp));
    }
    ifs.close();
    // for(auto it = orders.begin(); it != orders.end(); ++ it){
    //     cout<<it->first<<endl;
    //     for(auto vit = (*it).second.begin(); vit != (*it).second.end(); ++ vit){
    //         cout<<vit->first<<" "<<vit->second<<endl;
    //     }
    // cout<<"*****\n";
    // }
    return;
}


//set
void Orders::setValue(int key1, string key2, string value){
    map<string, string> temp{make_pair(key2, value)};
    orders.insert(make_pair(key1, temp)); 
}

//get
string Orders::getValue(int key1, string key2){
    try
    {
        if(orders.find(key1) != orders.end()){
            if(orders[key1].find(key2) != orders[key1].end()){
                return orders[key1][key2];
            }
        }
        //cout<<key1<<" &&& "<<key2<<endl;
        throw "No specify key";
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
        return "None";
    }
}

//直接就是刷新整个文件
void Orders::updateOrder(){
    //更新判空
    if(size == 0){
        return;
    }
    else{
        ofstream ofs(ORDER_FILE, ios::out | ios::trunc);    //要对原有数据置空
        for(int i = 0; i < size; ++ i){
            ofs<<"date:"<<orders[i]["date"]<<" ";
            ofs<<"interval:"<<orders[i]["interval"]<<" ";
            ofs<<"computerRoomId:"<<orders[i]["computerRoomId"]<<" ";
            ofs<<"studentId:"<<orders[i]["studentId"]<<" ";
            ofs<<"studentName:"<<orders[i]["studentName"]<<" ";
            ofs<<"applyStatus:"<<orders[i]["applyStatus"]<<endl;
        }
        ofs.close();
        cout<<"Update orders ... Done!\n";
    }
}