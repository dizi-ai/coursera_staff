#include <iostream>
#include <map>
#include <string>
#include <vector>
void BusesStopVec (std::map <std::string , std::vector<std::string>>& buses,std::vector<std::string>& stops, std:: string& n,std::vector<std::string>& rbuses){

    for (int i = 0 ; i < stops.size();i++){
        std::vector <std::string > vbuses;
        std::cout<< "Stop "<< stops[i]<< ": ";
        for (auto& c: buses) {
            for (auto &p:c.second) {
                if (p == stops[i]) {
                    if (c.first!=n)
                    vbuses.push_back(c.first);
                }
            }
        }
        if (vbuses.empty()){
            std::cout << "no interchange"<< std::endl;
        } else {
            for (auto& p :rbuses)
                for (auto& c:vbuses )
                    if(c==p)
                        std::cout << c << " ";
            std::cout << std::endl;
        }

    }
}
void NewBus (std::map <std::string , std::vector<std::string>>& buses,std::string& number, int & k,std::vector<std::string>& order){
    std::vector<std::string> stops;
    for (int i = 0; i < k ; i++){
        std::string part;
        std::cin>>part;
        stops.push_back(part);
    }
    buses[number]= stops;
    order.push_back(number);
}
void BusesStop(std::map <std::string , std::vector<std::string>>& buses, std::string& stop,std::vector<std::string>& order){
    bool estb = false;
    for (auto& c:buses)
        for (auto& p : c.second )
        if (p ==stop)
            estb=true;
    if ((buses.empty())||(!estb)){
        std::cout << "No stop "<<std::endl;
    } else {
        for(auto& f : order)
        for (auto& c: buses){
            if (c.first==f){
                std::vector<std::string> fv = c.second;
                for (auto& d : fv )
                    if(d==stop)
                        std::cout << f << " ";
            }
        }
        std::cout << std::endl;
    }
}
void StopBuses(std::map <std::string , std::vector<std::string>>& buses, std::string& number, std::vector<std::string>& rbuses ){
    bool estb = false;
    for (auto& c:buses)
        if (c.first==number)
            estb=true;

    if ((buses.empty())||(!estb)){
        std::cout << "No bus "<<std::endl;
    } else {
        for (auto& c : buses){
            std::vector<std::string> vbuses;
            for (auto& p : c.second ){
                if (c.first==number)
                    vbuses.push_back(p);
            }
            BusesStopVec(buses,vbuses, number,rbuses );
        }
    }
}
void All(std::map <std::string , std::vector<std::string>>& buses){
    if (buses.empty())
        std::cout << "No buses"<<std::endl;
    else {
        for (auto& c : buses) {
            std::cout <<"Bus " <<c.first << ": ";
            for (auto& p : c.second)
                std::cout<<p << " ";
            std::cout << std::endl;
        }
    }
}
void Obrabotka( std::map <std::string , std::vector<std::string>>& buses, int& n){
    std::vector<std::string> order;
    for (int i = 0 ; i <n ; i++){
        std::string command ;
        std::cin>>command;
        if (command=="NEW_BUS"){
            std::string number ;
            std::cin>> number ;
            int k;
            std::cin >> k ;
            NewBus(buses,number, k, order);
        } else if (command=="BUSES_FOR_STOP"){
            std::string stop;
            std::cin >> stop;
            BusesStop(buses,stop,order);

        }else if (command=="STOPS_FOR_BUS"){
            std::string number;
            std::cin>>number;
            StopBuses(buses,number,order);
        } else if (command=="ALL_BUSES"){
            All(buses);
        }
    }
}
int main() {
    int n ;
    std::cin >> n ;
    std::map <std::string , std::vector<std::string>> buses;
    Obrabotka(buses,n);
    return 0;
}
