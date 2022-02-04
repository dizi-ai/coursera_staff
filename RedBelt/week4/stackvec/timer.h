#pragma once

#include <chrono>
#include <iostream>
#include <string>


class Timer{
public:
    explicit Timer(const std::string& msg = "")
            : message(msg + ": ")
            , start(std::chrono::steady_clock::now())
    {
    }

    ~Timer() {
        auto finish = std::chrono::steady_clock::now();
        auto dur = finish - start;
        std::cerr << message
             << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
             << " ms" << std::endl;
    }
private:
    std::string message;
    std::chrono::steady_clock::time_point start;
};

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define Timer(message) \
  Timer UNIQ_ID(__LINE__){message};
