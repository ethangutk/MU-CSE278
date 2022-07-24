// Copyright 2020 Ethan Gutknecht
#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>


void printResults(int intArray[], int numOfUserInput,
                  std::vector<std::string> strVector) {
    for (int i = 0; i < numOfUserInput; i++) {
        intArray[i] = std::stoi(strVector[i]);
    }
    
    int *ptrArray = &intArray[numOfUserInput - 1];
    
    for (int i = numOfUserInput; i > 0; i--) {
        std::string outputString = "";

        std::cout << "The factors of " << *ptrArray << " are:" << std::endl;

        // running through all factors
        for (int k = (*ptrArray / 2); k > 1; k--) {
            if (*ptrArray % k == 0) {
                outputString = outputString + std::to_string(k) + " ";
            }
        }
        std::cout << outputString << std::endl;
        
        ptrArray--;
    }
}

// Test Code Below
int main(int argc, char *argv[]) {
    // Check for number of arguments
    if (argc != 2) {
        std::cerr << "Insert correct number of inputs." << std::endl;
        return 1;
    }
    
    
    int numOfUserInput = std::stoi(argv[1]);
    std::string userInput;
    
    
    std::cout << "Enter " << numOfUserInput << " number(s):";
    std::getline(std::cin, userInput);
    
    
    // splits input into a vector<string> & convert strings to ints
    std::vector<std::string> strVector;
    int intArray[numOfUserInput];
    boost::split(strVector, userInput, boost::is_any_of(" "));
    
    printResults(intArray, numOfUserInput, strVector);;
}
