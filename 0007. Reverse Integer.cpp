// Task: https://leetcode.com/problems/reverse-integer/description/

int reverse(int x) {
    long long res = 0;
    long long xCopy = x;

    while (xCopy) {
        res = res * 10 + (xCopy % 10);
        xCopy /= 10;
    }

    if ((res > 2147483647 && x >= 0) || (res <= -2147483648 && 0 > x)) {
        return 0;
    }

    return res;
}

int main() {
    // Example 1:
    std::cout << reverse(123) << std::endl;
    
    // Example 2:
    std::cout << reverse(-123) << std::endl;
    // Example 3:
    std::cout << reverse(120) << std::endl;

	// Example 4:
	std::cout << reverse(-1534236469) << std::endl;

	return 0;
}
