#include <iostream>
#include <fstream>

int main() {
	std::ifstream input_stream("data.csv");  // Open file in binary mode
	if (!input_stream) {
		std::cerr << "Error opening file!" << std::endl;
		return 1;
	}

	const size_t buffer_size = 80000;
	char buff[buffer_size];

	// Initialize the buffer with zeros to avoid any garbage values
	std::fill_n(buff, buffer_size, '\0');

	// Use a loop to read the entire file
	while (input_stream.getline(buff, buffer_size, '\0')) {
		// Process the buffer
		std::cout << buff;

		// Clear the buffer
		std::fill_n(buff, buffer_size, '\0');
	}

	std::cout << "Stream state after reading:" << std::endl;
	std::cout << "eof(): " << input_stream.eof() << std::endl;
	std::cout << "fail(): " << input_stream.fail() << std::endl;
	std::cout << "bad(): " << input_stream.bad() << std::endl;
	std::cout << "good(): " << input_stream.good() << std::endl;
	std::cout << "gcount(): " << input_stream.gcount() << std::endl;
	
	if (input_stream.gcount() > 0) {
		std::cout << buff;
	}

	// Close the file
	input_stream.close();
	return 0;
}
