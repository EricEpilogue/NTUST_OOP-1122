#include <iostream>
#include <string>
#include <fstream>
void getHighScore(std::string names[], int scores[], int size);

int main(int argc, char** argv) {
	std::string names[100];
	int scores[100] = {0};
	std::string name;
	int score = 0;
	int sizeOfNames = 0;
	int sizeOfScores = 0;
	std::ifstream file;
	file.open("scores.txt");

	while (file >> name >> score) {
		names[sizeOfNames++] = name;
		scores[sizeOfScores++] = score;
		//std::cout << name << "|" << score << std::endl;
	}
	getHighScore(names, scores, sizeOfNames);
	
	file.close();
	return 0;
}

void getHighScore(std::string names[], int scores[], int size) { 
	int tempScore[100] = { 0 };
	int highest = 0;
	int sensor = 0;
	int counter = 0;
	int topThree[3] = { 0 };
	std::string top[3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < size; j++) {
			tempScore[j] = scores[j];
			if (tempScore[j] >= highest) {
				highest = tempScore[j];
				sensor = j;
			}
		}

		topThree[i] = tempScore[sensor];
		top[i] = names[sensor];
		scores[sensor] = 0;
		highest = 0;
		std::cout << top[i] << "\n" << topThree[i] << std::endl;
	}
	
}
