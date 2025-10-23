#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_ATTEMPTS 6

class HangmanGame {
private:
    string secretWord;
    string displayWord;
    vector<char> guessedLetters;
    int attemptsLeft;
    int difficulty;

    vector<string> getWordsByDifficulty() {
        switch(difficulty) {
            case 1: // Easy - short words
                return {"apple", "grape", "kiwi", "pear", "plum", "fig", "date"};
            case 2: // Medium - medium words
                return {"banana", "cherry", "orange", "mango", "peach", "guava", "lemon"};
            case 3: // Hard - longer words
                return {"strawberry", "blueberry", "raspberry", "pineapple", "watermelon", "pomegranate", "blackberry"};
            default:
                return {"apple", "banana", "cherry"};
        }
    }

    string getRandomWord() {
        vector<string> words = getWordsByDifficulty();
        int index = rand() % words.size();
        return words[index];
    }

    bool alreadyGuessed(char letter) {
        return find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
    }

    bool updateWord(char letter) {
        bool found = false;
        for (size_t i = 0; i < secretWord.length(); i++) {
            if (secretWord[i] == letter) {
                displayWord[i] = letter;
                found = true;
            }
        }
        guessedLetters.push_back(letter);
        return found;
    }

    void displayHangman() {
        cout << endl;
        switch(attemptsLeft) {
            case 6:
                cout << "  _____" << endl;
                cout << "  |   |" << endl;
                cout << "  |   " << endl;
                cout << "  |   " << endl;
                cout << "  |   " << endl;
                cout << "  |   " << endl;
                cout << "__|__" << endl;
                break;
            case 5:
                cout << "  _____" << endl;
                cout << "  |   |" << endl;
                cout << "  |   O" << endl;
                cout << "  |   " << endl;
                cout << "  |   " << endl;
                cout << "  |   " << endl;
                cout << "__|__" << endl;
                break;
            case 4:
                cout << "  _____" << endl;
                cout << "  |   |" << endl;
                cout << "  |   O" << endl;
                cout << "  |   |" << endl;
                cout << "  |   " << endl;
                cout << "  |   " << endl;
                cout << "__|__" << endl;
                break;
            case 3:
                cout << "  _____" << endl;
                cout << "  |   |" << endl;
                cout << "  |   O" << endl;
                cout << "  |  /|" << endl;
                cout << "  |   " << endl;
                cout << "  |   " << endl;
                cout << "__|__" << endl;
                break;
            case 2:
                cout << "  _____" << endl;
                cout << "  |   |" << endl;
                cout << "  |   O" << endl;
                cout << "  |  /|\\" << endl;
                cout << "  |   " << endl;
                cout << "  |   " << endl;
                cout << "__|__" << endl;
                break;
            case 1:
                cout << "  _____" << endl;
                cout << "  |   |" << endl;
                cout << "  |   O" << endl;
                cout << "  |  /|\\" << endl;
                cout << "  |  / " << endl;
                cout << "  |   " << endl;
                cout << "__|__" << endl;
                break;
            case 0:
                cout << "  _____" << endl;
                cout << "  |   |" << endl;
                cout << "  |   O" << endl;
                cout << "  |  /|\\" << endl;
                cout << "  |  / \\" << endl;
                cout << "  |   " << endl;
                cout << "__|__" << endl;
                break;
        }
        cout << endl;
    }

    void setDifficulty() {
        cout << "Select difficulty level:" << endl;
        cout << "1. Easy (4-5 letters)" << endl;
        cout << "2. Medium (6-7 letters)" << endl;
        cout << "3. Hard (8+ letters)" << endl;
        cout << "Enter choice (1-3): ";
        
        while (!(cin >> difficulty) || difficulty < 1 || difficulty > 3) {
            cout << "Invalid input. Please enter 1, 2, or 3: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

public:
    HangmanGame() {
        srand(time(nullptr));
        setDifficulty();
        secretWord = getRandomWord();
        displayWord = string(secretWord.length(), '_');
        attemptsLeft = MAX_ATTEMPTS;
    }

    void play() {
        cout << "\nWelcome to Hangman!" << endl;
        cout << "Guess the fruit name." << endl;
        
        while (attemptsLeft > 0 && displayWord != secretWord) {
            displayHangman();
            cout << "Word: " << displayWord << endl;
            cout << "Attempts left: " << attemptsLeft << endl;
            cout << "Guessed letters: ";
            for (char c : guessedLetters) cout << c << " ";
            cout << "\nEnter a letter: ";

            string input;
            cin >> input;
            
            // Input validation for multiple characters
            if (input.length() != 1) {
                cout << "Please enter exactly one letter!" << endl;
                continue;
            }
            
            char guess = tolower(input[0]);

            if (!isalpha(guess)) {
                cout << "Invalid input. Please enter a letter." << endl;
                continue;
            }
            if (alreadyGuessed(guess)) {
                cout << "You already guessed that letter!" << endl;
                continue;
            }

            if (updateWord(guess))
                cout << "Good guess!" << endl;
            else {
                cout << "Wrong guess!" << endl;
                attemptsLeft--;
            }
        }
        
        displayHangman();
        if (displayWord == secretWord) {
            cout << "\nCongratulations! You guessed the word: " << secretWord << endl;
        } else {
            cout << "\nGame Over! The word was: " << secretWord << endl;
        }
    }
};

bool playAgain() {
    char choice;
    cout << "\nWould you like to play again? (y/n): ";
    cin >> choice;
    cin.ignore(10000, '\n'); // Clear input buffer
    return tolower(choice) == 'y';
}

int main() {
    cout << "=== HANGMAN GAME ===" << endl;
    
    do {
        HangmanGame game;
        game.play();
    } while (playAgain());
    
    cout << "Thanks for playing!" << endl;
    return 0;
}