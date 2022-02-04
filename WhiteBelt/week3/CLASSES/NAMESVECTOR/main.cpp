#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
class PersonData {
public:
    std::string name;
    std::string surname;
    int year;
};
class Person {
public:
    static bool FindYear(const int& yeard, const std::vector<PersonData>& data){
        for (auto& c : data)
            if (c.year==yeard)
                return true;
        return false;
    }
    int YearLook(int year){
        if (year>MinYear(data,year)){
            std::vector<int> yeardlistsort= GetSortedVec(yearlist);
            int i = 0 ;
            int temp = 0 ;
            for (int& c : yeardlistsort){
                if ((c<=year)&&(c>=temp))
                    temp=c;
                i++;
            }
            year = temp;
        }
        return year;
    }
    static int MinYear(std::vector<PersonData>& data, int yeard){
        for (auto& c : data)
            if (c.year<yeard)
                yeard= c.year;
        return yeard;
    }
    void ChangeLastName(const int& yeard, const std::string& surname) {
        if (FindYear(yeard, data)) {
            for (auto& c : data)
                if (c.year == yeard) {
                    c.surname = surname;
                }
        }
        else {
            PersonData newp;
            newp.year = yeard;
            newp.surname = surname;
            data.push_back(newp);
            yearlist.push_back(yeard);
        }

    }
    void ChangeFirstName(const int& yeard, const std::string& name) {
        if (FindYear(yeard, data)) {
            for (auto& c : data)
                if (c.year == yeard) {
                    c.name = name;
                }
        }
        else {
            PersonData newp;
            newp.year = yeard;
            newp.name = name;
            data.push_back(newp);
            yearlist.push_back(yeard);
        }
    }
    static std::vector<int> GetSortedVec(std::vector<int>yearlist){
        sort(yearlist.begin(),yearlist.end());
        return yearlist;
    }
    int PrevYear (int year){
        if (year>MinYear(data,year)){
            std::vector<int> yeardlistsort= GetSortedVec(yearlist);
            int i = 0 ;
            int temp = 0 ;
            for (int& c : yeardlistsort){
                if ((c<year)&&(c>temp))
                    temp=c;
                i++;
            }
            year = temp;
        }
        return year;
    }
    void  FillTheGap(std::vector <PersonData>& data, std::string& nv,std::string& sv , int yeard) {
        if (yeard!=PrevYear(yeard))
            while(((nv.empty())||(sv.empty()))&&(yeard!=MinYear(data,yeard))){
                int temp = PrevYear(yeard);
                if (nv.empty()){
                    for (auto& c : data)
                        if (c.year==temp)
                            nv=c.name;
                }
                if (sv.empty()){
                    for (auto& c : data)
                        if (c.year==temp)
                            sv=c.surname;
                }
                yeard= temp;
                FillTheGap(data,nv,sv,yeard);
            }

    }


    std::string GetFullName(int yeard) {
        std::string nv;
        std::string sv;
        yeard = YearLook(yeard);
        for (auto& c : data )
            if (c.year==yeard){
                nv=c.name;
                sv=c.surname;
            }
        FillTheGap(data, nv,sv, yeard);
        std::string vivod;
        if ((nv.empty())&&(sv.empty()))
            vivod="Incognito";
        else if ((!nv.empty())&&(sv.empty()))
            vivod= nv+" with unknown last name";
        else if ((nv.empty())&&(!sv.empty()))
            vivod= sv+" with unknown first name";
        else
            vivod= nv + " "+ sv;
        return vivod;
    };
    std::string GetFullNameWithHistory(int yeard) {
        std::vector<std::string> fornames;
        std::vector<std::string> forsurnames;
        std::vector<std::string> fornames1;
        std::vector<std::string> forsurnames1;
        std::string nv;
        std::string sv;
        yeard=YearLook(yeard);
        for (auto& c : data )
            if (c.year==yeard){
                nv=c.name;
                sv=c.surname;
            }
        FillTheGap(data,nv,sv,yeard);
        PrevNames(data,yeard,fornames,forsurnames);
        for (int i = 0 ; i < fornames.size()-1;i++){
            for (int j = i+1 ;j < fornames.size();j++){
                if (fornames[i]==fornames[j])
                    fornames[j].erase();
                if (fornames[i]==nv)
                    fornames[i].erase();
            }
        }
        for (int i = 0 ; i < forsurnames.size()-1;i++){
            for (int j = i+1 ;j < forsurnames.size();j++){
                if (forsurnames[i]==forsurnames[j])
                    forsurnames[j].erase();
                if (forsurnames[i]==sv)
                    forsurnames[i].erase();
            }
        }
        std::string prevnames;
        int i = 0 ;
        for (auto& c : fornames)
            if ((!c.empty())&&(c!=" "))
                fornames1.push_back(c);
        for (auto& c : fornames1 ) {
            if (fornames1.size() - 1 - i > 0)
                prevnames += c + ", ";
            else
                prevnames += c;
            i++;
        }

        if (!prevnames.empty()) {
            nv+=" ";
            nv += "(" + prevnames + ")";
        }
        prevnames.clear();
        i = 0 ;
        for (auto& c : forsurnames)
            if ((!c.empty())&&(c!=" "))
                forsurnames1.push_back(c);
        for (auto& c : forsurnames1 ) {
            if (forsurnames1.size() - 1 - i > 0)
                prevnames += c + ", ";
            else
                prevnames += c;
            i++;
        }
        if (!prevnames.empty()) {
            sv += " ";
            sv += "(" + prevnames + ")";
        }
        std::string vivod;
        if ((nv.empty())&&(sv.empty()))
            vivod="Incognito";
        else if ((!nv.empty())&&(sv.empty()))
            vivod= nv+" with unknown last name";
        else if ((nv.empty())&&(!sv.empty()))
            vivod= sv+" with unknown first name";
        else
            vivod= nv + " "+ sv;
        return vivod;
    }
    void PrevNames(std::vector<PersonData>& data, int yeard, std::vector<std::string>& fornames,std::vector<std::string>& forsurnames){
        if (yeard!=PrevYear(yeard))
            while (yeard!=MinYear(data,yeard)){
                int temp = PrevYear(yeard);
                for (auto& c : data)
                    if (c.year== temp){
                        if (!c.name.empty())
                            fornames.push_back(c.name);
                        if (!c.surname.empty())
                            forsurnames.push_back(c.surname);
                    }
                yeard = temp ;
                PrevNames(data, yeard, fornames,forsurnames);
            }
    }
private:
    std::vector <PersonData> data;
    std::vector<int>yearlist;
};
int main()
{
    Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    std::cout << person.GetFullNameWithHistory(1940) << std::endl;
    return 0;
}