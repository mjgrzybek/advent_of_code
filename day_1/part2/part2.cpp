#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

int main() {
	auto file = std::ifstream("input.txt");

	std::vector<int> values;
	std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::back_inserter(values));

	std::set<int> seen;
	long sum{0};

	//avoid infinite loop
	size_t iterationsCtr{0};

	while(iterationsCtr < values.size()) {
		for(const auto v : values) {
			sum += v;
			
			if(seen.find(sum) == seen.end()) {
				seen.insert(sum);
			}
			else {
				std::cout << sum << std::endl;
				return 0;
			}
		}

		++iterationsCtr;
	}
}
