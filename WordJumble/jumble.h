typedef char* charArrayPtr;
#include <string>
namespace std {
	class JumblePuzzle {
	public:
		JumblePuzzle(string word, string difficulty);
		JumblePuzzle(const JumblePuzzle &puzzle);
		int getSize();
		int getRowPos();
		int getColPos();
		char getDirection();
		charArrayPtr* getJumble();
	private:
		string word;
		int size;
		int rowPos;
		int colPos;
		char direction;
		charArrayPtr* jumble;
		char getRandomLetter();
		char getRandomDirection();
		int getRandomNumber(int max);
	}; 
	class BadJumbleException {
	public:
		BadJumbleException(const string& message);
		string what() const;
	private:
		string message;
	};
}