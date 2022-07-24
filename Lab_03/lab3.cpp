// Copyright 2020 Ethan Gutknecht


#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <climits>

int computeSum(std::vector<int> inputNumList) {
    int sum = 0;
    
    for (auto & num : inputNumList) {
        sum = sum + num;
    }

    return sum;
}

double computeAverage(std::vector<int> inputNumList) {
    double average = 0.0;
    int numOfInputs = 0;
    for (auto & num : inputNumList) {
        average = average + num;
        numOfInputs++;
    }

    return average/numOfInputs;
}

int computeMax(std::vector<int> inputNumList) {
    int max = INT_MIN;

    for (auto & num : inputNumList) {
        if (max < num) {
            max = num;
        }
    }

    return max;
}

int computeMin(std::vector<int> inputNumList) {
    int min = INT_MAX;

    for (auto & num : inputNumList) {
        if (min > num) {
            min = num;
        }
    }

    return min;
}

void printResult(std::ostream& out, int sum, int min, double average, int max) {
    out << "Sum: " << sum << std::endl;
    out << "Min: " << min << std::endl;
    out << "Average: " << average << std::endl;
    out << "Max: " << max << std::endl;
}


int main(int argc, char *argv[]) {
    // Verify the correct number of arguments
    if (argc != 3) {
        std::cerr << "Specify input and output files\n";
        return 0;  // non-zero return from main to signal error
    }

    // Create streams with command line arguments
    std::ifstream input(argv[1]);  // Open input file
    std::ofstream output(argv[2]);  // Create/overwrite output file
    
    
    // Check streams were successfully created
    if (!input.good() || !output.good()) {
        std::cerr << "Error opening input or output streams\n";
        return 0;  // non-zero return from main to signal error
    }

    // Read input file to some data structure
    /* Update Here - need some data structure */
    int num;
    std::vector<int> numList;
    while (input >> num) {
        numList.push_back(num);
    }


    // Compute the sum, average, min, max
    int sum = computeSum(numList);
    double average = computeAverage(numList);
    int min = computeMin(numList);
    int max = computeMax(numList);
    
    
    
    // Display results -- DO NOT MODIFY BELOW THIS LINE
    printResult(output, sum, min, average, max);
    printResult(std::cout, sum, min, average, max);
}
