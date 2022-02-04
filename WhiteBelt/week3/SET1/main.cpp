#include <iostream>
#include <string>
#include <map>
#include <set>
void Add(std::map <std::string,std::set<std::string>>& map,std::map <std::string,std::set<std::string>>& map2,std::string& w1,std::string& w2){
    if ((map2[w1].count(w2)==0)&&(map[w2].count(w1)==0)){
        map[w1].insert(w2);
        map2[w2].insert(w1);
    }
}
void Count(std::map <std::string,std::set<std::string>>& map,std::map <std::string,std::set<std::string>>& map2,std::string& w1){
        std::cout << (map2[w1].size()+map[w1].size())<<std::endl;
}
void Check(std::map <std::string,std::set<std::string>>& map,std::map <std::string,std::set<std::string>>& map2,std::string& w1,std::string& w2 ){
    if (((map2[w2].count(w1)!=0)&&(map[w1].count(w2)!=0))||((map[w2].count(w1)!=0)&&(map2[w1].count(w2)!=0)))
        std::cout << "YES"<<std::endl;
    else
        std::cout << "NO"<<std::endl;
}
void Execution(std::map <std::string,std::set<std::string>>& map,std::map <std::string,std::set<std::string>>& map2, int& n){
    for (int i = 0 ; i < n ; ++i){
        std::string command;
        std::cin>>command;
        if(command=="ADD"){
            std::string w1,w2;
            std::cin>>w1>>w2;
            Add(map,map2,w1,w2);
        }else if (command=="COUNT"){
            std::string w1;
            std::cin>>w1;
            Count(map,map2,w1);
        }else if (command=="CHECK"){
            std::string w1,w2;
            std::cin>>w1>>w2;
            Check(map,map2,w1,w2);
        }
    }
}
int main() {
    int n;
    std::cin >> n;
    std::map <std::string,std::set<std::string>> map;
    std::map <std::string,std::set<std::string>> map2;
    Execution(map,map2,n);
}
