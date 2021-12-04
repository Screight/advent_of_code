int StringToInt(std::string p_stringNumber) {

	const int DIFF_ASCI_VALUE_AND_NUMBER = 48;
	int number = 0;
	int numberOfDigits = p_stringNumber.size();
	int exponent;

	for (int i = 0; i < numberOfDigits; i++) {
		exponent = numberOfDigits - i - 1;
		number += (p_stringNumber[i] - DIFF_ASCI_VALUE_AND_NUMBER) * pow(10, exponent);
	}

	return number;

}

int CharToInt(char p_charNumber) {

	const int DIFF_ASCI_VALUE_AND_NUMBER = 48;
	int number = 0;

	return p_charNumber - DIFF_ASCI_VALUE_AND_NUMBER;

}

std::vector<std::string> ReadFromFile(std::string p_fileName) {

	std::vector<std::string> stringNumbers;
	// string to store file lines (all the characters until the end of the current line)
	std::string textCopied = " ";
	// declare a file
	std::fstream file;
	// open a file in read mode
	file.open(p_fileName, std::ios::in);

	// while we haven't reach the end of the file
	/*Returns true if the eofbit error state flag is set for the stream.
	This flag is set by all standard input operations when the End - of - File is reached in the sequence associated with the stream.*/
	int i = 0;
	while (!file.eof()) {
		file >> textCopied;

		stringNumbers.push_back(textCopied);

		// move into the next line
		i++;
	}
	// close the file
	file.close();

	return stringNumbers;
}

std::vector<int> GetDataSeparatedWithCharacter(char p_separator, std::string p_fileName, int line) {

	std::vector<int> numbers;
	int separator_0 = -1;
	int separator_f = 0;

	// string to store file lines (all the characters until the end of the current line)
	std::string textCopied = " ";
	// declare a file
	std::fstream file;
	// open a file in read mode
	file.open(p_fileName, std::ios::in);

	for (int i = 0; i < line; i++) {
		file >> textCopied;
	}

	separator_f = textCopied.find(p_separator, separator_0 + 1);

	while (separator_f != std::string::npos) {

		std::string subString = textCopied.substr(separator_0 + 1, separator_f - separator_0 - 1);

		if (subString.length() != 0) {
			numbers.push_back(StringToInt(subString));
		}

		separator_0 = textCopied.find(',', separator_0 + 1);
		separator_f = textCopied.find(',', separator_f + 1);


	}

	std::string subString = textCopied.substr(separator_0 + 1, textCopied.length());
	numbers.push_back(StringToInt(subString));

	/*for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << std::endl;
	}*/

	file.close();

	return numbers;

}