#include <iostream>
#include <vector>
#include <algorithm>
class FunctionReverse{
public:
    FunctionReverse(char op, double val){
        oper= op;
        value= val;
    }
    double Apply(double& sval) const {
        if (oper =='+'){
            return sval+=value;
        }
        else if (oper =='-') {
            return sval-=value;
        }
        else if (oper =='*') {
            return sval*=value;
        }
        else if (oper =='/') {
            return sval/=value;
        }
    }
    void Invert(){
        if (oper=='+'){
            oper = '-';
        }
        else if (oper=='-') {
            oper = '+';
        }
        else if (oper=='*') {
            oper = '/';
        }
        else if (oper=='/') {
            oper = '*';
        }
    }
private:
    char oper;
    double value;
};
class Function {
public:
    void AddPart(const char& new_oper, const double& val){
        query.push_back({new_oper, val});
    }
    double Apply (double val) const {
        for (const FunctionReverse& c : query)
            val= c.Apply(val);
        return val;

    }
    void Invert(){
        for (FunctionReverse& c : query) {
            c.Invert();
        }
        std::reverse(query.begin(), query.end());
    }
private:
    std::vector<FunctionReverse> query;
};
double Make(char operation, double exp){
    Function f;
    f.AddPart(operation, exp);
    return f.Apply(exp);
}
int main() {
    double y = 10;
    std::cout<< Make('+', 10);
    return 0;
}
