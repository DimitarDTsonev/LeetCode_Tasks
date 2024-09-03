// Task : https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/?envType=daily-question&envId=2024-09-03

#include <iostream>
#include <string>

int getLucky(std::string s, int k)
{
	int num = 0;
	for (char& ch : s)
	{
		if ((int)ch / 10 != 0)
		{
			int holder = (int)ch - 96;
			holder /= 10;
			num += holder % 10;
		}
		num += ((int)ch - 96) % 10;
	}

	while (k != 1)
	{
		int helper = 0;

		while (num)
		{
			helper += num % 10;
			num /= 10;
		}
		--k;
		num = helper;
	}
	return num;
}

int main()
{
	std::cout << getLucky("iiii", 1) << '\n';
	std::cout << getLucky("leetcode", 2) << '\n';
	std::cout << getLucky("zbax", 2) << '\n';

	return 0;
}
