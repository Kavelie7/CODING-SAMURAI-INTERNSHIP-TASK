// NumberGuessingGame.cpp
#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    // Loop until the user guesses correctly
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        }
        else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed it in " << attempts << " attempts." << endl;
        }

    } while (guess != secretNumber);

    return 0;
}
