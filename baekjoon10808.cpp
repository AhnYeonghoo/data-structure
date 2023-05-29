#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    std::string str;
    std::vector<int> result(26);
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        result.at(str[i] - 97)++;
    }

    for (const auto& ele : result)
    {
        cout << ele << " ";
    }



    return 0;
}