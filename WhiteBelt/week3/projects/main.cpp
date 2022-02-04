#include <iostream>
#include <vector>
#include <string>
void AddMilestone(std::vector<std::string>& v, int& date, std::string& milestone){
    if ((!v[date-1].empty())&&(!milestone.empty()))
        v[date-1]+=" "+milestone;
    else
        v[date-1]+=milestone;
}
void DumpMilestone(std::vector<std::string>& v, int& date){
    std::string str = v[date-1];
    int i = 0 ;
    for (int j = 0 ; j <str.size();j++ ){
        if(str[j]==' ')
        ++i;
    }
    if (!str.empty())
        ++i;
    std::cout<< i<< " "<< str<< std::endl;
}
int Calendar(int& month){
    switch(month){
        case 1:
            return -3;
        case 2:
            return 3;
        case 3:
            return -1;
        case 4:
            return 1;
        case 5:
            return -1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return -1;
        case 9:
            return 1;
        case 10:
            return -1;
        case 11:
            return 1;
        case 12:
            return 0;
    }
}
void Next (std::vector<std::string>& v, int& month){
    int lessormore = Calendar(month);
    int date = v.size() - abs(lessormore);
    if (lessormore>0)
        for (int i = 0 ; i < lessormore; ++i)
            v.push_back("");
    else if (lessormore<0){
        for (int i = abs(lessormore); i > 0;--i ){
            int si = v.size() -i;
            if (!v[si].empty())
                AddMilestone(v,date,v[si]);
        }
        for (int i = 0 ; i < abs(lessormore); ++i)
            v.pop_back();
    }
}
void Obrabotka(std::vector<std::string>& v,int& n){
    int month =1 ;
    for (int i = 0 ;  i < n; i++){
        std::string command;
        std::cin >> command;
        if (command=="NEXT"){
            Next(v,month);
            ++month;
            if (month==13)
                month=1;
        }
        else {
            int daynumber;
            std::cin >> daynumber;
            if (command=="ADD"){
                std::string milestone;
                std::cin>>milestone;
                AddMilestone(v,daynumber,milestone);
            }
            else
                DumpMilestone(v,daynumber);
        }
    }
}
int main() {
    int n ;
    std::cin>>n ;
    std::vector<std::string> dela ;
    dela.assign(31,"");
    Obrabotka(dela,n);
}

