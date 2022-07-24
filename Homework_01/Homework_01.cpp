// Copyright Ethan Gutknecht
#include <iostream>
#include <string>

// Variables
unsigned int wc = 0;
unsigned int pointer = 0;

// Main block
int main(int argc, char** argv) {
    // Get user input from the user
    std::string inputText;
    std::getline(std::cin, inputText);
    
    // Loop through every character
    while (pointer < inputText.length()) {
        if (inputText.at(pointer) == ' ') {
            if (inputText.at(pointer + 1) == 65) wc++;  // A
            else if (inputText.at(pointer + 1) == 97)  wc++;  // a
            else if (inputText.at(pointer + 1) == 69)  wc++;  // E
            else if (inputText.at(pointer + 1) == 101) wc++;  // e
            else if (inputText.at(pointer + 1) == 73)  wc++;  // I
            else if (inputText.at(pointer + 1) == 105) wc++;  // i
            else if (inputText.at(pointer + 1) == 79)  wc++;  // O
            else if (inputText.at(pointer + 1) == 111) wc++;  // o
            else if (inputText.at(pointer + 1) == 85)  wc++;  // U
            else if (inputText.at(pointer + 1) == 117) wc++;  // u
        }
        if (pointer == 0) {
            if (inputText.at(pointer) == 65) wc++;  // A
            else if (inputText.at(pointer) == 97)  wc++;  // a
            else if (inputText.at(pointer) == 69)  wc++;  // E
            else if (inputText.at(pointer) == 101) wc++;  // e
            else if (inputText.at(pointer) == 73)  wc++;  // I
            else if (inputText.at(pointer) == 105) wc++;  // i
            else if (inputText.at(pointer) == 79)  wc++;  // O
            else if (inputText.at(pointer) == 111) wc++;  // o
            else if (inputText.at(pointer) == 85)  wc++;  // U
            else if (inputText.at(pointer) == 117) wc++;  // u
        }
        pointer++;
    }
    
    // Print the output
    std::cout << wc << "\n";
    return 0;
}
