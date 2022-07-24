// Copyright Ethan Gutknecht
#include <iostream>
#include <string>
// Variables
unsigned int pointer = 0;
unsigned int numOfWords = 0;
std::string largestWord = "";
std::string currentWord = "";
// Main block
int main(int argc, char** argv) {
    // Get user input from the user
    std::string inputText;
    std::cout << "Enter a line: ";
    std::getline(std::cin, inputText);
    // Loop through every character
    while (pointer < inputText.length()) {
        if (inputText.at(pointer) == ' ' || pointer == inputText.length() - 1) {
            if (pointer == inputText.length() - 1 && largestWord.length() < currentWord.length() + 1) {
              largestWord = currentWord + inputText.at(pointer);
            }
            else if (largestWord.length() < currentWord.length()) largestWord = currentWord;
            numOfWords++;
            currentWord = "";
        } else {
            currentWord = currentWord + inputText.at(pointer);
        }
        pointer++;
    }
    // Print the output
    std::cout << "Number of words: " << numOfWords <<
                 "\nLargest word: " << largestWord << "\n";
    return 0;
}
