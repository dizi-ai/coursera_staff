#pragma once

#include <cstdlib>
#include <algorithm>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
    SimpleVector() =default;
    explicit SimpleVector(const size_t& size) {
        delete [] data;
        data = new T[size];
        size_=size;
        capacity_=size;
    }
    ~SimpleVector() {
        delete [] data;
    }

    T& operator[](const size_t& size) {
        return data[size];
    }

    T* begin() {
        return data;
    }
    T* end() {
        return data+size_;
    }

    size_t Size() const {
        return size_;
    }
    size_t Capacity() const {
        return capacity_;
    }
    void PushBack(const T& value) {
        size_++;
        if (capacity_==0){
            capacity_=1;
            delete[] data;
            data = new T[capacity_ * 2];
        }
        data[size_-1]=value;
        if (size_==capacity_) {
            capacity_ *= 2;
            T* temp = new T[capacity_];
            std::copy(data,data+size_,temp);
            delete [] data;
            data=temp;
        }
    }

private:
    T* data= nullptr;
    size_t size_=0;
    size_t capacity_=0;
};
