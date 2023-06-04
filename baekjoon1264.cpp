#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main1264()
{
	string result;
	string a = "#";
	vector<int> d;
	int count = 0;
	while (getline(cin, result))
	{
		count = 0;
		if (result == "#") break;
		for (const auto& ele : result)
		{
			if (ele == 'a' || ele == 'e' || ele == 'i'
				|| ele == 'o' || ele == 'u' || ele == 'A'
				|| ele == 'E' || ele == 'O' || ele == 'U'
				|| ele == 'I')
			{
				count++;
			}
		}
		d.push_back(count);
	}

	for (const auto& e : d)
	{
		cout << e << endl;
	}

	return 0;
}