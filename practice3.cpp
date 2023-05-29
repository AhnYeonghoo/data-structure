#include <string>
#include <iostream>
#include <forward_list>
using namespace std;

struct Citizen
{
    std::string name;
    int age;
};

std::ostream& operator<<(std::ostream& os, const Citizen& c)
{
    return (os << "[" << c.name << ", " << c.age << "]");
}

int main()
{
    std::forward_list<Citizen> citizens = {
        {"Kim", 22}, {"Lee", 25}, {"park", 18}, {"Jin", 16}
    };

    auto citizens_copy = citizens;

    cout << "전체 시민들: ";
    for (const auto& c : citizens)
        cout << c << " ";
    cout << endl;

    citizens.remove_if([](const Citizen& c)
    {
        return (c.age < 19);
    });

    cout << "투표권이 있는 시민들: ";
    for (const auto& c : citizens)
        cout << c << " ";
    cout << endl;

    citizens_copy.remove_if([](const Citizen& c)
    {
        return (c.age != 18);
    });


    cout << "내년에 투표권이 생기는 시민들: ";
    for (const auto& c: citizens_copy)
        cout << c << " ";
    cout << endl;
}