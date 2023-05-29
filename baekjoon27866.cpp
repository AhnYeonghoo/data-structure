#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::string str;
    int i;
    getline(cin, str);
    cin >> i;
    cout << str.at(i-1);
    return 0;
}