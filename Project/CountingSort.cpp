#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countSort(vector<int>& input)
{
	map<int, int> freq;

	for (int x : input)
	{
		freq[x]++; // freq[4]++
	}
	
	int i = 0;

	for (auto& p : freq)
	{
		while (p.second--)
		{
			input[i++] = p.first;
		}
	}
}

int main()
{
	vector<int> input = { 4, 2, 1, 4, 1, 4, 2, 1, 10 };
	countSort(input);

	for (auto &i : input)
		cout << i << " ";

	return 0;
}