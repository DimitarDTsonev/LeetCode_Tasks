#include<string>
#include<iostream>
#include<unordered_map>

std::string intToRoman(int num) {
	std::unordered_map<int, char> roman; 
	roman[1] = 'I';
	roman[5] = 'V';
	roman[10] = 'X';
	roman[50] = 'L';
	roman[100] = 'C';
	roman[500] = 'D';
	roman[1000] = 'M';
	roman[5000] = 'G';
	roman[10000] = 'H';

	std::string tmp = std::to_string(num);
	const int numDigits = tmp.length();

	std::string res = "";
	for (int i = 0; i < numDigits; ++i) {
		const char src = tmp[i]; 
		const int number = (src - '0'); 
		const int place = (numDigits - 1) - i;
		const int absolute = pow(10, place);

		if (number == 9) {
			res.append(1, roman[absolute]);
			res.append(1, roman[(number + 1) * absolute]);
		}
		else {
			if (number >= 5) {
				res.append(1, roman[5 * absolute]);
				res.append(number - 5, roman[absolute]);
			}
			else {
				if (number >= 4) {
					res.append(1, roman[absolute]);
					res.append(1, roman[5 * absolute]);
				}
				else {
					res.append(number, roman[absolute]);
				}
			}
		}
	}
	return res;
}

int main() {
	// Test 1:
	int toRoman1 = 3;
	std::cout << intToRoman(toRoman1) << std::endl;

	// Test 2:
	int toRoman2 = 58;
	std::cout << intToRoman(toRoman2) << std::endl;

	// Test 3:
	int toRoman3 = 1984;
	std::cout << intToRoman(toRoman3) << std::endl;

	return 0;
}
