#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
void PrintVec(std::vector<std::string>& v){
    for (const auto& i : v){
        std::cout<< i << " ";
    }
    std::cout<<std::endl;
}
bool Compare(std::string& w1, std::string& w2){
   if (w1.size()>w2.size())
       return true;
   else if (w1.size()<w2.size())
       return false;
   else {
       for (int i = 0 ; i < w2.size();i++) {
           int iw1 = tolower(w1[i]);
           int iw2 = tolower(w2[i]);
           if (iw1 < iw2)
               return false;
           else if (iw1 > iw2)
               return true;
           }
       }
   return false;
   }
void SortVec(std::vector<std::string>& ch){
    for (int i = 0 ; i < ch.size()-1;i++){
        for (int j = 0 ; j <ch.size()-1- i ; j++){
            if (Compare(ch[j], ch[j+1])){
                std::string temp;
                temp = ch[j];
                ch[j]= ch[j+1];
                ch[j+1]=temp;

            }
        }
    }
    PrintVec(ch);
}
void Execution(std::vector<std::string>& ch, int& n){
    for (int i = 0 ; i < n ; i ++){
        std::string str;
        std::cin >> str ;
        ch.push_back(str);
    }
    if (n!=0)
        SortVec(ch);
    else
        std::cout<<"";

    /*sort(ch.begin(), ch.end(),[](std::string i , std::string j){
            if (!Compare(i, j))
                return i < j;
    });
    sort(ch.begin(), ch.end(),[](std::string i , std::string j){
        if (!Compare(i, j))
            return i > j;
    });
    PrintVec(ch);*/
}
int main() {
    int n;
    std::cin >> n ;
    std::vector<std::string> mass;
    Execution(mass,n);
    return 0;
}
