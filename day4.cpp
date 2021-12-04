std::vector<int> GetBingoNumbers() {
	return GetDataSeparatedWithCharacter(',', "day4.txt", 1);
}

std::vector<std::vector<std::vector<int>>> GetBoards() {

	// vector de cartones que guarda un vector que contiene vectores con las filas de los cartones jeje
	std::vector<std::vector<std::vector<int>>> boards;
	std::vector<int> numbers;


	int currentLine = 2;
	int count = 0;

	// since i'm continiusly openning and closing the file this part of the code is highly inneficient
	while (count != 100) {
		std::vector<std::vector<int>> board;

		for (int i = 0; i < 5; i++) {
			board.push_back(GetDataSeparatedWithCharacter(',', "day4.txt", currentLine));
			currentLine++;
		}
		boards.push_back(board);
		count++;
	}

	return boards;

}

int GetWinningBoard(std::vector<std::vector<std::vector<int>>> boards) {

	std::vector<std::vector<int>> winningBoard;

	std::vector<int> bingoNumbers = GetBingoNumbers();
	int currentBingoNumber = 0;
	int bingoNumberCount = 0;
	int score = 0;

	bool isPlaying = true;
	int numberOfBoards = boards.size();

	while (isPlaying && (bingoNumberCount < bingoNumbers.size())) {
		currentBingoNumber = bingoNumbers[bingoNumberCount]; // get number to check for
		// check for the number in all boards
		for (int boardNumber = 0; boardNumber < numberOfBoards; boardNumber++) {
			std::vector<std::vector<int>>* board = &boards[boardNumber]; // get current board

			bool numberFound = false;
			for (int row = 0; row < 5 && !numberFound; row++) {
				for (int column = 0; column < 5; column++) {
					if ((*board)[row][column] == currentBingoNumber) {
						(*board)[row][column] = -1;
						numberFound = true;
					}
				}
			}

		}

		// check for lines in rows
		// check for the number in all boards
		for (int boardNumber = 0; boardNumber < numberOfBoards; boardNumber++) {
			std::vector<std::vector<int>>* board = &boards[boardNumber]; // get current board
			for (int row = 0; row < 5 && isPlaying; row++) {
				int sum = 0;
				for (int column = 0; column < 5; column++) {
					sum += (*board)[row][column];
				}
				if (sum == -5) {
					isPlaying = 0;
					winningBoard = *board;
				}
			}
		}

		// check for lines in columns
		// check for the number in all boards
		for (int boardNumber = 0; boardNumber < numberOfBoards; boardNumber++) {
			std::vector<std::vector<int>>* board = &boards[boardNumber]; // get current board
			for (int column = 0; column < 5 && isPlaying; column++) {
				int sum = 0;
				for (int row = 0; row < 5; row++) {
					sum += (*board)[row][column];
				}
				if (sum == -5) {
					isPlaying = 0;
					winningBoard = *board;
				}
			}
		}
		bingoNumberCount++;
	}

	int lastNumber = bingoNumbers[bingoNumberCount - 1];

	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++) {
			if (winningBoard[row][column] != -1) {
				score += lastNumber * winningBoard[row][column];
			}
		}
	}

	return score;
}

int GetLastWinningBoard(std::vector<std::vector<std::vector<int>>> boards) {
	std::vector<std::vector<std::vector<int>>> winningBoards;
	std::vector<std::vector<int>> lastWinningBoard;

	std::vector<int> bingoNumbers = GetBingoNumbers();
	int currentBingoNumber = 0;
	int bingoNumberCount = 0;
	int score = 0;
	int lastNumber = 0;

	bool isPlaying = true;
	int numberOfBoards = boards.size();

	while (bingoNumberCount < bingoNumbers.size()) {
		currentBingoNumber = bingoNumbers[bingoNumberCount]; // get number to check for
		// check for the number in all boards

		for (int boardNumber = 0; boardNumber < numberOfBoards; boardNumber++) {
			std::vector<std::vector<int>>* board = &boards[boardNumber]; // get current board

			bool numberFound = false;
			for (int row = 0; row < 5 && !numberFound; row++) {
				for (int column = 0; column < 5; column++) {
					if ((*board)[row][column] == currentBingoNumber) {
						(*board)[row][column] = -1;
						numberFound = true;
					}
				}
			}

		}

		// check for lines in rows
		// check for the number in all boards
		for (int boardNumber = 0; boardNumber < numberOfBoards;) {
			std::vector<std::vector<int>>* board = &boards[boardNumber]; // get current board
			for (int row = 0; row < 5 && isPlaying; row++) {
				int sum = 0;
				for (int column = 0; column < 5; column++) {
					sum += (*board)[row][column];
				}
				if (sum == -5) {
					isPlaying = false;
					lastWinningBoard = *board;
					lastNumber = currentBingoNumber;
					boards.erase(boards.begin() + boardNumber);
					numberOfBoards = boards.size();
				}
			}
			if (isPlaying) {
				boardNumber++;
			}
			isPlaying = true;
		}

		// check for lines in columns
		// check for the number in all boards
		for (int boardNumber = 0; boardNumber < numberOfBoards; ) {
			std::vector<std::vector<int>>* board = &boards[boardNumber]; // get current board
			for (int column = 0; column < 5 && isPlaying; column++) {
				int sum = 0;
				for (int row = 0; row < 5; row++) {
					sum += (*board)[row][column];
				}
				if (sum == -5) {
					isPlaying = false;
					lastWinningBoard = *board;
					lastNumber = currentBingoNumber;
					boards.erase(boards.begin() + boardNumber);
					numberOfBoards = boards.size();
				}
			}
			if (isPlaying) {
				boardNumber++;
			}
			isPlaying = true;
		}
		bingoNumberCount++;
	}
	bool found = false;

	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++) {
			if (lastWinningBoard[row][column] != -1) {
				score += lastNumber * lastWinningBoard[row][column];
			}
		}
	}

	return score;
}

void ShowBoard(std::vector<std::vector<int>> p_board) {

	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++) {
			std::cout << p_board[row][column] << " ";
		}
		std::cout << std::endl;
	}

}

int GetScore(std::vector<std::vector<int>> p_board, int lastNumber) {

	int score = 0;

	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++) {
			if (p_board[row][column] != -1) {
				score += p_board[row][column];
			}
		}
	}

	score *= lastNumber;

	return score;

}

int dayFour_A() {

	int score = GetWinningBoard(GetBoards());

	std::cout << score << std::endl;

	return score;

}

int dayFour_B() {

	int score = GetLastWinningBoard(GetBoards());

	std::cout << score << std::endl;

	return score;

}