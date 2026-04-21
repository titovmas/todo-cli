#include <iostream>
#include <string>

int main() {
	std::string input;

	while (true) {
		std::cout << "> ";
		std::getline(std::cin, input);

		if (input == "exit") {
			break;
		}
		std::cout << "You typed: " << input << std::endl;
	}

	return 0;
}
