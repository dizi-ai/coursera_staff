#include <iostream>
#include <string>
#include <vector>
class Block {
public:
    Block() {
        d = 0;
        sh = 0;
        v = 0;
    }
    Block(const double& a, const double& b, const double& c) {
        d = a;
        sh = b;
        v = c;
    }
    uint64_t GetWeight() {
        return static_cast<uint64_t>(d) * static_cast<uint64_t>(sh) * static_cast<uint64_t>(v);
    }
    void SetD(double& a) {
        d = a;
    }
    void SetSh(double& a) {
        sh = a;
    }
    void SetV(double& a) {
        v = a;
    }
private:
    double d;
    double sh;
    double v;
};
std::istream& operator>>(std::istream& e, Block& bl) {
    double p, q, t;
    e >> p >> q >> t;
    bl.SetD(p);
    bl.SetSh(q);
    bl.SetV(t);
    return e;
}
int main(){
    int k;
    int16_t r;
    std::vector<Block>bl;
    std::cin >> k >> r;
    for (int i = 0; i < k; ++i) {
        Block t;
        std::cin >> t;
        bl.push_back(t);
    }
    uint64_t sum = 0;
    for (auto& c : bl) {
        sum += static_cast<uint64_t>(c.GetWeight() * r);
    }
    std::cout << sum << std::endl;
}


