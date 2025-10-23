Hangman C++ Game

A complete implementation of the classic Hangman game in C++ with enhanced features and visual elements.

 🎮 Features

- **Multiple Difficulty Levels**: Easy, Medium, and Hard with appropriate word lengths
- **Visual Hangman Art**: Progressive ASCII art display
- **Smart Word Categories**: Fruit-themed words organized by difficulty
- **Input Validation**: Robust error handling for user inputs
- **Play Again Feature**: Continuous gameplay without restarting
- **Guess Tracking**: Keep track of previously guessed letters

 🚀 Getting Started

 Prerequisites
- C++ Compiler (GCC, Clang, or MSVC)
- CMake (optional, for building)

 Compilation & Running

Using c++
```bash
c++ -o hangman src/hangman.cpp -std=c++11
./hangman

Using CMake:

```bash
mkdir build && cd build
cmake ..
make
./hangman
```

🎯 How to Play

1. Run the executable
2. Select difficulty level (1-3)
3. Guess letters one at a time
4. Try to guess the word before running out of attempts
5. Win by revealing all letters or lose after 6 wrong guesses
6. Choose to play again or exit

Welcome to Hangman!
Guess the fruit name.

  _____
  |   |
  |   O
  |  /|\
  |  / 
  |   
__|__

Word: _ p p _ _
Attempts left: 2
Guessed letters: a e i o u p l
Enter a letter:


