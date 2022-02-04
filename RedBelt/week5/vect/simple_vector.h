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
    SimpleVector(const SimpleVector<T>& other):data(new T[other.capacity_]),size_(other.capacity_),capacity_(other.capacity_){
        std::copy(other.begin(), other.end(),begin());
    }
    SimpleVector<T>& operator=(const SimpleVector<T>& other){
        delete[] data;

        data = new T[other.size_];
        size_ = other.size_;
        capacity_ = other.capacity_;

        std::copy(other.begin(), other.end(), begin());

        return *this;
    }
    bool operator==(const SimpleVector<T>&other){
        if(data==other.data&&size_==other.size_&& capacity_==other.capacity_)
            return true;
        return false;
    }
    ~SimpleVector() {
        delete [] data;
    }
    const T* begin() const{
        return data;
    }
    const T* end() const{
        return data+size_;
    }

    T* begin() {
        return data;
    }
    T* end() {
        return data+size_;
    }
    T& operator[](const size_t& size) {
        return data[size];
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
