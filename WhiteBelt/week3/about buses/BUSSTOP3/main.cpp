#include <iostream>
#include <map>
#include <string>
#include <set>
void Add(std::map<int, std::set<std::string>>& stops, std::set<std::string>& neww){
    unsigned int si = stops.size()+1;
    stops[si] = neww ;
    std::cout<< "New bus "<< si<<std::endl;
}
void CompareInMap(std::map<int, std::set<std::string>>& stops,std::set<std::string>& neww){
    bool estb = false;
    int nomer=0 ;
    for (auto& c : stops){
        ++nomer;
        if (c.second==neww)
            estb=true;
        if(estb)
            break;
    }
    if (!estb){
        Add(stops, neww);
    } else {
        std::cout << "Already exists for "<< nomer<<std::endl;
    }
}
void Obrabotka(std::map<int, std::set<std::string>>& stops, int& n){
    for (int i = 0 ; i < n ; ++i){
        int k;
        std::cin >> k;
        std::set<std::string> neww;
        for (int j = 0 ; j < k ; ++j){
            std::string str ;
            std::cin >> str ;
            neww.insert(str);
        }
        CompareInMap(stops, neww);
    }
}
int main() {
    int n;
    std::cin>>n;
    std::map<int, std::set<std::string>> stops;
    Obrabotka(stops,n);
    return 0;
}
