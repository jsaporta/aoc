#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

int main() {
	int first, second;
	long abs_diff_sum;
	std::ifstream input("d1p1-input.txt");
	std::pair<int, int> entry;
	std::string line;
	std::vector<int> first_list;
	std::vector<int> second_list;

	abs_diff_sum = 0;

	while (std::getline(input, line)) {
		std::istringstream iss(line);
		if (iss >> first >> second) {
			first_list.push_back(first);
			second_list.push_back(second);
		} else {
			std::cerr << "Error: Maleformed line: " << line << std::endl;
		}
	}

	std::sort(first_list.begin(), first_list.end());
	std::sort(second_list.begin(), second_list.end());

	for (std::vector<int>::size_type i = 0; i < first_list.size(); i++)
		abs_diff_sum += abs(first_list[i] - second_list[i]);

	std::cout << "The sum of the absolute differences "
		<< "between the first and second lists is: "
		<< abs_diff_sum << std::endl;;
	
	input.close();
	return 0;
}
