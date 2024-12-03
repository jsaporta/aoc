#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

bool eval_report(std::vector<int> report) {
	int diff;

	if (!std::is_sorted(report.begin(), report.end())) {
		std::reverse(report.begin(), report.end());
		if (!std::is_sorted(report.begin(), report.end()))
			return false;
	}
	std::sort(report.begin(), report.end());

	for (long unsigned int i = 1; i < report.size(); i++) {
		diff = report[i] - report[i - 1];
		if (!(1 <= diff && diff <= 3))
			return false;
	}
	return true;
}

int main() {
	int true_count;
	int x;
	unsigned int num_safe_reports = 0;
	std::ifstream input_file("input.txt");
	std::string line;
	std::vector<int> report;

	while (std::getline(input_file, line)) {
		std::istringstream iss(line);

		report.clear();
		while (iss >> x)
			report.push_back(x);

		true_count = 0;
		// This is where I test all the possible vectors made by deleting a
		// single element from report. Can be easily modified only to use
		// report itself, as in the first problem.
		for (size_t i = 0; i < report.size(); i++) {
			std::vector<int> v;
			v.insert(v.end(), report.begin(), report.begin() + i);
			v.insert(v.end(), report.begin() + (i + 1), report.end());
			if (eval_report(v))
				true_count++;
		}
		if (true_count >= 1)
			num_safe_reports++;
	}

	std::cout << "The number of safe reports is: " << num_safe_reports << std::endl;

	input_file.close();
	return 0;
}
