// Copyright Ethan Gutknecht
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;



void printResults(std::string hexVal) {
    int size = hexVal.size();
    int i = size - 1;

    std::cout << "| ";
    while (i > 0) {
            // std::cout << hexVal.str().substr(i - 1, i);

            std::cout << hexVal.at(i - 1);
            std::cout << hexVal.at(i);
            std::cout << " | ";
            i = i - 2;
    }
    std::cout << "\n";
}



int main(int argc, char* argv[]) {
    // Check file input
    if (argc != 2) {
        std::cerr << "Need to specify necessary files\n";
        return 0;
    }

    // Setup any necessary stream(s)
    std::ifstream input(argv[1]);  // Open input file

    // Process input
    std::string inputLine;
    while (std::getline(input, inputLine)) { 
        // Split input data
        vector<string> splitLine;
        boost::split(splitLine, inputLine, boost::is_any_of(" "));

        // Stringstream to hold the hex value
        stringstream hexVal;

        // Convert data
        int decimalValue = std::stoi(splitLine[3]);

        // Put data into stream as hex value
        hexVal << std::hex << decimalValue;

        // Check to see if hex value size is even
        if ( hexVal.str().size() % 2 == 1 ) {
            // Clear stringstream
            hexVal.str("");

            // Put data in the stream with a leading value
            hexVal << "0" << std::hex << decimalValue;
        }

        // Print out hex in little ending splitting the pairs
        // with a " | " character (e.g., | 01 | )
        printResults(hexVal.str());
    }
}
