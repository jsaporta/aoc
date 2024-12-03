#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

int main() {
	int first, second;
	long similarity_score;
	std::ifstream input("d1-input.txt");
	std::string line;
	std::unordered_map<int, int> m;
	std::vector<int> first_list;
	std::vector<int> second_list;

	similarity_score = 0;

	while (std::getline(input, line)) {
		std::istringstream iss(line);
		if (iss >> first >> second) {
			first_list.push_back(first);
			second_list.push_back(second);
		}
	}

	for (auto x : second_list)
		m[x]++;

	for (auto x : first_list)
		similarity_score += x * m[x];

	std::cout << "Similarity score: " << similarity_score << std::endl;
	
	input.close();
	return 0;
}
