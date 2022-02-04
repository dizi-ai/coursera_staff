#include <iostream>
#include <map>
#include <string>
#include <vector>
void Add(std::map<int, std::vector<std::string>>& stops, std::vector<std::string>& neww){
    int si = stops.size()+1;
    stops[si] = neww ;
    std::cout<< "New bus "<< si<<std::endl;
}
void CompareInMap(std::map<int, std::vector<std::string>>& stops,std::vector<std::string>& neww){
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
};
void Obrabotka(std::map<int, std::vector<std::string>>& stops, int& n){
    for (int i = 0 ; i < n ; ++i){
        int k;
        std::cin >> k;
        std::vector<std::string> neww;
        for (int i = 0 ; i < k ; ++i){
            std::string str ;
            std::cin >> str ;
            neww.push_back(str);
        }
        CompareInMap(stops, neww);
    }
}
int main() {
    int n;
    std::cin>>n;
    std::map<int, std::vector<std::string>> stops;
    Obrabotka(stops,n);
    return 0;
}
