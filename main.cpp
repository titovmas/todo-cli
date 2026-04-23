#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string input;
	std::vector<std::string> tasks;

	while (true) {
		std::cout << "> ";
		std::getline(std::cin, input);
		
		if (input == "exit") {
			break;
		} else if (input.rfind("add ", 0) == 0) {
			std::string task = input.substr(4);
			tasks.push_back(task);
			std::cout << "Task added: " << task << std::endl;
		} else if (input == "list") {
			if (tasks.empty()) {
				std::cout << "No tasks yet." << std::endl;
			} else {
				for (size_t i = 0; i < tasks.size(); i++) {
					std::cout << i + 1 << ". " << tasks[i] << std::endl;
				}
			}
		}
	}

	return 0;
}
