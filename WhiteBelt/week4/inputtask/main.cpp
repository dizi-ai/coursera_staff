#include <iostream>
#include <string>
#include <vector>
struct Student {
    std::string name ;
    std::string surname;
    std::string day;
    std::string month;
    std::string year;

};
void FillTheVec(int& n, std::vector<Student>& students){
    for (int i = 0 ; i < n; i++ ){
        Student student;
        std::string str;
        std::cin >> str;
        student.name = str ;
        std::cin >> str;
        student.surname = str ;
        std::cin>>str;
        student.day=str;
        std::cin>>str;
        student.month=str;
        std::cin>>str;
        student.year=str;
        students.push_back(student);
    }
}
std::string GetBday(int& n, std::vector<Student>& students){
    std::string bday;
    bday +=students[n-1].day+".";
    bday +=students[n-1].month+"."+students[n-1].year;
    return bday;
}
std::string GetName(int& n, std::vector<Student>& students){
    return students[n-1].name+" "+students[n-1].surname;
}
int main() {
    int n;
    std::cin >> n ;
    std::vector<Student> students;
    FillTheVec(n,students);
    std::cin >> n;
    for (int i = 0 ; i < n;i++){
        std::string command;
        std::cin>> command;
        int k;
        std::cin >> k;
        if ((command=="name")&&(k>0)&&(k <= students.size())){
            std::cout << GetName(k,students)<< std::endl;
        }
        else if ((command=="date")&&(k>0)&&(k <= students.size())){
            std::cout << GetBday(k,students)<< std::endl;
        }
        else {
            //std::getline(std::cin,command);
            std::cout<< "bad request"<<std::endl;
        }
    }

    return 0;
}
