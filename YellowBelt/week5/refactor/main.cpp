#include <iostream>
#include <string>
#include <utility>
#include <vector>
class Dizi{
public:
    Dizi(std::string   t,std::string   r  ): Name(std::move(t)), Role(std::move(r)){}
    virtual void Walk(std::string destination) =0;
    const std::string Name;
    const std::string Role;
};

class Student : public Dizi{
public:

    Student(const std::string& name, std::string  favouriteSong):Dizi(name, "Student"), FavouriteSong(std::move(favouriteSong)) {}

    void Learn() {
        std::cout << "Student: " << this->Name << " learns" << std::endl;
    }

    void Walk(const std::string destination) override {
        std::cout << "Student: " << this->Name << " walks to: " << destination << std::endl;
        SingSong();
    }

    void SingSong() {
        std::cout << "Student: " << this->Name << " sings a song: " << FavouriteSong << std::endl;
    }

public:
    const std::string FavouriteSong;
};


class Teacher : public Dizi{
public:

    Teacher(const std::string& name, std::string  subject): Dizi(name, "Teacher"), Subject(std::move(subject)) {}

    void Teach() {
        std::cout << "Teacher: " << this->Name << " teaches: " << Subject << std::endl;
    }

    void Walk(const std::string destination) override {
        std::cout << "Teacher: " << this->Name << " walks to: " << destination << std::endl;
    }

public:
    const std::string Subject;
};


class Policeman : public Dizi{
public:
    explicit Policeman(const std::string& name): Dizi(name, "Policeman") {}

    void Check(Dizi& t) {
        std::cout << "Policeman: " << this->Name << " checks "<<t.Role<<". "<<t.Role<<"s name is: " << t.Name << std::endl;
    }

    void Walk(std::string destination) override {
        std::cout << "Policeman: " << this->Name << " walks to: " << destination << std::endl;
    }
};

void VisitPlaces(Dizi& t, const std::vector<std::string>& places) {
    for (const auto& p : places) {
        t.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}