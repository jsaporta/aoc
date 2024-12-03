#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

std::vector<int> extractAndMultiply(const std::string& input) {
	bool enabled = true;
	std::vector<int> results;
	std::regex pattern(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
    	std::smatch match;

    	auto searchStart = input.cbegin();
    	while (std::regex_search(searchStart, input.cend(), match, pattern)) {
		if (match[1].matched && match[2].matched) {
			int x = std::stoi(match[1].str());
			int y = std::stoi(match[2].str());
    	    		results.push_back(enabled ? x * y : 0);
		} else if (match.str().find("do()") != std::string::npos) {
			enabled = true;
		} else if (match.str().find("don't()") != std::string::npos) {
			enabled = false;
		}
    	    	searchStart = match.suffix().first; // Move to the rest of the string
    	}

    	return results;
}

int main() {
	unsigned long total = 0;

	std::ifstream t("input.txt");
	std::stringstream buffer;
	buffer << t.rdbuf();
	std::vector<int> products = extractAndMultiply(buffer.str());

    	for (int product : products) {
    	    total += product;
    	}
	std::cout << "The total sum is: " << total << std::endl;
    	return 0;
}
