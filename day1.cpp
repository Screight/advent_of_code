void dayOne(int p_segment) {

	int count = 0;
	int partialSum1 = 0;
	int partialSum2 = 0;
	std::vector<int> numbers;
	std::vector<std::string> stringNumbers = ReadFromFile("dayOne.txt");

	for (int i = 0; i < stringNumbers.size(); i++) {
		numbers.push_back(StringToInt(stringNumbers[i]));
	}

	for (int i = 0; i < numbers.size() - p_segment - 1; i++) {
		for (int j = 0; j < p_segment; j++) {
			partialSum1 += numbers[i + j];
			partialSum2 += numbers[i + j + 1];
		}
		if (partialSum2 > partialSum1) {
			count++;
		}
		partialSum1 = 0;
		partialSum2 = 0;
	}
	std::cout << "Count: " << count << std::endl;
}