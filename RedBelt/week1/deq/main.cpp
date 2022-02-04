#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Deque{
public:
    Deque()= default;
    [[nodiscard]] bool Empty() const{
        if (front.empty()&&back.empty())
            return true;
        return false;
    }
    size_t Size() const{
        return front.size()+back.size();
    }
    T& operator[](const size_t& t){
        if(t>=front.size()||front.empty())
            return back[t-front.size()];
        return front[front.size()-t-1];
    }
    const T& operator[](const size_t& t) const{
        if(t>=front.size()||front.empty())
            return back[t-front.size()];
        return front[front.size()-t-1];
    }
    const T& At(const int& t) const{
        if (t>front.size()+back.size()||t<0)
            throw std::out_of_range("");
        if(t>=front.size()||front.empty())
            return back[t-front.size()];
        return front[front.size()-t-1];
    }
    T& At(const int& t){
        if (t>front.size()+back.size()||t<0)
            throw std::out_of_range("");
        if(t>=front.size()||front.empty())
            return back[t-front.size()];
        return front[front.size()-t-1];
    }
    const T& Front() const {
        if (!front.empty())
            return front.back();
        return back.front();
    }
    T& Front(){
        if (!front.empty())
            return front.back();
        return back.front();
    }
    const T& Back() const {
        if (!back.empty())
            return back.back();
        return front.front();
    }
    T& Back(){
        if (!back.empty())
            return back.back();
        return front.front();
    }
    void PushFront(const T& t){
        front.push_back(t);
    }
    void PushBack(const T& t){
        back.push_back(t);
    }
private:
    std::vector<T>front;
    std::vector<T>back;

};
int main() {
    /*
    Deque<int> dq;
    dq.PushFront(1);
    std::cout<<dq.Front()<<std::endl;
    dq.PushFront(2);
    std::cout<<dq.Front()<<std::endl;
    dq.PushFront(3);
    std::cout<<dq.Front()<<std::endl;
    dq.PushFront(4);
    std::cout<<dq.Front()<<std::endl;
    dq.PushFront(5);
    std::cout<<dq.Front()<<std::endl;
    dq.PushFront(6);
    std::cout<<dq.Front()<<std::endl;
    dq.PushFront(7);
    std::cout<<dq.Front()<<std::endl;
/*
    Deque<int>dq;
    dq.PushBack(1);
    std::cout<<dq.Back()<<std::endl;//1
    std::cout<<dq.Front()<<std::endl;//1
    std::cout<<dq.At(0)<<std::endl;//1
    dq.PushFront(2);
    std::cout<<dq.Front()<<std::endl;//2
    dq.PushFront(3);
    std::cout<<dq.Size()<<std::endl;//3
    dq.PushFront(4);
    std::cout<<dq.Size()<<std::endl;//4
    dq.PushFront(5);
    std::cout<<dq.Size()<<std::endl;//5
    auto it = dq.Front();
    auto it2= dq.Back();
    std::cout<<it<<" "<<it2<<std::endl;//5 1
    std::cout<<dq.Size()<<std::endl;//5
    dq.PushBack(3);
    std::cout<<dq.Back()<<std::endl;//3
    std::cout<<dq.Size()<<std::endl;//6
    dq.PushBack(11);
    std::cout<<dq.At(dq.Size()-1)<<std::endl;//11
    std::cout<<dq.At(dq.Size()-2)<<std::endl;//3
    std::cout<<dq.At(dq.Size()-3)<<std::endl;//1
    std::cout<<dq.At(dq.Size()-4)<<std::endl;//2
    std::cout<<dq.At(dq.Size()-5)<<std::endl;//3
    std::cout<<dq.At(dq.Size()-6)<<std::endl;//4
    std::cout<<dq.At(dq.Size()-7)<<std::endl;//5
*/
    return 0;
}
