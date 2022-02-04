#include <iostream>
#include <vector>
#include <map>
#include <tuple>
// Объявим функции без тела,
// чтобы их можно было использовать в произвольном порядке

// Для простых типов
template<typename T>
T Sqr(T value);

// Для вектора
template<typename T>
std::vector<T> Sqr(const std::vector<T>& value);

// Для словаря
template<typename K, typename V>
std::map<K, V> Sqr(const std::map<K, V>& value);

// Для пары
template<typename K, typename V>
std::pair<K, V> Sqr(const std::pair<K, V>& value);

// Теперь реализуем их в соответствии с заданием
template<typename T>
T Sqr(T value) {
    return value * value;
}

template<typename T>
std::vector<T> Sqr(const std::vector<T>& value) {
    std::vector<T> result;
    for (const T& x : value) {
        // Здесь важно, что вместо x * x вызывается функция Sqr:
        // это позволяет возводить в квадрат составные объекты
        result.push_back(Sqr(x));
    }

    return result;
}

template<typename K, typename V>
std::map<K, V> Sqr(const std::map<K, V>& value) {
    std::map<K, V> result;
    for (const auto& element : value) {
        result[element.first] = Sqr(element.second);
    }
    return result;
}

template<typename K, typename V>
std::pair<K, V> Sqr(const std::pair<K, V>& value) {
    return {Sqr(value.first), Sqr(value.second)};
}
int main() {
    std::map<int, std::vector<double>> maps;
    auto res = Sqr(maps);
    // Пример вызова функции
    std::vector<int> r={2,3};
    std::vector<int> v = { 1, 2, 3 };
    std::cout << "vector:";
    for (int x : Sqr(v)) {
        std::cout << ' ' << x;
    }
    std::cout << std::endl;

    std::map<int, std::pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };

    std::cout << "map of pairs:" << std::endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
    }
    std::pair<std::pair<int,int>, std::pair<int,int> > x = make_pair(
            std::make_pair(1,2),
            std::make_pair(3,4)
    );
    x=Sqr(x);
    std::cout<<x.first.first<<' '<<x.first.second<<' '
        <<x.second.first<<' '<<x.second.second<<std::endl;
    return 0;

}
