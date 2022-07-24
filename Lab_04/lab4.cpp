// Copyright Ethan Gutknecht=
#include <iostream>
#include <string>
#include <unordered_map>

using StrIntMap = std::unordered_map<std::string, int>;

void createWeekMap(StrIntMap* weekNum) {
    *weekNum =    {{"Sunday", 1}, {"Monday", 2}, {"Tuesday", 3},
                 {"Wednesday", 4}, {"Thursday", 5}, {"Friday", 6},
                 {"Saturday", 7}};
}


void createMonthMap(StrIntMap* monthNumRefrence) {
    *monthNumRefrence =    {{"January", 1}, {"February", 2}, {"March", 3},
                            {"April", 4}, {"December", 12}, {"November", 11},
                            {"October", 10}, {"May", 5}, {"August", 8},
                            {"June", 6}, {"July", 7}, {"September", 9}};
}

void getAndSortLineFromUser(std::string* inputWeek, std::string* inputMonth) {
    std::string inputLine;
    unsigned int pointer = 0;
    
    std::cout << "Enter a month and weekday: ";
    std::getline(std::cin, inputLine);
    
    while ( pointer < inputLine.length() ) {  // gets input month
        if ( inputLine.at(pointer) == ' ' ) {
            *inputMonth = inputLine.substr(0, pointer);
            break;
        }
        pointer++;
    }
    *inputWeek = inputLine.substr(pointer + 1);  // gets input week
}

int main() {
    // Creates Instances, calls creation using methods with functions
    StrIntMap monthNum;
    StrIntMap weekNum;
    std::string inputWeek;
    std::string inputMonth;
    createWeekMap(&weekNum);
    createMonthMap(&monthNum);
    while (true) {
          // calls for line and sorts line
        getAndSortLineFromUser(&inputWeek, &inputMonth);
         // checks if inputs are valid
        if (monthNum.find(inputMonth) == monthNum.end()) {
            std::cerr << "The month " << inputMonth << " is not valid\n";
        } else if (weekNum.find(inputWeek) == weekNum.end()) {
            std::cerr << "The day " << inputWeek << " is not valid\n";
        } else {
            std::cout << inputMonth << ", " << inputWeek << " => ";
            std::cout << monthNum.find(inputMonth)->second << ", ";
            std::cout << weekNum.find(inputWeek)->second << "\n";
            break;
        }
    }
  return 0;
}
