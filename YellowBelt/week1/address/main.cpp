#include <iostream>
#include <map>
#include <string>
template<typename k, typename v, typename c>
v& GetRefStrict(std::map<k, v>& m,c i) {
    if (m.find(static_cast<k>(i)) != m.end())
        return m.at(i);
    else
        throw std::runtime_error("runtime error");
}
template<typename k, typename v>
v& GetRefStrict(std::map<k, v>& m,const k i) {
    if (m.find(i) != m.end())
        return m.at(i);
    else
        throw std::runtime_error("runtime error");
}
int main() {
    std::map<std::string, std::string> m = {{"one", "Hello"}, {"two", "Hi"}};
    std::string& item = GetRefStrict(m, ("one"));
    item = "newvalue";
    std::cout << m["one"] << std::endl;

    return 0;
}
