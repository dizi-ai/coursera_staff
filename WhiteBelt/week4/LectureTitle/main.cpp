#include <iostream>
#include <string>
struct Specialization{
    std::string value;
    explicit Specialization(const std::string& nv){
        value=nv;
    }
};
struct Course{
    std::string value;
    explicit Course(const std::string& nv){
        value=nv;
    }
};
struct Week{
    std::string value;
    explicit Week (const std::string& nv){
        value=nv;
    }
};
struct LectureTitle {
    LectureTitle(const Specialization& new_spec,const Course& new_course,const Week& new_week){
        specialization=new_spec.value;
        course=new_course.value;
        week=new_week.value;
    }
    std::string specialization;
    std::string course;
    std::string week;
};
int main() {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );
    //LectureTitle title("C++", "White belt", "4th");*/

   //LectureTitle title(std::string("C++"), std::string("White belt"), std::string("4th"));

    //LectureTitle title = {"C++", "White belt", "4th"};

    //LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

    /*LectureTitle title(
            Course("White belt"),
            Specialization("C++"),
            Week("4th")
    );*/

   /* LectureTitle title(
            Specialization("C++"),
            Week("4th"),
            Course("White belt")
    );*/
    return 0;
}
