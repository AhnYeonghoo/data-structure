#include <iostream>
using namespace std;

int MAX = 0;
int main()
{
    int num[9][9];
    short x = 1, y = 1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> num[i][j];
            if (MAX < num[i][j])
            {
                x = i + 1;
                y = j + 1;
                MAX = num[i][j];
            }
        }
    }
    cout << MAX << '\n';
    cout << x << " " << y;

    return 0;
}