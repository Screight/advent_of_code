void dayTwo_A() {
	std::vector<std::string> submarineInstructions = ReadFromFile("dayTwo.txt");
	std::string instruction = " ";
	int distance = 0;
	int horizontalPosition = 0;
	int verticalPosition = 0; // depth, it increases as the submarine goes down
	int result = 0;

	for (int i = 0; i < submarineInstructions.size() - 2; i += 2) {
		instruction = submarineInstructions[i];
		distance = StringToInt(submarineInstructions[i + 1]);

		if (instruction == "forward") {
			horizontalPosition += distance;
		}
		else if (instruction == "down") {
			verticalPosition += distance;
		}
		else if (instruction == "up") {
			verticalPosition -= distance;
		}

	}

	result = horizontalPosition * verticalPosition;

	std::cout << "Distance :" << horizontalPosition << std::endl;
	std::cout << "Depth :" << verticalPosition << std::endl;
	std::cout << "Result: " << result << std::endl;
}

void dayTwo_B() {
	std::vector<std::string> submarineInstructions = ReadFromFile("dayTwo.txt");
	std::string instruction = " ";
	int value = 0;
	int aim = 0;
	int horizontalPosition = 0;
	int verticalPosition = 0; // depth, it increases as the submarine goes down
	int result = 0;

	for (int i = 0; i < submarineInstructions.size() - 2; i += 2) {
		instruction = submarineInstructions[i];
		value = StringToInt(submarineInstructions[i + 1]);

		if (instruction == "forward") {
			horizontalPosition += value;
			verticalPosition += aim * value;
		}
		else if (instruction == "down") {
			aim += value;
		}
		else if (instruction == "up") {
			aim -= value;
		}

	}

	result = horizontalPosition * verticalPosition;

	std::cout << "Distance :" << horizontalPosition << std::endl;
	std::cout << "Depth :" << verticalPosition << std::endl;
	std::cout << "Result: " << result << std::endl;
}