#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <stdexcept>

// Function to guess numbers
void playNumberGuessingGame() {
    int score = 0;
    int rounds = 5;
    char guess;
    int prevNumber = std::rand() % 100 + 1; // Generate the first random number between 1 and 100
    int nextNumber;
    
    std::cout << "You start with the number: " << prevNumber << "\n\n";

    for (int i = 0; i < rounds; ++i) {
        bool validInput = false;

        // Input validation for guess
        while (!validInput) {
            try {
                std::cout << "Round " << i + 1 << ": Will the next number be higher (H) or lower (L)? ";
                std::cin >> guess;

                if (guess != 'H' && guess != 'h' && guess != 'L' && guess != 'l') {
                    throw std::invalid_argument("Invalid input! Please enter 'H' for Higher or 'L' for Lower.");
                }
                validInput = true;
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << "\n";
            }
        }

        nextNumber = std::rand() % 100 + 1;

        if ((guess == 'H' || guess == 'h') && nextNumber > prevNumber) {
            std::cout << "Correct! The next number was " << nextNumber << " (Higher)\n";
            score++;
        } else if ((guess == 'L' || guess == 'l') && nextNumber < prevNumber) {
            std::cout << "Correct! The next number was " << nextNumber << " (Lower)\n";
            score++;
        } else {
            std::cout << "Wrong! The next number was " << nextNumber << "\n";
        }

        prevNumber = nextNumber;
        std::cout << "Your current score: " << score << "\n\n";
    }

    std::cout << "Game Over! Your final score: " << score << " out of " << rounds << " rounds.\n";
}

// Function to guess colors
void playColorGuessingGame() {
    std::vector<std::string> colors = {"Red", "Blue", "Green", "Yellow", "Purple", "Orange"};
    int score = 0;
    int rounds = 5;
    char guess;
    std::string prevColor = colors[std::rand() % colors.size()];
    std::string nextColor;

    std::cout << "You start with the color: " << prevColor << "\n\n";

    for (int i = 0; i < rounds; ++i) {
        std::cout << "Round " << i + 1 << ": Will the next color come alphabetically later (L) or earlier (E)? ";
        std::cin >> guess;

        nextColor = colors[std::rand() % colors.size()];

        if ((guess == 'L' || guess == 'l') && nextColor > prevColor) {
            std::cout << "Correct! The next color was " << nextColor << " (Later in the alphabet)\n";
            score++;
        } else if ((guess == 'E' || guess == 'e') && nextColor < prevColor) {
            std::cout << "Correct! The next color was " << nextColor << " (Earlier in the alphabet)\n";
            score++;
        } else {
            std::cout << "Wrong! The next color was " << nextColor << "\n";
        }

        prevColor = nextColor;
        std::cout << "Your current score: " << score << "\n\n";
    }

    std::cout << "Game Over! Your final score: " << score << " out of " << rounds << " rounds.\n";
}

// Function to guess animals (categorized)
void playAnimalGuessingGame() {
    std::vector<std::string> animals = {
        "Lion (Land)", "Shark (Marine)", "Frog (Amphibian)", "Eagle (Air)",
        "Elephant (Land)", "Whale (Marine)", "Salamander (Amphibian)", "Parrot (Air)"
    };
    int score = 0;
    int rounds = 5;
    std::string prevAnimal = animals[std::rand() % animals.size()];
    std::string nextAnimal;

    std::cout << "You start with the animal: " << prevAnimal << "\n\n";

    for (int i = 0; i < rounds; ++i) {
        std::cout << "Round " << i + 1 << ": Will the next animal come from the same habitat? (Y/N) ";
        char guess;
        std::cin >> guess;

        nextAnimal = animals[std::rand() % animals.size()];

        if ((guess == 'Y' || guess == 'y') && nextAnimal.substr(nextAnimal.find("(")) == prevAnimal.substr(prevAnimal.find("("))) {
            std::cout << "Correct! The next animal was " << nextAnimal << " (Same habitat)\n";
            score++;
        } else if ((guess == 'N' || guess == 'n') && nextAnimal.substr(nextAnimal.find("(")) != prevAnimal.substr(prevAnimal.find("("))) {
            std::cout << "Correct! The next animal was " << nextAnimal << " (Different habitat)\n";
            score++;
        } else {
            std::cout << "Wrong! The next animal was " << nextAnimal << "\n";
        }

        prevAnimal = nextAnimal;
        std::cout << "Your current score: " << score << "\n\n";
    }

    std::cout << "Game Over! Your final score: " << score << " out of " << rounds << " rounds.\n";
}

// Function to guess fruits or vegetables
void playFruitOrVegetableGuessingGame() {
    std::vector<std::string> fruits = {"Apple", "Banana", "Orange", "Grape", "Mango", "Pineapple"};
    std::vector<std::string> vegetables = {"Carrot", "Broccoli", "Potato", "Tomato", "Cucumber", "Spinach"};
    int score = 0;
    int rounds = 5;
    std::string category;
    std::string nextItem;
    
    for (int i = 0; i < rounds; ++i) {
        // Randomly choose between fruits and vegetables
        category = (std::rand() % 2 == 0) ? "Fruit" : "Vegetable";
        nextItem = (category == "Fruit") ? fruits[std::rand() % fruits.size()] : vegetables[std::rand() % vegetables.size()];

        std::cout << "Round " << i + 1 << ": Is the next item a Fruit (F) or a Vegetable (V)? ";
        char guess;
        std::cin >> guess;

        if ((guess == 'F' || guess == 'f') && category == "Fruit") {
            std::cout << "Correct! The item was " << nextItem << " (Fruit)\n";
            score++;
        } else if ((guess == 'V' || guess == 'v') && category == "Vegetable") {
            std::cout << "Correct! The item was " << nextItem << " (Vegetable)\n";
            score++;
        } else {
            std::cout << "Wrong! The item was " << nextItem << " (" << category << ")\n";
        }

        std::cout << "Your current score: " << score << "\n\n";
    }

    std::cout << "Game Over! Your final score: " << score << " out of " << rounds << " rounds.\n";
}

int main() {
    char choice;
    
    do {
        try {
            std::cout << "Welcome to the Intuition Strengthening Game!\n";
            std::cout << "Choose a category:\n";
            std::cout << "1. Guess Numbers\n";
            std::cout << "2. Guess Colors\n";
            std::cout << "3. Guess Animals\n";
            std::cout << "4. Guess Fruits or Vegetables\n";
            std::cout << "5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (choice == '1') {
                playNumberGuessingGame();
            } else if (choice == '2') {
                playColorGuessingGame();
            } else if (choice == '3') {
                playAnimalGuessingGame();
            } else if (choice == '4') {
                playFruitOrVegetableGuessingGame();
            } else if (choice == '5' || choice == 'n' || choice=='N') {
                std::cout << "Thanks for playing! Goodbye!\n";
                break;
            } else {
                throw std::invalid_argument("Invalid choice! Please enter a number between 1 and 5.");
            }
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\n";
        }

        std::cout << "Would you like to play again? (Y/N): ";
        std::cin >> choice;
        if(choice=='n' || choice == 'N') std::cout<<"Get Out of my lawn!";
        
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
