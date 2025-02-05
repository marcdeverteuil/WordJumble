#include "jumble.h"
using namespace std;
JumblePuzzle::JumblePuzzle(string word, string difficulty) {
	int sizeMultiplier = 0;
	if (difficulty == "easy") {
		sizeMultiplier = 2;
	}
	else if (difficulty == "medium") {
		sizeMultiplier = 3;
	}
	else if (difficulty == "hard") {
		sizeMultiplier = 4;
	}
	else {
		throw BadJumbleException("Difficutly must be inputed as 'easy', 'medium' or 'hard'");
	}
	this->word = word;
	int length = this->word.length();
	this->size = length*sizeMultiplier;
	this->direction = getRandomDirection();
	this->colPos = getRandomNumber(size);
	this->rowPos = getRandomNumber(size);
	charArrayPtr* puzzle = new charArrayPtr[size]();
	for (int i = 0; i < size; i++) {
		char* col = new char[size]();
		puzzle[i] = col;
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			puzzle[i][j] = getRandomLetter();
		}
	}
	if (this->direction == 'n') {
		while (this->colPos +1-length < 0) {
			this->colPos = getRandomNumber(size);
		}
		for (int i = 0; i < length; i++) {
			{
				puzzle[this->colPos-i][this->rowPos] = this->word[i];
			}
		}
	}
	else if (this->direction == 'e') {
		while (this->rowPos + 1 - length < 0) {
			this->rowPos = getRandomNumber(size);
		}
		for (int i = 0; i < length; i++) {
			{
				puzzle[this->colPos][this->rowPos-i] = this->word[i];
			}
		}
	}
	else if (this->direction == 's') {
		while (this->colPos + length >=size) {
			this->colPos = getRandomNumber(size);
		}
		for (int i = 0 ; i < length; i++) {
			{
				puzzle[this->colPos+i][rowPos] = this->word[i];
			}
		}
	}
	else if (this->direction == 'w') {
		while (this->rowPos + length >= size) {
			this->rowPos = getRandomNumber(size);
		}
		for (int i = 0; i < length; i++) {{
				puzzle[this->colPos][this->rowPos+i] = this->word[i];
			}
		}
	}
	this->jumble = puzzle;
}
JumblePuzzle::JumblePuzzle(const JumblePuzzle &puzzle) {
	this->word = puzzle.word;
	this->size = puzzle.size;
	this->rowPos = puzzle.rowPos;
	this->colPos = puzzle.colPos;
	this->direction = puzzle.direction;
	this->jumble = new charArrayPtr[size]();
	for (int i = 0; i < size; i++) {
		char* col = new char[size]();
		this->jumble[i] = col;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			this->jumble[i][j] = puzzle.jumble[i][j];
		}
	}
}
charArrayPtr* JumblePuzzle::getJumble() {
	return this->jumble;
}
int JumblePuzzle::getSize() {
	return this->size;
}

int JumblePuzzle::getRowPos()
{
	return this->rowPos;
}

int JumblePuzzle::getColPos()
{
	return this->colPos;
}

char JumblePuzzle::getDirection()
{
	return this->direction;
}
char JumblePuzzle::getRandomDirection()
{
	string directions = "nwse";
	return directions[getRandomNumber(4)];
}
char JumblePuzzle::getRandomLetter()
{
	string letters = "abcdefghijklmnopqrstuvwxyz";
	return letters[getRandomNumber(26)];
}

int JumblePuzzle::getRandomNumber(int max)
{
	return rand() % max;
}


std::BadJumbleException::BadJumbleException(const string &message)
{
	this->message = message;
}

string std::BadJumbleException::what() const
{
	return message;
}
