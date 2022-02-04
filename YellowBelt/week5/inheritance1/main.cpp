#include <iostream>

using namespace std;

class Animal {
public:
    Animal(std::string t):Name(std::move(t)){}

    const string Name;
};


class Dog : public Animal{
public:
    Dog(std::string t):Animal(std::move(t)){}

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
/*
int main(void){
    Dog d("Spew");
    d.Bark();
    return 0;
}
 */