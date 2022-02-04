#include <iostream>
#include <vector>
int main()
{
    int k;
    double sum=0;
    std::vector<double>temperatura;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        double temp;
        std::cin >> temp;
        temperatura.push_back(temp);
        sum+=temp;
    }
    sum/=temperatura.size();
    std::vector<int>days;
    for (int i = 0; i < temperatura.size(); ++i) {
        if (temperatura[i] > sum) {
            days.push_back(i);
        }
    }
    std::cout << days.size()<<std::endl;
    for (const auto& c : days) {
        std::cout << c << " ";
    }
}


