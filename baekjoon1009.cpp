#include <iostream>

using namespace std;

int main1009temp()
{
	int t;
	int a, b, count;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		count = a % 10;
		for (int j = 0; j < b; j++)
		{
			count *= a;
			count %= 10;
		}
		if (count == 0) cout << 10 << endl;
		else cout << count << endl;
	}

	return 0;
}