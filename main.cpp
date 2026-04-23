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

		if (input.rfind("add ", 0) == 0) {
			std::string task = input.substr(4);
			std::cout << "Task added: " << task << std::endl;
		}
	}

	return 0;
}
