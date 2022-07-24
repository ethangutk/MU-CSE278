// Copyright Ethan Gutknecht

#include <iostream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <utility>

  // Variables 
std::map<std::string, double> mapOfGrades;  // type , percentage

int totalQuizPoints;
int quizPointsEarned;

int totalHwPoints;
int hwPointsEarned;

int totalLabPoints;
int labPointsEarned;

int totalMidtermPoints;
int midtermPointsEarned;

int totalFinalPoints;
int finalPointsEarned;



using namespace std;

void addToMap() {
    mapOfGrades.insert(std::pair<string, double>
    ("quiz", quizPointsEarned/totalQuizPoints));
    mapOfGrades.insert(std::pair<string, double>
    ("lab", labPointsEarned/totalLabPoints));
    mapOfGrades.insert(std::pair<string, double>
    ("homework", hwPointsEarned/totalHwPoints));
    mapOfGrades.insert(std::pair<string, double>
    ("midterm", midtermPointsEarned/totalMidtermPoints));
    mapOfGrades.insert(std::pair<string, double>
    ("final_exam", finalPointsEarned/totalFinalPoints));
}

void convertToLetter() {
}


void parseInputFile(std::ifstream& input) {
    // variables
    int counter = 0; 
    std::string line;  
    // reads file line by line and splits string
    while (input >> line) {
        // vector of 3 items, split string
        vector<string> splitLine;
        boost::split(splitLine, line, boost::is_any_of(","));
        
        if (splitLine[0].compare("quiz")) {
            totalQuizPoints  += std::stof(splitLine[2]);
            quizPointsEarned += std::stof(splitLine[1]);
        } else if (splitLine[0].compare("lab")) {
            totalLabPoints  += std::stof(splitLine[2]);
            labPointsEarned += std::stof(splitLine[1]);
        } else if (splitLine[0].compare("homework")) {
            totalHwPoints  += std::stof(splitLine[2]);
            hwPointsEarned += std::stof(splitLine[1]);
        } else if (splitLine[0].compare("midterm")) {
            totalMidtermPoints  += std::stof(splitLine[2]);
            midtermPointsEarned += std::stof(splitLine[1]);
        } else if (splitLine[0].compare("final_exam")) {
            totalFinalPoints  += std::stof(splitLine[2]);
            finalPointsEarned += std::stof(splitLine[1]);
        }
        counter++;
    }
    addToMap();
}

void parseWeights() {
}


void printResults() {
    // out << "Sum: " << sum << std::endl;
    // out << "Min: " << min << std::endl;
    // out << "Average: " << average << std::endl;
    // out << "Max: " << max << std::endl;
}


int main(int argc, char *argv[]) {
    // Verify the correct number of arguments
    if (argc != 3) {
        std::cerr << "Need to specify necessary files\n";
        return 0;  
    }

    // Create streams with command line arguments
    std::ifstream input(argv[1]);  // Open input file
    std::ofstream output(argv[2]);  // Create/overwrite output file
    
    
    // Check streams were successfully created
    if (!input.good() || !output.good()) {
        std::cerr << "There was an error opening one of the files\n";
        return 0;  // non-zero return from main to signal error
    }
    
    parseInputFile(input);
    printResults();
}












