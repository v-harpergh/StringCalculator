#include <iostream>

#include <string>
#include <vector>

// I could just use free functions from STL but I think it ruins the point of the assignment
constexpr bool isdelimiter(std::vector<char>& delimiters, const char c) {
	for (const auto& v : delimiters) {
		if (c == v) {
			return true;
		}
	}
	return false;
}

constexpr int64_t to_integer(std::string_view buffer) {

}

constexpr int64_t parse_input(std::vector<char>& delimiters, std::string_view input) {
	int64_t result = 0;
	std::vector<int64_t> numbers{};
	std::string buffer{};

	for (const auto c : input) {
		if (isdelimiter(delimiters, c)) {
			if (!buffer.empty()) {
				numbers.push_back(std::stoi(buffer));
			}
			buffer = "";
		}
		else {
			buffer += c;
		}
	}

	if (!buffer.empty()) {
		numbers.push_back(std::stoi(buffer));
	}

	for (const auto& n : numbers) {
		result += n;
	}

	return result;
}

int main()
{
	std::vector<char> delimiters = { ',', ';' };
	std::string input{};

	std::cout << "Enter numbers separated by [";

	for (const auto& d : delimiters) {
		std::cout << d << "";
	}

	std::cout << "]\n";

	std::cin >> input;

	if (std::cin.fail()) {
		std::cout << "std::cin failed";
		return 1;
	}

	int64_t result = parse_input(delimiters, input);

	std::cout << result << "\n";
}