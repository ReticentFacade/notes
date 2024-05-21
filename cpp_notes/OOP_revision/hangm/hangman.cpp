#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<ctime>
#include<cstdlib>


class Hangman {
    // Attributes:
    std::string secretWord;
    std::string guessedWord;
    int remainingAttempts;
    std::set<char> guessedLetters;

    public:
        // Constructor
        Hangman(std::string word, int maxAttempts) : secretWord(word), guessedWord(word.size(), '_'), remainingAttempts(maxAttempts) {}

        // Methods
        bool guessedLetter(char letter) {
            if (guessedLetters.find(letter) != guessedLetters.end()) {
                std::cout << "You already guessed that letter" << std::endl;
                return false;
            }

            guessedLetters.insert(letter);
            
            bool correctGuess = false;
            for (size_t i = 0; i < secretWord.size(); i++) {
                if (secretWord[i] == letter) {
                    guessedWord[i] = letter;
                    correctGuess = true;
                }
            }

            if (!correctGuess) remainingAttempts--;

            return correctGuess;
        }

        bool isGameWon() const {
            return guessedWord == secretWord;
        }

        bool isGameLost() const {
            return remainingAttempts <= 0;
        }

        void displayCurrentState() const {
            std::cout << "Current Word: " << guessedWord << std::endl;
            std::cout << "Remaining Attempts: " << remainingAttempts << std::endl;
            std::cout << "Guessed Letters: ";

            for (char letter: guessedLetters) {
                std::cout << letter << " ";
            }
            std::cout << std::endl;
        }
};

// Main game loop -> 
std::string getRandomWord() {
    std::vector<std::string> words = {"kiwi", "hangman", "business", "people"};
    std::srand(std::time(0));

    return words[std::rand() % words.size()];
}

int main() {
    std::string word = getRandomWord();
    Hangman game(word, 6);

    while (!game.isGameWon() && !game.isGameLost()) {
        game.displayCurrentState();

        std::cout << "Enter a letter: ";
        char guess;
        std::cin >> guess;

        // Clearing input buffer -> 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!game.guessedLetter(guess)) std::cout << "Wrong letter!";

        if (game.isGameWon()) std::cout << "Congratulations! You've won! The word was: " << word << std::endl;
        else if (game.isGameLost()) std::cout << "You've lost! The word was: " << word << std::endl;
    }

    return 0;
}