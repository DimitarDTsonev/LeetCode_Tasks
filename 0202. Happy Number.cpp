#include <iostream>
#include <set>

int sumOfSquears(int n) {
	int num = 0;
	while (n != 0) {
		num += (n % 10) * (n % 10);
		n /= 10;
	}
	return num;
}

std::set<int> set;
bool isHappy(int n) {
	if (n == 1) {
		set.clear();
		return true;
	}
	if (set.find(n) != set.end()) {
		set.clear();
		return false;
	}
	set.insert(n);
	int num = sumOfSquears(n);

	return isHappy(num);
}

int main() {
	// Example 1:
	std::cout << isHappy(19) << '\n';

	// Example 2:
	std::cout << isHappy(2) << '\n';

	return 0;
}
