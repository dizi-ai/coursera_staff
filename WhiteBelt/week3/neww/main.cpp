#include <iostream>
#include <map>
#include <string>
void Add(std::map <std::string, std::string>& map, std::string& key , std::string& value){
    map[key]=value;
}
void Dump(std::map <std::string, std::string>& map){
    if (map.empty())
        std::cout <<"There are no countries in the world" <<std::endl;
    else {
        for (const auto &c : map)
            std::cout << c.first << "/" << c.second << " ";
        std::cout << std::endl;
    }
}
void Change(std::map <std::string, std::string>& map, std::string& cname, std::string& gname){
    if (map.count(cname)==0) {
        Add(map, cname, gname);
        std::cout <<"Introduce new country "<< cname << " with capital "<< gname << std::endl;
    } else {
        if(map[cname]==gname){
            std::cout <<"Country " << cname << " hasn't changed its capital"<< std::endl;
        } else {
            std::cout << "Country " << cname << " has changed its capital from " << map[cname] << " to " << gname
                      << std::endl;
            map.erase(cname);
            map[cname] = gname;
        }
    }

}
void Rename(std::map <std::string, std::string>& map,std::string& old, std::string neww ){
    bool keyv3=true;
    bool keyv2 = true;
    for (auto& c : map) {
        if (c.first == old)
            keyv3 = false;
        if (c.first == neww)
            keyv2 = false;
    }
    if ((!keyv3)&&(old!=neww)&&(keyv2)) {
        std::string a;
        a = map[old];
        std::cout << "Country " << old << " with capital " << a << " has been renamed to " << neww << std::endl;
        map.erase(old);
        Add(map, neww, a);
    } else {
        std::cout<< "Incorrect rename, skip" << std::endl;
    }
}
void AboutCountry(std::map <std::string, std::string>& map, std::string& name){
    int keyv =0;
    for (auto& c : map)
        if (c.first==name)
            ++keyv;
        if (keyv==0)
            std::cout <<   "Country "<< name << " doesn't exist"<< std::endl;
        else
            std::cout<<"Country " <<name << " has capital "<< map[name] << std::endl;
}
void Obrabotka (std::map <std::string, std::string>& map, int& n){
    for (int i = 0; i < n ; i++){
        std::string str ;
        std::cin>>str;
        if (str=="CHANGE_CAPITAL"){
            std::string cname, gname ;
            std::cin >> cname >> gname;
            Change(map,cname, gname);
        } else if (str=="RENAME"){
            std::string old, neww ;
            std::cin >> old >> neww;
            Rename(map, old, neww);
        }else if(str=="ABOUT"){
            std::string name;
            std::cin >> name ;
            AboutCountry(map, name);
        }else {
            Dump(map);
        }
    }
}
int main() {
     int n ;
     std::cin >> n ;
     std::map <std::string, std::string> info ;
    Obrabotka (info,n);
}
