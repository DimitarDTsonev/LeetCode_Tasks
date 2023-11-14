#include<iostream>
#include<stack>

void printBinaryCodeForNumberN(int n) {
	std::stack<bool> binary;
	size_t remainder = 0;

	if (n == 0) {
		std::cout << "0" << std::endl;
		return;
	}

	while (n > 0) {
		remainder = n % 2;
		binary.push(remainder);
		n /= 2;
	}

	while (!binary.empty()) {
		std::cout << binary.top();
		binary.pop();
	}
}

int main() {
	unsigned n = 0;
	std::cout << "Enter a possitive number to see its binary representation -> ";
	std::cin >> n;

	printBinaryCodeForNumberN(n);

	return 0;
}
