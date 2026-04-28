#include <iostream>
#include <string>
#include <vector>

// Define a Task as a structure
// This allows adding more fields like 'due_date' or 'is_completed' in the future
struct Task {
	std::string description;
};

int main() {
	// Vector to store task objects in memory
	std::vector<Task> tasks;
	std::string input;

	while (true) {
		std::cout << "> ";
		//std::getline(std::cin, input);
		
		// Check for end-of-file (Ctrl+D) or if the user typed "exit"
		if (!std::getline(std::cin, input) || input == "exit") {
			break;
		}
		
		// --- ADD COMMAND ---
		// Checks if the input starts with "add" (4 characters)
		if (input.rfind("add ", 0) == 0) {
			std::string task_text = input.substr(4);
			
			tasks.push_back({task_text});
			std::cout << "Task added: " << task_text << std::endl;
		}
		
		// --- LIST COMMAND ---	
		// Displays all current tasks with their index numbers
		else if (input == "list") {
			if (tasks.empty()) {
				std::cout << "No tasks yet" << std::endl;
			} else {
				for (size_t i = 0; i < tasks.size(); i++) {
					std::cout << i + 1 << ". " << tasks[i].description << std::endl;
				}
			}
		}
		
		// --- DONE COMMAND ---
		// Removes a task by its list number
		else if (input.rfind("done ", 0) == 0) {
			try { 
				int index = std::stoi(input.substr(5));
				
				if (index > 0 && index <= static_cast<int>(tasks.size())) {
					tasks.erase(tasks.begin() + index - 1);
					std::cout << "Task completed" << std::endl;
				} else {
					std::cout << "Task doesn't exist" << std::endl;
				}
			} catch(...) {
				std::cout << "Error: please enter a valid task number" << std::endl;
			}
		}
	}

	return 0;
}
