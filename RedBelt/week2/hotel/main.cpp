#include <iostream>
#include "test_runner.h"
#include <string>
#include <deque>
#include <map>
#include <unordered_set>
#include <unordered_map>
struct Info{
    Info(const std::string& hotel1,const int64_t& time1,const int& cid,const int& room1){
        hotel=hotel1;
        time=time1;
        client=cid;
        room=room1;
    }
    std::string hotel;
    int64_t time;
    int client;
    int room;
};
class Hotel{
public:
    Hotel()=default;
    void Book(const int64_t& time,const std::string& hotel,const int& cid,const int& room){
        for (int i=0;i<time_manager.size();++i){
            if (time-86399>time_manager[i].time) {
                roomsin[time_manager[i].hotel]-=time_manager[i].room;
                hotel_to_clients_[time_manager[i].hotel].erase(time_manager[i].client);
                time_manager.pop_front();
                --i;
            }
            else
                break;
        }
        time_manager.emplace_back(Info(hotel,time,cid,room));
        roomsin[hotel]+=room;
        hotel_to_clients_[hotel].insert(cid);
    }
    int Clients(const std::string& hotel) const{
        if (hotel_to_clients_.count(hotel) == 0)
            return 0;
        return hotel_to_clients_.at(hotel).size();
    }
    int Rooms(const std::string& hotel) const{
        if (roomsin.count(hotel)==0)
            return 0;
        return roomsin.at(hotel);
    }
private:
    std::deque<Info> time_manager;
    std::map<std::string,int> roomsin;
    std::unordered_map<std::string, std::unordered_set<int>> hotel_to_clients_;
};

void Test1(){
    Hotel hot;
    ASSERT_EQUAL(hot.Clients("Marriott"),0)
    ASSERT_EQUAL(hot.Rooms("Marriott"),0)
    hot.Book(10,"FourSeasons",1,2);
    hot.Book(10,"Marriott",1,1);
    hot.Book(86409,"FourSeasons",2,1);
    ASSERT_EQUAL(hot.Clients("FourSeasons"),2)
    ASSERT_EQUAL(hot.Rooms("FourSeasons"),3)
    ASSERT_EQUAL(hot.Clients("Marriott"),1)
    hot.Book(86410,"Marriott",2,10);
    ASSERT_EQUAL(hot.Rooms("FourSeasons"),1)
    ASSERT_EQUAL(hot.Rooms("Marriott"),10)
}
void Test2(){
    Hotel b;

    ASSERT_EQUAL(b.Rooms("a"),0);
    ASSERT_EQUAL(b.Clients("a"),0);

    ASSERT_EQUAL(b.Rooms("b"),0);
    ASSERT_EQUAL(b.Clients("c"),0);

    b.Book(-100000,"a",100000,1000);
    b.Book(-100000,"a",100003,1000);
    b.Book(-100000,"b",100002,1000);
    ASSERT_EQUAL(b.Rooms("a"),2000);
    ASSERT_EQUAL(b.Clients("a"),2);

    b.Book(-10000,"a",100002,1000);
    ASSERT_EQUAL(b.Rooms("a"),1000);
    ASSERT_EQUAL(b.Clients("a"),1);
    ASSERT_EQUAL(b.Rooms("b"),0);
    ASSERT_EQUAL(b.Clients("b"),0);

}
void Test3(){
    Hotel b;
    b.Book(1,"a",11,4);
    b.Book(50000,"a",11,5);
    b.Book(90000,"a",22,2);
    ASSERT_EQUAL(b.Clients("a"),2);
    ASSERT_EQUAL(b.Rooms("a"),7);
}
int main() {
    //TestRunner tr;
    //RUN_TEST(tr, Test1)
    //RUN_TEST(tr, Test2)
    //RUN_TEST(tr, Test3)
    Hotel hot;
    int q = 0;
    std::cin >> q;
    for (int i = 0;i < q;++i){
        std::string cmd;
        std::cin>>cmd;
        if (cmd=="BOOK"){
            int cid, room;
            int64_t time;
            std::string hotel;
            std::cin>>time>>hotel>>cid>>room;
            hot.Book(time,hotel,cid,room);
        }
        else if (cmd=="CLIENTS"){
            std::string hotel;
            std::cin>>hotel;
            std::cout<<hot.Clients(hotel)<<std::endl;
        }
        else if(cmd=="ROOMS"){
            std::string hotel;
            std::cin>>hotel;
            std::cout<<hot.Rooms(hotel)<<std::endl;
        }
    }
    return 0;
}