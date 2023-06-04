#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    bool flag = true;
    if (str.length() == 1) flag = true;
    else
    {
        for (int i = 0; i < str.length() / 2; i++)
        {
            if (str.at(i) == str.at(str.length() - i - 1))
                {
                    flag = true;
                }
                else
                {
                    cout << 0 << endl;
                    return 0;
                }   
        }
    }
    

    if (flag) cout << 1;
    return 0;
}