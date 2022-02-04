#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <iomanip>
#include <cmath>
class Figure{
public:
    virtual std::string Name(void) const=0;
    virtual double Perimeter(void) const=0;
    virtual double Area(void) const=0;
};
class Rect:public Figure{
public:
    Rect(const int& t,const int& t1):height(t),width(t1){

    }
    std::string Name(void) const override{
        return this->name;
    }
    double Perimeter(void) const override{
        return 2*(height+width);
    }
    double Area(void) const override{
        return height * width;
    };
private:
    const std::string name= "RECT";
    const int height;
    const int width;

};
class Triangle : public Figure{
public:
    Triangle(const int& t,const int& t1,const int& t2):a(t),b(t1),c(t2){

    }
    std::string Name(void) const override{
        return this->name;
    }
    double Perimeter(void) const override{
        return a+b+c;
    }
    double Area(void) const override{
        double p = Perimeter()/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
private:
    const std::string name="TRIANGLE";
    const int a;
    const int b;
    const int c;
};
class Circle : public Figure{
public:
    explicit Circle(const int& t):r(t){

    }
    std::string Name(void) const override{
        return this->name;
    }
    double Perimeter(void) const override{
        return 2*r*3.14;
    }
    double Area(void) const override{
        return 3.14*r*r;
    }
private:
    const std::string name="CIRCLE";
    const int r;
};

std::shared_ptr<Figure> CreateFigure(std::istringstream& is){
    std::string fn;
    std::shared_ptr<Figure> fig;
    is >> fn;
    if (fn=="CIRCLE"){
        int r;
        is>>r;
        fig=std::make_shared<Circle>(r);
    }
    else if(fn=="TRIANGLE"){
        int a,b,c;
        is>>a>>b>>c;
        fig=std::make_shared<Triangle>(a,b,c);
    }
    else if(fn=="RECT"){
        int h,w;
        is>>h>>w;
        fig=std::make_shared<Rect>(h,w);
    }
    return fig;
}
int main() {
    std::vector<std::shared_ptr<Figure>> figures;
    for (std::string line; getline(std::cin, line); ) {
        std::istringstream is(line);

        std::string command;
        is >> command;
        if (command == "ADD") {
            is >> std::ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                std::cout << std::fixed << std::setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << std::endl;
            }
        }
    }
    return 0;
}
