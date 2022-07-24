// Copyright
#include <iostream>
#include <string>

unsigned int pointer = 0;
unsigned int numOfWords = 0;
unsigned int numCharInCurrentWord = 0;
std::string largestWord = "";



/*
 * A simple string operation program
 */
int main(int argc, char** argv) {
    // Variables to track word count and largest word

    // Get user input from the user
    std::string inputText;
    std::cout << "\nEnter a line: ";
    std::getline(std::cin, inputText);
    
    
    // Variable to track current position in string

    // Loop through the input while it has spaces
    while(pointer < inputText.length() /* some other condition */){
        
        if (inputText.substr(pointer, pointer + 1) == " ") {
            //increase word count
            numOfWords++;
            
            if (numCharInCurrentWord > largestWord.length()) {
                //get current word if its the biggest and replace biggest
                largestWord = inputText.substr(pointer - numCharInCurrentWord, pointer);
            }
        }
        else numCharInCurrentWord++;        
    }
    
    //Print the output
    std::cout << "\nNumber of words: " << numOfWords << "\n";
    std::cout << "\nLargest word: " << largestWord << "\n";
    return 0;
}

