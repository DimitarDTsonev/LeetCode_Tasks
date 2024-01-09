// Task: https://leetcode.com/problems/fizz-buzz/description/
// Beats 100.0% for time:

#include<iostream>
#include<string>
#include<vector>

std::vector<std::string> fizzBuzz(int n) {
	std::vector<std::string> result;

	for (size_t i = 1; i <= n; i++) {
		std::string currentString;
		if (i % 3 == 0 && i % 5 == 0) {
			currentString.append("FizzBuzz");
		}
		else if(i % 3 == 0){
			currentString.append("Fizz");
		}
		else if (i % 5 == 0) {
			currentString.append("Buzz");
		}
		else {
			currentString.append(std::to_string(i));
		}
		result.push_back(currentString);
	}

	return result;
}

void printVector(const std::vector<std::string> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	// Example 1:
	std::vector<std::string> vec1;
	vec1 = fizzBuzz(3);
	printVector(vec1);

	// Example 2:
	std::vector<std::string> vec2;
	vec2 = fizzBuzz(5);
	printVector(vec2);

	// Example 3:
	std::vector<std::string> vec3;
	vec3 = fizzBuzz(15);
	printVector(vec3);

	return 0;
}
