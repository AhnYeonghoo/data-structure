#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main5597()
{
	vector<int> students;
	int num[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
	17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
	unsigned short n;
	
	// 입력받기
	for (int i = 0; i < 28; i++)
	{
		cin >> n;
		students.push_back(n);
	}

	sort(students.begin(), students.end());
	
	for (int i = 0; i < 30; i++)
	{
		if (!(std::count(students.begin(), students.end(), num[i])))
		{
			cout << num[i] << '\n';
		}
	}
	
	
	
	return 0;
}