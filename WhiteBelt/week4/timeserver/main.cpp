#include <iostream>
#include <exception>
#include <string>


class TimeServer {
public:
    std::string GetCurrentTime() {
        try {
            last_fetched_time=AskTimeServer();
            return  last_fetched_time;
        }
        catch (std::system_error) {
            return  last_fetched_time;
        }
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
    }

private:
    std::string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        std::cout << ts.GetCurrentTime() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception got: " << e.what() << std::endl;
    }
    return 0;
}
