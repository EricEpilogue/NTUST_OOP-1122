#include <iostream>
#include <string>

void getHighScore(std::string names[], int scores[], int sizeOfNames, int sizeOfScores);

int main(int argc, char** argv) {
	std::string names[100];
	int scores[100];
	std::string name;
	int score = 0;
	int sizeOfNames = 0;
	int sizeOfScores = 0;

	while (!std::cin.eof()) {
		std::cin >> name >> score;
		names[sizeOfNames++] = name;
		scores[sizeOfScores++] = score;
	}

	getHighScore(names, scores, sizeOfNames, sizeOfScores);

	return 0;
}

void getHighScore(std::string names[], int scores[], int sizeOfNames, int sizeOfScores) {
	int temp = 0;
	int tracker = 0;
	int topScore[sizeOfScores];
	std::string topPlayer[sizeOfNames];
	for (int i = 0; i < sizeOfScores; i++) {
		if (scores[i] > temp) {
			temp = scores[i];
			tracker = i;
		}

	}
}
