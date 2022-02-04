#include <iostream>
#include <string>
#include <deque>
struct OpNum {
    std::string op;
    std::string num;
};

int main() {
    std::deque<std::string> dq;
    int n;
    bool was = false;

    std::string arg;
    std::cin >> arg;
    dq.push_back(arg);
    std::cin >> n;
    OpNum pr;
    for (int i = 0; i < n; ++i) {
        OpNum on;
        std::cin>>on.op>>on.num;
        if ((on.op=="/" || on.op =="*")&&(pr.op=="+"||pr.op=="-")){
            dq.push_front("(");
            dq.push_back(")");
        }
        dq.push_back(on.op);
        dq.push_back(on.num);
        pr=on;
    }
    for (const auto& item : dq){
        if (item=="+"||item=="-"||item=="*"||item=="/")
            std::cout<<" "<<item<<" ";
        else
            std::cout<<item;
    }
    return 0;
}