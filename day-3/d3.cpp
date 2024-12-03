#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

std::vector<int> extractAndMultiply(const std::string& input) {
	std::vector<int> results;
    	std::regex pattern(R"(mul\((\d+),(\d+)\))");
    	std::smatch match;

    	auto searchStart = input.cbegin();
    	while (std::regex_search(searchStart, input.cend(), match, pattern)) {
    		int x = std::stoi(match[1].str());
    	    	int y = std::stoi(match[2].str());
    	    	results.push_back(x * y);
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
