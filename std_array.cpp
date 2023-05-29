#include <iostream>
#include <array>

using namespace std;

void print(std::array<int, 5> arr);

template<size_t N>
void print(const std::array<int, N>& arr);



int main()
{
    std::array<int, 10> arr1;
    arr1[0] = 1;
    
    cout << "arr1 배열의 첫 번째 원소: " << arr1[0] << endl;
    
    std::array<int, 4> arr2 = {1, 2,3 , 4};
    
    for (int i = 0; i < arr2.size(); i++)
        cout << arr2[i] << endl;
        
    cout << endl;

    std::array<int, 4> arr3 = {1, 2, 3, 4};
    
    try
    {
        cout << arr3.at(3) << endl;
        //cout << arr3.at(4) << endl;
    }
    catch (const std::out_of_range& ex)
    {
        cerr << ex.what() << endl;
    }

    std::array<int, 5> arr4 = {1, 2, 3, 4, 5};
    print(arr4);

    return 0;
}

void print(std::array<int, 5> arr)
{
    for (auto& ele : arr)
    {
        cout << ele << ", ";
    }
}

template<size_t N>
void print(const std::array<int, N>& arr)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        auto element = (*it);
        cout << element << ", ";
    }
}