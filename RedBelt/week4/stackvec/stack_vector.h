#pragma once

#include <stdexcept>
#include <array>

template <typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0){
        if (a_size>capacity_)
            throw std::invalid_argument("");
        size_=a_size;
    }

    T& operator[](size_t index){
        return array_[index];
    }
    const T& operator[](size_t index) const{
        return array_[index];
    }

    auto begin(){
        return array_.begin();
    }
    auto end(){
        return array_.begin()+size_;
    }
    auto begin() const{
        return array_.begin();
    }
    auto end() const{
        return array_.begin()+size_;
    }

    size_t Size() const{
        return size_;
    }
    size_t Capacity() const{
        return capacity_;
    }

    void PushBack(const T& value){
        if (size_==capacity_)
            throw std::overflow_error("");
        array_[size_]=value;
        size_++;

    }
    T PopBack(){
        if (size_==0)
            throw std::underflow_error("");
        size_--;
        return array_[size_];
    }

private:
    std::array<T,N> array_;
    const size_t capacity_=N;
    size_t size_=0;
};
