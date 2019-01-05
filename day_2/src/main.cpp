#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <string_view>
#include <map>

using namespace std::string_literals;

auto findRepetitionsUniqueImpl(std::string_view letters) {
	std::vector<int> occured;

	using std::begin;
	using std::cbegin;
	using std::end;
	using std::cend;

	int occ=0;
	char prev;
	for(const auto l : letters) {
		// first iter only
		if(occ==0) {
			occ=1;
			prev=l;
			continue;
		}

		// the same char found, increment
		if(prev == l) {
			++occ;
			prev=l;
			continue;
		}
		// other char found, push result if valid and restart counter
		else if(occ > 1 && occ < 4) {
			occured.push_back(occ);
		}

		prev=l;
		occ=1;
	}

	if(occ > 1)
		occured.push_back(occ);

	std::sort(begin(occured), end(occured));
	auto last = std::unique(begin(occured), end(occured));
	occured.erase(last, end(occured));

	return occured;
}

auto findRepetitionsUnique(std::string_view s) {
	std::string letters{s};

	using std::begin;
	using std::end;
	std::sort(begin(letters), end(letters));

	std::cout << "line: " << letters << std::endl;
	return findRepetitionsUniqueImpl(letters);
}

template<typename C>
std::string print(C& container) {
	std::string ret;
	for(const auto& val : container) {
		ret += std::to_string(val) + " ";
	}
	return ret;
}

template<typename K, typename V>
std::string print(std::map<K,V>& container) {
	std::string ret;
	for(const auto& val : container) {
		ret += "("s + std::to_string(val.first) + ":"s + std::to_string(val.second) + ") ";
	}
	return ret;
}


int main(int argc, const char* argv[]) {
	auto inputFname = "input.txt"s;
	if(argc==2)
		inputFname = argv[1];

	auto file = std::ifstream(inputFname);

	std::vector<std::string> lines;
	std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), std::back_inserter(lines));

	std::map<int,int> occursPerWordCount;

	for(size_t it=0; it<lines.size(); ++it) {
		const auto& line = lines[it];

		auto reps = findRepetitionsUnique(line);
		std::cout << "reps: " << print(reps) << std::endl;

		for(const auto& rep : reps) {
			++occursPerWordCount[rep];
		}
		std::cout << "oPWC: " << print(occursPerWordCount) << std::endl;
		std::cout << "=-=-=-=-=-=" << std::endl;
	}

	long result=1;
	for(auto it : occursPerWordCount) {
		result *= it.second;
	}

	std::cout << result << std::endl;
}
