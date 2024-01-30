// Task: https://leetcode.com/problems/maximum-frequency-stack/description/

#include<iostream>
#include<vector>

class FreqStack {
private:
	std::vector<std::pair<int, int>> vec;
public:
	FreqStack() {

	}

	void push(int val) {
		int counter = 1;
		for (size_t i = 0; i < vec.size(); ++i) {
			if (vec[i].first == val) {
				++vec[i].second;
				++counter;
			}
		}
		vec.push_back(std::make_pair(val, counter));
	}

	int pop() {
		int size = vec.size();
		std::pair<int, int> toReturn(vec[size - 1].first, vec[size - 1].second);

		for (int i = size - 1; i > -1; i--) {
			if (toReturn.second < vec[i].second) {
				toReturn = vec[i];
			}
		}
		
		for (int i = size - 1; i > -1; i--)	{
			if (vec[i].first == toReturn.first) {
				for (int j = i; j < vec.size() - 1; j++){
					std::swap(vec[j], vec[j + 1]);
				}
				vec.pop_back();
				--size;
				break;
			}
		}

		for (int i = size - 1; i > -1; i--) {
			if (toReturn.first == vec[i].first) {
				--vec[i].second;
			}
		}

		return toReturn.first;
	}
};

int main() {
	// Example 1:
	FreqStack st;
	
	st.push(5);
	st.push(7);
	st.push(5);
	st.push(7);
	st.push(4);
	st.push(5);
	std::cout << st.pop() << " " << st.pop() << " " << st.pop() << " " << " " << st.pop();

	return 0;
}
