#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len)
{
    len++;
    for (int i = len; i > idx; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[idx] = num;
   
    
}

void erase(int idx, int arr[], int& len)
{
    for (int i = idx; i < len; i++)
    {
        arr[i] = arr[i+1];
    }
    len--;
    
    
}

void printArr(int arr[], int& len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\n\n";
}

int main()
{
    vector<int> v1(3, 5);
    cout << v1.size();
    v1.push_back(7);
    
    vector<int> v2(2);
    v2.insert(v2.begin()+1, 3);
    
    vector<int> v3 = {1, 2, 3, 4};
    v3.erase(v3.begin()+2);

    cout << v3.at(0) << v3.at(1) << v3.at(2) << '\n';
    
    vector<int> v4;
    v4 = v3;
    cout << v4[0] << v4[1] << v4[2] << '\n';
    v4.pop_back();
    v4.clear();
}