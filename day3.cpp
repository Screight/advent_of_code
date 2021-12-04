void dayThree_A() {
	std::vector<std::string> binaries = ReadFromFile("dayThree.txt");

	int numberOfBinaries = binaries.size();
	int binarySize = binaries[0].size();

	int* epsilonRate = new int[numberOfBinaries];
	int epsilonRateDecimal = 0;
	int* gammaRate = new int[numberOfBinaries];
	int gammaRateDecimal = 0;

	int powerConsumption = 0;

	int count_0 = 0;
	int count_1 = 0;


	for (int bitIndex = 0; bitIndex < binarySize; bitIndex++) {
		for (int binary = 0; binary < numberOfBinaries; binary++) {
			int bitDigit = CharToInt((binaries[binary])[bitIndex]);
			//count number of 0 and 1 for all binaries in position bitIndex
			if (bitDigit == 0) {
				count_0++;
			}
			else {
				count_1++;
			}
		}
		// compare two values and assign 1 or 0 to news binaries
		if (count_0 > count_1) {
			gammaRate[bitIndex] = 0;
			epsilonRate[bitIndex] = 1;
		}
		else {
			gammaRate[bitIndex] = 1;
			epsilonRate[bitIndex] = 0;
		}
		count_0 = 0;
		count_1 = 0;
	}

	// change from base 2 to base 10
	for (int bitIndex = 0; bitIndex < binarySize; bitIndex++) {

		epsilonRateDecimal += pow(2, binarySize - 1 - bitIndex) * epsilonRate[bitIndex];
		gammaRateDecimal += pow(2, binarySize - 1 - bitIndex) * gammaRate[bitIndex];

	}

	powerConsumption = epsilonRateDecimal * gammaRateDecimal;

	std::cout << "Epsilon rate: " << epsilonRateDecimal << std::endl;
	std::cout << "Gamma rate: " << gammaRateDecimal << std::endl;
	std::cout << "Power consumption: " << powerConsumption;

	delete[] epsilonRate;
	delete[] gammaRate;
}

int GetOxygenGeneratorRating() {

	std::vector<std::string> binaries = ReadFromFile("dayThree.txt");
	//std::vector<std::string> binaries = { "00100","11110","10110","10111","10101","01111","00111","11100","10000","11001","00010","01010" };

	int numberOfBinaries = binaries.size();
	int binarySize = binaries[0].size();

	int* oxygenGeneratorRating = new int[numberOfBinaries];
	int oxygenGeneratorRatingDecimal = 0;

	int count_0 = 0;
	int count_1 = 0;

	int dominantNumber = 0;

	int numberOfBinariesLeft = binaries.size();

	for (int bitIndex = 0; bitIndex < binarySize; bitIndex++) {
		if (binaries.size() != 1) {

			for (int binary = 0; binary < numberOfBinariesLeft; binary++) {
				int bitDigit = CharToInt((binaries[binary])[bitIndex]);
				//count number of 0 and 1 for all binaries in position bitIndex
				if (bitDigit == 0) {
					count_0++;
				}
				else {
					count_1++;
				}
			}

			if (count_0 > count_1) {
				dominantNumber = 0;
			}
			else {
				dominantNumber = 1;
			}

			for (int binary = 0; binary < binaries.size();) {

				if (CharToInt(binaries[binary][bitIndex]) != dominantNumber) {
					binaries.erase(binaries.begin() + binary);
				}
				else {
					binary++;
				}

			}

			count_0 = 0;
			count_1 = 0;
			numberOfBinariesLeft = binaries.size();

		}
	}

	for (int i = 0; i < binaries[0].size(); i++) {
		oxygenGeneratorRating[i] = CharToInt(binaries[0][i]);
	}

	for (int bitIndex = 0; bitIndex < binarySize; bitIndex++) {

		oxygenGeneratorRatingDecimal += pow(2, binarySize - 1 - bitIndex) * oxygenGeneratorRating[bitIndex];

	}

	std::cout << "Oxygen generator rating: " << oxygenGeneratorRatingDecimal << std::endl;

	return oxygenGeneratorRatingDecimal;

	delete[] oxygenGeneratorRating;
}

int GetCo2GeneratorRating() {

	std::vector<std::string> binaries = ReadFromFile("dayThree.txt");

	//std::vector<std::string> binaries = { "00100","11110","10110","10111","10101","01111","00111","11100","10000","11001","00010","01010" };

	int numberOfBinaries = binaries.size();
	int binarySize = binaries[0].size();

	int* co2GeneratorRating = new int[numberOfBinaries];
	int co2GeneratorRatingDecimal = 0;

	int count_0 = 0;
	int count_1 = 0;

	int dominantNumber = 0;

	int numberOfBinariesLeft = binaries.size();

	for (int bitIndex = 0; bitIndex < binarySize; bitIndex++) {
		if (binaries.size() != 1) {

			for (int binary = 0; binary < numberOfBinariesLeft; binary++) {
				int bitDigit = CharToInt((binaries[binary])[bitIndex]);
				//count number of 0 and 1 for all binaries in position bitIndex
				if (bitDigit == 0) {
					count_0++;
				}
				else {
					count_1++;
				}
			}

			if (count_1 < count_0) {
				dominantNumber = 1;
			}
			else {
				dominantNumber = 0;
			}

			for (int binary = 0; binary < binaries.size();) {
				if (CharToInt(binaries[binary][bitIndex]) != dominantNumber) {
					binaries.erase(binaries.begin() + binary);
				}
				else {
					binary++;
				}
			}

			count_0 = 0;
			count_1 = 0;
			numberOfBinariesLeft = binaries.size();

		}
	}

	for (int i = 0; i < binaries[0].size(); i++) {
		co2GeneratorRating[i] = CharToInt(binaries[0][i]);
	}

	for (int bitIndex = 0; bitIndex < binarySize; bitIndex++) {

		co2GeneratorRatingDecimal += pow(2, binarySize - 1 - bitIndex) * co2GeneratorRating[bitIndex];

	}

	std::cout << "CO2 generator rating: " << co2GeneratorRatingDecimal << std::endl;

	return co2GeneratorRatingDecimal;

	delete[] co2GeneratorRating;
}

void dayThree_B() {

	int lifeSupportRating = GetOxygenGeneratorRating() * GetCo2GeneratorRating();

	std::cout << "Life support rating: " << lifeSupportRating;

}