#include <iostream>
#include <vector>
#include <string>
using namespace std;

int mainsolved ()
{
	cin.tie(0);
	std::vector<__int64> vi1, vi2;
	std::string str1, str2;
	std::string strNum1, strNum2;
	std::vector<__int64> result;

	getline(cin, str1);
	getline(cin, str2);

	for (int i = 0; i < str1.length(); i++)
	{
		if (str1.at(i) == ' ')
		{
			vi1.push_back(_atoi64(strNum1.c_str()));
			strNum1 = "";
		}
		else
		{
			strNum1 += str1.at(i);
			continue;
		}
	}
	
	for (int i = 0; i < str2.length(); i++)
	{
		if (str2.at(i) == ' ')
		{
			vi2.push_back(_atoi64(strNum2.c_str()));
			strNum2 = "";
		}
		else
		{
			strNum2 += str2.at(i);
			continue;
		}
	}

	vi1.push_back(_atoi64(strNum1.c_str()));
	vi2.push_back(_atoi64(strNum2.c_str()));

	for (int i = 0; i < vi1.size(); i++)
	{
		cout << vi1.at(i) + vi2.at(i);
	}


	return 0;
}