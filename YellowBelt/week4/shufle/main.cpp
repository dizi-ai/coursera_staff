#include <iostream>
#include <vector>
#include <algorithm>
std::ostream& operator<< (std::ostream& os, std::vector<int>& v){
    for (int i = 0 ; i < v.size();++i){
        if (i!=v.size()-1)
            os<<v[i]<<" ";
        else
            os<<v[i];
    }
    return os;
}
int make(const int& q){
    int res=1;
    for (int i = 1 ; i < q+1;++i){
        res*=i;
    }
    return res;
}
void shuffle(const int& q){
    std::vector<int> temp;
    for (int i = 0; i < q;++i) {
        temp.push_back(i+1);
    }
    //std::cout<<temp<<std::endl;
    for (int i = 0 ; i < make(q);++i) {
        std::prev_permutation(temp.begin(), temp.end());
        std::cout << temp<<std::endl;
    }


}
int main() {
    int q;
    std::cin>>q;
    shuffle(q);
    return 0;
}
